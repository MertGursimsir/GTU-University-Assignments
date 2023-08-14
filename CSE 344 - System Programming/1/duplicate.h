#ifndef __dup__
#define __dup__

int dup(int oldfd);
int dup2(int oldfd, int newfd);
int validation(int fd);

#endif