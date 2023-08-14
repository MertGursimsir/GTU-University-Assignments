#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<errno.h>
#include <sys/mman.h>
#include<time.h>
#include<string.h>
#include<semaphore.h>
#include<ctype.h>
#include "header.h"

#define BUFFER_SIZE 1024
#define BUFFER_SIZE_INCREMENT 1024
#define INPUT_SIZE 512
#define REQUEST_SIZE 5120
#define TASK_QUEUE_SIZE 512
#define PATH_MAX 4096

typedef struct Task {
    char command[REQUEST_SIZE];
    pid_t pid;
    char currentDirectory[PATH_MAX];
} Task;

struct stringKeeper{
    int size;
    char *string;
};
struct stringKeeper bufferTemp;

char* buffer = NULL;
char* new_buffer = NULL;

char fifodir[256];
int logFile;
pthread_t *th;
int POOL;

Task taskQueue[TASK_QUEUE_SIZE];
int taskCount = 0;

pthread_mutex_t mutexQueue;
pthread_cond_t condQueue;
sem_t sem;
sem_t semF;

int clientNum;
char directory[256];

pid_t childPIDs[BUFFER_SIZE];
int pid_pos = 0;

struct stringKeeper readF(char* word, char* argv1, int i, int lineNo){
    char filename[256] = "/tmp/";
    strcat(filename, argv1);
    strcat(filename, "/");
    strcat(filename, word);
    bufferTemp.string = NULL;
    int fd = open(filename, O_RDONLY);
    if (fd == -1){
        if (errno == ENOENT){
            bufferTemp.string = malloc(BUFFER_SIZE);
            strcpy(bufferTemp.string, "This file does not exist.");
            bufferTemp.size = 25;
            return bufferTemp;
        }
        printf("File error. Unsuccessful...\n");
        return bufferTemp;
    }
    buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL){
        printf("Allocating memory error. Unsuccessful...\n");
        if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
        return bufferTemp;
    }
    int buffer_pos = 0, buffer_size = BUFFER_SIZE;
    if (i == 3){
        int line_num = lineNo;
        int current_line = 1;
        
        if (line_num <= 0) printf("There is no such line.\n");
        else{
            for(;;){
                if (buffer_pos == buffer_size){
                    new_buffer = realloc(buffer, buffer_size + BUFFER_SIZE_INCREMENT);
                    if (new_buffer == NULL){
                        printf("Allocating memory error. Unsuccessful...\n");
                        free(buffer);
                        if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                        return bufferTemp;
                    }
                    buffer = new_buffer;
                    buffer_size += BUFFER_SIZE_INCREMENT;
                }
                size_t readData = read(fd, &buffer[buffer_pos], 1);
                if (readData == 0){
                    if (current_line != line_num){
                        strcpy(buffer, "There is no such line.");
                        buffer_pos = 22;
                    }
                    break;
                }
                else if (readData == -1){
                    printf("Reading file error. Unsuccessful...\n");
                    free(buffer);
                    if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                    return bufferTemp;
                }
                if (current_line == line_num){
                    if (buffer[buffer_pos] == '\n') break;
                    buffer_pos++;
                }
                else if (buffer[buffer_pos] == '\n') current_line++;
            }
            if (buffer_pos == buffer_size){
                printf("Line too long. Unsuccessful...\n");
                free(buffer);
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                return bufferTemp;
            }
            else{
                buffer[buffer_pos] = '\0';
            }
        }
    }
    else{
        for(;;){
            if (buffer_pos == buffer_size){
                new_buffer = realloc(buffer, buffer_size + BUFFER_SIZE_INCREMENT);
                if (new_buffer == NULL){
                    printf("Allocating memory error. Unsuccessful...\n");
                    free(buffer);
                    if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                    return bufferTemp;
                }
                buffer = new_buffer;
                buffer_size += BUFFER_SIZE_INCREMENT;
            }
            size_t readData = read(fd, &buffer[buffer_pos++], 1);
            if (readData == 0) break;
            else if (readData == -1){
                printf("Reading file error. Unsuccessful...\n");
                free(buffer);
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                return bufferTemp;
            }
        }
        buffer[buffer_pos] = '\0';
    }
    if (close(fd) == -1){
        printf("Closing file error. Unsuccessful...\n");
        return bufferTemp;
    }
    bufferTemp.string = buffer;
    bufferTemp.size = buffer_pos;
    return bufferTemp;
}

char* writeT(char** words, int i, char* argv1){
    int bytesRead;
    int currentLine = 1;
    int lineNumber = atoi(words[2]);
    char toWrite[INPUT_SIZE] = "";
    char c;
    int readLetter = 0;
    int lineFlag = 1;
    int j;
    char filename[256] = "/tmp/";
    strcat(filename, argv1);
    strcat(filename, "/");
    strcat(filename, words[1]);

    for (j = 0; j < strlen(words[2]); ++j) if (!isdigit(words[2][j])) lineFlag = 0;

    if (!lineFlag){
        if (access(filename, F_OK) != -1) strcat(toWrite, "\n");
        int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT);
        if (fd == -1){
            printf("File error. Unsuccessful...\n");
            if (close(fd) == -1);
            return "ERROR";
        }
        for (j = 2; j < i; ++j){
            strcat(toWrite, words[j]);
            strcat(toWrite, " ");
        }
        if (write(fd, toWrite, strlen(toWrite)) == -1){
            perror("Writing error.");
            if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
            return "ERROR";
        }
    }
    else{
        for (j = 3; j < i; ++j){
            strcat(toWrite, words[j]);
            strcat(toWrite, " ");
        }
        if (access(filename, F_OK) == -1){
            int fd = open(filename, O_WRONLY | O_CREAT);
            if (write(fd, toWrite, strlen(toWrite)) == -1){
                perror("Writing error.");
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                return "ERROR";
            }
        }
        else{
            int fd = open(filename, O_WRONLY);
            int fileDescriptor = open(filename, O_RDONLY);
            if (fd == -1 || fileDescriptor == -1){
                printf("File error. Unsuccessful...\n");
                if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                return "ERROR";
            }

            if (lineNumber != 1){
                while (1) {
                    bytesRead = read(fileDescriptor, &c, 1);
                    readLetter++;
                    if (bytesRead < 0) {
                        printf("Error reading the file.\n");
                        if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                        if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                        return "ERROR";
                    }
                    if (bytesRead == 0) {
                        if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                        if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                        return "Line number exceeds the file length.";
                    }
                    else if (c == '\n') {
                        currentLine++;
                        if (currentLine == lineNumber) break;
                    }
                }
            }
                    
            lseek(fd, readLetter, SEEK_CUR);

            int buffer_pos = 0, buffer_size = BUFFER_SIZE;
            int readChar = 0;
            int flag = 1;
            buffer = malloc(BUFFER_SIZE);
            if (buffer == NULL){
                printf("Allocating memory error. Unsuccessful...\n");
                if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                return "ERROR";
            }
            for(;;){
                if (buffer_pos == buffer_size){
                    new_buffer = realloc(buffer, buffer_size + BUFFER_SIZE_INCREMENT);
                    if (new_buffer == NULL){
                        printf("Allocating memory error. Unsuccessful...\n");
                        free(buffer);
                        if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                        if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                        return "ERROR";
                    }
                    buffer = new_buffer;
                    buffer_size += BUFFER_SIZE_INCREMENT;
                }
                size_t readData = read(fileDescriptor, &buffer[buffer_pos], 1);
                if (readData == 0) break;
                else if (readData == -1){
                    printf("Reading file error. Unsuccessful...\n");
                    free(buffer);
                    if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                    if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                    return "ERROR";
                }
                if (!flag) buffer_pos++;
                if (flag && buffer[buffer_pos] == '\n'){
                    flag = 0;
                }
                readChar++;
            }
            strcat(toWrite, "\n");       
            if (write(fd, toWrite, strlen(toWrite)) == 1){
                perror("Writing error.");
                if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                free(buffer);
                return "ERROR";
            }
            if (write(fd, buffer, readChar) == 1){
                perror("Writing error.");
                if (close(fileDescriptor) == -1) printf("Closing file error. Unsuccessful...\n");
                if (close(fd) == -1) printf("Closing file error. Unsuccessful...\n");
                free(buffer);
                return "ERROR";
            }

            int fd1, fd2;
            fd1 = close(fileDescriptor); fd2 = close(fd);
            if (fd1 == -1 || fd2 == -1){printf("Closing file error. Unsuccessful...\n"); free(buffer); return "ERROR";}

            free(buffer);
        }
    }
    
    return "SUCCESS";
}

char* upload(char* filename, char* cwd, char* argv1, int upload){
    char serverFile[256], clientFile[256];
    if (upload){
        strcpy(serverFile, "/tmp/");
        strcat(serverFile, argv1);
        strcat(serverFile, "/");
        strcat(serverFile, filename);
        
        strcpy(clientFile, "");
        strcat(clientFile, cwd);
        strcat(clientFile, "/");
        strcat(clientFile, filename);
    }
    else{
        strcpy(clientFile, "/tmp/");
        strcat(clientFile, argv1);
        strcat(clientFile, "/");
        strcat(clientFile, filename);
        
        strcpy(serverFile, "");
        strcat(serverFile, cwd);
        strcat(serverFile, "/");
        strcat(serverFile, filename);
    }

    if (access(clientFile, F_OK) == -1){
        if (upload) return "File does not exist on client side.";
        else return "File does not exist on server side.";
    }
    if (access(serverFile, F_OK) != -1){
        if (upload) return "File does exist on server side.";
        else return "File does exist on client side.";
    }

    char* buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL){
        printf("Allocating memory error. Unsuccessful...\n");
        return "ERROR";
    }
    int fdClient = open(clientFile, O_RDONLY, 0666);
    int buffer_pos = 0, buffer_size = BUFFER_SIZE;
    for(;;){
        if (buffer_pos == buffer_size){
            char* new_buffer = realloc(buffer, buffer_size + BUFFER_SIZE_INCREMENT);
            if (new_buffer == NULL){
                printf("Allocating memory error. Unsuccessful...\n");
                free(buffer);
                if (close(fdClient) == -1) printf("Closing file error. Unsuccessful...\n");
                return "ERROR";
            }
            buffer = new_buffer;
            buffer_size += BUFFER_SIZE_INCREMENT;
        }
        size_t readData = read(fdClient, &buffer[buffer_pos++], 1);
        if (readData == 0) break;
        else if (readData == -1){
            printf("Reading file error. Unsuccessful...\n");
            free(buffer);
            if (close(fdClient) == -1) printf("Closing file error. Unsuccessful...\n");
            return "ERROR";
        }
    }
    buffer[buffer_pos] = '\0';
    if (close(fdClient) == -1){ printf("Closing file error. Unsuccessful...\n"); return "ERROR";}

    int fdServer = open(serverFile, O_WRONLY | O_APPEND | O_CREAT, 0666);
    if (fdServer == -1){
        printf("File error. Unsuccessful...\n");
        if (close(fdServer) == -1) printf("Closing file error. Unsuccessful...\n");
        return "ERROR";
    }
    if (write(fdServer, buffer, buffer_pos) == -1){
        perror("Writing error.");
        if (close(fdServer) == -1) printf("Closing file error. Unsuccessful...\n");
        return "ERROR";
    }
    
    free(buffer);
    if (close(fdServer) == -1) printf("Closing file error. Unsuccessful...\n");
    return "SUCCESS";
}

void executeTask(Task* task) {
    char clientFifo[CLIENT_FIFO_NAME_LEN];
    char *clientResFifo;
    struct response res;
    int clientResFD;
    char pidC[20];
    int currentClient;

    sprintf(pidC, "%d", task->pid);
    snprintf(clientFifo, CLIENT_FIFO_NAME_LEN, CLIENT_FIFO_TEMPLATE, (long)task->pid);
    clientResFifo = strcat(clientFifo, "_res");

    char *words[100];
    int i = 0;
    char *token = strtok(task->command, " ");
    while (token != NULL) {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    int sem_control;
    sem_getvalue(&sem, &sem_control);


    clientResFD = open(clientResFifo, O_WRONLY);
    if (clientResFD == -1){
        perror("FIFO opening error. Exiting...");
        return;
    }
    
    if (strcmp(words[0], "Connect") == 0){
        if (sem_control <= 0){ printf("Connection request PID %d... Que FULL\n", task->pid);}
        childPIDs[pid_pos++] = task->pid;
        currentClient = ++clientNum;
        sem_wait(&sem);
        strcpy(res.seq, "Connection established\n");
        write(logFile, pidC, sizeof(pidC));
        write(logFile, " connected.\n", 12);
        printf("Client PID %d connected as \"client%d\"\n", task->pid, currentClient);
    }
    else if (strcmp(words[0], "tryConnect") == 0){
        if (sem_control <= 0) strcpy(res.seq, "X");
        else{
            childPIDs[pid_pos++] = task->pid;
            currentClient = ++clientNum;
            sem_wait(&sem);
            strcpy(res.seq, "Connection established\n");
            write(logFile, pidC, sizeof(pidC));
            write(logFile, " connected.\n", 12);
            printf("Client PID %d connected as \"client%d\"\n", task->pid, currentClient);
        }
    }
    else if (strcmp(words[0], "help") == 0 && i == 1) strcpy(res.seq, "\n\tAvailable commands are:\n\nhelp, list, readF, writeT, upload, download, quit, killServer\n\n");
    else if (strcmp(words[0], "help") == 0 && i == 2){
        if (strcmp("help", words[1]) == 0) strcpy(res.seq, "\n\thelp <command>\n\t\tdisplay the list of possible client requests (command is optional)\n\n");
        else if (strcmp("list", words[1]) == 0) strcpy(res.seq, "\n\tlist\n\t\tsends a request to display the list of files in Servers directory\n\t\t(also displays the list received from the Server)\n\n");
        else if (strcmp("readF", words[1]) == 0) strcpy(res.seq, "\n\treadF <file> <line #>\n\t\trequests to display the # line of the <file>, if no line number is given\n\t\tthe whole contents of the file is requested (and displayed on the client side)\n\n");
        else if (strcmp("writeT", words[1]) == 0) strcpy(res.seq, "\n\twriteT <file> <line #> <string>\n\t\trequest to write the content of “string” to the #th line the <file>, if the line # is not given\n\t\twrites to the end of file. If the file does not exists in Servers directory creates and edits the\n\t\tfile at the same time\n\n");
        else if (strcmp("upload", words[1]) == 0) strcpy(res.seq, "\n\tupload <file>\n\t\tuploads the file from the current working directory of client to the Servers directory\n\t\t(beware of the cases no file in clients current working directory and file with the same\n\t\tname on Servers side)\n\n");
        else if (strcmp("download", words[1]) == 0) strcpy(res.seq, "\n\tdownload <file>\n\t\trequest to receive <file> from Servers directory to client side\n\n");
        else if (strcmp("quit", words[1]) == 0) strcpy(res.seq, "\n\tquit\n\t\tSend write request to Server side log file and quits\n\n");
        else if (strcmp("killServer", words[1]) == 0) strcpy(res.seq, "\n\tkillServer\n\t\tSends a kill request to the Server\n\n");
        else strcpy(res.seq, "\n\tThere is no such command.\n\n");
    }
    else if (strcmp("readF", words[0]) == 0 && (i == 3 || i == 2)){
        sem_wait(&semF);
        struct stringKeeper result;
        if (i == 2) result = readF(words[1], directory, i, 0);
        else result = readF(words[1], directory, i, atoi(words[2]));
        if (result.string != NULL){
            if (result.size < RESPONSE_SIZE) strcpy(res.seq, result.string);
            else strcpy(res.seq, "-Text is too big to transfer.-");
            free(result.string);
        }
        else{
            strcpy(res.seq, "ERROR\n");
        }
        sem_post(&semF);
    }
    else if (strcmp("writeT", words[0]) == 0 && i >= 3){
        sem_wait(&semF);
        strcpy(res.seq, writeT(words, i, directory));
        sem_post(&semF);
    }
    else if (strcmp("upload", words[0]) == 0 && i == 2){
        sem_wait(&semF);
        strcpy(res.seq, upload(words[1], task->currentDirectory, directory, 1));
        sem_post(&semF);
    }
    else if (strcmp("download", words[0]) == 0 && i == 2){
        sem_wait(&semF);
        strcpy(res.seq, upload(words[1], task->currentDirectory, directory, 0));
        sem_post(&semF);
    }
    else if (strcmp("list", words[0]) == 0 && i == 1){
        sem_wait(&semF);
        char ls[BUFFER_SIZE];
        int ls_pos = 0;
        char command[128] = "ls -a > _mert_ls_server.txt /tmp/";
        strcat(command, directory);
        system(command);
        int lsfd = open("_mert_ls_server.txt", O_RDONLY);
        if (lsfd == -1) strcpy(res.seq, "Error during reading list of files.");
        else{
            while(read(lsfd, &ls[ls_pos++], 1) > 0);
            ls[ls_pos-1] = '\0';
            if(close(lsfd) == -1) strcpy(res.seq, "Error during reading list of files.");
            else strcpy(res.seq, ls);
        }
        if (remove("_mert_ls_server.txt") != 0) perror("Couldn't remove file used for ls command.");
        sem_post(&semF);
    }
    else if (strcmp(task->command, "quit") == 0 && i == 1){
        printf("client %d disconnected...\n", task->pid);
        strcpy(res.seq, "bye");

        write(logFile, pidC, sizeof(pidC));
        write(logFile, " disconnected.\n", 15);

        sem_post(&sem);
    }
    else if (strcmp(task->command, "killServer") == 0 && i == 1){
        strcpy(res.seq, "");
        kill(getpid(), SIGINT);
    }
    else{
        strcpy(res.seq, "There is no such command. Try again.");
    }

    if (write(clientResFD, &res, sizeof(struct response)) == -1){
        perror("FIFO response writing error.");
    }
    if (close(clientResFD) == -1) perror("Closing Client FIFO error.");

    
    
}

void submitTask(Task task) {
    pthread_mutex_lock(&mutexQueue);
    taskQueue[taskCount++] = task;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&condQueue);
}

void* startThread(void* args) {
    while (1) {
        Task task;

        pthread_mutex_lock(&mutexQueue);
        while (taskCount == 0) {
            pthread_cond_wait(&condQueue, &mutexQueue);
        }

        task = taskQueue[0];
        int i;
        for (i = 0; i < taskCount - 1; i++) {
            taskQueue[i] = taskQueue[i + 1];
        }
        taskCount--;
        pthread_mutex_unlock(&mutexQueue);

        executeTask(&task);
    }
}

void sigint_handler(int signum) {
    printf("I got killed. Exiting...\n");
    int i;
    int fd;
    char pid[50];
    
    pthread_mutex_destroy(&mutexQueue);
    free(th);

    
    for (i = 0; i < pid_pos; ++i){
        kill(childPIDs[i], SIGKILL);
        sprintf(pid, "%d", childPIDs[i]);
        write(logFile, pid, sizeof(pid_t));
        write(logFile, " is killed.\n", 12);
        sprintf(pid, "/tmp/%d_res", childPIDs[i]);
        unlink(pid);
    }
    for (fd = 0; fd < getdtablesize(); fd++) {
        close(fd);
    }
    if (buffer!=NULL) free(buffer);
    if (new_buffer!=NULL) free(new_buffer);
    if (bufferTemp.string!=NULL) free(bufferTemp.string);

    sem_destroy(&sem);
    sem_destroy(&semF);
    unlink(fifodir);

    exit(signum);
}

int main(int argc, char* argv[]) {
    if (argc != 4){
        perror("Bad arguments. Exiting...");
        return -1;
    }

    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting SIGINT handler");
        return 1;
    }

    int maxClients = atoi(argv[2]);
    int poolSize = atoi(argv[3]); 
    POOL = poolSize;
    int pid = getpid();

    char pidStr[256], dir[256] = "/tmp/";
    strcpy(fifodir, "/tmp/");
    sprintf(pidStr, "%d", pid);

    if (mkdir(strcat(dir, argv[1]), S_IRWXU | S_IRWXG | S_IRWXO) == -1){
        if (errno != EEXIST){
            perror("Error during directory creation. Exiting...");
            return -1;
        }
    }
    strcpy(directory, argv[1]);

    if (maxClients <= 0){
        printf("No client to serve. Exiting...\n");
        return 0;
    }
    
    logFile = open(strcat(strcat(strcat(dir, "/"), "LOG"), ".txt"), O_WRONLY | O_APPEND | O_CREAT, 0666);
    if (logFile == -1){
        perror("Log file error. Exiting...");
        return -1;
    }

    umask(0);
    if (mkfifo(strcat(fifodir, pidStr), 0777) == -1){
        if (errno!=EEXIST){
            printf("Could not create FIFO file. Exiting...\n");
            return -1;
        }
    }

    printf("Server Started PID %d...\nwaiting for clients...\n", pid);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    th = (pthread_t*)calloc(poolSize, sizeof(pthread_t));
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    sem_init(&sem, 0, maxClients);
    sem_init(&semF, 0, 1);
    clientNum = 0;

    pthread_mutex_init(&mutexQueue, NULL);
    pthread_cond_init(&condQueue, NULL);

    int i;
    for (i = 0; i < POOL; i++) {
        if (pthread_create(&th[i], &attr, &startThread, NULL) != 0) {
            perror("Failed to create the thread");
        }
    }
    pthread_attr_destroy(&attr);
    
    int serverFD;
    struct request req;

    while(1) {
        serverFD = open(fifodir, O_RDONLY);
        if (serverFD == -1){
            perror("FIFO opening error. Exiting...");
            return -1;
        }
        if (read(serverFD, &req, sizeof(struct request)) == -1){
            perror("Error reading request; discarding...");
            continue;
        }
        if (close(serverFD) == -1) perror("Closing Server FIFO error.");
        
        Task t;
        strcpy(t.command, req.seq);
        strcpy(t.currentDirectory, req.currentDirectory);
        t.pid = req.pid;
        submitTask(t);
    }
    
    return 0;
}