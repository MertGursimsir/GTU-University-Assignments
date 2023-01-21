/***
 ***	MERT GURSIMSIR 1901042646
***/
#include <iostream>
#include <vector>
#include <string>
#include "headers.h"
using namespace std;

void create_board(vector <vector<Cells>>& board, int size){
	//Creating 2D vector for the boards with resizing the board parameter
	board.resize(size);
	for(int i = 0; i < size; ++i)
		board[i].resize(size);
}

void create_board6(vector <vector<Cells>>& board){
	//Creating 2D vector for the pyramid with resizing the board parameter
	board.resize(5);
	for(int i = 0; i < 5; ++i)
		board[i].resize(9);
}

void fill_board1(vector <vector<Cells>>& board1){
	for (int i = 0; i < 7; ++i)
		switch (i){
			case 0:
			case 6: for (int j = 0; j < 7; ++j)
						switch(j){
							//filling gaps
							case 0:
							case 1:
							case 5:
							case 6: board1[i][j] = Cells::none;
									break;
							//placing pegs
							default: board1[i][j] = Cells::peg;
									 break;
						}
					break;
			case 1:
			case 5: for (int j = 0; j < 7; ++j)
						switch(j){
							//filling gaps
							case 0:
							case 6: board1[i][j] = Cells::none;
									break;
							//placing pegs
							default: board1[i][j] = Cells::peg;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 7; ++j)
						board1[i][j] = Cells::peg;
					 break;
		}
	//placing the empty slot
	board1[2][3] = Cells::empty;
}

void fill_board2(vector <vector<Cells>>& board2){
	for (int i = 0; i < 9; ++i)
		switch(i){
			case 0:
			case 1:
			case 2:
			case 6:
			case 7:
			case 8: for (int j = 0; j < 9; ++j)
						switch(j){
							//filling gaps
							case 0:
							case 1:
							case 2:
							case 6:
							case 7:
							case 8: board2[i][j] = Cells::none;
									break;
							//placing pegs
							default: board2[i][j] = Cells::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 9; ++j)
						board2[i][j] = Cells::peg;
					 break;
		}
	//placing the empty slot
	board2[4][4] = Cells::empty;
}

void fill_board3(vector <vector<Cells>>& board3){
	for (int i = 0; i < 8; ++i)
		switch(i){
			case 0:
			case 1:
			case 2:
			case 6:
			case 7: for(int j = 0; j < 8; ++j)
						switch(j){
							//filling the gaps
							case 0:
							case 1:
							case 5:
							case 6:
							case 7: board3[i][j] = Cells::none;
									break;
							//placing pegs
							default: board3[i][j] = Cells::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 8; ++j)
						board3[i][j] = Cells::peg;
					 break;
		}
	//placing the empty slot
	board3[4][3] = Cells::empty;
}

void fill_board4(vector <vector<Cells>>& board4){
	for(int i = 0; i < 7; ++i)
		switch (i){
			case 0: 
			case 1:
			case 5:
			case 6: for(int j = 0; j < 7; ++j)
						switch (j){
							//filling the gaps
							case 0:
							case 1:
							case 5:
							case 6: board4[i][j] = Cells::none;
									break;
							//placing pegs
							default: board4[i][j] = Cells::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 7; ++j)
						board4[i][j] = Cells::peg;
					 break;
		}
	//placing the empty slot
	board4[3][3] = Cells::empty;
}

void fill_board5(vector <vector<Cells>>& board5){
	for(int i = 0; i < 9; ++i)
		switch(i){
			//placing pegs and filling the gaps in proper coordinates
			case 0:
			case 8: for(int j = 0; j < 9; ++j)
						if (j == 4) board5[i][j] = Cells::peg;
						else board5[i][j] = Cells::none;
					break;
			case 1:
			case 7: for(int j = 0; j < 9; ++j)
						if (j==3 || j==4 || j==5) board5[i][j] = Cells::peg;
						else board5[i][j] = Cells::none;
					break;
			case 2: 
			case 6: for(int j = 0; j < 9; ++j)
						if (j==0 || j==1 || j==7 || j==8) board5[i][j] = Cells::none;
						else board5[i][j] = Cells::peg;
					break;
			case 3: 
			case 5: for(int j = 0; j < 9; ++j)
						if (j==0 || j==8) board5[i][j] = Cells::none;
						else board5[i][j] = Cells::peg;
					break;
			default: for(int j = 0; j < 9; ++j)
						board5[i][j] = Cells::peg;
					 break;
		}
	//placing the empty slot
	board5[4][4] = Cells::empty;
}

void fill_board6(vector <vector<Cells>>& board6){
	for (int i = 0; i < 5; ++i)
			switch(i){
				case 0: //filling first row
						for (int j = 0; j < 9; ++j)
							if (j == 4) board6[i][j] = Cells::empty;
							else board6[i][j] = Cells::none;
						break;
				case 1: //filling second row
						for (int j = 0; j < 9; ++j)
							if (j==3 || j==5) board6[i][j] = Cells::peg;
							else board6[i][j] = Cells::none;
						break;
				case 2: //filling third row
						for (int j = 0; j < 9; ++j)
							if (j==2||j==4||j==6) board6[i][j] = Cells::peg;
							else board6[i][j] = Cells::none;
						break;
				case 3: //filling fourth row
						for (int j = 0; j < 9; ++j)
							if (j%2 == 0) board6[i][j] = Cells::none;
							else board6[i][j] = Cells::peg;
						break;
				case 4: //filling fifth row
						for (int j = 0; j < 9; ++j)
							if (j%2 == 0) board6[i][j] = Cells::peg;
							else board6[i][j] = Cells::none;
						break;
			}
}		

void print_board(vector <vector<Cells>> board, int size){
	string text = "a b c d e f g ";			//column text with the length of minimum number of columns which is 7
	if (size == 8) text.append("h ");		//column text will be appended if number of column is 8
	else if (size == 9) text.append("h i");	//column text will be appended if number of column is 9
	cout << "  " << text << endl;			//printing column text

	//printing the board and numbers for row
	for (int i = 0; i < size; ++i){
		cout << i+1 << " ";
		for (int j = 0; j<size; ++j)
			if (board[i][j] == Cells::peg)
				cout << "P ";
			else if (board[i][j] == Cells::empty)
				cout << ". ";
			else if (board[i][j] == Cells::none)
				cout << "  ";
		cout << endl;
	}
}

void print_board6(vector <vector<Cells>> board){
	cout << "  " << "a b c d e f g h i" << endl;	//column text

	//printing the board and numbers for row
	for (int i = 0; i < 5; ++i){
		cout << i+1 << " ";
		for (int j = 0; j<9; ++j)
			if (board[i][j] == Cells::peg)
				cout << "P ";
			else if (board[i][j] == Cells::empty)
				cout << ". ";
			else if (board[i][j] == Cells::none)
				cout << "  ";
		cout << endl;
	}
}

bool is_valid_up(const vector <vector<Cells>> board, int size, int row, int col){
	bool flag = true;
	if (row <= 1 || row >= size) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[row-1][col] != Cells::peg || board[row][col] != Cells::peg) flag = false;	//move isn't valid if the current slot or one up slot do not have peg
	else if (board[row-2][col] != Cells::empty) flag = false;	//move isn't valid if two up slot is not empty
	return flag;
}

bool is_valid_down(const vector <vector<Cells>> board, int size, int row, int col){
	bool flag = true;
	if (row < 0 || row >= size-2) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[row+1][col] != Cells::peg || board[row][col]!=Cells::peg) flag = false;	//move isn't valid if the current slot or one down slot do not have peg
	else if (board[row+2][col] != Cells::empty) flag = false;	//move isn't valid if two down slot is not empty
	return flag;
}

bool is_valid_right(const vector <vector<Cells>> board, int size, int row, int col){
	bool flag = true;
	if (col >= size-2 || row < 0 || row >= size) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[row][col+1] != Cells::peg || board[row][col]!=Cells::peg) flag = false;	//move isn't valid if the current slot or one right slot do not have peg
	else if (board[row][col+2] != Cells::empty) flag = false;	//move isn't valid if two right slot is not empty
	return flag;
}

bool is_valid_left(const vector <vector<Cells>> board, int size, int row, int col){
	bool flag = true;
	if (col <= 1 || row < 0 || row >= size) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[row][col-1] != Cells::peg || board[row][col] != Cells::peg) flag = false;	//move isn't valid if the current slot or one left slot do not have peg
	else if (board[row][col-2] != Cells::empty) flag = false;	//move isn't valid if two left slot is not empty
	return flag;
}

bool is_there_up(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid up movement left
	for (int i = 2; i < size; ++i)
		for(int j = 0; j < size; ++j)
			if (is_valid_up(board, size, i, j)) return true;
	return false;
}

bool is_there_down(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid down movement left
	for (int i = 0; i < size-2; ++i)
		for(int j = 0; j < size; ++j)
			if (is_valid_down(board,size,i,j)) return true;
	return false;
}

bool is_there_right(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid right movement left
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size-2; ++j)
			if (is_valid_right(board,size,i,j)) return true;
	return false;
}

bool is_there_left(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid left movement left
	for (int i = 0; i < size; ++i)
		for (int j = 2; j < size; ++j)
			if (is_valid_left(board,size,i,j)) return true;
	return false;
}

bool is_finished(const vector <vector<Cells>> board, int size){
	//checking every movement to make sure that there is no move left
	if (is_there_left(board, size) ||
		is_there_up(board, size) ||
		is_there_right(board,size) ||
		is_there_down(board,size))
		return false;
	else return true;
}

void move_up(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row-1][col] = Cells::empty;	//making the 1 up coordinate empty
	board[row-2][col] = Cells::peg;		//placing the peg to 2 up coordinate 
}

void move_down(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row+1][col] = Cells::empty;	//making the 1 down coordinate empty
	board[row+2][col] = Cells::peg;		//placing the peg to 2 down coordinate
}

void move_right(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row][col+1] = Cells::empty;	//making the 1 right coordinate empty
	board[row][col+2] = Cells::peg; 	//placing the peg to 2 right coordinate
}

void move_left(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row][col-1] = Cells::empty;	//making the 1 left coordinate empty
	board[row][col-2] = Cells::peg;		//placing the peg to 2 left coordinate
}

bool is_valid_upright(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row <= 1 || row > 4 || col >= 5 || (row == 2 && col == 4) ) flag = false;				//move isn't valid if coordinate is not proper
	else if (board[row][col] != Cells::peg || board[row-1][col+1] != Cells::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row-2][col+2] != Cells::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool is_valid_upleft(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row <= 1 || row > 4 || col < 4 || (row == 2 && col == 4)) flag = false;					//move isn't valid if coordinate is not proper
	else if (board[row][col] != Cells::peg || board[row-1][col-1] != Cells::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row-2][col-2] != Cells::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool is_valid_downright(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row > 2 || row < 0) flag = false;														//move isn't valid if coordinate is not proper
	else if (board[row][col] != Cells::peg || board[row+1][col+1] != Cells::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row+2][col+2] != Cells::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool is_valid_downleft(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row > 2 || row < 0) flag = false;														//move isn't valid if coordinate is not proper
	else if (board[row][col] != Cells::peg || board[row+1][col-1] != Cells::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row+2][col-2] != Cells::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool is_valid_left_b6(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row < 2 || row > 4 || col < 4) flag = false;											//move isn't valid if coordinate is not proper
	else if (board[row][col-2] != Cells::peg || board[row][col] != Cells::peg) flag = false;	//move isn't valid if the current slot or one left slot do not have peg
	else if (board[row][col-4] != Cells::empty) flag = false;									//move isn't valid if two left slot is not empty
	return flag;
}

bool is_valid_right_b6(const vector <vector<Cells>> board, int row, int col){
	bool flag = true;
	if (row < 2 || row > 4 || col > 4) flag = false;										//move isn't valid if coordinate is not proper
	else if (board[row][col+2] != Cells::peg || board[row][col]!=Cells::peg) flag = false;	//move isn't valid if the current slot or one right slot do not have peg
	else if (board[row][col+4] != Cells::empty) flag = false;								//move isn't valid if two right slot is not empty
	return flag;
}

void move_upright(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row-1][col+1] = Cells::empty;	//making the cross coordinate empty
	board[row-2][col+2] = Cells::peg;	//placing the peg
}

void move_upleft(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row-1][col-1] = Cells::empty;	//making the cross coordinate empty
	board[row-2][col-2] = Cells::peg;	//placing the peg
}

void move_downright(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row+1][col+1] = Cells::empty;	//making the cross coordinate empty
	board[row+2][col+2] = Cells::peg;	//placing the peg
}

void move_downleft(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row+1][col-1] = Cells::empty;	//making the cross coordinate empty
	board[row+2][col-2] = Cells::peg;	//placing the peg
}

void move_right_b6(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row][col+2] = Cells::empty;	//making the 1 right coordinate empty
	board[row][col+4] = Cells::peg; 	//placing the peg to 2 right coordinate
}

void move_left_b6(vector <vector<Cells>>& board, int row, int col){
	board[row][col] = Cells::empty;		//making the current coordinate empty
	board[row][col-2] = Cells::empty;	//making the 1 left coordinate empty
	board[row][col-4] = Cells::peg;		//placing the peg to 2 left coordinate
}

bool is_there_ur(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid upside-right movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if(is_valid_upright(board,i,j)) return true;
	return false;
}

bool is_there_ul(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid upside-left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < size; ++j)
			if(is_valid_upleft(board,i,j)) return true;
	return false;
}

bool is_there_dr(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid down-right movement left
	for (int i = 0; i < 3; ++i)
		for (int j = 2; j < 7; ++j)
			if(is_valid_downright(board,i,j)) return true;
	return false;
}

bool is_there_dl(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid down-left movement left
	for (int i = 0; i < 3; ++i)
		for (int j = 2; j < 7; ++j)
			if(is_valid_downleft(board,i,j)) return true;
	return false;
}

bool is_there_left_b6(const vector <vector<Cells>> board, int size){
	//checking the pieces of board if there are any valid left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < size; ++j)
			if(is_valid_left_b6(board,i,j)) return true;
	return false;
}

bool is_there_right_b6(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid right movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if(is_valid_right_b6(board,i,j)) return true;
	return false;
}

bool is_finished_b6(const vector <vector<Cells>> board, int size){
	//checking every movement to make sure that there is no move left
	if (is_there_ur(board, size) ||
		is_there_ul(board, size) ||
		is_there_dr(board) ||
		is_there_dl(board) ||
		is_there_right_b6(board) ||
		is_there_left_b6(board,size))
		return false;
	else return true;
}