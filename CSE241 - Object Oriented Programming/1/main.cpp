/***
 ***	MERT GURSIMSIR 1901042646
***/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>	//only for random numbers, for rand function
#include "headers.h"
using namespace std;

int main(){
	//CREATING AND FILLING THE BOARDS
	vector <vector<Cells>> board, board1, board2, board3, board4, board5, board6;
	create_board(board1, 7);	fill_board1(board1);
	create_board(board2, 9);	fill_board2(board2);
	create_board(board3, 8);	fill_board3(board3);
	create_board(board4, 7);	fill_board4(board4);
	create_board(board5, 9);	fill_board5(board5);
	create_board6(board6);		fill_board6(board6);

	/*****************************************************************************/

	int board_type, row, col, game_type, size, computer_direction;
	bool flag;
	char column, direction, cross_direction;

	//ASKING FOR THE BOARD TYPE
	cout << "...WELCOME TO PEG SOLITAIRE..." << endl
		 << "------------------------------" << endl
		 << "First board:" << endl
		 << "------------" << endl;
	print_board(board1, 7);
	cout << "\n\nSecond board:" << endl
		 << "-------------" << endl;
	print_board(board2, 9);
	cout << "\n\nThird board:" << endl
		 << "------------" << endl;
	print_board(board3, 8);
	cout << "\n\nFourth board:" << endl
		 << "-------------" << endl;
	print_board(board4, 7);
	cout << "\n\nFifth board:" << endl
		 << "------------" << endl;
	print_board(board5, 9);
	cout << "\n\nSixth board:" << endl
		 << "------------" << endl;
	print_board6(board6);
	do{
		flag = true;
		cout << "\nPlease choose the board type (from 1 to 6): ";
		cin >> board_type;
		//Assigning choosen board to the variable "board" and changing the size conveniently
		switch (board_type){
			case 1: board = board1; size = 7; break;
			case 2: board = board2; size = 9; break;
			case 3: board = board3; size = 8; break;
			case 4: board = board4; size = 7; break;
			case 5: board = board5; size = 9; break;
			case 6: board = board6; size = 9; break;
			default: flag = false;
					 cout << "Please choose from 1 to 6." << endl;
					 break;
		}
	}while(!flag);

	/*****************************************************************************/

	//ASKING FOR THE GAME TYPE
	do{
		cout << "Is this a human player game or a computer game?\n(1 for human player game, 2 for computer game): ";
		cin >> game_type;
	}while(game_type!=1&&game_type!=2);

	/*****************************************************************************/
	flag = false;
	if (board_type != 6) print_board(board,size);
	else print_board6(board);
	switch (game_type){
		//HUMAN PLAYER GAME
		case 1:	while(!flag){	//continue until there are no move left
					//getting column info and assign proper number for indexing
					cout << "Enter column (just 1 letter): ";
					cin >> column;
					switch (column){
						case 'A': 
						case 'a': col=0; break;
						case 'B': 
						case 'b': col=1; break;
						case 'C':
						case 'c': col=2; break;
						case 'D':
						case 'd': col=3; break;
						case 'E':
						case 'e': col=4; break;
						case 'F':
						case 'f': col=5; break;
						case 'G':
						case 'g': col=6; break;
						case 'H':
						case 'h': col=7; break;
						case 'I':
						case 'i': col=8; break;
						default:col = -1;
					}
					if (col == -1 || col >= size) cout<<"You have entered invalid column. Try again.\n";
					else{
						//getting row number
						cout << "Enter row number: ";
						cin >> row;	--row;
						//getting the direction
						cout << "Enter direction (U for up, D for down, L for left, R for right): ";
						cin >> direction;
						if (board_type != 6){
							//implement the move if it is valid for the boards 1, 2, 3, 4, OR 5
							switch (direction){
								case 'U': 
								case 'u': if (is_valid_up(board,size,row,col)) move_up(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								case 'D': 
								case 'd': if (is_valid_down(board,size,row,col)) move_down(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								case 'R': 
								case 'r': if (is_valid_right(board,size,row,col)) move_right(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								case 'L': 
								case 'l': if (is_valid_left(board,size,row,col)) move_left(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								default: cout << "Please enter proper direction." << endl;
							}
							print_board(board,size);
						}
						else{
							//implement the move if it is valid for the board 6
							switch(direction){
								case 'U': //asking again if user wants to go up-right or up-left
								case 'u': cout << "Please enter 'R' if you want to go up-right or 'L' if you want to go up-left: ";
										  cin >> cross_direction;
										  switch (cross_direction){
										  	case 'R':
										  	case 'r': if(is_valid_upright(board,row,col)) move_upright(board,row,col);
										  			  else cout << "Invalid coordinates, try again.\n";
										  			  break;
										  	case 'L':
										  	case 'l': if(is_valid_upleft(board,row,col)) move_upleft(board,row,col);
										  			  else cout << "Invalid coordinates, try again.\n";
										  			  break;
										  	default: cout << "Please enter proper direction." << endl;
										  }
										  break;
								case 'D': //asking again if user wants to go down-right or down-left
								case 'd': cout << "Please enter 'R' if you want to go down-right or 'L' if you want to go down-left: ";
										  cin >> cross_direction;
										  switch (cross_direction){
										  	case 'R':
										  	case 'r': if(is_valid_downright(board,row,col)) move_downright(board,row,col);
										  			  else cout << "Invalid coordinates, try again.\n";
										  			  break;
										  	case 'L':
										  	case 'l': if(is_valid_downleft(board,row,col)) move_downleft(board,row,col);
										  			  else cout << "Invalid coordinates, try again.\n";
										  			  break;
										  	default: cout << "Please enter proper direction." << endl;
										  }
										  break;
								case 'R': 
								case 'r': if (is_valid_right_b6(board,row,col)) move_right_b6(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								case 'L': 
								case 'l': if (is_valid_left_b6(board,row,col)) move_left_b6(board, row, col);
										  else cout << "Invalid coordinates, try again.\n";
										  break;
								default: cout << "Please enter proper direction." << endl;
							}
							print_board6(board);
						}
					}
					//checking if the game has finished
					if (board_type == 6) flag = is_finished_b6(board, size);
					else flag = is_finished(board, size);
				}
				break;

		/*****************************************************************************/

		//COMPUTER GAME
		case 2: string text = "ABCDEFGHI";	//text to identify the column
				flag = false;
				while (!flag){	//continue until there are no move left
					if (board_type!=6){
						//COMPUTER PLAY FOR BOARDS 1, 2, 3, 4, OR 5
						col = rand() % size;	//random column from 0 to size
						row = rand() % size;	//random row from 0 to size
						computer_direction = rand() % 4;	//random direction from 0 to 4 (0 for up, 1 for down, 2 for right, 3 for left)
						switch (computer_direction){
							//making moves and printing them with the board
							case 0: if (is_valid_up(board,size,row,col)){
										move_up(board, row, col);
										cout << "\nComputer played " << text[col] << row+1 << " - Up.\n"; 
										print_board(board,size);
									} 
									break;
							case 1:	if (is_valid_down(board,size,row,col)){
										move_down(board, row, col);
										cout << "\nComputer played " << text[col] << row+1 << " - Down.\n"; 
										print_board(board,size);
									}
									break;
							case 2:	if (is_valid_right(board,size,row,col)){
										move_right(board, row, col);
										cout << "\nComputer played " << text[col] << row+1 << " - Right.\n";
										print_board(board,size);
									}
									break;
							case 3:	if (is_valid_left(board,size,row,col)){
										move_left(board, row, col);
										cout << "\nComputer played " << text[col] << row+1 << " - Left.\n";
										print_board(board,size);
									}
									break;
						}
					}
					else{
						//COMPUTER PLAY FOR BOARD 6
						col = rand() % size;		//random column from 0 to size
						row = rand() % (size/2 + 1);//random column from 0 to 5
						computer_direction = rand() % 6; //random direction from 0 to 6 (0 for up-right, 1 for up-left, 2 for down-right, 3 for down-left, 4 for left, 5 for right)
						switch(computer_direction){
							//making moves and printing them with the board
							case 0: if (is_valid_upright(board,row,col)){
										move_upright(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Upright.\n";
										print_board6(board);
									}
									break;
							case 1:	if (is_valid_upleft(board,row,col)){
										move_upleft(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Upleft.\n";
										print_board6(board);
									}
									break;
							case 2:	if (is_valid_downright(board,row,col)){
										move_downright(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Downright.\n";
										print_board6(board);
									}
									break;
							case 3:	if (is_valid_downleft(board,row,col)){
										move_downleft(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Downleft.\n";
										print_board6(board);
									}
									break;
							case 4:	if (is_valid_left_b6(board,row,col)){
										move_left_b6(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Left.\n";
										print_board6(board);
									}
									break;
							case 5:	if (is_valid_right_b6(board,row,col)){
										move_right_b6(board,row,col);
										cout << "\nComputer played " << text[col] << row+1 << " - Right.\n";
										print_board6(board);
									}
									break;
						}
					}
					//checking if the game has finished
					if (board_type == 6) flag = is_finished_b6(board, size);
					else flag = is_finished(board, size);
				}
				break;				
	}

	/*****************************************************************************/

	//CALCULATING THE SCORE
	int score = 0;
	if (board_type != 6){	//calculating for boards 1, 2, 3, 4, and 5
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				if (board[i][j] == Cells::peg) ++score;	//increment the score when we see the peg
	}
	else{	//calculating for board 6
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < size; ++j)
				if (board[i][j] == Cells::peg) ++score;	//increment the score when we see the peg
	}
	cout << endl << score << " pegs left.\nGoodbye!\n";

	return 0;
}