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

#define THREAD_NUM 5
#define BUFFER_SIZE 1024
#define BLOCK_SIZE 2048

pthread_t* th;
char cwd[PATH_MAX];
int serverSocket;
typedef struct {
    int socket;
    struct sockaddr_in address;
} ClientInfo;

ClientInfo* clientQueue[256];
int clientCount = 0;
int clientSize = 256;
int currentFile = 0;
int taken = 0;
int type;

bool toSend = false;

pthread_mutex_t mutexQueue;
pthread_mutex_t fileTask;
pthread_mutex_t socketMutex;
pthread_mutex_t socketMutexR;
pthread_cond_t condQueue;
pthread_cond_t fullCondQueue;
pthread_cond_t fileCond;


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
    int mode; //0 modified, 1 created, 2 deleted, 3 folder
} Changed;

Changed changed[256];
int changedCount = 0;

DirectorySnapshot oldSnapshot, newSnapshot;
int interrupt = 0;

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

void executeTask(ClientInfo* client) {
    int clientSocket = client->socket;
    struct sockaddr_in clientAddress = client->address;

    int number;
    char filename[100];
    
    //printf("Caring with: %s:%d\n", inet_ntoa((client->address).sin_addr), ntohs((client->address).sin_port));

    while(1){
        //printf("Receiving number...\n");
        if (recv(clientSocket, &number, sizeof(number), 0) == -1) {
            perror("recv num");
            exit(1);
        }
        if (number == -1){
            pthread_mutex_lock(&mutexQueue);
            int i;
            for (i = 0; i < clientCount; ++i){
                if (clientQueue[i]->socket == clientSocket){
                    int j;
                    for (j = 0; j < clientCount-1; ++j){
                        clientQueue[j] = clientQueue[j+1];
                    }
                }
            }
            clientCount--; taken--;
            pthread_mutex_unlock(&mutexQueue);
            printf("Client %s:%d exited.\n", inet_ntoa((client->address).sin_addr), ntohs((client->address).sin_port));
            close(clientSocket);
            break; 
        }
        //printf("Receiving filename...\n");
        if (recv(clientSocket, filename, sizeof(filename), 0) == -1) {
            perror("recv file");
            exit(1);
        }
        if (strcmp(filename, "-FINISH-") == 0){
            pthread_mutex_lock(&mutexQueue);
            int i;
            for (i = 0; i < clientCount; ++i){
                if (clientQueue[i]->socket == clientSocket){
                    int j;
                    for (j = 0; j < clientCount-1; ++j){
                        clientQueue[j] = clientQueue[j+1];
                    }
                }
            }
            clientCount--; taken--;
            pthread_mutex_unlock(&mutexQueue);
            printf("Client %s:%d exited.\n", inet_ntoa((client->address).sin_addr), ntohs((client->address).sin_port));
            close(clientSocket);
            break; 
        }
        char block[BLOCK_SIZE];
        bool flag = false, removed = false;
        
        if (number == 2){
            remove(filename);
            char ender[BLOCK_SIZE];
            if (recv(clientSocket, ender, sizeof(block), 0) == -1) {
                perror("send");
                exit(1);
            }
            //printf("deleted: %s\n", ender);
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
            //printf("Receiving file...\n");
            while (1) {
                int bytes = recv(clientSocket, block, sizeof(block), 0);
                if (bytes == -1) {
                    perror("recv block");
                    exit(1);
                }
                if (strcmp(block, "-END-") == 0) break;
                if (strcmp(block, "-FINISH-") == 0){
                    pthread_mutex_lock(&mutexQueue);
                    int i;
                    for (i = 0; i < clientCount; ++i){
                        if (clientQueue[i]->socket == clientSocket){
                            int j;
                            for (j = 0; j < clientCount-1; ++j){
                                clientQueue[j] = clientQueue[j+1];
                            }
                        }
                    }
                    clientCount--; taken--;
                    pthread_mutex_unlock(&mutexQueue);
                    printf("Client %s:%d exited.\n", inet_ntoa((client->address).sin_addr), ntohs((client->address).sin_port));

                    close(clientSocket);
                    close(destfd);
                    return; 
                }
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

void* startThread(void* args) {
    while (1) {
        pthread_mutex_lock(&mutexQueue);
        while (taken >= clientCount) {
            pthread_cond_wait(&condQueue, &mutexQueue);
        }
        
        ClientInfo* client = clientQueue[taken++];
        
        pthread_mutex_unlock(&mutexQueue);
        pthread_cond_signal(&fullCondQueue);
        
        executeTask(client);
        
    }
}

bool sendBeginning(int clientS, char* directory){
    bool isEmpty = true;
    DIR *dir = opendir(directory);
    size_t bytesRead;
    char block[BLOCK_SIZE];
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[512];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            char outputName[strlen(path) - strlen(cwd) + 1];
            
            extractRemainingCharacters(path, strlen(cwd)+1, outputName);
            strcpy(block, outputName);
            if (entry->d_type == DT_DIR){
                int number = 0;
                send(clientS, &number, sizeof(number), 0);
                send(clientS, block, sizeof(block), 0);
                sendBeginning(clientS, path);
            }
            else{
                int number = 1;
                send(clientS, &number, sizeof(number), 0);
                send(clientS, block, sizeof(block), 0);
                int file = open(path, O_RDONLY);
                while ((bytesRead = read(file, block, sizeof(block))) > 0) {
                    block[bytesRead] = '\0';
                    send(clientS, block, sizeof(block), 0);
                }
                char ender[] = "-END-";
                send(clientS, ender, sizeof(block), 0);
            }
            isEmpty = false;
        }
    }
    closedir(dir);
    return isEmpty;
}

void* listenerThread(void* args) {
    int serverSocket = *((int*)args);
    while (1){
        int clientSocket;
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);

        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLength);
        if (clientSocket == -1) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
        bool isEmpty = sendBeginning(clientSocket, cwd);
        if (!isEmpty){
            int number = -1;
            send(clientSocket, &number, sizeof(number), 0);
        }
        

        ClientInfo *clientInfo = (ClientInfo *)malloc(sizeof(ClientInfo));
        clientInfo->socket = clientSocket;
        clientInfo->address = clientAddress;

        pthread_mutex_lock(&mutexQueue);
        clientQueue[clientCount++] = clientInfo;
        pthread_mutex_unlock(&mutexQueue);
        pthread_cond_signal(&condQueue);
    }
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
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
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

void compareSnapshots() {
    Changed changedFile;
    int found, q;
    for (int i = 0; i < newSnapshot.count; i++) {
        found = 0;
        for (int j = 0; j < oldSnapshot.count; j++) {
            if (strcmp(newSnapshot.entries[i].name, oldSnapshot.entries[j].name) == 0) {
                found = 1;
                if (newSnapshot.entries[i].modified_time != oldSnapshot.entries[j].modified_time) {
                    //printf("File modified: %s\n", newSnapshot.entries[i].name);
                    if (newSnapshot.entries[i].isFile) continue;
                    else changedFile.mode = 0;
                    strcpy(changedFile.name, newSnapshot.entries[i].name);
                    changed[changedCount++] = changedFile;
                }
                break;
            }
        }
        if (found == 0) {
            //printf("New file/subdirectory added: %s\n", newSnapshot.entries[i].name);
            if (newSnapshot.entries[i].isFile) changedFile.mode = 3;
            else changedFile.mode = 1;
            strcpy(changedFile.name, newSnapshot.entries[i].name);

            changed[changedCount++] = changedFile;
        }
    }

    for (int i = 0; i < oldSnapshot.count; i++) {

        found = 0;
        for (int j = 0; j < newSnapshot.count; j++) {
            if (strcmp(oldSnapshot.entries[i].name, newSnapshot.entries[j].name) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            //printf("File/subdirectory deleted: %s\n", oldSnapshot.entries[i].name);
            changedFile.mode = 2;
            strcpy(changedFile.name, oldSnapshot.entries[i].name);

            changed[changedCount++] = changedFile;
        }
    }
}

void freeSnapshot() {
    free(oldSnapshot.entries);
}

void* changerThread(void* args) {
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
    //("FILE IS STARTED %d\n", clientCount);
    int i;
    char block[BLOCK_SIZE];
    size_t bytesRead;
    char outputName[strlen(curr.name) - strlen(cwd) + 1];
    extractRemainingCharacters(curr.name, strlen(cwd)+1, outputName);
    strcpy(curr.name, outputName);
    for (i = 0; i < clientCount; ++i){
        ClientInfo* client = clientQueue[i];
        int clientSocket = client->socket;
        struct sockaddr_in clientAddress = client->address;

        //printf("FILE IS SENDING TO: %s:%d\n%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port), clientSocket);
        
        if (send(clientSocket, &curr.mode, sizeof(curr.mode), 0) == -1) {
            // perror("send");
            // exit(1);
        }
        
        // Send the filename to the server
        if (send(clientSocket, curr.name, 100, 0) == -1) {
            // perror("Send failed");
            // exit(1);
        }

        if (curr.mode != 2 && curr.mode != 3){
            int file = open(curr.name, O_RDONLY);
            if (file == -1) {
                // perror("open");
                // exit(1);
            }

            while ((bytesRead = read(file, block, sizeof(block))) > 0) {
                block[bytesRead] = '\0';
                if (send(clientSocket, block, sizeof(block), 0) == -1) {
                    // perror("send");
                    // exit(1);
                }
            }

            close(file);
        }
        
        char ender[] = "-END-";
        if (send(clientSocket, ender, sizeof(block), 0) == -1) {
            // perror("send");
            // exit(1);
        }

        //printf("FILE IS SENT TO: %s:%d\n%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port), clientSocket);
        
    }
}

void* senderThread(void* args) {
    int serverSocket = *((int*)args);
    while (1) {
        //printf("TOSENT\n");
        pthread_mutex_lock(&fileTask);
        while (changedCount == 0) {
            pthread_cond_wait(&fileCond, &fileTask);
        }
        Changed curr = changed[0];
        int i;
        for (i = 0; i < changedCount - 1; i++) {
            changed[i] = changed[i + 1];
        }
        changedCount--;
        //printf("TOSENT\n");
        pthread_mutex_unlock(&fileTask);

        sendFile(curr);
    }
}

void handler(int signum) {
    int i, fd;
    for (i = 0; i < clientCount; ++i){
        ClientInfo* client = clientQueue[i];
        int number = -1;
        send(client->socket, &number, sizeof(number), 0);
    }
    for (fd = 0; fd < getdtablesize(); fd++) {
        close(fd);
    }
    kill(getpid(), SIGKILL);
}

int main(int argc, char* argv[]) {
    if (argc != 4){
        printf("Invalid arguments.\n");
        return -1;
    }
    strcpy(cwd, argv[1]);
    int threadPoolSize = atoi(argv[2]);
    int port = atoi(argv[3]);



    struct sigaction saINT, saTERM, saQUIT;
    memset(&saINT, 0, sizeof(saINT));
    saINT.sa_handler = &handler;
    saINT.sa_flags = SA_RESTART;
    sigaction(SIGINT, &saINT, NULL);

    oldSnapshot.entries = NULL;
    oldSnapshot.count = 0;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Bind socket to the given port
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == -1) {
        perror("Listen failed");
        return 1;
    }

    printf("Server listening on port %d...\n", port);

    th = (pthread_t*)calloc(threadPoolSize, sizeof(pthread_t));
    pthread_mutex_init(&mutexQueue, NULL);
    pthread_mutex_init(&fileTask, NULL);
    pthread_mutex_init(&socketMutex, NULL);
    pthread_mutex_init(&socketMutexR, NULL);
    pthread_cond_init(&condQueue, NULL);
    pthread_cond_init(&fullCondQueue, NULL);
    pthread_cond_init(&fileCond, NULL);
    pthread_t listener, changedFiles, sender;

    //CREATION OF THREADS
    if (pthread_create(&listener, NULL, &listenerThread, &serverSocket)){
        perror("Thread create error.");
        return -1;
    }
    int i;
    for (i = 0; i < threadPoolSize; i++) {
        if (pthread_create(&th[i], NULL, &startThread, NULL) != 0) {
            perror("Failed to create the thread");
        }
    }
    if (pthread_create(&changedFiles, NULL, &changerThread, NULL)){
        perror("Thread create error.");
        return -1;
    }
    if (pthread_create(&sender, NULL, &senderThread, &serverSocket)){
        perror("Thread create error.");
        return -1;
    }


    //WAITING FOR THREADS
    for (i = 0; i < threadPoolSize; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join the thread");
        }
    }
    if (pthread_join(listener, NULL) != 0) {
        perror("Failed to join the thread");
    }
    if (pthread_join(changedFiles, NULL) != 0) {
        perror("Failed to join the thread");
    }
    if (pthread_join(sender, NULL) != 0) {
        perror("Failed to join the thread");
    }

    // Close server socket and free resources
    close(serverSocket);
    //free(threadPool);
    pthread_mutex_destroy(&mutexQueue);
    pthread_mutex_destroy(&fileTask);
    pthread_mutex_destroy(&socketMutex);
    pthread_mutex_destroy(&socketMutexR);
    pthread_cond_destroy(&condQueue);
    pthread_cond_destroy(&fileCond);
    pthread_cond_destroy(&fullCondQueue);
    return 0;
}