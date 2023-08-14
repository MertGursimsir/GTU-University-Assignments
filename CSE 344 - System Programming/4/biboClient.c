#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<time.h>
#include<string.h>

#include "header.h"
#define INPUT_SIZE 512

static char clientFifo[CLIENT_FIFO_NAME_LEN];

static void removeFifo(void){
    unlink(clientFifo);
}

int request(char *dir, char* connectType){
    int serverFD, clientResFD;
    struct request req;
    struct response res;
    char *clientResFifo;
    snprintf(clientFifo, CLIENT_FIFO_NAME_LEN, CLIENT_FIFO_TEMPLATE, (long)getpid());
    clientResFifo = strcat(clientFifo, "_res");
    umask(0);

    if (mkfifo(clientResFifo, 0777) == -1){
        if (errno!=EEXIST){
            perror("Could not create FIFO file. Exiting...\n");
            return -1;
        }
    }
    
    if (atexit(removeFifo) != 0){
        printf("FIFO error.");
        return -1;
    }

    char input[INPUT_SIZE];
    int connected = 0;
    req.pid = getpid();
    strcpy(req.seq, connectType);
    if (getcwd(req.currentDirectory, PATH_MAX) == NULL) {
        perror("getcwd() error. Exiting...");
        return -1;
    }
    while(1){
        //WRITE REQUEST TO SERVER FIFO
        serverFD = open(dir, O_WRONLY);
        if (serverFD == -1){
            perror("FIFO opening error. Exiting...");
            unlink(clientResFifo);
            return -1;
        }
        if (!connected){
            strcpy(req.seq, connectType);
            connected = 1;
        }
        else{
            printf(">> ");
            fgets(input, INPUT_SIZE, stdin);
            input[strcspn(input, "\n")] = '\0';
            strcpy(req.seq, input);
        }
        if (write(serverFD, &req, sizeof(struct request)) == -1){
            perror("Server requesting error.");
            unlink(clientResFifo);
            return -1;
        }
        close(serverFD);
        

        //READ REQUEST FROM RES FIFO
        clientResFD = open(clientResFifo, O_RDONLY);
        if (clientResFD == -1){
            perror("Client FIFO opening error.");
            unlink(clientResFifo);
            return -1;
        }
        if (read(clientResFD, &res, sizeof(struct response)) == -1){
            perror("Error reading response.");
            unlink(clientResFifo);
            return -1;
        }

        if (strcmp(res.seq, "X") == 0) {printf("Que is full. Goodbye.\n"); close(clientResFD); unlink(clientResFifo); return 1;}
        
        printf("%s\n", res.seq);

        close(clientResFD);

        if (strcmp("quit", input) == 0) break;
    }
    
    unlink(clientResFifo);

    return 0;
}

int main(int argc, char *argv[]){
    if (argc != 3 || (strcmp("Connect", argv[1]) != 0 && strcmp("tryConnect", argv[1]) != 0)){
        perror("Bad arguments. Exiting...");
        return -1;        
    }

    int ServerPID = atoi(argv[2]);
    int pid = getpid();

    char pidStr[256], dir[256] = "/tmp/";
    sprintf(pidStr, "%d", pid);
    strcat(dir, argv[2]);

    if (access(dir, F_OK) == -1) {
        printf("Server does not exist. Exiting...\n");
        return -1;
    }

    write(STDOUT_FILENO, ">> Waiting for Que...", 21);

    char connectType[11];
    strcpy(connectType, argv[1]);

    return request(dir, connectType);
    
    ///////////////////////////////////////////////////////////////////////////////////////
}