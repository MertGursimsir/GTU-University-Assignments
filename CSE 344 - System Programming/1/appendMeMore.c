#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char* path = argv[1];
	int i, fd, bytes = atoi(argv[2]);

	//Argument check
	if (argc < 3 || argc > 4){
		fprintf(stderr, "Bad argument number. Correct one is --> \"./appendMeMore filenName num-bytes [x]\"\n");
		return 1;
	}

	if (argc == 3){
		fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 0666);
		if (fd == -1){
			fprintf(stderr, "File opening error.\n");
			return 1;
		}
		for (i = 0; i < bytes; ++i)
			write(fd, "m", 1);
		//Write with append
	}
	else if (argc == 4 && argv[3][0] == 'x'){
		fd = open(path, O_WRONLY | O_CREAT, 0666);
		if (fd == -1){
			fprintf(stderr, "File opening error.\n");
			return 1;
		}
		for (i = 0; i < bytes; ++i){
			lseek(fd, 0, SEEK_END);
			write(fd, "m", 1);
		}
		//Write with lseek
	}
	else{
		fprintf(stderr, "Invalid argument. Correct one is --> \"./appendMeMore filenName num-bytes [x]\"\n");
		return 1;
	}

	close(fd);

	return 0;
}