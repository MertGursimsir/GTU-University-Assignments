#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#define COMMAND_LIMIT 20
#define COMMAND_LENGTH_LIMIT 1024

int fileName = 0;

void sigint_handler(int signum) {
    printf("\nCtrl+C received. Press Enter...\n");
    fflush(stdout);
}

void sigterm_handler(int signum) {
    printf("\nSIGTERM received. Press Enter...\n");
    fflush(stdout);
}

void sigquit_handler(int signum) {
    printf("\nSIGQUIT received. Press Enter...\n");
    fflush(stdout);
}

void log_child_processes(int pid, char command[COMMAND_LENGTH_LIMIT]) {
    time_t timeVal;
    struct tm * information;
    char stamp[20];
    char fn[20];
    FILE *logf;

    sprintf(fn, "%d", fileName++);
    time(&timeVal);
    information = localtime(&timeVal);
    strftime(stamp, sizeof(stamp), "%Y%m%d_%H-%M-%S_", information);
    logf = fopen(strcat(strcat(stamp, fn), ".txt"), "w");
    if (logf == NULL) printf("Failed to create log file\n");
    else{
        fprintf(logf, "CHILD: ");
        fprintf(logf, "Command: %s, Process ID: %d", command, pid);
        fclose(logf);
    }
}

int systems(char* command){
    char* commands[COMMAND_LIMIT];
    int commandNum = 0;
    char *token;
    int pipeDescr[COMMAND_LIMIT - 1][2];
    pid_t pids[COMMAND_LIMIT];
    struct sigaction saINT, saTERM, saQUIT;
    
    token = strtok(command, "|");
    while (token != NULL && commandNum < COMMAND_LIMIT) {
        commands[commandNum++] = token;
        token = strtok(NULL, "|");
    }

    for (int i = 0; i < commandNum - 1; i++) {
        if (pipe(pipeDescr[i]) == -1) {
            perror("pipe");
            return -1;
        }
    }


    for (int i = 0; i < commandNum; i++) {
        switch (pids[i] = fork()){
            case -1:
                perror("fork");
                return -1;
            case 0:
                //duplicate STDIN of pipe end
                if (i > 0) {
                    if (dup2(pipeDescr[i-1][0], STDIN_FILENO) == -1) {
                        perror("dup2");
                        _exit(EXIT_FAILURE);
                    }
                }

                //duplicate STDOUT of pipe end
                if (i < commandNum - 1) {
                    if (dup2(pipeDescr[i][1], STDOUT_FILENO) == -1) {
                        perror("dup2");
                        _exit(EXIT_FAILURE);
                    }
                }

                //Close pipe ends
                for (int j = 0; j < commandNum - 1; j++) {
                    close(pipeDescr[j][0]);
                    close(pipeDescr[j][1]);
                }

                //Execute the command
                execl("/bin/sh", "sh", "-c", commands[i], NULL);
                perror("execl");
                exit(127);
        }
    }
    //Log files
    for (int i = 0; i < commandNum; ++i){
        if (i == commandNum-1) commands[i][strlen(commands[i])-1] = '\0';
        log_child_processes(pids[i], commands[i]);
    }
    
    // Close all pipes
    for (int i = 0; i < commandNum - 1; i++) {
        if (close(pipeDescr[i][0]) == -1) perror("Closing error.");
        if (close(pipeDescr[i][1]) == -1) perror("Closing error.");
    }

    // Wait for child processes
    for (int i = 0; i < commandNum; i++) {
        if (waitpid(pids[i], NULL, 0) == -1){
            kill(pids[i], SIGKILL);
        }
    }

    return 0;
}

int main(int argc, char* argv[]){
    char command[COMMAND_LENGTH_LIMIT];
    int status = 0;

    struct sigaction saINT, saTERM, saQUIT;
    memset(&saINT, 0, sizeof(saINT));
    saINT.sa_handler = &sigint_handler;
    saINT.sa_flags = SA_RESTART;
    sigaction(SIGINT, &saINT, NULL);

    memset(&saTERM, 0, sizeof(saTERM));
    saTERM.sa_handler = &sigterm_handler;
    saTERM.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &saTERM, NULL);

    memset(&saQUIT, 0, sizeof(saQUIT));
    saQUIT.sa_handler = &sigquit_handler;
    saQUIT.sa_flags = SA_RESTART;
    sigaction(SIGQUIT, &saQUIT, NULL);

    printf("Welcome dear user to my terminal emulator. Enjoy!\n");
    while(1){
        fileName = 0;
        printf("\nCommand $> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) break;

        if (strcmp(command, ":q\n") == 0) break;

        if (sizeof(command) > 0) status = systems(command);

        if (status == -1) printf("Try again.\n");
    }

    printf("\nThanks for using! Good-bye!\n");

    return 0;
}