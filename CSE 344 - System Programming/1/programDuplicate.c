#include "duplicate.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int checkOpening(int fd){
    if (fd == -1){
		fprintf(stderr, "File opening error.\n");
		return 1;
	}
    else return 0;
}

int main(){
    int fd, dupfd, fd2, dupfd2, fd3, dupfd3, dupfd4, pos1, pos2, i, read_bytes;
    char buf1[4], buf2[9];
    char buf3[5], buf4[10];

    printf("TEST 1: test.txt file is going to be created (if doesn't exist) and its descriptor will be duplicated into next available place.\n");

    fd = open("test.txt", O_RDWR | O_CREAT, 0666); if (checkOpening(fd)) return 1;
    dupfd = dup(fd);
    printf("fd original                --> %d\nduplicated fd              --> %d\n\n", fd, dupfd);
    printf("original fd status flags   --> %d\nduplicated fd status flags --> %d\n\n", fcntl(fd, F_GETFL), fcntl(dupfd, F_GETFL, 0));

    printf("Now write mert to original fd, gursimsir to duplicated fd, seek to beginning, read 4 bytes with duplicated fd, read 9 bytes with original fd.\nREAD DATA --> ");
    write(fd, "mert", 4);
    write(dupfd, "gursimsir", 9);
    lseek(fd, 0, SEEK_SET);
    read_bytes = read(dupfd, buf1, sizeof(buf1));
    for (i = 0; i < read_bytes; ++i) printf("%c", buf1[i]);
    read_bytes = read(fd, buf2, sizeof(buf2));
    for (i = 0; i < read_bytes; ++i) printf("%c", buf2[i]);
    printf("\n\n");

    printf("Now set file offset to 42 in original fd and check file offset position in duplicated fd.\n");
    pos1 = lseek(fd, 42, SEEK_SET);
    pos2 = lseek(dupfd, 0, SEEK_CUR);
    printf("Offset of duplicated file: %d\n", pos2);

    close(fd);
    close(dupfd);

    printf("\n\n=====================================================================================================================================================\n\n");

    printf("TEST 2: test2.txt file is going to be created (if doesn't exist) and its descriptor will be duplicated into 2 next place.\n");

    fd2 = open("test2.txt", O_RDWR | O_CREAT, 0666); if (checkOpening(fd2)) return 1;
    dupfd2 = dup2(fd2, fd2+2);
    printf("fd original                --> %d\nduplicated fd              --> %d\n\n", fd2, dupfd2);
    printf("original fd status flags   --> %d\nduplicated fd status flags --> %d\n\n", fcntl(fd2, F_GETFL), fcntl(dupfd2, F_GETFL, 0));

    printf("Now write erkan to original fd, zergeroglu to duplicated fd, seek to beginning, read 5 bytes with duplicated fd, read 10 bytes with original fd.\nREAD DATA --> ");
    write(fd2, "erkan", 5);
    write(dupfd2, "zergeroglu", 10);
    lseek(fd2, 0, SEEK_SET);
    read_bytes = read(dupfd2, buf3, sizeof(buf3));
    for (i = 0; i < read_bytes; ++i) printf("%c", buf3[i]);
    read_bytes = read(fd2, buf4, sizeof(buf4));
    for (i = 0; i < read_bytes; ++i) printf("%c", buf4[i]);
    printf("\n\n");

    printf("Now set file offset to 42 in original fd and check file offset position in duplicated fd.\n");
    pos1 = lseek(fd2, 42, SEEK_SET);
    pos2 = lseek(dupfd2, 0, SEEK_CUR);
    printf("Offset of duplicated file: %d\n", pos2);

    close(fd2);
    close(dupfd2);

    printf("\n\n=====================================================================================================================================================\n\n");

    printf("TEST 3: Now let's try sending the same file descriptor of test3.txt to dup2 and see their descriptor values.\n");

    fd3 = open("test3.txt", O_RDWR | O_CREAT, 0666); if (checkOpening(fd3)) return 1;
    dupfd3 = dup2(fd2, fd2);
    printf("fd original                --> %d\nduplicated fd              --> %d\n\n", fd3, dupfd3);
    printf("original fd status flags   --> %d\nduplicated fd status flags --> %d\n\n", fcntl(fd3, F_GETFL), fcntl(dupfd3, F_GETFL, 0));

    close(fd3);
    close(dupfd3);

    printf("\n\n=====================================================================================================================================================\n\n");

    printf("TEST 4: Now let's try sending the invalid file descriptor as oldfd.\n");

    printf("Descriptor we got from dup2 with invalid descriptor parameters: %d\n", dup2(10, 10));
    printf("errno: %s\n", strerror(errno));

    printf("\n\n=====================================================================================================================================================\n\n");

    printf("TEST 5: Duplicating the standard output --> descriptor 1.\n");

    dupfd4 = dup(1);
    printf("Write \"HELLO!\" to descriptor we got from dup(1).\nDuplicated descriptor value: %d\n", dupfd4);
    write(dupfd4, "HELLO!\n", 7);

    close(dupfd4);

    return 0;
}