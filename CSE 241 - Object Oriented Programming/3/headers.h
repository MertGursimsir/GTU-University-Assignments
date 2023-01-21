#include <iostream>
#include <vector>
#include <cstdlib> //only for rand
#include <string>
#include <fstream>
using namespace std;

enum class State{empty, peg, none};
//Strong enum type for cell state

class PegSolitaire{
public:
	//Cell class to represent a Peg Solitaire cell.
	class Cell{
	public:
		Cell();
		Cell(int rowValue, int colValue);
		//Constructors to start the Cell object

		//Some setters and getters that might be useful
		void setRow(int rowValue);
	    void setCol(int colValue);
	    void setSt(State stateValue);
	    int getCol() const; 
	    int getRow() const;
	    State getSt() const;

		friend class PegSolitaire; //accepting PegSolitaire as friend
	private:
		int column;
		State state;
		int row;
	};

	PegSolitaire(int boardValue);//Takes the board type
	PegSolitaire(string text);	 //For loaded games
	PegSolitaire();				 //No parameter constructor

	void writeTo(string text, int row, int col) const;	//Write to file
	bool readFrom(string text);	//Read from a file

	int numOfPegs(int row, int col) const;		//Returns number of pegs
	int numOfEmptyCells(int row, int col) const;//Returns number of empty cells
	int numOfPegsOut(int row, int col) const;	//Returns number of pegs taken out from the board

	void display(int row, int col) const;
	//Displays current board on the screen

	void play();													//Plays automatically
	void play(Cell coordinate, char direction, int row, int col);	//Takes coordinates and plays the user.
	void play2(Cell coordinate, char direction, int row, int col);	//Play for pyramid

	bool ifEnded() const;
	bool ifEnded(int r, int c) const;	
	//Returns if the game ended

	void playGame();
	//Plays the game by asking the user the board type
	//first then automatically plays the game until it ends.

	void userPlay();
	//For user to play the game

	void playNormal();
	void playPyramid();

	static int totalPegsAllBoards(){ return totalPegs;} 
	//Returns the total number of pegs in all the game boards

	bool compare(const PegSolitaire& other) const;
	//Returns true if the first game has more pegs, otherwise it returns false

	void createBoard(int size);		//to create normal boards
	void createBoard(int row, int col);	//to create pyramid

	static void checkInput(); //checking if input is correct type

	void choosePlayer();
	//Choosing the player type, computer or human

	//Filling the boards
	void fillBoard1();
	void fillBoard2();
	void fillBoard3();
	void fillBoard4();
	void fillBoard5();
	void fillBoard6();
	void fillSquare();

	bool is_valid_up(int row, int col, int userRow, int userCol) const;	//checking if up move is legal or not
	bool is_valid_down(int row, int col, int userRow, int userCol) const;	//checking if down move is legal or not
	bool is_valid_right(int row, int col, int userRow, int userCol) const;//checking if right move is legal or not
	bool is_valid_left(int row, int col, int userRow, int userCol) const;	//checking if left move is legal or not
	bool is_there_up(int row, int col) const;	//checking if are there any up move left
	bool is_there_down(int row, int col) const;	//checking if are there any down move left
	bool is_there_right(int row, int col) const;//checking if are there any right move left
	bool is_there_left(int row, int col) const;	//checking if are there any left move left
	void move_up(int row, int col);				//move the specified row and column up
	void move_down(int row, int col);			//move the specified row and column down
	void move_right(int row, int col);			//move the specified row and column right
	void move_left(int row, int col);			//move the specified row and column left

	bool is_valid_upright(int row, int col) const;	//checking if the cross upright move is legal or not
	bool is_valid_upleft(int row, int col) const;		//checking if the cross upleft move is legal or not
	bool is_valid_downright(int row, int col) const;	//checking if the cross downright move is legal or not
	bool is_valid_downleft(int row, int col) const;	//checking if the cross downleft move is loegal or not
	bool is_valid_left_b6(int row, int col) const;	//checking if the left move is legal or not for the pyramid board
	bool is_valid_right_b6(int row, int col) const;	//checking if the right move is legal or not for the pyramid board
	void move_upright(int row, int col);		//move the specified row and column upright for pyramid board
	void move_upleft(int row, int col);		//move the specified row and column upleft for pyramid board
	void move_downright(int row, int col);	//move the specified row and column downright for the pyramid board
	void move_downleft(int row, int col);	//move the specified row and column downleft for the pyramid board
	void move_right_b6(int row, int col);	//move the specified row and column right for the pyramid board
	void move_left_b6(int row, int col);		//move the specified row and column left for the pyramid board
	bool is_there_ur() const;		//checking if are there any upright move left
	bool is_there_ul() const;		//checking if are there any upleft move left
	bool is_there_dr() const;		//checking if are there any downright move left
	bool is_there_dl() const;		//checking if are there any downleft move left
	bool is_there_left_b6() const;	//checking if are there any left move left
	bool is_there_right_b6() const;	//checking if are there any right move left
	void beginning();



private:
	vector <vector<Cell>> board;	//2D vector of Cell object
	int boardType;	//An int from 1 to 6
	int side;		//An int for side of the square board
	int compOrHuman;//1 for human, 2 for computer game
	char gameType;	//"L" for loaded game, "B" for board 1 to 6, "S" for square game, "A" for active game, "E" for error
	bool isEnded; 	//0 if not ended, 1 if ended
	static int activeGames;
	static int allGames;
	static int totalPegs;	//Total number of pegs in all the game boards
};

typedef PegSolitaire::Cell inCell;