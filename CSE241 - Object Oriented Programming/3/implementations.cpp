#include "headers.h"

inline void inCell::setRow(int rowValue) {row = rowValue;}
inline void inCell::setCol(int colValue) {column = colValue;}
inline void inCell::setSt(State stateValue) {state = stateValue;}
inline int inCell::getCol() const {return column;}
inline int inCell::getRow() const {return row;}
inline State inCell::getSt() const {return state;}

int PegSolitaire::totalPegs = 0;
int PegSolitaire::activeGames = 0;
int PegSolitaire::allGames = 0;

inCell::Cell(int rowValue, int colValue) : row(rowValue), column(colValue){ /* Body intentionally empty*/}

inCell::Cell(){
	row = 0;
	column = 'a';
	state = State::empty;
}

void PegSolitaire::checkInput(){
	//Checking if we get the correct type
	if (cin.fail()){
		cin.clear();
		cin.ignore(57,'\n');
	}
}

void PegSolitaire::beginning(){
	vector <PegSolitaire> games;
	int selection, secondSelection, otherSelection;
	int numberOfPegs = 0;
	bool isPyramid;
	string input;
	
	while (true){
		cout << "\n\nMenu:\n";
		cout << "1 - Start the game." << endl;
		cout << "2 - Load the game." << endl;
		cout << "3 - See active games and choose one of them." << endl;
		cout << "4 - Show number of pegs for all active games." << endl;
		cout << "5 - Compare 2 active games." << endl;
		cout << "6 - Exit." << endl;
		cout << "Enter your choice: ";
		cin >> selection;
		PegSolitaire::checkInput();
		switch(selection){
			//Adding new board to the games vector 
			case 1: games.push_back(PegSolitaire()); break;
			
			//Adding new board from the file to the games vector
			case 2: cout << "Type the file name: ";
					cin >> input;
					games.push_back(PegSolitaire(input)); 
					if (games[games.size()-1].gameType == 'E') games.pop_back();
					break;

			//Listing active games and make the user choose whichever (s)he wants
			case 3: if (games.size() == 0) cerr << "There are no active games.";
					else{
						cout << "There are " << games.size() << " active games.\n";
						for (int i =0; i < games.size(); ++i){
							cout << "Game[" << i+1<<"]\n";
						}
						cout << "Choose one of them with number: ";
						cin >> secondSelection;
						PegSolitaire::checkInput();
						if (secondSelection <= 0 || secondSelection > games.size()) cerr << "Invalid input.\n";
						else {
							games[secondSelection-1].gameType = 'A';
							if (games[secondSelection-1].compOrHuman == 1) games[secondSelection-1].userPlay();
							else if (games[secondSelection-1].compOrHuman == 2)  games[secondSelection-1].playGame();
						}
					}
					break;

			//Adding all the active games' number of pegs and show it to user
			case 4: for (int i=0; i < games.size(); ++i){
						if (games[i].board[0][3].state == State::none && games[i].board[0][5].state == State::none && games[i].board[0][4].state == State::peg) isPyramid = true;
						if (isPyramid) numberOfPegs += games[i].numOfPegs(5, 9);
						else numberOfPegs += games[i].numOfPegs(games[i].side, games[i].side);
					}
					PegSolitaire::totalPegs = numberOfPegs;
					numberOfPegs = totalPegsAllBoards();
					cout << "There are " << numberOfPegs << " pegs in the all games.\n";
					break;

			//Comparing 2 active games if they exist
			case 5: if(games.size()<2) cerr << "There is no enough active games to compare.";
					else if (games.size()==2){
						if(games[0].compare(games[1])) cout << "Game 1 has more pegs than game 2.\n";
						else cout << "Game 2 has at least equal number of pegs with game 1.\n";
					}
					else{
						cout << "Enter two numbers between 1 and " << games.size() <<endl;
						cout << "First number: ";
						cin >> secondSelection;
						PegSolitaire::checkInput();
						cout << "Second number: ";
						cin >> otherSelection;
						PegSolitaire::checkInput();
						if (secondSelection <= 0 || secondSelection > games.size() || otherSelection <= 0 || otherSelection > games.size()) cerr << "Invalid input.\n";
						else{
							if(games[secondSelection-1].compare(games[otherSelection-1])) cout << "Game " << secondSelection << " has more pegs than game " << otherSelection << endl;
							else cout << "Game " << otherSelection << " has at least equal number of pegs with game " << secondSelection << endl;
						} 
					}
					break;

			//Exiting
			case 6: cout << "\nGOODBYE <3 HOPE YOU ENJOY.\n"; return;
			default: cerr << "You have entered invalid input.";
		}
	}
}

bool PegSolitaire::compare(const PegSolitaire& other) const{
	//Comparing 2 boards according to their peg numbers
	//boards have same weight and height except for pyramid so first checking if the board is pyramid.
	bool isPyramidMe, isPyramidOther;
	int numOfPegsMe, numOfPegsOther;
	if (board[0][3].state == State::none && board[0][5].state == State::none && board[0][4].state == State::peg) isPyramidMe = true;
	if (other.board[0][3].state == State::none && other.board[0][5].state == State::none && other.board[0][4].state == State::peg) isPyramidOther = true;

	if (isPyramidMe) numOfPegsMe = numOfPegs(5, 9);
	else numOfPegsMe = numOfPegs(side, side);

	if (isPyramidOther) numOfPegsOther = other.numOfPegs(5, 9);
	else numOfPegsOther = other.numOfPegs(other.side, other.side);

	return numOfPegsMe > numOfPegsOther;
}

PegSolitaire::PegSolitaire(){
	//Initializing the board with arbitrary values, later will change
	boardType = 0;
	side = 0;
	gameType = 'B';
	isEnded = false;
	activeGames++;
	allGames++;
	choosePlayer();
}

PegSolitaire::PegSolitaire(int boardValue): boardType(boardValue){}

PegSolitaire::PegSolitaire(string text){
	//For opening the game with a file
	if (!readFrom(text)){
		cerr << "There is no such a file, try again.\n\n";
		gameType = 'E';
	}
}

void PegSolitaire::choosePlayer(){
	//Choosing the player type, computer or human
	int numInput;
	bool flag = true;
	
	while (flag){
		cout << "\n\nChoose the player type first:\n"
		 	 << "1 - User" << endl
		 	 << "2 - Computer" << endl;
		flag = false;
		cout << "Enter your choice: ";
		cin >> numInput;
		checkInput();
		if (numInput == 1) {
			compOrHuman = 1;
			userPlay();
		}
		else if (numInput == 2){
			compOrHuman = 2;
			playGame();
		}
		else{
			cerr << "Your input is invalid.\n";
			flag = true;
		}
	}
}

void PegSolitaire::playGame(){
	//Choosing the board type
	//Then creating the board according to input
	int numInput;
	bool flag = true;
	
	if (gameType != 'L' && gameType != 'A'){
		while(flag){
			cout << "\n\nPlease select the board type from 1 to 6." << endl
			 << "Also you can play on the square board by typing 0." << endl
			 << "Enter your choice: ";
			cin >> numInput;
			checkInput();
			
			if (numInput >= 1 && numInput <= 6){
				boardType = numInput;
				gameType = 'B';
				switch (numInput){
					case 1: createBoard(7); fillBoard1(); side = 7; break;
					case 2: createBoard(9); fillBoard2(); side = 9; break;
					case 3: createBoard(8); fillBoard3(); side = 8; break;
					case 4: createBoard(7); fillBoard4(); side = 7; break;
					case 5: createBoard(9); fillBoard5(); side = 9; break;
					case 6: createBoard(5, 9); fillBoard6(); break;
				}
				flag = false;
			}
			else if (numInput == 0){
				cout << "\nSelect side of the square (minimum 5 - maximum 26 (there are 26 letters for the columns)): ";
				cin >> numInput;
				checkInput();

				if (numInput >= 5 && numInput <= 26){
					side = numInput;
					gameType = 'S';
					createBoard(numInput);
					fillSquare();
					flag = false;
				}
				else cerr << "Your input is invalid. Try again.";
			}
			else cerr << "Your input is invalid. Try again.";
		}
	}
	play(); //Plays automatically
}

void PegSolitaire::play(){
	//Computer plays the game randomly 
	//In every step, additional choices has shown to the user
	//So every user can do whatever as he/she wants in every step
	int row, col, compCol, compRow, compDirection;
	bool finished = false, movePlayed = false;
	string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string input;

	if (side == 0) {  //if pyramid
		row = 5; col = 9;
		display(row, col);
		while (!finished){
			movePlayed = false;
			compCol = rand() % col;
			compRow = rand() % row;
			compDirection = rand() % 6; //random direction from 0 to 6 (0 for up-right, 1 for up-left, 2 for down-right, 3 for down-left, 4 for left, 5 for right)

			switch(compDirection){
				case 0:if (is_valid_upright(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_upright(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Upright.\n";
						}
						break;
				case 1:if (is_valid_upleft(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_upleft(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Upleft.\n";
						}
				case 2:if (is_valid_downright(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_downright(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Downright.\n";
						}
						break;
				case 3:if (is_valid_downleft(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_downleft(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Downleft.\n";
						}
						break;
				case 4:if (is_valid_left_b6(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_left_b6(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Left.\n";
						}
						break;
				case 5:if (is_valid_right_b6(compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_right_b6(compRow,compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Right.\n";
						}
						break;
			}
			finished = ifEnded(); 
			if (movePlayed){
				display(row, col);
				if (!finished){
					while(true){
						cout << "You can enter: "<< endl
							 << "--> [SAVE] [FILE.TXT] to save your current game\n"
							 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
							 << "--> [PE] to see number of pegs\n"
							 << "--> [EM] to see number of empty cells\n"
							 << "--> [PO] to see number of pegs taken out from the board\n"
							 << "--> [QX] to quit to the main menu\n"
							 << "--> [C] to continue to game\n"
							 << "Enter: ";
						cin >> input;
						if (input == "QX"){ finished = true; gameType = 'A'; break;}
						else if (input == "C") break;
						else if (input == "LOAD"){
							cin >> input;
							if(!readFrom(input)){
								cerr << "There is no such file, try again.\n";
							}
							else return;
						}
						else if (input == "SAVE"){
							cin >> input;
							writeTo(input, row, col);
							return;
						}
						else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
						else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
						else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
						else cout << "Invalid input, try again.\n";
					}
				}
			}
		}
 		if (ifEnded()){ 
 			cout << "Computer has finished the game !!! Congratulations computer, you are great.\n";
 			isEnded = true;
 		}
	}
	else{
		row = col = side;
		display(row, col);
		while (!finished){
			movePlayed = false;
			compCol = rand() % col;
			compRow = rand() % row;
			compDirection = rand() % 4; //random direction from 0 to 4 (0 for up, 1 for down, 2 for right, 3 for left)
			switch (compDirection){
				case 0:if (is_valid_up(row, col, compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_up(compRow, compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Up.\n"; 
						} 
						break;
				case 1:if (is_valid_down(row, col, compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_down( compRow, compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Down.\n"; 
						}
						break;
				case 2:if (is_valid_right(row, col,compRow,compCol)){	//Playing if direction and coordinate are okay
							movePlayed = true;
							move_right( compRow, compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Right.\n";
						}
						break;
				case 3:if (is_valid_left(row, col,compRow,compCol)){		//Playing if direction and coordinate are okay
							movePlayed = true;
							move_left( compRow, compCol);
							cout << "\nComputer played " << text[compCol] << compRow+1 << " - Left.\n";
						}
						break;
			}
			finished = ifEnded(row, col);
			if (movePlayed){
				display(row, col);
				if (!finished){
					while(true){
						cout << "You can enter: "<< endl
							 << "--> [SAVE] [FILE.TXT] to save your current game\n"
							 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
							 << "--> [PE] to see number of pegs\n"
							 << "--> [EM] to see number of empty cells\n"
							 << "--> [PO] to see number of pegs taken out from the board\n"
							 << "--> [QX] to quit to the main menu\n"
							 << "--> [C] to continue to game\n"
							 << "Enter: ";
						cin >> input;
						if (input == "QX"){ finished = true; gameType='A'; break;}
						else if (input == "C") break;
						else if (input == "LOAD"){
							cin >> input;
							if(!readFrom(input)) cerr << "There is no such file, try again.\n";
							else return;
						}
						else if (input == "SAVE"){
							cin >> input;
							writeTo(input, row, col);
							return;
						}
						else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
						else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
						else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
						else cout << "Invalid input, try again.\n";
					}
				}
			}
		}
		if (ifEnded(row, col)){ 
 			cout << "Computer has finished the game !!! Congratulations computer, you are great.\n";
 			isEnded = true;
 		}
	}
}

void PegSolitaire::userPlay(){
	//For user to play the game.
	//First they select the board type, then start playing according to board
	int numInput;
	bool flag = true;
	if (gameType != 'L' && gameType != 'A'){
		while(flag){
			cout << "\n\nPlease select the board type from 1 to 6." << endl
			 << "Also you can play on the square board by typing 0." << endl
			 << "Enter your choice: ";
			cin >> numInput;
			checkInput();
			
			if (numInput >= 1 && numInput <= 6){
				boardType = numInput;
				gameType = 'B';
				switch (numInput){
					case 1: createBoard(7); fillBoard1(); side = 7; break;
					case 2: createBoard(9); fillBoard2(); side = 9; break;
					case 3: createBoard(8); fillBoard3(); side = 8; break;
					case 4: createBoard(7); fillBoard4(); side = 7; break;
					case 5: createBoard(9); fillBoard5(); side = 9; break;
					case 6: createBoard(5, 9); fillBoard6(); break;
				}
				flag = false;
			}
			else if (numInput == 0){
				cout << "\nSelect side of the square (minimum 5 - maximum 26 (there are 26 letters for the columns)): ";
				cin >> numInput;
				checkInput();

				if (numInput >= 5 && numInput <= 26){
					side = numInput;
					gameType = 'S';
					createBoard(numInput);
					fillSquare();
					flag = false;
				}
				else cerr << "Your input is invalid. Try again.";
			}
			else cerr << "Your input is invalid. Try again.";
		}
	}
	if (side == 0) playPyramid();
	else playNormal();
}

void PegSolitaire::playPyramid(){
	char userDirection;
	int row, col, userCol, userRow;
	string input;
	auto finished = false;

	row = 5; col = 9;
	display(row, col);
	while (!finished){
		while(true){
			//ASKING ADDITIONAL CHOICES TO USER
			//Details of choices has shown to the user
			cout << "\nYou can enter:\n"
				 << "--> Column letter in uppercase\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true; gameType='A';break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input[0] >= 65 && input[0] < col+65){ userCol = input[0]-65; break;}
			else cerr << "Please enter valid column letter.\n";
		}

		if (finished == true) continue;

		while(true){
			cout << "\nYou can enter:\n"
				 << "--> Row number\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true;gameType='A'; break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input[0] >= 49 && input[0] < 58){
				if (input.length()==2 && input[1] >= 48 && input[1] < 58) userRow = (input[0]-48)*10 + (input[1]-48);
				else if(input.length()==1) userRow = input[0]-48;
				else {cerr << "Please enter valid input.\n"; continue;}
				--userRow;
				if (userRow >= row || userRow < 0) cerr << "Please stay in range.\n";
				else break;
			}
			else cerr << "Please enter valid input.\n";
		}

		if (finished == true) continue;

		while (true){
			cout << "\nYou can enter:\n"
				 << "--> Direction in uppercase\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true;gameType='A'; break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input!="R" && input!="L" && input!="U" && input!="D"){	//Controlling if user enters invalid direction
				cerr << "Please enter valid coordinates.\n";
			}
			else {userDirection = input[0]; break;}
		}

		if (finished == true) continue;

		play2(Cell(userRow,userCol), userDirection, row, col);
		display(row, col);
		finished = ifEnded();
	}
	if (ifEnded()){ 
		cout << "You have finished the game !!! Congratulations human, you are awesome.\n";
	 	isEnded = true;
 	}
}

void PegSolitaire::play2(Cell coordinate, char direction, int row, int col){
	string input;
	char userDirection;
	switch(direction){
		//Asking again in U and D directions for the pyramid game board
		case 'U': while (true){
					cout << "Enter R or L to go Up-Right or Up-Left: ";
					cin >> input;
					if (input!="R" && input!="L") cerr << "Please enter valid coordinates.\n";
					else {userDirection = input[0]; break;}
				  }
				  switch (userDirection){
					case 'R': if(is_valid_upright(coordinate.row, coordinate.column)) move_upright(coordinate.row,coordinate.column);
							  else cerr << "Invalid coordinates, try again.\n";
					case 'L': if(is_valid_upleft(coordinate.row, coordinate.column)) move_upleft(coordinate.row,coordinate.column);
							  else cerr << "Invalid coordinates, try again.\n";
				  }
				break;
		case 'D':while (true){
					cout << "Enter R or L to go Down-Right or Down-Left: ";
					cin >> input;
					if (input!="R" && input!="L") cerr << "Please enter valid coordinates.\n";
					else {userDirection = input[0]; break;}
				  }
				  switch (userDirection){
					case 'R': if(is_valid_downright(coordinate.row, coordinate.column)) move_downright(coordinate.row,coordinate.column);
							  else cerr << "Invalid coordinates, try again.\n";
					case 'L': if(is_valid_downleft(coordinate.row, coordinate.column)) move_downleft(coordinate.row,coordinate.column);
							  else cerr << "Invalid coordinates, try again.\n";
				  }
				break;

		case 'R':if (is_valid_right_b6(coordinate.row,coordinate.column)) move_right_b6(coordinate.row,coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
		case 'L':if (is_valid_left_b6(coordinate.row,coordinate.column)) move_left_b6(coordinate.row,coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
	}
}

void PegSolitaire::playNormal(){
	char userDirection;
	string input;
	int row, col, userCol, userRow;
	auto finished = false;

	row = col = side;
	display(row, col);
	while (!finished){
		while(true){
			/* 
			TAKING INPUT (COLUMN-ROW-DIRECTION) ONE BY ONE
			Everytime we take an input, we ask for the additional choices.
			Their meanings are shown to the user.
			*/ 
			cout << "\nYou can enter:\n"
				 << "--> Column letter in uppercase\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true;gameType='A'; break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input[0] >= 65 && input[0] < col+65){ userCol = input[0]-65; break;}
			else cerr << "Please enter valid column letter.\n";
		}

		if (finished == true) continue;

		while(true){
			cout << "\nYou can enter:\n"
				 << "--> Row number\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true; gameType='A';break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input[0] >= 49 && input[0] < 58){
				if (input.length()==2 && input[1] >= 48 && input[1] < 58) userRow = (input[0]-48)*10 + (input[1]-48);
				else if(input.length()==1) userRow = input[0]-48;
				else {cerr << "Please enter valid input.\n"; continue;}
				--userRow;
				if (userRow >= row || userRow < 0) cerr << "Please stay in range.\n";
				else break;
			}
			else cerr << "Please enter valid input.\n";
		}

		if (finished == true) continue;

		while (true){
			cout << "\nYou can enter:\n"
				 << "--> Direction in uppercase\n"
				 << "--> [SAVE] [FILE.TXT] to save your current game\n"
				 << "--> [LOAD] [FILE.TXT] to load another game onto this game\n"
				 << "--> [PE] to see number of pegs\n"
				 << "--> [EM] to see number of empty cells\n"
				 << "--> [PO] to see number of pegs taken out from the board\n"
				 << "--> [QX] to quit to the main menu\n"
				 << "Enter: ";
			cin >> input;
			if (input == "QX") {finished = true;gameType='A'; break;}
			else if (input == "SAVE"){
				cin >> input;
				writeTo(input, row , col);
				return;
			}
			else if (input == "LOAD"){
				cin >> input;
				if(!readFrom(input)) cerr << "There is no such file, try again.\n";					
				else return;
			}
			else if (input == "PE") cout << "There are " << numOfPegs(row, col) << " pegs in the board.\n";
			else if (input == "EM") cout << "There are " << numOfEmptyCells(row, col) << " empty cells in the board.\n";
			else if (input == "PO") cout<< numOfPegsOut(row,col) << " pegs taken out from the board.\n";
			else if (input!="R" && input!="L" && input!="U" && input!="D"){	//Controlling if user enters invalid direction
				cerr << "Please enter valid coordinates.\n";
			}
			else {userDirection = input[0]; break;}
		}

		if (finished == true) continue;

		play(Cell(userRow,userCol), userDirection, row, col);
		display(row, col);
		finished = ifEnded(row, col);
	}
	if (ifEnded(row, col)){ 
 		cout << "You have finished the game !!! Congratulations human, you are awesome.\n";
 		isEnded = true;
 	}
}

void PegSolitaire::play(Cell coordinate, char direction, int row, int col){
	switch(direction){
		//Playing the movement according the inputs
		case 'U':if (is_valid_up(row,col,coordinate.row, coordinate.column)) move_up(coordinate.row, coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
				 break;
		case 'D':if (is_valid_down(row,col,coordinate.row, coordinate.column)) move_down(coordinate.row, coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
				 break;
		case 'R':if (is_valid_right(row,col,coordinate.row, coordinate.column)) move_right(coordinate.row, coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
				 break;
		case 'L':if (is_valid_left(row,col,coordinate.row, coordinate.column)) move_left(coordinate.row, coordinate.column);
				 else cerr << "Invalid coordinates, try again.\n";
				 break;
	}
}

bool PegSolitaire::readFrom(string text){
	fstream loads;
	char c;
	int row, col, comp_or_human;

	loads.open(text);
	if (!loads) return false;
	
	//Reading the informations in the same order as we put them in the file
	loads >> row >> col >> comp_or_human >> gameType;

	createBoard(row);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j){
			loads >> c;
			if (c == '_') board[i][j].state = State::none;
			else if (c == 'P') board[i][j].state = State::peg;
			else if (c == '.') board[i][j].state = State::empty;
		}

	compOrHuman = comp_or_human;

	if (row == 5 && col == 9) side = 0;
	else side = row;

	isEnded = false;
	boardType = 0;

	if (compOrHuman == 0) choosePlayer();
	else {
		if (compOrHuman == 1) userPlay();
		else if (compOrHuman == 2) playGame();
	}
	loads.close();
	return true;
}

void PegSolitaire::writeTo(string text, int row , int col) const{
	fstream save;
	save.open(text, fstream::out);

	//Reading row, column number and player of the game and type of the game information
	save << row << endl;
	save << col << endl;
	save << compOrHuman << endl;
	save << 'L' << endl;	//L for loaded

	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			if (board[i][j].state == State::peg) save << "P";
			else if (board[i][j].state == State::empty) save << ".";
			else save << "_";
		}
		save << endl;
	}

	for (int i = 0; i < 20; ++i) save << "      ";	//printing spaces to delete if anything left in the file from previous saves
	save.close();
}

int PegSolitaire::numOfPegs(int row, int col) const{
	int number=0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j].state == State::peg) ++number; //increasing number by 1 everytime we see peg cell. 
	return number;
}

int PegSolitaire::numOfEmptyCells(int row, int col) const{
	int number=0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (board[i][j].state == State::empty) ++number; //increasing number by 1 everytime we see empty cell. 
	return number;
}

int PegSolitaire::numOfPegsOut(int row, int col) const{
	//number of pegs out is equal to number of empty cells - 1
	return numOfEmptyCells(row, col) - 1;
}

void PegSolitaire::createBoard(int size){
	//Creating 2D vector for the boards with resizing the board parameter
	board.resize(size);
	for(int i = 0; i < size; ++i)
		board[i].resize(size);
}

void PegSolitaire::createBoard(int row, int col){
	//Creating 2D vector for the pyramid with resizing the board parameter
	board.resize(row);
	for(int i = 0; i < row; ++i)
		board[i].resize(col);
}

bool PegSolitaire::is_valid_up(int row, int col, int userRow, int userCol) const{
	bool flag = true;
	if (userRow <= 1 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow-1][userCol].state != State::peg || board[userRow][userCol].state != State::peg) flag = false;	//move isn't valid if the current slot or one up slot do not have peg
	else if (board[userRow-2][userCol].state != State::empty) flag = false;	//move isn't valid if two up slot is not empty
	return flag;
}

bool PegSolitaire::is_valid_down(int row, int col, int userRow, int userCol) const{
	bool flag = true;
	if (userRow < 0 || userRow >= row-2) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow+1][userCol].state != State::peg || board[userRow][userCol].state!=State::peg) flag = false;	//move isn't valid if the current slot or one down slot do not have peg
	else if (board[userRow+2][userCol].state != State::empty) flag = false;	//move isn't valid if two down slot is not empty
	return flag;
}

bool PegSolitaire::is_valid_right(int row, int col, int userRow, int userCol) const{
	bool flag = true;
	if (userCol >= col-2 || userRow < 0 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow][userCol+1].state  != State::peg || board[userRow][userCol].state !=State::peg) flag = false;	//move isn't valid if the current slot or one right slot do not have peg
	else if (board[userRow][userCol+2].state  != State::empty) flag = false;	//move isn't valid if two right slot is not empty
	return flag;
}

bool PegSolitaire::is_valid_left(int row, int col, int userRow, int userCol) const{
	bool flag = true;
	if (userCol <= 1 || userRow < 0 || userRow >= row) flag = false;	//move isn't valid if coordinate is not proper
	else if (board[userRow][userCol-1].state != State::peg || board[userRow][userCol].state != State::peg) flag = false;	//move isn't valid if the current slot or one left slot do not have peg
	else if (board[userRow][userCol-2].state != State::empty) flag = false;	//move isn't valid if two left slot is not empty
	return flag;
}

bool PegSolitaire::is_there_up(int row, int col) const{
	//checking the pieces of board if there are any valid up movement left
	for (int i = 2; i < row; ++i)
		for(int j = 0; j < col; ++j)
			if (is_valid_up(row, col, i, j)) return true;
	return false;
}

bool PegSolitaire::is_there_down(int row, int col) const{
	//checking the pieces of board if there are any valid down movement left
	for (int i = 0; i < row-2; ++i)
		for(int j = 0; j < col; ++j)
			if (is_valid_down(row, col,i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_right(int row, int col) const{
	//checking the pieces of board if there are any valid right movement left
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col-2; ++j)
			if (is_valid_right(row, col,i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_left(int row, int col) const{
	//checking the pieces of board if there are any valid left movement left
	for (int i = 0; i < row; ++i)
		for (int j = 2; j < col; ++j)
			if (is_valid_left(row, col,i,j)) return true;
	return false;
}

void PegSolitaire::move_up(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row-1][col].state = State::empty;	//making the 1 up coordinate empty
	board[row-2][col].state = State::peg;		//placing the peg to 2 up coordinate 
}

void PegSolitaire::move_down(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row+1][col].state = State::empty;	//making the 1 down coordinate empty
	board[row+2][col].state = State::peg;		//placing the peg to 2 down coordinate
}

void PegSolitaire::move_right(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row][col+1].state = State::empty;	//making the 1 right coordinate empty
	board[row][col+2].state = State::peg; 	//placing the peg to 2 right coordinate
}

void PegSolitaire::move_left(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row][col-1].state = State::empty;	//making the 1 left coordinate empty
	board[row][col-2].state = State::peg;		//placing the peg to 2 left coordinate
}

bool PegSolitaire::is_valid_upright(int row, int col) const{
	bool flag = true;
	if (row <= 1 || row > 4 || col >= 5 || (row == 2 && col == 4) ) flag = false;				//move isn't valid if coordinate is not proper
	else if (board[row][col].state != State::peg || board[row-1][col+1].state != State::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row-2][col+2].state != State::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool PegSolitaire::is_valid_upleft(int row, int col) const{
	bool flag = true;
	if (row <= 1 || row > 4 || col < 4 || (row == 2 && col == 4)) flag = false;					//move isn't valid if coordinate is not proper
	else if (board[row][col].state != State::peg || board[row-1][col-1].state != State::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row-2][col-2].state != State::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool PegSolitaire::is_valid_downright(int row, int col) const{
	bool flag = true;
	if (row > 2 || row < 0) flag = false;														//move isn't valid if coordinate is not proper
	else if (board[row][col].state != State::peg || board[row+1][col+1].state != State::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row+2][col+2].state != State::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool PegSolitaire::is_valid_downleft(int row, int col) const{
	bool flag = true;
	if (row > 2 || row < 0) flag = false;														//move isn't valid if coordinate is not proper
	else if (board[row][col].state != State::peg || board[row+1][col-1].state != State::peg) flag = false;	//move isn't valid if current slot or cross slot do not have peg
	else if (board[row+2][col-2].state != State::empty) flag = false;									//move isn't valid if the slot that peg will fit in is not empty
	return flag;
}

bool PegSolitaire::is_valid_left_b6(int row, int col) const{
	bool flag = true;
	if (row < 2 || row > 4 || col < 4) flag = false;											//move isn't valid if coordinate is not proper
	else if (board[row][col-2].state != State::peg || board[row][col].state != State::peg) flag = false;	//move isn't valid if the current slot or one left slot do not have peg
	else if (board[row][col-4].state != State::empty) flag = false;									//move isn't valid if two left slot is not empty
	return flag;
}

bool PegSolitaire::is_valid_right_b6(int row, int col) const{
	bool flag = true;
	if (row < 2 || row > 4 || col > 4) flag = false;										//move isn't valid if coordinate is not proper
	else if (board[row][col+2].state != State::peg || board[row][col].state!=State::peg) flag = false;	//move isn't valid if the current slot or one right slot do not have peg
	else if (board[row][col+4].state != State::empty) flag = false;								//move isn't valid if two right slot is not empty
	return flag;
}

void PegSolitaire::move_upright(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row-1][col+1].state = State::empty;	//making the cross coordinate empty
	board[row-2][col+2].state = State::peg;	//placing the peg
}

void PegSolitaire::move_upleft(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row-1][col-1].state = State::empty;	//making the cross coordinate empty
	board[row-2][col-2].state = State::peg;	//placing the peg
}

void PegSolitaire::move_downright(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row+1][col+1].state = State::empty;	//making the cross coordinate empty
	board[row+2][col+2].state = State::peg;	//placing the peg
}

void PegSolitaire::move_downleft(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row+1][col-1].state = State::empty;	//making the cross coordinate empty
	board[row+2][col-2].state = State::peg;	//placing the peg
}

void PegSolitaire::move_right_b6(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row][col+2].state = State::empty;	//making the 1 right coordinate empty
	board[row][col+4].state = State::peg; 	//placing the peg to 2 right coordinate
}

void PegSolitaire::move_left_b6(int row, int col){
	board[row][col].state = State::empty;		//making the current coordinate empty
	board[row][col-2].state = State::empty;	//making the 1 left coordinate empty
	board[row][col-4].state = State::peg;		//placing the peg to 2 left coordinate
}

bool PegSolitaire::is_there_ur() const{
	//checking the pieces of board if there are any valid upside-right movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if(is_valid_upright(i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_ul() const{
	//checking the pieces of board if there are any valid upside-left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < 9; ++j)
			if(is_valid_upleft(i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_dr() const{
	//checking the pieces of board if there are any valid down-right movement left
	for (int i = 0; i < 3; ++i)
		for (int j = 2; j < 7; ++j)
			if(is_valid_downright(i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_dl() const{
	//checking the pieces of board if there are any valid down-left movement left
	for (int i = 0; i < 3; ++i)
		for (int j = 2; j < 7; ++j)
			if(is_valid_downleft(i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_left_b6() const{
	//checking the pieces of board if there are any valid left movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 4; j < 9; ++j)
			if(is_valid_left_b6(i,j)) return true;
	return false;
}

bool PegSolitaire::is_there_right_b6() const{
	//checking the pieces of board if there are any valid right movement left
	for (int i = 2; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if(is_valid_right_b6(i,j)) return true;
	return false;
}

bool PegSolitaire::ifEnded() const{
	//checking every movement to make sure that there is no move left
	if (is_there_ur() ||
		is_there_ul() ||
		is_there_dr() || 
		is_there_dl() ||
		is_there_right_b6() ||
		is_there_left_b6())
		return false;
	else return true;
}

bool PegSolitaire::ifEnded(int r, int c) const{
	//checking every movement to make sure that there is no move left
	if (is_there_left(r, c) ||
		is_there_up(r, c) ||
		is_there_right(r, c) ||
		is_there_down(r, c))
		return false;
	else return true;
}

void PegSolitaire::display(int row, int col) const{
	string columns, text = " a b c d e f g h i j k l m n o p q r s t u v w x y z ";	//letters for columns
	for (int i = 0; i < col*2; i+=2)
		columns.append(text, i, 2);	//append letters to columns string in number of column at the board
	cout << "  " << columns << endl;
	for (int i = 0; i < row; ++i){
		cout << i+1 << " ";
		if ((i+1)/10 == 0) cout << " ";
		for (int j = 0; j < col; ++j)
			if (board[i][j].state == State::peg)			//Printing P if the slot has a peg
				cout << "P ";
			else if (board[i][j].state == State::empty)	//Printing . if the slot is empty
				cout << ". ";
			else if (board[i][j].state == State::none)	//Printing a space if we are not in slot
				cout << "  ";
		cout << endl;
	}
}

void PegSolitaire::fillBoard1(){
	for (int i = 0; i < 7; ++i)
		switch (i){
			case 0:
			case 6: for (int j = 0; j < 7; ++j)
						switch(j){
							//filling gaps
							case 0:
							case 1:
							case 5:
							case 6: board[i][j].state = State::none;
									break;
							//placing pegs
							default: board[i][j].state = State::peg;
									 break;
						}
					break;
			case 1:
			case 5: for (int j = 0; j < 7; ++j)
						switch(j){
							//filling gaps
							case 0:
							case 6: board[i][j].state = State::none;
									break;
							//placing pegs
							default: board[i][j].state = State::peg;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 7; ++j)
						board[i][j].state = State::peg;
					 break;
		}
	//placing the empty slot
	board[2][3].state = State::empty;
}

void PegSolitaire::fillBoard2(){
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
							case 8: board[i][j].state = State::none;
									break;
							//placing pegs
							default: board[i][j].state = State::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 9; ++j)
						board[i][j].state = State::peg;
					 break;
		}
	//placing the empty slot
	board[4][4].state = State::empty;
}

void PegSolitaire::fillBoard3(){
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
							case 7: board[i][j].state = State::none;
									break;
							//placing pegs
							default: board[i][j].state = State::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 8; ++j)
						board[i][j].state = State::peg;
					 break;
		}
	//placing the empty slot
	board[4][3].state = State::empty;
}

void PegSolitaire::fillBoard4(){
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
							case 6: board[i][j].state = State::none;
									break;
							//placing pegs
							default: board[i][j].state = State::peg;
									 break;
						}
					break;
			default: //placing remaining pegs
					 for(int j = 0; j < 7; ++j)
						board[i][j].state = State::peg;
					 break;
		}
	//placing the empty slot
	board[3][3].state = State::empty;
}

void PegSolitaire::fillBoard5(){
	for(int i = 0; i < 9; ++i)
		switch(i){
			//placing pegs and filling the gaps in proper coordinates
			case 0:
			case 8: for(int j = 0; j < 9; ++j)
						if (j == 4) board[i][j].state = State::peg;
						else board[i][j].state = State::none;
					break;
			case 1:
			case 7: for(int j = 0; j < 9; ++j)
						if (j==3 || j==4 || j==5) board[i][j].state = State::peg;
						else board[i][j].state = State::none;
					break;
			case 2: 
			case 6: for(int j = 0; j < 9; ++j)
						if (j==0 || j==1 || j==7 || j==8) board[i][j].state = State::none;
						else board[i][j].state = State::peg;
					break;
			case 3: 
			case 5: for(int j = 0; j < 9; ++j)
						if (j==0 || j==8) board[i][j].state = State::none;
						else board[i][j].state = State::peg;
					break;
			default: for(int j = 0; j < 9; ++j)
						board[i][j].state = State::peg;
					 break;
		}
	//placing the empty slot
	board[4][4].state = State::empty;
}

void PegSolitaire::fillBoard6(){
	for (int i = 0; i < 5; ++i)
			switch(i){
				case 0: //filling first row
						for (int j = 0; j < 9; ++j)
							if (j == 4) board[i][j].state = State::empty;
							else board[i][j].state = State::none;
						break;
				case 1: //filling second row
						for (int j = 0; j < 9; ++j)
							if (j==3 || j==5) board[i][j].state = State::peg;
							else board[i][j].state = State::none;
						break;
				case 2: //filling third row
						for (int j = 0; j < 9; ++j)
							if (j==2||j==4||j==6) board[i][j].state = State::peg;
							else board[i][j].state = State::none;
						break;
				case 3: //filling fourth row
						for (int j = 0; j < 9; ++j)
							if (j%2 == 0) board[i][j].state = State::none;
							else board[i][j].state = State::peg;
						break;
				case 4: //filling fifth row
						for (int j = 0; j < 9; ++j)
							if (j%2 == 0) board[i][j].state = State::peg;
							else board[i][j].state = State::none;
						break;
			}
}

void PegSolitaire::fillSquare(){
	//filling rows and columns of square board and make one slot empty
	for(int i = 0; i < side; ++i)
		for (int j = 0; j < side; ++j)
			board[i][j].state = State::peg;
	board[side/2][side/2].state = State::empty;
}