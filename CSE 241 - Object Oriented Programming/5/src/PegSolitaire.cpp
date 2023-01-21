#include "PegSolitaire.h"
using namespace std;

namespace Gursimsir{
	//Constructor
	PegSolitaire::PegSolitaire() : BoardGame2D(43, this){ 
		initialize();
	}

	//Function to play the game for 1 move
	bool PegSolitaire::playUser(string movement){
		if (movement[2] != ' ') return false;

		//Getting row, column and direction from the string input
		int row = movement[0] - 48;
		int col = movement[1] - 64;
		string direction = movement.substr(3);

		//Calling proper functions after some control
		if (row < 1 || row > 9) return false;
		if (col < 1 || col > 9) return false;
		if (direction == "UP") return playUp(row, col);
		else if (direction == "DOWN") return playDown(row, col);
		else if (direction == "LEFT") return playLeft(row, col);
		else if (direction == "RIGHT") return playRight(row, col);
		else return false;

		return true;
	}

	bool PegSolitaire::playUp(int row, int col){
		//Playing the indicated peg up
		if (row < 3) return false;
		else if (board[row-1][col-1] != 'P') return false;
		else if (board[row-2][col-1] == 'P' && board[row-3][col-1] == '.'){
			board[row-1][col-1] = '.'; board[row-2][col-1] = '.'; board[row-3][col-1] = 'P';
		}
		else return false;
		decreaseScore();
		return true;
	}

	bool PegSolitaire::playDown(int row, int col){
		//Playing the indicated peg down
		if (row > 7) return false;
		else if (board[row-1][col-1] != 'P') return false;
		else if (board[row][col-1] == 'P' && board[row+1][col-1] == '.'){
			board[row-1][col-1] = '.'; board[row][col-1] = '.'; board[row+1][col-1] = 'P';
		}
		else return false;
		decreaseScore();
		return true;
	}

	bool PegSolitaire::playLeft(int row, int col){
		//Playing the indicated peg left
		if (col < 3) return false;
		else if (board[row-1][col-1] != 'P') return false;
		else if (board[row-1][col-2] == 'P' && board[row-1][col-3] == '.'){
			board[row-1][col-1] = '.'; board[row-1][col-2] = '.'; board[row-1][col-3] = 'P';
		}
		else return false;
		decreaseScore();
		return true;
	}

	bool PegSolitaire::playRight(int row, int col){
		//Playing the indicated peg right
		if (col > 7) return false;
		else if (board[row-1][col-1] != 'P') return false;
		else if (board[row-1][col] == 'P' && board[row-1][col+1] == '.'){
			board[row-1][col-1] = '.'; board[row-1][col] = '.'; board[row-1][col+1] = 'P';
		}
		else return false;
		decreaseScore();
		return true;
	}

	void PegSolitaire::playAuto(){
		//Playing the game automatically by 1 move
		int row, col, direction;
		bool flag = true;
		while (flag){
			flag = false;
			row = randomGenerator(1, 9);
	        col = randomGenerator(1, 9);
	        direction = randomGenerator(1, 4);
	        switch (direction){
	        	case 1: while(!playUp(row, col)){ flag = true; break; } break;
	        	case 2:	while(!playDown(row, col)) { flag = true; break; } break;
	        	case 3:	while(!playLeft(row, col)) { flag = true; break; } break;
	        	case 4:	while(!playRight(row, col)) { flag = true; break; } break;
	        }
		}
	}

	void PegSolitaire::print() const{
		//Printing the board and score
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "\x1b[2J"; 
        cout << "\033[0;0H";
		cout << "  a b c d e f g h i \n";
		for (auto i = 0; i < 9; ++i){
			cout << i+1 << " ";
			for (auto j = 0; j < 9; ++j) cout << board[i][j] << " ";
			cout << endl;
		}
		cout << "Your score is " << boardScore() << endl;
	}

	bool PegSolitaire::endGame(){
		//Checking if the game ended
		for (int i = 2; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[i][j] == 'P'){
					if (board[i-1][j] == 'P' && board[i-2][j] == '.') return false;
				}
			}
		}
		for (int i = 0; i < 7; ++i){
			for (int j = 0; j < 9; ++j){
				if (board[i][j] == 'P'){
					if (board[i+1][j] == 'P' && board[i+2][j] == '.') return false;
				}
			}
		}
		for (int i = 0; i < 9; ++i){
			for (int j = 2; j < 9; ++j){
				if (board[i][j] == 'P'){
					if (board[i][j-1] == 'P' && board[i][j-2] == '.') return false;
				}
			}
		}
		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 7; ++j){
				if (board[i][j] == 'P'){
					if (board[i][j+1] == 'P' && board[i][j+2] == '.') return false;
				}
			}
		}
		return true;
	}

	void PegSolitaire::initialize(){
		//Initialize the board
		board.resize(9);
		for (auto i = 0; i < 9; ++i) board[i].resize(9);

		for (auto i = 0; i < 9; ++i){
			for(auto j = 0; j < 9; ++j){
				if (i==3 || i==4 || i==5) board[i][j] = 'P';
				else{
					if(j==3 || j==4 || j==5) board[i][j] = 'P';
					else board[i][j] = ' ';
				}
			}
		}
		board[4][4] = '.';
	}
}