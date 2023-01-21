#include "EightPuzzle.h"
using namespace std;

namespace Gursimsir{
	//Constructor
	EightPuzzle::EightPuzzle() : BoardGame2D(8, this) { 
		initialize();
	}

	bool EightPuzzle::isSolvable(){
		//Checking if the board can be solved
		//Find the number that comes after from one slot that is bigger than that slot
		//If number is even, board can be solved. Otherwise it cannot.
		int total = 0, counter = 0;;
		vector <int> temp(8);

		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				if (board[i][j] != ' ') temp[counter++] = board[i][j] - 48;
			}
		}
		for (int i = 0; i < 7; ++i){
			for (int j = i; j < 8; ++j){
				if (temp[i] > temp[j]) total++;
			}
		}
		if (total % 2 == 0) return true;
		else return false;
	}

	void EightPuzzle::playAuto(){
		//Play the board automatically for 1 move
		int direction;
		bool flag = true;
		while (flag){
			flag = false;
	        direction = randomGenerator(1, 4);
	        switch (direction){
	        	case 1: while(!playUser("UP")){ flag = true; break; } break;
	        	case 2:	while(!playUser("DOWN")) { flag = true; break; } break;
	        	case 3:	while(!playUser("LEFT")) { flag = true; break; } break;
	        	case 4:	while(!playUser("RIGHT")) { flag = true; break; } break;
	        }
		}
	}

	void EightPuzzle::initialize(){
		//Initializing the board
		board.resize(3);
		for (auto i = 0; i < 3; ++i) board[i].resize(3);

		char num = '1';
		for (auto i = 0; i < 3; ++i){
			for (auto j = 0; j < 3; ++j){
				board[i][j] = num++;
			}
		}
		board[2][2] = ' ';

		//Shuffling the board randomly and accept one if that is solvable
		do{
			int random_i, random_j, temp;
			for(int i = 0; i < 3; ++i)
				for(int j = 0; j < 3; ++j){
					random_i = randomGenerator(0, 2);
					random_j = randomGenerator(0, 2);
					temp = board[i][j];
					board[i][j] = board[random_i][random_j];
					board[random_i][random_j] = temp;
				}
		}while(!isSolvable());
		
	}

	void EightPuzzle::print() const{
		//Printing the board
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "\x1b[2J"; 
        cout << "\033[0;0H";
		cout << "-------------\n";
		for (auto i = 0; i < 3; ++i){
			cout << "| ";
			for (auto j = 0; j < 3; ++j) cout << board[i][j] << " | ";
			cout << endl << "-------------\n";
		}
		cout << "Your score is " << boardScore() << endl;
	}

	bool EightPuzzle::playUser(string movement){
		//Getting the place of empty slot in the board
		int row, col;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[i][j] == ' '){ row = i; col = j;}

		//Calling proper functions after some control
		if (movement == "UP") return playUp(row, col);
		else if (movement == "DOWN") return playDown(row, col);
		else if (movement == "LEFT") return playLeft(row, col);
		else if (movement == "RIGHT") return playRight(row, col);
		else return false;

		return true;
	}

	bool EightPuzzle::playUp(int row, int col){
		//Playing up the empty slot
		if (row == 0) return false;
		else {board[row][col] = board[row-1][col]; board[row-1][col] = ' ';}
		calcScore();
		return true;
	}

	bool EightPuzzle::playDown(int row, int col){
		//Playing down the empty slot
		if (row == 2) return false;
		else { board[row][col] = board[row+1][col]; board[row+1][col] = ' ';}
		calcScore();
		return true;
	}

	bool EightPuzzle::playLeft(int row, int col){
		//Playing left the empty slot
		if (col == 0) return false;
		else { board[row][col] = board[row][col-1]; board[row][col-1] = ' ';}
		calcScore();
		return true;
	}

	bool EightPuzzle::playRight(int row, int col){
		//Playing right the empty slot
		if (col == 2) return false;
		else { board[row][col] = board[row][col+1]; board[row][col+1] = ' ';}
		calcScore();
		return true;
	}

	void EightPuzzle::calcScore(){
		//Calculating the score according the correctness of the numbers
		char counter = '1';
		int scoreTemp = 8;
		for(int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				if (board[i][j] == counter) scoreTemp--;
				counter++;
			}
		}
		score = scoreTemp;
	}

	bool EightPuzzle::endGame(){
		//Returns true if board is ordered
		char control = '1';
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				if (control == '9') control = ' ';
				if (board[i][j] != control) return false;
				else control++;
			}
		}
		return true;
	}
}