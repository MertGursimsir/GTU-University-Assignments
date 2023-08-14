all: biboClient biboServer

biboClient: biboClient.o
	gcc biboClient.o -o biboClient

biboServer: biboServer.o
	gcc biboServer.o -o biboServer

biboClient.o: biboClient.c  
	gcc -c biboClient.c	

biboServer.o: biboServer.c  
	gcc -c biboServer.c	

clean:
	rm -rf *o biboClient biboServer