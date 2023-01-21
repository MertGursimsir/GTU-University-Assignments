#include "Klotski.h"
using namespace std;

namespace Gursimsir{
	//Constructor
	Klotski::Klotski() : BoardGame2D(4, this) { 
		initialize();
	}

	void Klotski::playAuto(){
		//Playing the game automatically for one move
		int row, col, direction;
		bool flag = true;
		while (flag){
			flag = false;
			row = randomGenerator(1, 5);
	        col = randomGenerator(1, 4);
	        direction = randomGenerator(1, 4);
	        switch (direction){
	        	case 1: while(!playUp(row, col)){ flag = true; break; } break;
	        	case 2:	while(!playDown(row, col)) { flag = true; break; } break;
	        	case 3:	while(!playLeft(row, col)) { flag = true; break; } break;
	        	case 4:	while(!playRight(row, col)) { flag = true; break; } break;
	        }
		}
	}

	void Klotski::initialize(){
		//Initializing the board
		board.resize(5);
		for (int i = 0; i < 5; ++i) board[i].resize(4);

		board[0][0] = board[1][0] = 'A';
		board[0][1] = board[0][2] = board[1][1] = board[1][2] = 'X';
		board[0][3] = board[1][3] = 'B';
		board[2][0] = board[3][0] = 'C';
		board[2][1] = board[2][2] = 'D'; 
		board[2][3] = board[3][3] = 'E';
		board[3][1] = 'F';
		board[3][2] = 'G';
		board[4][0] = 'H';
		board[4][3] = 'I';
		board[4][1] = board[4][2] = ' ';
	}

	void Klotski::print() const{
		//Printing the board and score
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "\x1b[2J"; 
        cout << "\033[0;0H";

		cout << "  a b c d\n";
		for (int i = 0; i < 5; ++i){
			cout << i+1 << " ";
			for (int j = 0; j < 4; ++j){
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Your score is " << boardScore() << endl;
	}

	bool Klotski::endGame(){
		//Returns true if game is ended
		if (board[4][1] == 'X' && board[4][2] == 'X') return true;
		else return false;
	}

	void Klotski::calcScore(){
		//Calculating score according to X square's place
		if (board[0][0] == 'X') score = 5;
		else if (board[0][1] == 'X') score = 4;
		else if (board[0][2] == 'X') score = 5;
		else if (board[1][0] == 'X') score = 4;
		else if (board[1][1] == 'X') score = 3;
		else if (board[1][2] == 'X') score = 4;
		else if (board[2][0] == 'X') score = 3;
		else if (board[2][1] == 'X') score = 2;
		else if (board[2][2] == 'X') score = 3;
		else if (board[3][0] == 'X') score = 1;
		else if (board[3][1] == 'X') score = 0;
		else if (board[3][2] == 'X') score = 1;
	}

	bool Klotski::playUser(string movement){
		//Getting row, column and direction from the string input
		if (movement[2] != ' ') return false;
		int row = movement[0] - 48;
		int col = movement[1] - 64;
		string direction = movement.substr(3);

		//Calling proper functions after some control
		if (row < 1 || row > 5) return false;
		if (col < 1 || col > 4) return false;
		if (direction == "UP") return playUp(row, col);
		else if (direction == "DOWN") return playDown(row, col);
		else if (direction == "LEFT") return playLeft(row, col);
		else if (direction == "RIGHT") return playRight(row, col);
		else return false;

		return true;
	}

	bool Klotski::playUp(int row, int col){
		//Playing up indicated piece of the board
		row--; col--;
		if (row == 0) return false;
		else{
			char c = board[row][col];
			if (c == ' ') return false;
			if (c == 'A' || c == 'B' || c == 'C' || c == 'E'){
				//Playing vertical rectangles
				if (board[row-1][col] == c){ 
					if (row < 2) return false;
					else if (board[row-2][col] != ' ') return false;
					else { board[row-2][col] = c; board[row][col] = ' '; }
				}
				else if (board[row-1][col] == ' '){
					board[row-1][col] = c; board[row+1][col] = ' ';
				}
				else return false;
			}
			else if (c == 'D'){
				//Playing horizontal rectangle
				if (col > 0){
					if (board[row][col-1] == 'D'){
						if (board[row-1][col] == ' ' && board[row-1][col-1] == ' '){
							board[row-1][col] = board[row-1][col-1] = 'D';
							board[row][col] = board[row][col-1] = ' ';
						}
						else return false;
					}
				}
				if (col < 3){
					if (board[row][col+1] == 'D'){
						if (board[row-1][col] == ' ' && board[row-1][col+1] == ' '){
							board[row-1][col] = board[row-1][col+1] = 'D';
							board[row][col] = board[row][col+1] = ' ';
						}
						else return false;
					}
				}
			}
			else if (c == 'H' || c == 'F' || c == 'G' || c == 'I'){
				//Playing one squares
				if (board[row-1][col] != ' ') return false;
				else {board[row-1][col] = c; board[row][col] = ' ';}
			}
			else if (c == 'X'){
				//Playing the X square
				//We need to control specified row and column's place
				//Then play according to that coordinates
				if (col > 0){
					if (board[row][col-1] == 'X'){
						if (board[row-1][col] == 'X'){
							if (row < 2) return false;
							else{
								if (board[row-2][col] != ' ' || board[row-2][col-1] != ' ') return false;
								else{
									board[row-2][col] = board[row-2][col-1] = 'X';
									board[row][col] = board[row][col-1] = ' ';
 								}
							}
						}
						else if (board[row-1][col-1] == ' ' && board[row-1][col] == ' '){
							board[row-1][col] = board[row-1][col-1] = 'X';
							board[row+1][col] = board[row+1][col-1] = ' ';
						}
						else return false;
					}
				}
				if (col < 3){
					if (board[row][col+1] == 'X'){
						if (board[row-1][col] == 'X'){
							if(row < 2) return false;
							else{
								if (board[row-2][col] != ' ' || board[row-2][col+1] != ' ') return false;
								else {
									board[row-2][col] = board[row-2][col+1] = 'X';
									board[row][col] = board[row][col+1] = ' ';
								}
							}
						}
						else if(board[row-1][col] == ' ' && board[row-1][col+1] == ' '){
							board[row-1][col] = board[row-1][col+1] = 'X';
							board[row+1][col] = board[row+1][col+1] = ' ';
						}
						else return false;
					}
				}
			}
		}
		calcScore();
		return true;
	}

	bool Klotski::playDown(int row, int col){
		//Playing down indicated piece of the board
		row--; col--;
		if (row == 4) return false;
		else{
			char c = board[row][col];
			if (c == ' ') return false;
			if (c == 'A' || c == 'B' || c == 'C' || c == 'E'){
				//Playing vertical rectangles
				if (board[row+1][col] == c){ 
					if (row > 2) return false;
					else if (board[row+2][col] != ' ') return false;
					else { board[row+2][col] = c; board[row][col] = ' '; }
				}
				else if (board[row+1][col] == ' '){
					board[row+1][col] = c; board[row-1][col] = ' ';
				}
				else return false;
			}
			else if (c == 'D'){
				//Playing horizontal rectangle
				if (col > 0){
					if (board[row][col-1] == 'D'){
						if (board[row+1][col] == ' ' && board[row+1][col-1] == ' '){
							board[row+1][col] = board[row+1][col-1] = 'D';
							board[row][col] = board[row][col-1] = ' ';
						}
						else return false;
					}
				}
				if (col < 3){
					if (board[row][col+1] == 'D'){
						if (board[row+1][col] == ' ' && board[row+1][col+1] == ' '){
							board[row+1][col] = board[row+1][col+1] = 'D';
							board[row][col] = board[row][col+1] = ' ';
						}
						else return false;
					}
				}
			}
			else if (c == 'H' || c == 'F' || c == 'G' || c == 'I'){
				//Playing one squares
				if (board[row+1][col] != ' ') return false;
				else {board[row+1][col] = c; board[row][col] = ' ';}
			}
			else if (c == 'X'){
				//Playing the X square
				//We need to control specified row and column's place
				//Then play according to that coordinates
				if (col > 0){
					if (board[row][col-1] == 'X'){
						if (board[row+1][col] == 'X'){
							if (row > 2) return false;
							else{
								if (board[row+2][col] != ' ' || board[row+2][col-1] != ' ') return false;
								else{
									board[row+2][col] = board[row+2][col-1] = 'X';
									board[row][col] = board[row][col-1] = ' ';
 								}
							}
						}
						else if (board[row+1][col-1] == ' ' && board[row+1][col] == ' '){
							board[row+1][col] = board[row+1][col-1] = 'X';
							board[row-1][col] = board[row-1][col-1] = ' ';
						}
						else return false;
					}
				}
				if (col < 3){
					if (board[row][col+1] == 'X'){
						if (board[row+1][col] == 'X'){
							if(row > 2) return false;
							else{
								if (board[row+2][col] != ' ' || board[row+2][col+1] != ' ') return false;
								else {
									board[row+2][col] = board[row+2][col+1] = 'X';
									board[row][col] = board[row][col+1] = ' ';
								}
							}
						}
						else if(board[row+1][col] == ' ' && board[row+1][col+1] == ' '){
							board[row+1][col] = board[row+1][col+1] = 'X';
							board[row-1][col] = board[row-1][col+1] = ' ';
						}
						else return false;
					}
				}
			}
		}
		calcScore();
		return true;
	}

	bool Klotski::playLeft(int row, int col){
		//Playing left indicated piece of the board
		row--; col--;
		if (col == 0) return false;
		else{
			char c = board[row][col];
			if (c == ' ') return false;
			if (c == 'A' || c == 'B' || c == 'C' || c == 'E'){
				//Playing vertical rectangles
				if (row > 0){
					if (board[row-1][col] == c){ 
						if (board[row][col-1] != ' ' || board[row-1][col-1] != ' ') return false;
						else { board[row][col-1] = board[row-1][col-1] = c; board[row][col] = board[row-1][col] = ' '; }
					}
				}
				if (row < 4){
					if (board[row+1][col] == c){
						if(board[row][col-1] != ' ' || board[row+1][col-1] != ' ') return false;
						else{ board[row][col-1] = board[row+1][col-1] = c; board[row][col] = board[row+1][col] = ' '; }
					}
				}				
			}
			else if (c == 'D'){
				//Playing horizontal rectangle
				if (board[row][col-1] == 'D'){
					if (col < 2) return false;
					else if (board[row][col-2] != ' ') return false;
					else{
						board[row][col-2] = 'D';
						board[row][col] = ' ';
					}
				}
				else{
					if (board[row][col-1] != ' ') return false;
					else{
						board[row][col-1] = 'D';
						board[row][col+1] = ' ';
					}
				}
			}
			else if (c == 'H' || c == 'F' || c == 'G' || c == 'I'){
				//Playing one squares
				if (board[row][col-1] != ' ') return false;
				else {board[row][col-1] = c; board[row][col] = ' ';}
			}
			else if (c == 'X'){
				//Playing the X square
				//We need to control specified row and column's place
				//Then play according to that coordinates
				if (row > 0){
					if (board[row][col-1] == 'X'){
						if (col < 2) return false;
						if (board[row-1][col] == 'X'){
							if (board[row][col-2] != ' ' || board[row-1][col-2] != ' ') return false;
							else{
								board[row][col-2] = board[row-1][col-2] = 'X';
								board[row][col] = board[row-1][col] = ' ';
 							}
							
						}
						else if (board[row+1][col-2] == ' ' && board[row][col-2] == ' '){
							board[row][col-2] = board[row+1][col-2] = 'X';
							board[row+1][col] = board[row][col] = ' ';
						}
						else return false;
					}
					else{
						if (board[row-1][col] == 'X'){
							if (board[row][col-1] != ' ' || board[row-1][col-1] != ' ') return false;
							else{
								board[row][col-1] = board[row-1][col-1] = 'X';
								board[row][col+1] = board[row-1][col+1] = ' ';
							}
						}
						else if (board[row+1][col-1] == ' ' && board[row][col-1] == ' '){
							board[row+1][col-1] = board[row][col-1] = 'X';
							board[row+1][col+1] = board[row][col+1] = ' ';
						}
					}
				}
				if (row == 0){
					if (board[row][col+1] == 'X'){
						if (board[row+1][col-1] != ' ' || board[row][col-1] != ' ') return false;
						else {
							board[row+1][col-1] = board[row][col-1] = 'X';
							board[row+1][col+1] = board[row][col+1] = ' ';
						}
					}
					else if (col < 2) return false;
					else if(board[row][col-2] == ' ' && board[row+1][col-2] == ' '){
						board[row][col-2] = board[row+1][col-2] = 'X';
						board[row][col] = board[row+1][col] = ' ';
					}
					else return false;
				}
			}
		}
		calcScore();
		return true;
	}

	bool Klotski::playRight(int row, int col){
		//Playing right indicated piece of the board
		row--; col--;
		if (col == 3) return false;
		else{
			char c = board[row][col];
			if (c == ' ') return false;
			if (c == 'A' || c == 'B' || c == 'C' || c == 'E'){
				//Playing vertical rectangles
				if (row > 0){
					if (board[row-1][col] == c){ 
						if (board[row][col+1] != ' ' || board[row-1][col+1] != ' ') return false;
						else { board[row][col+1] = board[row-1][col+1] = c; board[row][col] = board[row-1][col] = ' '; }
					}
				}
				if (row < 4){
					if (board[row+1][col] == c){
						if(board[row][col+1] != ' ' || board[row+1][col+1] != ' ') return false;
						else{ board[row][col+1] = board[row+1][col+1] = c; board[row][col] = board[row+1][col] = ' '; }
					}
				}				
			}
			else if (c == 'D'){
				//Playing horizontal rectangle
				if (board[row][col+1] == 'D'){
					if (col > 1) return false;
					else if (board[row][col+2] != ' ') return false;
					else{
						board[row][col+2] = 'D';
						board[row][col] = ' ';
					}
				}
				else{
					if (board[row][col+1] != ' ') return false;
					else{
						board[row][col+1] = 'D';
						board[row][col-1] = ' ';
					}
				}
			}
			else if (c == 'H' || c == 'F' || c == 'G' || c == 'I'){
				//Playing one squares
				if (board[row][col+1] != ' ') return false;
				else {board[row][col+1] = c; board[row][col] = ' ';}
			}
			else if (c == 'X'){
				//Playing the X square
				//We need to control specified row and column's place
				//Then play according to that coordinates
				if (row > 0){
					if (board[row][col+1] == 'X'){
						if (col > 1) return false;
						if (board[row-1][col] == 'X'){				
							if (board[row][col+2] != ' ' || board[row-1][col+2] != ' ') return false;
							else{
								board[row][col+2] = board[row-1][col+2] = 'X';
								board[row][col] = board[row-1][col] = ' ';
	 						}
						}
						else if (board[row+1][col+2] == ' ' && board[row][col+2] == ' '){
							board[row+1][col+2] = board[row][col+2] = 'X';
							board[row+1][col] = board[row][col] = ' ';
						}
						else return false;
					}
					else{
						if (board[row-1][col] == 'X'){				
							if (board[row][col+1] != ' ' || board[row-1][col+1] != ' ') return false;
							else{
								board[row][col+1] = board[row-1][col+1] = 'X';
								board[row-1][col-1] = board[row][col-1] = ' ';
	 						}
						}
						else if (board[row+1][col+1] == ' ' && board[row][col+1] == ' '){
							board[row+1][col+1] = board[row][col+1] = 'X';
							board[row+1][col-1] = board[row][col-1] = ' ';
						}
						else return false;
					}
				}
				if (row == 0){
					if (board[row][col+1] == 'X'){
						if (col > 1) return false;
						if (board[row+1][col+2] != ' ' || board[row][col+2] != ' ') return false;
						else {
							board[row+1][col+2] = board[row][col+2] = 'X';
							board[row+1][col] = board[row][col] = ' ';
						}
					}
					else if (board[row][col-1] == 'X'){
						if (board[row+1][col+1] != ' ' || board[row][col+1] != ' ') return false;
						else {
							board[row+1][col+1] = board[row][col+1] = 'X';
							board[row+1][col-1] = board[row][col-1] = ' ';
						}
					}
				}
			}
		}
		calcScore();
		return true;
	}
}