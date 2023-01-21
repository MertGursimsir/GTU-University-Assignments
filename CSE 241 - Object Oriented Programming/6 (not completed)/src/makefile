output: main.o GTUVector.o GTUIterator.o GTUIteratorConst.o
	g++ -std=c++11 main.o GTUVector.o GTUIterator.o GTUIteratorConst.o -o output

main.o: main.cpp Iterable.h
	g++ -std=c++11 -c main.cpp

GTUVector.o: GTUVector.cpp GTUVector.h Iterable.h
	g++ -std=c++11 -c GTUVector.cpp

GTUIterator.o: GTUIterator.cpp GTUIterator.h Iterable.h
	g++ -std=c++11 -c GTUIterator.cpp

GTUIteratorConst.o: GTUIteratorConst.cpp GTUIteratorConst.h Iterable.h
	g++ -std=c++11 -c GTUIteratorConst.cpp

clean:
	rm *.o output