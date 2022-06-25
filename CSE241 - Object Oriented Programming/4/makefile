output: main.o implementation.o
	g++ -std=c++11 main.o implementation.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

implementation.o: implementation.cpp header.h
	g++ -std=c++11 -c implementation.cpp

clean:
	rm *.o output