#include "BoardGame2D.h"
#include "EightPuzzle.h"
#include "PegSolitaire.h"
#include "Klotski.h"

using namespace std;
using namespace Gursimsir;

void driver();

int main(){
	//Constructors calls initialize function
	PegSolitaire PSGame;
	Klotski KGame;
	EightPuzzle EPGame;

	cout << "WELCOME TO WORLD OF BOARD GAMES.\n";
	driver();
	//driver function can be commented out because playUser is already testing many functions.
	//but it is written to be make sure that everything works outside the class.

	//playUser function that takes no parameter checks many functions
	//It calls overloaded playUser that takes a string,
	//print function and operator<< to print the game, endGame function to check if the game is ended,
	//and other helper functions to move or calculate the score
	PSGame.BoardGame2D::playUser();
	KGame.BoardGame2D::playUser();
	EPGame.BoardGame2D::playUser();

	this_thread::sleep_for(chrono::milliseconds(1500));
	PegSolitaire PSGame1, PSGame2;
	Klotski KGame1, KGame2;
	EightPuzzle EPGame1, EPGame2;
	vector<BoardGame2D*> games(6);

	games[0] = &PSGame1;
	games[1] = &PSGame2;
	games[2] = &KGame1;
	games[3] = &KGame2;
	games[4] = &EPGame1;
	games[5] = &EPGame2;

	//playVector function checks many functions
	//It calls playAutoAll function which in turn calls 
	//playAuto, endGame, and print functions of the derived classes
	//Static playVector function determines the class type by checking its pointer stored in the members
	BoardGame2D::playVector(games);
	//It takes not so much time to play Peg Solitaire
	//It takes very much time to play Eight Puzzle and Klotski because it doesn't play smart
	//Between 500 000 and 1 000 000 moves are required to finish the game for that games according to my experiments.

	return 0;
}

void driver(){
	PegSolitaire PSGame;
	Klotski KGame;
	EightPuzzle EPGame;

	//TESTING FUNCTIONS FOR PEGSOLITAIRE CLASS
	this_thread::sleep_for(chrono::milliseconds(1500));
	cout << PSGame;
	cout << "Let's try to play 1 move for PegSolitaire (5C RIGHT):\n";
	PSGame.playUser("5C RIGHT");
	this_thread::sleep_for(chrono::milliseconds(3000));
	PSGame.print();
	cout << "Let's check the endGame function:\n";
	if (PSGame.endGame()) cout << "Game is ended.\n";
	else cout << "Game is not ended.\n";
	cout << "Let computer to play 1 move automatically with playAuto function:\n";
	PSGame.playAuto();
	this_thread::sleep_for(chrono::milliseconds(6000));
	cout << PSGame;
	cout << "Let's check boardScore function:\n";
	cout << "Our score which is returned by boardScore() is: " << PSGame.boardScore() << endl;

	/*******************************************************************************************/

	//TESTING FUNCTIONS FOR KLOTSKI CLASS
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << KGame;
	cout << "Let's try to play 1 move for Klotski (5A RIGHT):\n";
	KGame.playUser("5A RIGHT");
	this_thread::sleep_for(chrono::milliseconds(3000));
	KGame.print();
	cout << "Let's check the endGame function:\n";
	if (KGame.endGame()) cout << "Game is ended.\n";
	else cout << "Game is not ended.\n";
	cout << "Let computer to play 1 move automatically with playAuto function:\n";
	KGame.playAuto();
	this_thread::sleep_for(chrono::milliseconds(6000));
	cout << KGame;
	cout << "Let's check boardScore function:\n";
	cout << "Our score which is returned by boardScore() is: " << KGame.boardScore() << endl;

	/*******************************************************************************************/

	//TESTING FUNCTIONS FOR EIGHTPUZZLE CLASS
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << EPGame;
	cout << "Let's try to play 1 move for EightPuzzle (RIGHT):\n";
	EPGame.playUser("RIGHT");
	this_thread::sleep_for(chrono::milliseconds(3000));
	EPGame.print();
	cout << "Let's check the endGame function:\n";
	if (EPGame.endGame()) cout << "Game is ended.\n";
	else cout << "Game is not ended.\n";
	cout << "Let computer to play 1 move automatically with playAuto function:\n";
	EPGame.playAuto();
	this_thread::sleep_for(chrono::milliseconds(6000));
	cout << EPGame;
	cout << "Let's check boardScore function:\n";
	cout << "Our score which is returned by boardScore() is: " << EPGame.boardScore() << endl;
}