#include "duplicate.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int dup(int oldfd){
    //Duplicate oldfd into next available position
    int newfd;
    printf("\n-----oldfd is duplicating (dup)-----\n\n");
    if (validation(oldfd)){
        newfd = fcntl(oldfd, F_DUPFD, 0);
        return newfd;
    }
    else return -1;
}

int dup2(int oldfd, int newfd){
    //Duplicate the oldfd into newfd
    printf("\n-----oldfd is duplicating into newfd (dup2)-----\n\n");
    if (validation(oldfd)){
        if (oldfd != newfd){
            if (fcntl(newfd, F_GETFD) >= 0) close(newfd);
            return fcntl(oldfd, F_DUPFD, newfd);
        }
        else return newfd;
    }
    else return -1;
}

int validation(int fd){
    //Validate the fd descriptor
    int r = fcntl(fd, F_GETFL);
    if (r < 0){
        errno = EBADF;
        return 0;
    }
    return 1;
}