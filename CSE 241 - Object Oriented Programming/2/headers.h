/***
 ***	MERT GURSIMSIR 1901042646
***/
using namespace std;

enum class Cells {empty, peg, none};	//strong enum type for representing cell state

void fill_board1(vector <vector<Cells>>& board1);	//filling board #1
void fill_board2(vector <vector<Cells>>& board2);	//filling board #2
void fill_board3(vector <vector<Cells>>& board3);	//filling board #3
void fill_board4(vector <vector<Cells>>& board4);	//filling board #4
void fill_board5(vector <vector<Cells>>& board5);	//filling board #5
void fill_board6(vector <vector<Cells>>& board6);	//filling board #6
void print_board(const vector <vector<Cells>>& board, int row, int col);	//print board
void create_board(vector <vector<Cells>>& board, int row=7, int col=7);		//creating the board with resizing
bool load_file(string name, vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp);		//loading file
void save_file(string name, const vector <vector <Cells>> board, int row, int col, int num_of_moves,bool is_comp);	//saving file
void comp_or_human(vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp, bool flag);	//determining if the game is human or computer
bool is_pyramid(const vector <vector <Cells>> board, const int row, const int col);		//determining if the board is pyramid or not
bool is_valid_up(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol);	//checking if up move is legal or not
bool is_valid_down(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol);	//checking if down move is legal or not
bool is_valid_right(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol);//checking if right move is legal or not
bool is_valid_left(const vector <vector<Cells>> board, int row, int col, int userRow, int userCol);	//checking if left move is legal or not
bool is_there_up(const vector <vector<Cells>> board, int row, int col);		//checking if are there any up move left
bool is_there_down(const vector <vector<Cells>> board, int row, int col);	//checking if are there any down move left
bool is_there_right(const vector <vector<Cells>> board, int row, int col);	//checking if are there any right move left
bool is_there_left(const vector <vector<Cells>> board, int row, int col);	//checking if are there any left move left
bool is_finished(const vector <vector<Cells>> board, int row, int col);		//controlling if the board is finished
void move_up(vector <vector<Cells>>& board, int row, int col);				//move the specified row and column up
void move_down(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column down
void move_right(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column right
void move_left(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column left
bool is_valid_upright(const vector <vector<Cells>> board, int row, int col);	//checking if the cross upright move is legal or not
bool is_valid_upleft(const vector <vector<Cells>> board, int row, int col);		//checking if the cross upleft move is legal or not
bool is_valid_downright(const vector <vector<Cells>> board, int row, int col);	//checking if the cross downright move is legal or not
bool is_valid_downleft(const vector <vector<Cells>> board, int row, int col);	//checking if the cross downleft move is loegal or not
bool is_valid_left_b6(const vector <vector<Cells>> board, int row, int col);	//checking if the left move is legal or not for the pyramid board
bool is_valid_right_b6(const vector <vector<Cells>> board, int row, int col);	//checking if the right move is legal or not for the pyramid board
void move_upright(vector <vector<Cells>>& board, int row, int col);		//move the specified row and column upright for pyramid board
void move_upleft(vector <vector<Cells>>& board, int row, int col);		//move the specified row and column upleft for pyramid board
void move_downright(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column downright for the pyramid board
void move_downleft(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column downleft for the pyramid board
void move_right_b6(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column right for the pyramid board
void move_left_b6(vector <vector<Cells>>& board, int row, int col);		//move the specified row and column left for the pyramid board
bool is_there_ur(const vector <vector<Cells>> board);		//checking if are there any upright move left
bool is_there_ul(const vector <vector<Cells>> board);		//checking if are there any upleft move left
bool is_there_dr(const vector <vector<Cells>> board);		//checking if are there any downright move left
bool is_there_dl(const vector <vector<Cells>> board);		//checking if are there any downleft move left
bool is_there_left_b6(const vector <vector<Cells>> board);	//checking if are there any left move left
bool is_there_right_b6(const vector <vector<Cells>> board);	//checking if are there any right move left
bool is_finished_pyramid(const vector <vector<Cells>> board);	//checking if the pyramid board is finished
bool beginning(vector <vector <Cells>>& board, int& row, int& col, bool& is_saved, bool& is_comp);	//function that makes movements