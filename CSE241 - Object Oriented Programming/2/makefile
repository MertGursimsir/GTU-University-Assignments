output: main.o implementations.o
	g++ -std=c++11 main.o implementations.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

implementations.o: implementations.cpp headers.h
	g++ -std=c++11 -c implementations.cpp

clean:
	rm *.o output