all: appendMeMore program

program: duplicate.o programDuplicate.o
	gcc duplicate.o programDuplicate.o -o program

appendMeMore: appendMeMore.o
	gcc appendMeMore.o -o appendMeMore
	
duplicate.o: duplicate.c
	gcc -c duplicate.c

programDuplicate.o: programDuplicate.c
	gcc -c programDuplicate.c

appendMeMore.o: appendMeMore.c  
	gcc -c appendMeMore.c	

clean:
	rm -rf *o appendMeMore program test.txt test2.txt test3.txt