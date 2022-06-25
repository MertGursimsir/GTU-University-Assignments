#include "BoardGame2D.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"
using namespace std;

namespace Gursimsir{
	//Constructors
	BoardGame2D::BoardGame2D() : score(0), gamePtr(this){ }
	BoardGame2D::BoardGame2D(int scoreValue, BoardGame2D* gamePtrValue) : score(scoreValue), gamePtr(gamePtrValue){ }

	//Function that plays the game until it ends
	void BoardGame2D::playAutoAll(){
		//Determine type of the game by looking the pointer
		PegSolitaire *derivedPtr = dynamic_cast<PegSolitaire*> (gamePtr);
		EightPuzzle *derivedPtr2 = dynamic_cast<EightPuzzle*> (gamePtr);
		Klotski *derivedPtr3 = dynamic_cast<Klotski*> (gamePtr);

		//PLAY PEG SOLITAIRE
		if (derivedPtr != nullptr){
			derivedPtr->print();
			while (!derivedPtr->endGame()){
				derivedPtr->playAuto();
				derivedPtr->print();
			}
		}
		//PLAY EIGHT PUZZLE
		else if (derivedPtr2 != nullptr){
			derivedPtr2->print();
			while (!derivedPtr2->endGame()){
				derivedPtr2->playAuto();
				derivedPtr2->print();
			}
		}
		//PLAY KLOTSKI
		else if (derivedPtr3 != nullptr){
			derivedPtr3->print();
			while (!derivedPtr3->endGame()){
				derivedPtr3->playAuto();
				derivedPtr3->print();
			}
		}
	}

	void BoardGame2D::playVector(vector <BoardGame2D*> games){
		//This function calls playAutoAll for all the BoardGame2D pointers in the vector
		cout << "Games in the vector will be played in order.\n"
			 << "This may take some time.\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
		for (int i = 0; i < games.size(); ++i) games[i]->playAutoAll();
	}

	void BoardGame2D::playUser(){
		//Determine type of the game by looking the pointer
		PegSolitaire *derivedPtr = dynamic_cast<PegSolitaire*> (gamePtr);
		EightPuzzle *derivedPtr2 = dynamic_cast<EightPuzzle*> (gamePtr);
		Klotski *derivedPtr3 = dynamic_cast<Klotski*> (gamePtr);

		string str;
		fstream test;

		//Opening test file
		test.open("test.txt", fstream::in | fstream::out | fstream::app);

		//Get input and play the game accordingly for Peg Solitaire
		if (derivedPtr != nullptr){
			cout << "~ LET'S PLAY SOME PEG SOLITAIRE ~\n";
			cout << "Give your instructions (such as \"2B UP\"):\n"
				 << "-----------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(3000));
			while (!derivedPtr->endGame()){
				test << *derivedPtr << endl;
				derivedPtr->print();
				cout << "INPUT --> ";
				getline(cin, str);
				if (!derivedPtr->playUser(str)) {cout << "\nPlease enter valid input\n"; continue;}
			}
			test << *derivedPtr << endl;
			derivedPtr->print();
		}
		//Get input and play the game accordingly for Eight Puzzle
		else if (derivedPtr2 != nullptr){
			cout << "~ LET'S PLAY SOME EIGHT PUZZLE ~\n";
			cout << "Give your instruction (such as \"LEFT\"):\n"
				 << "---------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(3000));
			while (!derivedPtr2->endGame()){
				test << *derivedPtr2 << endl;
				derivedPtr2->print();
				cout << "INPUT --> ";
				getline(cin, str);
				if(!derivedPtr2->playUser(str)) {cout << "\nPlease enter valid input \n"; continue;}
			}
			test << *derivedPtr2 << endl;
			derivedPtr2->print();
		}
		//Get input and play the game accordingly for Klotski
		else if (derivedPtr3 != nullptr){
			cout << "~ LET'S PLAY SOME KLOTSKI ~\n";
			cout << "Give your instructions (such as \"2B UP\") \n"
				 << "----------------------------------------\n";
			this_thread::sleep_for(chrono::milliseconds(3000));
			while (!derivedPtr3->endGame()){
				test << *derivedPtr3 << endl;
				derivedPtr3->print();
				cout << "INPUT --> ";
				getline(cin, str);
				if(!derivedPtr3->playUser(str)) {cout << "\nPlease enter valid input\n"; continue;}
			}
			test << *derivedPtr3 << endl;
			derivedPtr3->print();
		}
		test.close();
	}

	ostream& operator<<(ostream& outputStream, const BoardGame2D& game){
		//Determine type of the game by looking the pointer
		PegSolitaire *derivedPtr = dynamic_cast<PegSolitaire*> (game.gamePtr);
		EightPuzzle *derivedPtr2 = dynamic_cast<EightPuzzle*> (game.gamePtr);
		Klotski *derivedPtr3 = dynamic_cast<Klotski*> (game.gamePtr);
		this_thread::sleep_for(chrono::milliseconds(500));

		//Starting from top left corner of the terminal (just for terminal, not for files etc.)
		cout << "\x1b[2J"; 
	    cout << "\033[0;0H";

	    //Printing PegSolitaire board and score
		if (derivedPtr != nullptr){
			outputStream << "  a b c d e f g h i \n";
			for (auto i = 0; i < 9; ++i){
				outputStream << i+1 << " ";
				for (auto j = 0; j < 9; ++j) outputStream << derivedPtr->board[i][j] << " ";
				outputStream << endl;
			}
			outputStream << "Your score is " << derivedPtr->boardScore() << endl;
		}
		//Printing EightPuzzle board and score
		else if (derivedPtr2 != nullptr){
			outputStream << "-------------\n";
			for (auto i = 0; i < 3; ++i){
				outputStream << "| ";
				for (auto j = 0; j < 3; ++j) outputStream << derivedPtr2->board[i][j] << " | ";
				outputStream << endl << "-------------\n";
			}
			outputStream << "Your score is " << derivedPtr2->boardScore() << endl;
		}
		//Printing Klotski board and score
		else if (derivedPtr3 != nullptr){
			outputStream << "  a b c d\n";
			for (int i = 0; i < 5; ++i){
				outputStream << i+1 << " ";
				for (int j = 0; j < 4; ++j){
					outputStream << derivedPtr3->board[i][j] << " ";
				}
				outputStream << endl;
			}
			outputStream << "Your score is " << derivedPtr3->boardScore() << endl;
		}

		return outputStream;
	}

	int BoardGame2D::randomGenerator(int min, int max){
		//Generating random number
		random_device randomCreator;
        mt19937 rand(randomCreator());
        uniform_int_distribution<mt19937::result_type> randRange(min, max);
        return randRange(randomCreator);
	}
}