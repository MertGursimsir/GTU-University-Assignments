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
    int serverFD, clientReqFD, clientResFD;
    struct request req;
    struct response res;
    char *clientReqFifo;
    char *clientResFifo;
    char temp[CLIENT_FIFO_NAME_LEN];
    snprintf(clientFifo, CLIENT_FIFO_NAME_LEN, CLIENT_FIFO_TEMPLATE, (long)getpid());
    strcpy(temp, clientFifo);
    clientReqFifo = strcat(temp, "_req");
    clientResFifo = strcat(clientFifo, "_res");
    umask(0);

    if (getcwd(req.currentDirectory, PATH_MAX) == NULL) {
        perror("getcwd() error. Exiting...");
        return -1;
    }

    if (mkfifo(clientReqFifo, 0777) == -1){
        if (errno!=EEXIST){
            perror("Could not create FIFO file. Exiting...\n");
            return -1;
        }
    }
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


    //CONNECTION
    serverFD = open(dir, O_WRONLY);
    if (serverFD == -1){
        perror("FIFO opening error. Exiting...");
        return -1;
    }
    strcpy(req.seq, connectType);
    req.pid = getpid();
    if (write(serverFD, &req, sizeof(struct request)) == -1){
        perror("Server requesting error.");
        return -1;
    }
    close(serverFD);

    if (strcmp(connectType, "tryConnect") == 0){
        clientResFD = open(clientResFifo, O_RDONLY);
        if (clientResFD == -1){
            perror("Client FIFO opening error.");
            return -1;
        }
        if (read(clientResFD, &res, sizeof(struct response)) == -1){
            perror("Error reading response.");
            return -1;
        }
        if (strcmp(res.seq, "0") == 0) {printf("Que is full. Goodbye.\n"); close(clientResFD); unlink(clientResFifo); unlink(clientReqFifo); return 1;}
        close(clientResFD);
    }
    
    int connected = 0;
    while(1){
        //WRITE REQUEST TO REQ FIFO
        clientReqFD = open(clientReqFifo, O_WRONLY);
        if (clientReqFD == -1){
            perror("FIFO opening error. Exiting...");
            unlink(clientReqFifo);
            unlink(clientResFifo);

            return -1;
        }
        if (!connected){
            printf("Connection established:\n");
            connected = 1;
        }
        char input[INPUT_SIZE];
        printf(">> ");
        fgets(input, INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(req.seq, input);
        if (write(serverFD, &req, sizeof(struct request)) == -1){
            perror("Server requesting error.");
            unlink(clientReqFifo);
            unlink(clientResFifo);

            return -1;
        }
        close(clientReqFD);
        

        //READ REQUEST FROM RES FIFO
        clientResFD = open(clientResFifo, O_RDONLY);
        if (clientResFD == -1){
            perror("Client FIFO opening error.");
            unlink(clientReqFifo);
        unlink(clientResFifo);

            return -1;
        }
        if (read(clientResFD, &res, sizeof(struct response)) == -1){
            perror("Error reading response.");
            unlink(clientReqFifo);
        unlink(clientResFifo);

            return -1;
        }
        
        printf("%s", res.seq);
        printf("\n");

        close(clientResFD);

        if (strcmp("quit", input) == 0) break;
        if (strcmp(res.seq, "tryConnect") == 0) break;
    }
    
    unlink(clientReqFifo);
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