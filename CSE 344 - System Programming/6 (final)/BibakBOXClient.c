#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
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

#define BUFFER_SIZE 1024
#define BLOCK_SIZE 2048

pthread_cond_t fileCond;
pthread_mutex_t fileTask;
pthread_mutex_t socketMutex;
pthread_mutex_t socketMutexR;

char detailedNames[256][256];
int currentFile = 0;
int logFile;


typedef struct {
    char name[256];
    bool isFile;
    time_t modified_time;
} FileEntry;

typedef struct {
    FileEntry *entries;
    int count;
} DirectorySnapshot;

typedef struct {
    char name[100];
    int mode; //0 modified, 1 created, 2 deleted
} Changed;

Changed changed[256];
int changedCount = 0;
int type = 0;

DirectorySnapshot oldSnapshot, newSnapshot;

bool interrupted = false;
int clientSocket;

char cwd[PATH_MAX];

void handler(int signum) {
    interrupted = true;
    int number = -1;
    int fd;
    char filename[100] = "-FINISH-";
    char block[BLOCK_SIZE] = "-FINISH-";
    switch (type){
        case 0: if (send(clientSocket, &number, sizeof(number), 0) == -1) {
                    perror("send");
                    exit(1);
                }
                break;
        case 1: if (send(clientSocket, filename, 100, 0) == -1) {
                    perror("Send failed");
                    return;
                }
                break;
        case 2: if (send(clientSocket, block, sizeof(block), 0) == -1) {
                    perror("send");
                    exit(1);
                }
                break;
    }
    
    for (fd = 0; fd < getdtablesize(); fd++) {
        close(fd);
    }

    kill(getpid(), SIGKILL);
}

void extractFilename(char *filename) {
    const char *lastSlash = strrchr(filename, '/');
    if (lastSlash != NULL) {
        strcpy(filename, lastSlash + 1); 
    } else {
        strcpy(filename, cwd); 
    }
}

void extractRemainingCharacters(const char *inputString, int n, char *outputString) {
    strncpy(outputString, inputString + n, strlen(inputString) - n);
    outputString[strlen(inputString) - n] = '\0';
}

void createSnapshot(const char *directory, DirectorySnapshot* snapshot) {
    DIR *dir = opendir(directory);
    bool flag;
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, "LOG_FILE_CLIENT.txt") != 0) {
            flag = false;
            char path[512];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            struct stat fileStat;
            if (stat(path, &fileStat) < 0) {
                printf("stat %s", path);
                exit(EXIT_FAILURE);
            }

            if (S_ISDIR(fileStat.st_mode)) {
                flag = true;
            }

            snapshot->entries = realloc(snapshot->entries, (snapshot->count + 1) * sizeof(FileEntry));
            FileEntry *fileEntry = &(snapshot->entries[snapshot->count]);
            strcpy(fileEntry->name, path);
            fileEntry->modified_time = fileStat.st_mtime;
            fileEntry->isFile = flag;

            snapshot->count++;

            if (flag) createSnapshot(path, snapshot);
        }
    }

    closedir(dir);
}

void writeLog(const char* path, const char* messageLog){
    char toWrite[1026];
    time_t currentTime;
    time(&currentTime);
    char* timeString = ctime(&currentTime);
    snprintf(toWrite, sizeof(toWrite), "%s   -> File %s %s.\n", timeString, path, messageLog);
    write(logFile, toWrite, strlen(toWrite));
}

void compareSnapshots() {
    Changed changedFile;
    int found, q;
    bool newlyArrived = false;
    for (int i = 0; i < newSnapshot.count; i++) {
        newlyArrived = false;
        char path[PATH_MAX+256];
        for (q = 0; q < currentFile; ++q){
            snprintf(path, sizeof(path), "%s/%s", cwd, detailedNames[q]);
            if (strcmp(path, newSnapshot.entries[i].name) == 0) {
                newlyArrived = true;
                pthread_mutex_lock(&socketMutex);
                int z;
                for (z = 0; z < currentFile-1; ++z){
                    strcpy(detailedNames[q], detailedNames[q+1]);
                }
                currentFile--;
                pthread_mutex_unlock(&socketMutex);

            }
        }
        if (newlyArrived){
            writeLog(path, "has arrived");
            continue;
        }

        found = 0;
        for (int j = 0; j < oldSnapshot.count; j++) {
            if (strcmp(newSnapshot.entries[i].name, oldSnapshot.entries[j].name) == 0) {
                found = 1;
                if (newSnapshot.entries[i].modified_time != oldSnapshot.entries[j].modified_time) {
                    //printf("File modified: %s\n", newSnapshot.entries[i].name);
                    writeLog(newSnapshot.entries[i].name, "has been modified");
                    if (newSnapshot.entries[i].isFile) continue;
                    else changedFile.mode = 0;
                    strcpy(changedFile.name, newSnapshot.entries[i].name);

                    changed[changedCount++] = changedFile;
                    pthread_cond_signal(&fileCond);
                }
                break;
            }
        }
        if (found == 0) {
            //printf("New file/subdirectory added: %s\n", newSnapshot.entries[i].name);
            writeLog(newSnapshot.entries[i].name, "has been added");
            if (newSnapshot.entries[i].isFile) changedFile.mode = 3;
            else changedFile.mode = 1;
            strcpy(changedFile.name, newSnapshot.entries[i].name);

            changed[changedCount++] = changedFile;
            pthread_cond_signal(&fileCond);
        }
    }

    for (int i = 0; i < oldSnapshot.count; i++) {
        newlyArrived = false;
        char path[PATH_MAX+256];
        for (q = 0; q < currentFile; ++q){
            snprintf(path, sizeof(path), "%s/%s", cwd, detailedNames[q]);
            if (strcmp(path, newSnapshot.entries[i].name) == 0) {
                newlyArrived = true;
                pthread_mutex_lock(&socketMutex);
                int z;
                for (z = 0; z < currentFile-1; ++z){
                    strcpy(detailedNames[q], detailedNames[q+1]);
                }
                currentFile--;
                pthread_mutex_unlock(&socketMutex);

            }
        }
        if (newlyArrived) continue;

        found = 0;
        for (int j = 0; j < newSnapshot.count; j++) {
            if (strcmp(oldSnapshot.entries[i].name, newSnapshot.entries[j].name) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            //printf("File/subdirectory deleted: %s\n", oldSnapshot.entries[i].name);
            writeLog(oldSnapshot.entries[i].name, "has been deleted");
            changedFile.mode = 2;
            strcpy(changedFile.name, oldSnapshot.entries[i].name);

            changed[changedCount++] = changedFile;
            pthread_cond_signal(&fileCond);
        }
    }
}

void freeSnapshot() {
    free(oldSnapshot.entries);
}

void* checker(void* args){
    int flag = 0;
    while (1) {
        if (!flag){createSnapshot(cwd, &oldSnapshot); flag = 1;}

        sleep(3);

        newSnapshot.entries = NULL;
        newSnapshot.count = 0;

        createSnapshot(cwd, &newSnapshot);

        pthread_mutex_lock(&fileTask);
        compareSnapshots();
        pthread_mutex_unlock(&fileTask);
        pthread_cond_signal(&fileCond);

        freeSnapshot();

        oldSnapshot = newSnapshot;
    }
}

void sendFile(Changed curr){
    char block[BLOCK_SIZE];
    size_t bytesRead;
    //printf("%s - %d\n", curr.name, curr.mode);
    type = 0;
    if (send(clientSocket, &curr.mode, sizeof(curr.mode), 0) == -1) {
        perror("send");
        exit(1);
    }
    char outputName[strlen(curr.name) - strlen(cwd) + 1];
    extractRemainingCharacters(curr.name, strlen(cwd)+1, outputName);
    strcpy(curr.name, outputName);
    //printf("-->%s<--\n", outputName);
    type = 1;
    if (send(clientSocket, curr.name, 100, 0) == -1) {
        perror("Send failed");
        return;
    }
    if (curr.mode != 2 && curr.mode != 3){
        int file = open(curr.name, O_RDONLY);
        if (file == -1) {
            perror("open");
            exit(1);
        }
        type = 2;
        while ((bytesRead = read(file, block, sizeof(block))) > 0) {
            block[bytesRead] = '\0';
            if (send(clientSocket, block, sizeof(block), 0) == -1) {
                perror("send");
                exit(1);
            }
        }

        close(file);
    }
    
    char ender[] = "-END-";
    if (send(clientSocket, ender, sizeof(block), 0) == -1) {
        perror("send");
        exit(1);
    }
    type = 0;

    
    //printf("%s has been sent.\n", curr.name);
}

void* sender(void* args){
    while (!interrupted) {
        pthread_mutex_lock(&fileTask);
        while (changedCount == 0 ) {
            pthread_cond_wait(&fileCond, &fileTask);
        }
        Changed curr = changed[0];
        int i;
        for (i = 0; i < changedCount - 1; i++) {
            changed[i] = changed[i + 1];
        }
        changedCount--;

        pthread_mutex_unlock(&fileTask);

        sendFile(curr);
    }

    int number = -1;
    if (send(clientSocket, &number, sizeof(number), 0) == -1) {
        perror("send");
        exit(1);
    }
}

void* receiver(void* args){
    int number;
    char filename[100];

    while(1){
        // Receive the number
        //printf("Receiving number\n");
        if (recv(clientSocket, &number, sizeof(number), 0) == -1) {
            perror("recv num");
            exit(1);
        }
        if (number == -1) handler(0);
        // Receive the filename
        //printf("%d Receiving filename\n", number);
        if (recv(clientSocket, filename, sizeof(filename), 0) == -1) {
            perror("recv file");
            exit(1);
        }
        // Receive the content in blocks
        char block[BLOCK_SIZE];
        bool flag = false, removed = false;
        if (number == 2){
            pthread_mutex_lock(&socketMutex);
            strcpy(detailedNames[currentFile++], filename);
            pthread_mutex_unlock(&socketMutex);

            remove(filename);
            char ender[BLOCK_SIZE];
            if (recv(clientSocket, ender, sizeof(block), 0) == -1) {
                perror("send");
                exit(1);
            }
            //printf("deleted: %s\n", ender);
            //--------------------WHAT IF OTHER CLIENT IS MODIFYING THIS FILE
        }
        else if (number == 3){
            //printf("Creating directory %s\n", filename);
            mkdir(filename, 0777);
            char ender[BLOCK_SIZE];
            if (recv(clientSocket, ender, sizeof(block), 0) == -1) {
                perror("send");
                exit(1);
            }
            //printf("directory created: %s\n", ender);
        }
        else if (number != -1){
            int destfd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0777); 
            //printf("Receiving file %s\n", filename);
            pthread_mutex_lock(&socketMutex);
            strcpy(detailedNames[currentFile++], filename);
            pthread_mutex_unlock(&socketMutex); 
            while (1) {
                int bytes = recv(clientSocket, block, sizeof(block), 0);
                if (bytes == -1) {
                    perror("recv block");
                    exit(1);
                }
                if (strcmp(block, "-END-") == 0) break; // All blocks received
                flag = true;
                write(destfd, block, strlen(block));
            }

            close(destfd);
        }

        // if (flag){
        //     printf("Received number: %d\n", number);
        //     printf("Received filename: %s\n", filename);
        // }
    }
}



int main(int argc, char *argv[]) {
    char* ip;
    int port;
    if (argc != 4 && argc != 3){
        printf("Invalid arguments.\n");
        return -1;
    }
    strcpy(cwd, argv[1]);
    port = atoi(argv[2]);
    if (argc == 3) {
        ip = "127.0.0.1";
    } else {
        ip = argv[3];
    }

    struct sigaction saINT, saTERM, saQUIT;
    memset(&saINT, 0, sizeof(saINT));
    saINT.sa_handler = &handler;
    saINT.sa_flags = SA_RESTART;
    sigaction(SIGINT, &saINT, NULL);

    oldSnapshot.entries = NULL;
    oldSnapshot.count = 0;
    
    char logName[PATH_MAX+100];
    snprintf(logName, sizeof(logName), "%s/%s", cwd, "LOG_FILE_CLIENT.txt");
    logFile = open(logName, O_WRONLY | O_TRUNC | O_CREAT, 0777); 

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port); // Port number of the server
    if (inet_pton(AF_INET, ip, &(serverAddress.sin_addr)) <= 0) {
        perror("Invalid IP address");
        return 1;
    }
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server.\n");

    int number;
    char block[BLOCK_SIZE];
    while (1){
        recv(clientSocket, &number, sizeof(number), 0);
        if (number == 0){
            recv(clientSocket, block, sizeof(block), 0);
            mkdir(block, 0777);
            //printf("directory->%d-%s\n", number, block);
        }
        else if (number == 1){
            recv(clientSocket, block, sizeof(block), 0);
            //printf("file->%d-%s\n", number, block);
            int destfd = open(block, O_WRONLY | O_TRUNC | O_CREAT, 0777);
            while (1) {
                int bytes = recv(clientSocket, block, sizeof(block), 0);
                if (bytes == -1) {
                    perror("recv block");
                    exit(1);
                }
                if (strcmp(block, "-END-") == 0) break;
                write(destfd, block, strlen(block));
            }
            close(destfd);
        }
        else if (number == -1){
            break;
        }
    }

    pthread_t checkerThread, senderThread, receiverThread;
    pthread_mutex_init(&fileTask, NULL);
    pthread_mutex_init(&socketMutex, NULL);
    pthread_mutex_init(&socketMutexR, NULL);
    pthread_cond_init(&fileCond, NULL);

    //CREATION OF THREADS
    if (pthread_create(&checkerThread, NULL, &checker, NULL)){
        perror("Thread create error.");
        return -1;
    }
    if (pthread_create(&senderThread, NULL, &sender, NULL)){
        perror("Thread create error.");
        return -1;
    }
    if (pthread_create(&receiverThread, NULL, &receiver, NULL)){
        perror("Thread create error.");
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////////////
    if (pthread_join(checkerThread, NULL) != 0) {
        perror("Failed to join the thread");
    }
    if (pthread_join(senderThread, NULL) != 0) {
        perror("Failed to join the thread");
    }
    if (pthread_join(receiverThread, NULL) != 0) {
        perror("Failed to join the thread");
    }

    pthread_mutex_destroy(&fileTask);
    pthread_mutex_destroy(&socketMutex);
    pthread_mutex_destroy(&socketMutexR);
    pthread_cond_destroy(&fileCond);
    
    close(clientSocket);

    return 0;
}
