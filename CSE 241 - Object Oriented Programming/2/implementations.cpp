/***
 ***	MERT GURSIMSIR 1901042646
***/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "headers.h"
using namespace std;

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

void print_board(const vector <vector<Cells>>& board, int row, int col){
	string columns, text = "a b c d e f g h i j k l m n o p q r s t u v w x y z ";	//letters for columns
	for (int i = 0; i < col*2; i+=2)
		columns.append(text, i, 2);	//append letters to columns string in number of column at the board
	cout << "  " << columns << endl;
	for (int i = 0; i < row; ++i){
		cout << i+1 << " ";
		for (int j = 0; j < col; ++j)
			if (board[i][j] == Cells::peg)			//Printing P if the slot has a peg
				cout << "P ";
			else if (board[i][j] == Cells::empty)	//Printing . if the slot is empty
				cout << ". ";
			else if (board[i][j] == Cells::none)	//Printing a space if we are not in slot
				cout << "  ";
		cout << endl;
	}
}

void create_board(vector <vector<Cells>>& board, int row, int col){
	//Creating 2D vector with resizing every element
	board.resize(row);
	for (int i = 0; i < row; ++i)
		board[i].resize(col);
}

bool load_file(string name, vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp){
	fstream load;
	string pass, doc_type;
	char c;

	load.open(name);
	if (!load) return false;	//returning false if file does not exist

	load >> doc_type;			//reading doc_type
	if (doc_type != "Arbitrary" && doc_type != "Saved") return false;	//if file is not one of the saved files, function returns false
	load >> pass >> row;		//reading row number (Rows: ...)
	load >> pass >> col;		//reading column number (Columns: ...)
	create_board(board, row, col);

	//reading board
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j){
			load >> c;
			if (c == '_') board[i][j] = Cells::none;
			else if (c == 'P') board[i][j] = Cells::peg;
			else if (c == '.') board[i][j] = Cells::empty;
		}
	
	if (doc_type == "Saved"){	//reading extra informations if the file is saved before
		is_saved = true;		
		load >> pass;	//reading ("HumanOrCOmputer:")
		load >> pass;	//reading ("Human" or "Computer")
		if (pass == "Human") is_comp = false;
		else is_comp = true;
		load >> pass;	//reading ("NumberOfMoves")
		load >> pass;	//reading number of moves have been made in the last play
		print_board(board, row, col);
		if (is_comp) cout << "This is a computer game.\n" << pass << " moves have been played last time.\nGame continues from where you left.\n\n";
		else cout << "This is a human game.\n" << pass << " moves have been played last time.\nGame continues from where you left.\n\n";
	}
	else is_saved = false;
	load.close();
	return true;
}

void comp_or_human(vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp, bool flag){
	string input;
	do{
		flag = false;
		cout << "\nIs this a human player game or a computer game?\n(1 for human player game, 2 for computer game): ";
		cin >> input;
		if (input == "LOAD"){
			cin >> input;
			if (!load_file(input, board, row, col, is_saved, is_comp)){	//loading file if the command is "LOAD" and file does exist
				cerr << "There is no such file, please try again.";
				flag = true;
			}
			else{	//Don't ask the question again if the game is saved because saved game already has that information
				if (is_saved) flag = false;
				else flag = true;
			}
		}
		else if (input == "SAVE"){	//Don't save because game hasn't started
			cin >> input;
			cerr << "Game hasn't started yet, please try again.";
			flag = true;
		}
		else if (input == "1") is_comp = false;
		else if (input == "2") is_comp = true;
		else{
			cerr << "You have entered invalid input, please try again.";
			flag = true;
		}
	}while(flag);
}

bool is_pyramid(const vector <vector <Cells>> board, const int row, const int col){
	//Check the pegs' places for the determine that game is pyramid or not
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j] == Cells::peg){
				if (board[i+1][j] == Cells::none) return true;
				else return false;
			}
	return false;
}

void save_file(string name, const vector <vector <Cells>> board, int row, int col, int num_of_moves,bool is_comp){
	fstream save;
	save.open(name, fstream::out);
	//saving the file type (arbitrary or saved), row number and column number
	save << "Saved" << endl
		 << "Rows: " << row << endl
		 << "Columns: " << col << endl;
	//saving the board
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			if (board[i][j] == Cells::peg) save << "P";
			else if (board[i][j] == Cells::empty) save << ".";
			else save << "_";
		}
		save << endl;
	}
	//saving the information that tells if the game is computer or human game
	save << "HumanOrComputer: ";
	if (is_comp) save << "Computer\n";
	else save << "Human\n";
	//saving number of moves that has been done in last game
	save << "NumberOfMoves: " << num_of_moves << endl;
	for (int i = 0; i < 20; ++i) save << "      ";	//printing spaces to delete if anything left in the file from previous saves
	save.close();
}

bool is_valid_up(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol){
	bool flag = true;
	if (userRow <= 1 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow-1][userCol] != Cells::peg || board[userRow][userCol] != Cells::peg) flag = false;	//move isn't valid if the current slot or one up slot do not have peg
	else if (board[userRow-2][userCol] != Cells::empty) flag = false;	//move isn't valid if two up slot is not empty
	return flag;
}

bool is_valid_down(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol){
	bool flag = true;
	if (userRow < 0 || userRow >= row-2) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow+1][userCol] != Cells::peg || board[userRow][userCol]!=Cells::peg) flag = false;	//move isn't valid if the current slot or one down slot do not have peg
	else if (board[userRow+2][userCol] != Cells::empty) flag = false;	//move isn't valid if two down slot is not empty
	return flag;
}

bool is_valid_right(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol){
	bool flag = true;
	if (userCol >= col-2 || userRow < 0 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow][userCol+1] != Cells::peg || board[userRow][userCol]!=Cells::peg) flag = false;	//move isn't valid if the current slot or one right slot do not have peg
	else if (board[userRow][userCol+2] != Cells::empty) flag = false;	//move isn't valid if two right slot is not empty
	return flag;
}

bool is_valid_left(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol){
	bool flag = true;
	if (userCol <= 1 || userRow < 0 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow][userCol-1] != Cells::peg || board[userRow][userCol] != Cells::peg) flag = false;	//move isn't valid if the current slot or one left slot do not have peg
	else if (board[userRow][userCol-2] != Cells::empty) flag = false;	//move isn't valid if two left slot is not empty
	return flag;
}

bool is_there_up(const vector <vector<Cells>> board, int row, int col){
	//checking the pieces of board if there are any valid up movement left
	for (int i = 2; i < row; ++i)
		for(int j = 0; j < col; ++j)
			if (is_valid_up(board, row, col, i, j)) return true;
	return false;
}

bool is_there_down(const vector <vector<Cells>> board, int row, int col){
	//checking the pieces of board if there are any valid down movement left
	for (int i = 0; i < row-2; ++i)
		for(int j = 0; j < col; ++j)
			if (is_valid_down(board,row, col,i,j)) return true;
	return false;
}

bool is_there_right(const vector <vector<Cells>> board, int row, int col){
	//checking the pieces of board if there are any valid right movement left
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col-2; ++j)
			if (is_valid_right(board,row, col,i,j)) return true;
	return false;
}

bool is_there_left(const vector <vector<Cells>> board, int row, int col){
	//checking the pieces of board if there are any valid left movement left
	for (int i = 0; i < row; ++i)
		for (int j = 2; j < col; ++j)
			if (is_valid_left(board,row, col,i,j)) return true;
	return false;
}

bool is_finished(const vector <vector<Cells>> board, int row, int col){
	//checking every movement to make sure that there is no move left
	if (is_there_left(board, row, col) ||
		is_there_up(board, row, col) ||
		is_there_right(board,row, col) ||
		is_there_down(board,row, col))
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

bool is_there_ur(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid upside-right movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if(is_valid_upright(board,i,j)) return true;
	return false;
}

bool is_there_ul(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid upside-left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < 9; ++j)
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

bool is_there_left_b6(const vector <vector<Cells>> board){
	//checking the pieces of board if there are any valid left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < 9; ++j)
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

bool is_finished_pyramid(const vector <vector<Cells>> board){
	//checking every movement to make sure that there is no move left
	if (is_there_ur(board) ||
		is_there_ul(board) ||
		is_there_dr(board) ||
		is_there_dl(board) ||
		is_there_right_b6(board) ||
		is_there_left_b6(board))
		return false;
	else return true;
}

bool beginning(vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp){
	int computerCol, computerRow, computerDirection;
	string input, userCol, userRow, userDirection;
	auto num_of_moves = 0;
	auto finished = false;
	decltype(finished) pyramid, flag, move_played;

	pyramid = is_pyramid(board,row,col);	//checking if the board is pyramid
	if (!is_saved) comp_or_human(board, row, col, is_saved, is_comp, flag);

	print_board(board,row,col);
	if (is_comp){
		string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		if (pyramid){
			while (!finished){
				move_played = false;
				computerCol = rand() % col;		//random column from 0 to column number
				computerRow = rand() % row;		//random row from 0 to row
				computerDirection = rand() % 6;	//random direction from 0 to 6 (0 for up-right, 1 for up-left, 2 for down-right, 3 for down-left, 4 for left, 5 for right)
				switch (computerDirection){
					case 0: if (is_valid_upright(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_upright(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Upright.\n";
							}
							break;
					case 1: if (is_valid_upleft(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_upleft(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Upleft.\n";
							}
							break;
					case 2:	if (is_valid_downright(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_downright(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Downright.\n";
							}
							break;
					case 3: if (is_valid_downleft(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_downleft(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Downleft.\n";
							}
							break;
					case 4: if (is_valid_left_b6(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_left_b6(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Left.\n";
							}
							break;
					case 5: if (is_valid_right_b6(board,computerRow,computerCol)){	//Playing if direction and coordinate are okay
								move_played = true;
								move_right_b6(board,computerRow,computerCol);
								num_of_moves++;
								cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Right.\n";
							}
							break;
				}
				finished = is_finished_pyramid(board);
				if (move_played){
					print_board(board, row, col);
					if (!finished){
						do{
							flag = false;
							cout << "Type anything to continue or enter a command to save (SAVE) this game or load (LOAD) another game: ";
							cin >> input;
							if (input == "LOAD"){
								cin >> input;
								if (!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
									cerr << "There is no such file, please try again.\n";
									flag = true;
								}
								else return true;	//If we successfully load the game, beginning function will be called again from the main function
							}
							else if (input == "SAVE"){
								cin >> input;
								save_file(input, board, row, col, num_of_moves, is_comp);
								cout << "Thanks for playing, you can continue later where you left." << endl
									 << "So long!" << endl;
								return false;
								//Program is finished if the game saved
							}
						}while(flag);
					}
				}
			}
		}
		else{
			while(!finished){
				move_played = false;
				computerCol = rand() % col;		//random column from 0 to column number
				computerRow = rand() % row;		//random row from 0 to row
				computerDirection = rand() % 4;	//random direction from 0 to 4 (0 for up, 1 for down, 2 for right, 3 for left)
				switch (computerDirection){
							//making moves and printing them with the board
							case 0: if (is_valid_up(board, row, col, computerRow,computerCol)){	//Playing if direction and coordinate are okay
										move_played = true;
										move_up(board, computerRow, computerCol);
										num_of_moves++;
										cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Up.\n"; 
									} 
									break;
							case 1:	if (is_valid_down(board,row, col, computerRow,computerCol)){	//Playing if direction and coordinate are okay
										move_played = true;
										move_down(board, computerRow, computerCol);
										num_of_moves++;
										cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Down.\n"; 
									}
									break;
							case 2:	if (is_valid_right(board,row, col,computerRow,computerCol)){	//Playing if direction and coordinate are okay
										move_played = true;
										move_right(board, computerRow, computerCol);
										num_of_moves++;
										cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Right.\n";
									}
									break;
							case 3:	if (is_valid_left(board,row, col,computerRow,computerCol)){		//Playing if direction and coordinate are okay
										move_played = true;
										move_left(board, computerRow, computerCol);
										num_of_moves++;
										cout << "\nComputer played " << text[computerCol] << computerRow+1 << " - Left.\n";
									}
									break;
				}
				finished = is_finished(board, row, col);
				if (move_played){
					print_board(board, row, col);
					if(!finished){
						do{
							flag = false;
							cout << "Type anything to continue or enter a command to save (SAVE) this game or load (LOAD) another game: ";
							cin >> input;
							if (input == "LOAD"){	
								cin >> input;
								if (!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.	
									cerr << "There is no such file, please try again.\n";
									flag = true;
								}
								else return true;	//If we successfully load the game, beginning function will be called again from the main function
							}
							else if (input == "SAVE"){
								cin >> input;
								save_file(input, board, row, col, num_of_moves, is_comp);
								cout << "Thanks for playing, you can continue later where you left." << endl
									 << "So long!" << endl;
								return false;
								//Program is finished if the game saved
							}
						}while(flag);
					}
				}
			}
		}
	}
	else{
			while (!finished){
				//GETTING COLUMN LETTER
				do{
					flag = false;
					cout << "Enter the column with uppercase letter (Only first letter will be considered): ";
					cin >> userCol;
					if (userCol == "LOAD"){
						cin >> input;
						if(!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
							cerr << "There is no such file, please try again.\n";
							flag = true;
						}
						else return true;	//If we successfully load the game, beginning function will be called again from the main function
					}
					else if (userCol == "SAVE"){
						cin >> input;
						save_file(input, board, row, col, num_of_moves, is_comp);
						cout << "Thanks for playing, you can continue later where you left." << endl
							 << "So long!" << endl;
						return false;
						//Program is finished if the game saved
					}
					else if (userCol[0] < 65 || userCol[0] > 65+col-1){	//Controlling if user exceeds the limit of the board
						cerr << "Please enter valid coordinates.\n";
						flag = true;
					}
				}while(flag);
				//GETTING ROW NUMBER
				do{
					flag = false;
					cout << "Enter the row (from 1 to " << row << " | only 1 digit will be considered): ";
					cin >> userRow;
					if (userRow == "LOAD"){
						cin >> input;
						if(!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
							cerr << "There is no such file, please try again.\n";
							flag = true;
						}
						else return true;	//If we successfully load the game, beginning function will be called again from the main function
					}
					else if (userRow == "SAVE"){
						cin >> input;
						save_file(input, board, row, col, num_of_moves, is_comp);
						cout << "Thanks for playing, you can continue later where you left." << endl
							 << "So long!" << endl;
						return false;
						//Program is finished if the game saved
					}
					else if (userRow[0] < 49 || userRow[0] > 48+row){	//Controlling if user exceeds the limit of the board
						cerr << "Please enter valid coordinates.\n";
						flag = true;
					}				
				}while(flag);
				//GETTING THE DIRECTION
				do{
					flag = false;
					cout << "Enter the direction (U for up, D for down, R for right, L for left): ";
					cin >> userDirection;
					if (userDirection == "LOAD"){
						cin >> input;
						if(!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
							cerr << "There is no such file, please try again.\n";
							flag = true;
						}
						else return true;	//If we successfully load the game, beginning function will be called again from the main function
					}
					else if (userDirection == "SAVE"){
						cin >> input;
						save_file(input, board, row, col, num_of_moves, is_comp);
						cout << "Thanks for playing, you can continue later where you left." << endl
								<< "So long!" << endl;
						return false;
						//Program is finished if the game saved
					}
					else if (userDirection!="R" && userDirection!="L" && userDirection!="U" && userDirection!="D"){	//Controlling if user enters invalid direction
						cerr << "Please enter valid coordinates.\n";
						flag = true;
					}
				}while(flag);
				if (pyramid){
					if (userDirection == "R"){	//Playing if direction and coordinate are okay
						if (is_valid_right_b6(board,userRow[0]-49,userCol[0]-65)){
							move_right_b6(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}
					else if (userDirection == "L"){	//Playing if direction and coordinate are okay
						if (is_valid_left_b6(board,userRow[0]-49,userCol[0]-65)){
							move_left_b6(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}
					else if (userDirection == "U"){
						//Asking again if user wants to go Up-Right or Up-Left
						do{
							flag = false;
							cout << "Please enter 'R' if you want to go up-right or 'L' if you want to go up-left: ";
							cin >> userDirection;
							if (userDirection == "LOAD"){	
								cin >> input;
								if(!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
									cerr << "There is no such file, please try again.\n";
									flag = true;
								}
								else return true;	//If we successfully load the game, beginning function will be called again from the main function
							}
							else if (userDirection == "SAVE"){
								cin >> input;
								save_file(input, board, row, col, num_of_moves, is_comp);
								cout << "Thanks for playing, you can continue later where you left." << endl
									 << "So long!" << endl;
								return false;
								//Program is finished if the game saved
							}
							else if (userDirection == "R"){	
								if(is_valid_upright(board,userRow[0]-49,userCol[0]-65)){	//Moving up-right if move is valid
									move_upright(board,userRow[0]-49,userCol[0]-65);
									num_of_moves++;
								}
								else cerr << "Invalid coordinates, try again.\n";
							}
							else if (userDirection == "L"){
								if(is_valid_upleft(board,userRow[0]-49,userCol[0]-65)){		//Moving up-left if move is valid
									move_upleft(board,userRow[0]-49,userCol[0]-65);
									num_of_moves++;
								}
								else cerr << "Invalid coordinates, try again.\n";
							}
							else cerr << "Invalid input, try again.\n";
						}while(flag);
					}
					else if (userDirection == "D"){
						//Asking again if user wants to go Down-Right or Down-Left
						do{
							flag = false;
							cout << "Please enter 'R' if you want to go down-right or 'L' if you want to go down-left: ";
							cin >> userDirection;
							if (userDirection == "LOAD"){
								cin >> input;
								if(!load_file(input, board, row, col, is_saved, is_comp)){	//Loading the game file if the file exists.
									cerr << "There is no such file, please try again.\n";
									flag = true;
								}
								else return true;	//If we successfully load the game, beginning function will be called again from the main function
							}
							else if (userDirection == "SAVE"){
								cin >> input;
								save_file(input, board, row, col, num_of_moves, is_comp);
								cout << "Thanks for playing, you can continue later where you left." << endl
									 << "So long!" << endl;
								return false;
								//Program is finished if the game saved
							}
							else if (userDirection == "R"){
								if(is_valid_downright(board,userRow[0]-49,userCol[0]-65)){	//Moving down-right if move is valid
									move_downright(board,userRow[0]-49,userCol[0]-65);
									num_of_moves;
								}
								else cerr << "Invalid coordinates, try again.\n";
							}
							else if (userDirection == "L"){
								if(is_valid_downleft(board,userRow[0]-49,userCol[0]-65)){	//Moving down-left if move is valid
									move_downleft(board,userRow[0]-49,userCol[0]-65);
									num_of_moves++;
								}
								else cerr << "Invalid coordinates, try again.\n";
							}
							else cerr << "Invalid input, try again.\n";
						}while (flag);
					}
					finished = is_finished_pyramid(board);
				}
				//IF BOARD IS NOT PYRAMID
				else{
					if (userDirection == "U"){
						if (is_valid_up(board,row,col,userRow[0]-49, userCol[0]-65)){	//Playing up if the coordinate is valid
							move_up(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}
					if (userDirection == "D"){
						if (is_valid_down(board,row,col,userRow[0]-49, userCol[0]-65)){	//Playing down if the coordinate is valid
							move_down(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}
					if (userDirection == "R"){
						if (is_valid_right(board,row,col,userRow[0]-49, userCol[0]-65)){//Playing right if the coordinate is valid
							move_right(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}
					if (userDirection == "L"){
						if (is_valid_left(board,row,col,userRow[0]-49, userCol[0]-65)){	//Playing left if the coordinate is valid
							move_left(board, userRow[0]-49, userCol[0]-65);
							num_of_moves++;
						}
						else cerr << "Invalid coordinates, try again.\n";
					}			  
					finished = is_finished(board, row, col);
				}
				print_board(board, row, col);
			}
	}

	//Counting the number of pegs to determine the score
	int score = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j] == Cells::peg)++score;
	cout << "The game is finished!" << endl << score << " peg(s) left." << endl << "Goodbye!" << endl;
	return false;
}