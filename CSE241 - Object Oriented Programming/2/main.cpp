/***
 ***	MERT GURSIMSIR 1901042646
***/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>		//for rand function only, used in "beginning" function
#include "headers.h"
using namespace std;

int main(){
	vector <vector <Cells>> board, board1, board2, board3, board4, board5, board6, arb_board1, arb_board2, arb_board3;
	int row, col, arb_row_1, arb_col_1, arb_row_2, arb_col_2, arb_row_3, arb_col_3;
	string input, coordinates;
	bool flag, is_saved = false, is_comp = false;

	//CREATING AND FILLIND BOARDS WHICH ARE ALREADY GIVEN
	create_board(board1);			fill_board1(board1);
	create_board(board2, 9, 9);		fill_board2(board2);
	create_board(board3, 8, 8); 	fill_board3(board3);
	create_board(board4); 			fill_board4(board4);
	create_board(board5, 9, 9); 	fill_board5(board5);
	create_board(board6, 5, 9); 	fill_board6(board6);

	//LOADING ARBITRARY BOARD WHICH ARE CREATED BY CODER
	load_file("arbitrary1.txt", arb_board1, arb_row_1, arb_col_1, is_saved, is_comp);
	load_file("arbitrary2.txt", arb_board2, arb_row_2, arb_col_2, is_saved, is_comp);
	load_file("arbitrary3.txt", arb_board3, arb_row_3, arb_col_3, is_saved, is_comp);

	//ASKING FOR THE BOARD TYPE
	cout << "...WELCOME TO PEG SOLITAIRE..." << endl
		 << "------------------------------" << endl
		 << "First board:" << endl
		 << "------------" << endl;
	print_board(board1, 7, 7);
	cout << "\n\nSecond board:" << endl
		 << "-------------" << endl;
	print_board(board2, 9, 9);
	cout << "\n\nThird board:" << endl
		 << "------------" << endl;
	print_board(board3, 8, 8);
	cout << "\n\nFourth board:" << endl
		 << "-------------" << endl;
	print_board(board4, 7, 7);
	cout << "\n\nFifth board:" << endl
		 << "------------" << endl;
	print_board(board5, 9, 9);
	cout << "\n\nSixth board:" << endl
		 << "------------" << endl;
	print_board(board6, 5, 9);
	cout << "\n\nSeventh board (first arbitrary board):" << endl
		 << "--------------------------------------" << endl;
	print_board(arb_board1, arb_row_1, arb_col_1);
	cout << "\n\nEighth board (second arbitrary board):" << endl
		 << "-------------------------------------" << endl;
	print_board(arb_board2, arb_row_2, arb_col_2);
	cout << "\n\nNineth board (third arbitrary board):" << endl
		 << "--------------------------------------" << endl;
	print_board(arb_board3, arb_row_3, arb_col_3);
	cout << "\n\n******YOU CAN SAVE A GAME OR LOAD THE GAME AT ANY STEP WITH THE COMMANDS \"LOAD FILE.TXT\" AND \"SAVE FILE.TXT\"******";
	do{
		cout << "\nPlease choose the board type (from 1 to 9) or you can load any valid file with the command \"LOAD FILE.TXT\": ";
		cin >> input;
		flag = false;
		//assigning board variable to choosen board
		if (input == "1"){ 	   	board = board1; row = col = 7; }
		else if (input == "2"){	board = board2; row = col = 9; }
		else if (input == "3"){	board = board3; row = col = 8; }
		else if (input == "4"){	board = board4; row = col = 7; }
		else if (input == "5"){	board = board5; row = col = 9; }
		else if (input == "6"){	board = board6; row = 5; col = 9;}
		else if (input == "7"){	board = arb_board1; row = arb_row_1; col = arb_col_1; }
		else if (input == "8"){	board = arb_board2; row = arb_row_2; col = arb_col_2; }
		else if (input == "9"){	board = arb_board3; row = arb_row_3; col = arb_col_3; }
		else if (input == "LOAD"){ 
			cin >> input; //taking name of the file
			if (!load_file(input, board, row, col, is_saved, is_comp)){	//control if file exist and load it to board
				cerr << "There is no such a file, please try again.";
				flag = true;
			}
		}
		else if (input == "SAVE"){
			cin >> input;
			cerr << "There is no game to save yet, please try again.";
			flag = true;
		}
		else{
			flag = true;
			cerr << "You have entered invalid input, please try again.";
		}
	}while(flag);

	/*****************************************************************************/

	//CALLING THE FUNCTION THAT STARTS EVERYTHING WHILE IT RETURNS TRUE - WHEN WE LOAD A FILE, IT RETURNS TRUE
	while (beginning(board, row, col, is_saved, is_comp));

	return 0;
}