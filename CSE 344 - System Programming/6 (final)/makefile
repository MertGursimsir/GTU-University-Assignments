all: BibakBOXClient BibakBOXServer

BibakBOXClient: BibakBOXClient.o
	gcc BibakBOXClient.o -o BibakBOXClient

BibakBOXServer: BibakBOXServer.o
	gcc BibakBOXServer.o -o BibakBOXServer

BibakBOXClient.o: BibakBOXClient.c  
	gcc -c BibakBOXClient.c	

BibakBOXServer.o: BibakBOXServer.c  
	gcc -c BibakBOXServer.c	

clean:
	rm -rf *o BibakBOXClient BibakBOXServer