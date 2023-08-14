#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdbool.h>
#include <signal.h>
#include <semaphore.h>

#define FILE_NAME 256
#define WRITE_SIZE 1024
#define MAX_OPEN_FILES_LIMIT 1020

typedef struct Buffer {
    int sourcefd, destinationfd;
    char fileName[FILE_NAME];
} Buffer;

Buffer* bufferQueue;
int bufferCount = 0;
int bufferSize;
int consumer_number;

long numOfBytes = 0;

pthread_mutex_t mutexQueue;
pthread_mutex_t stdoutBlock;
pthread_cond_t condQueue;
pthread_cond_t fullCondQueue;

pthread_t* consumer_threads;
pthread_t producer_thread;

bool finished = false;
bool interrupted = false;
bool limit = false;

int statFD;
int copiedFileNum = 1;

sem_t semaphore;


const char* getFileType(const char* fileName) {
    const char* dot = strrchr(fileName, '.');
    if (dot && dot != fileName) {
        return dot + 1;
    }
    return "none";
}

const char* getDest(const char* name) {
    const char* slash = strrchr(name, '/');
    if (slash && slash != name) {
        return slash + 1;
    }
    return name;
}

void executeTask(Buffer* buffer) {
    pthread_mutex_lock(&stdoutBlock);
    printf("COPY OF FILE \"%s\" IS STARTED. COPYING...\n", buffer->fileName);
    pthread_mutex_unlock(&stdoutBlock);

    char toWrite[WRITE_SIZE];
    int readVal;
    do{
        if (interrupted) return;
        readVal = read(buffer->sourcefd, toWrite, sizeof(toWrite)-1);
        toWrite[WRITE_SIZE - 1] = '\0';
        write(buffer->destinationfd, toWrite, readVal);
        numOfBytes += readVal;
    }while(readVal > 0);
    close(buffer->sourcefd);     
    close(buffer->destinationfd);
    sem_post(&semaphore); sem_post(&semaphore);

    pthread_mutex_lock(&stdoutBlock);
    printf("COPY OF FILE \"%s\" IS FINISHED.\n", buffer->fileName);
    pthread_mutex_unlock(&stdoutBlock);
}

void* startThread(void* args) {
    while (1) {
        pthread_mutex_lock(&mutexQueue);
        while (bufferCount == 0 && !finished && !interrupted) {
            pthread_cond_wait(&condQueue, &mutexQueue);
        }
        if ((finished && bufferCount == 0) || interrupted){
            pthread_mutex_unlock(&mutexQueue);
            break; 
        }
        Buffer buffer = bufferQueue[0];
        int i;
        for (i = 0; i < bufferCount - 1; i++) {
            bufferQueue[i] = bufferQueue[i + 1];
        }
        bufferCount--;
        pthread_mutex_unlock(&mutexQueue);
        pthread_cond_signal(&fullCondQueue);

        executeTask(&buffer);
    }
}

void* producerThread(void* args) {
    char* directoryPath = (char*)((char**)args)[0];
    char* destPath = (char*)((char**)args)[1];

    DIR* directory = opendir(directoryPath);
    if (directory == NULL) {
        perror("No directory");
    }
    else{
        struct dirent* entry;
        while ((entry = readdir(directory)) != NULL && !interrupted) {
            if (interrupted) break;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
            else if (entry->d_type == DT_DIR){
                char* paths[2];
                char temp[PATH_MAX];
                char tempDest[PATH_MAX];
                snprintf(temp, sizeof(temp), "%s/%s", directoryPath, entry->d_name);
                snprintf(tempDest, sizeof(tempDest), "%s/%s", destPath, entry->d_name);

                paths[0] = temp;
                paths[1] = tempDest;

                int result = mkdir(tempDest, 0777);
                if (result != 0) {
                    if (errno != EEXIST) perror("mkdir");
                }

                producerThread(paths);
            }
            else if (entry->d_type == DT_FIFO){
                char fifoPath[PATH_MAX];
                snprintf(fifoPath, sizeof(fifoPath), "%s/%s", destPath, entry->d_name);
                mkfifo(fifoPath, 0777);

                char stat[256];
                const char* fileType = "FIFO";
                snprintf(stat, sizeof(stat), "%d. %s%s\n", copiedFileNum++, "copied file type: ", fileType);
                write(statFD, stat, strlen(stat));

                printf("COPY OF FIFO \"%s\" IS STARTED. COPYING...\nCOPY OF FIFO \"%s\" IS FINISHED.\n", entry->d_name, entry->d_name);
            }
            else {
                char filePath[PATH_MAX];
                char destFile[PATH_MAX];
                snprintf(filePath, sizeof(filePath), "%s/%s", directoryPath, entry->d_name);
                snprintf(destFile, sizeof(destFile), "%s/%s", destPath, entry->d_name);

                sem_wait(&semaphore);
                if (interrupted) break;
                int fd = open(filePath, O_RDONLY); 
                if (fd == -1) {
                    pthread_mutex_lock(&stdoutBlock);
                    printf("Opening file error... %s could not be copied.\n", entry->d_name);
                    pthread_mutex_unlock(&stdoutBlock);
                    continue;
                }

                sem_wait(&semaphore);
                if (interrupted) break;
                int destfd = open(destFile, O_WRONLY | O_TRUNC | O_CREAT, 0777); 
                if (destfd == -1) {
                    pthread_mutex_lock(&stdoutBlock);
                    printf("Opening file error... %s could not be copied.\n", entry->d_name);
                    pthread_mutex_unlock(&stdoutBlock);
                    close(fd);
                    continue;
                }
                if (ftruncate(destfd, 0) == -1){
                    pthread_mutex_lock(&stdoutBlock);
                    printf("Error during truncating the file... %s could not be truncated.\n", entry->d_name);
                    pthread_mutex_unlock(&stdoutBlock);
                    close(destfd);
                    close(fd);
                    continue;
                }
                close(destfd);
                destfd = open(destFile, O_WRONLY, 0777);

                char stat[256];
                const char* fileType = getFileType(entry->d_name);
                snprintf(stat, sizeof(stat), "%d. %s%s\n", copiedFileNum++, "copied file type: ", fileType);
                write(statFD, stat, strlen(stat));

                Buffer buffer;
                buffer.sourcefd = fd;
                buffer.destinationfd = destfd;
                strcpy(buffer.fileName, entry->d_name);

                
                pthread_mutex_lock(&mutexQueue);
                while (bufferCount == bufferSize && !interrupted) {
                    pthread_cond_wait(&fullCondQueue, &mutexQueue);
                }
                if (interrupted){
                    pthread_mutex_unlock(&mutexQueue);
                    break;
                }
                bufferQueue[bufferCount++] = buffer;
                pthread_mutex_unlock(&mutexQueue);
                pthread_cond_signal(&condQueue);
                
            }
        }

        closedir(directory);
    }
    
}

void handler(int signum) {
    int i;
    interrupted = true;
    sem_post(&semaphore); sem_post(&semaphore);
    printf("\nSignal received. Exiting...\n");
    
    pthread_cond_signal(&fullCondQueue);
    pthread_cond_broadcast(&condQueue);

}

int main(int argc, char* argv[]) {
    if (argc != 5){
        printf("Bad argument number, exiting...\n");
        return -1;
    }
    bufferSize = atoi(argv[1]);
    consumer_number = atoi(argv[2]);
    char* source = argv[3];
    char* destination = argv[4];

    struct sigaction saINT, saTERM, saQUIT;
    memset(&saINT, 0, sizeof(saINT));
    saINT.sa_handler = &handler;
    saINT.sa_flags = SA_RESTART;
    sigaction(SIGINT, &saINT, NULL);

    memset(&saTERM, 0, sizeof(saTERM));
    saTERM.sa_handler = &handler;
    saTERM.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &saTERM, NULL);

    memset(&saQUIT, 0, sizeof(saQUIT));
    saQUIT.sa_handler = &handler;
    saQUIT.sa_flags = SA_RESTART;
    sigaction(SIGQUIT, &saQUIT, NULL);

    if (access(destination, F_OK) != -1){
        if (source[strlen(source)-1] == '/') source[strlen(source)-1] = '\0';
        const char* sourceFolder = getDest(source);
        sprintf(destination, "%s/%s", destination, sourceFolder);
        if (mkdir(destination, S_IRWXU | S_IRWXG | S_IRWXO) == -1){
            if (errno != EEXIST){
                perror("Error during directory creation. Exiting...");
                return -1;
            }
        }
    }
    else if (mkdir(destination, S_IRWXU | S_IRWXG | S_IRWXO) == -1){
        if (errno != EEXIST){
            perror("Error during directory creation. Exiting...");
            return -1;
        }
    }
    if (access(source, F_OK) == -1){
        printf("Invalid source path, exiting...\n");
        return -1;
    }
    if (bufferSize <= 0 || consumer_number <= 0){
        printf("Invalid numbers, exiting...\n");
        return -1;
    }

    char* paths[2];
    paths[0] = source;
    paths[1] = destination;

    bufferQueue = (Buffer*)calloc(bufferSize, sizeof(Buffer));
    statFD = open("statistics.txt", O_APPEND | O_CREAT | O_WRONLY | O_TRUNC, 0666); 

    pthread_mutex_init(&mutexQueue, NULL);
    pthread_mutex_init(&stdoutBlock, NULL);
    pthread_cond_init(&condQueue, NULL);
    pthread_cond_init(&fullCondQueue, NULL);
    sem_init(&semaphore, 0, MAX_OPEN_FILES_LIMIT);
    
    consumer_threads = (pthread_t*)calloc(consumer_number, sizeof(pthread_t));

    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    printf("Current time before first thread is created: %ld seconds, %ld microseconds\n", currentTime.tv_sec, currentTime.tv_usec);
    
    if (pthread_create(&producer_thread, NULL, &producerThread, paths) != 0) {
        perror("Failed to create the thread");
    }
    int i;
    for (i = 0; i < consumer_number; i++) {
        if (pthread_create(&consumer_threads[i], NULL, &startThread, NULL) != 0) {
            perror("Failed to create the thread");
        }
    }


    if (pthread_join(producer_thread, NULL) != 0) {
        perror("Failed to join the thread");
    }
    finished = true;
    pthread_cond_broadcast(&condQueue);
    for (i = 0; i < consumer_number; i++) {
        if (pthread_join(consumer_threads[i], NULL) != 0) {
            perror("Failed to join the thread");
        }
    }
    
    struct timeval lastCurrentTime, timeDifference;
    gettimeofday(&lastCurrentTime, NULL);
    printf("Current time after last join: %ld seconds, %ld microseconds\n", lastCurrentTime.tv_sec, lastCurrentTime.tv_usec);
    
    timeDifference.tv_sec = lastCurrentTime.tv_sec-currentTime.tv_sec;
    timeDifference.tv_usec = lastCurrentTime.tv_usec-currentTime.tv_usec;
    if (timeDifference.tv_usec < 0){ timeDifference.tv_sec--; timeDifference.tv_usec += 1000000; }
    printf("Total time passed to copy files: %ld seconds, %ld microseconds\n", timeDifference.tv_sec, timeDifference.tv_usec);

    char stat[100];
    snprintf(stat, sizeof(stat), "%s %ld %s\n", "Total of", numOfBytes, "bytes were copied.");
    write(statFD, stat, strlen(stat));
    snprintf(stat, sizeof(stat), "%s %d %s\n", "Total of", copiedFileNum-1, "files were copied.");
    write(statFD, stat, strlen(stat));
    printf("Total of %ld bytes were copied.\n", numOfBytes);
    printf("Total of %d files were copied.\n", copiedFileNum-1);

    pthread_mutex_destroy(&mutexQueue);
    pthread_mutex_destroy(&stdoutBlock);
    pthread_cond_destroy(&condQueue);
    pthread_cond_destroy(&fullCondQueue);
    sem_destroy(&semaphore);

    free(consumer_threads);
    free(bufferQueue);

    close(statFD);

    printf("END OF MAIN\n");

    return 0;
}