output: main.o PegSolitaire.o BoardGame2D.o EightPuzzle.o Klotski.o
	g++ -std=c++11 main.o BoardGame2D.o PegSolitaire.o EightPuzzle.o Klotski.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

PegSolitaire.o: PegSolitaire.cpp PegSolitaire.h
	g++ -std=c++11 -c PegSolitaire.cpp

BoardGame2D.o: BoardGame2D.cpp BoardGame2D.h
	g++ -std=c++11 -c BoardGame2D.cpp

EightPuzzle.o: EightPuzzle.cpp EightPuzzle.h
	g++ -std=c++11 -c EightPuzzle.cpp

Klotski.o: Klotski.cpp Klotski.h
	g++ -std=c++11 -c Klotski.cpp

clean:
	rm *.o output