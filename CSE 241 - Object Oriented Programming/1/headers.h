/***
 ***	MERT GURSIMSIR 1901042646
***/
using namespace std;

enum class Cells {empty, peg, none};	//strong enum type for representing cell state

void create_board(vector <vector<Cells>>& board, int size);	//creating the board with the size of "size"
void create_board6(vector <vector<Cells>>& board);			//creating the pyramid board
void fill_board1(vector <vector<Cells>>& board1);			//filling board #1
void fill_board2(vector <vector<Cells>>& board2);			//filling board #2
void fill_board3(vector <vector<Cells>>& board3);			//filling board #3
void fill_board4(vector <vector<Cells>>& board4);			//filling board #4
void fill_board5(vector <vector<Cells>>& board5);			//filling board #5
void fill_board6(vector <vector<Cells>>& board6);			//filling board #6
void print_board(vector <vector<Cells>> board, int size);	//printing boards with size of "size"
void print_board6(vector <vector<Cells>> board);			//printing the pyramid board
bool is_valid_up(const vector <vector<Cells>> board, int size, int row, int col);		//checking if up move is legal or not
bool is_valid_down(const vector <vector<Cells>> board, int size, int row, int col);		//checking if down move is legal or not
bool is_valid_right(const vector <vector<Cells>> board, int size, int row, int col);	//checking if right move is legal or not
bool is_valid_left(const vector <vector<Cells>> board, int size, int row, int col);		//checking if left move is legal or not
bool is_there_up(const vector <vector<Cells>> board, int size);		//checking if are there any up move left
bool is_there_down(const vector <vector<Cells>> board, int size);	//checking if are there any down move left
bool is_there_right(const vector <vector<Cells>> board, int size);	//checking if are there any right move left
bool is_there_left(const vector <vector<Cells>> board, int size);	//checking if are there any left move left
bool is_finished(const vector <vector<Cells>> board, int size);		//checking if the game is finsihed
void move_up(vector <vector<Cells>>& board, int row, int col);		//move the specified row and column up
void move_down(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column down
void move_right(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column right
void move_left(vector <vector<Cells>>& board, int row, int col);	//move the specified row and column left
bool is_valid_upright(const vector <vector<Cells>> board, int row, int col);	//checking if the cross upright move is legal or not
bool is_valid_upleft(const vector <vector<Cells>> board, int row, int col);		//checking if the cross upleft move is legal or not
bool is_valid_downright(const vector <vector<Cells>> board, int row, int col);	//checking if the cross downright move is legal or not
bool is_valid_downleft(const vector <vector<Cells>> board, int row, int col);	//checking if the cross downleft move is loegal or not
bool is_valid_left_b6(const vector <vector<Cells>> board, int row, int col);	//checking if the left move is legal or not for the 6th board
bool is_valid_right_b6(const vector <vector<Cells>> board, int row, int col);	//checking if the right move is legal or not for the 6th board
void move_upright(vector <vector<Cells>>& board, int row, int col);				//move the specified row and column upright for 6th board
void move_upleft(vector <vector<Cells>>& board, int row, int col);				//move the specified row and column upleft for 6th board
void move_downright(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column downright for the 6th board
void move_downleft(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column downleft for the 6th board
void move_right_b6(vector <vector<Cells>>& board, int row, int col);			//move the specified row and column right for the 6th board
void move_left_b6(vector <vector<Cells>>& board, int row, int col);				//move the specified row and column left for the 6th board
bool is_there_ur(const vector <vector<Cells>> board, int size);					//checking if are there any upright move left
bool is_there_ul(const vector <vector<Cells>> board, int size);					//checking if are there any upleft move left
bool is_there_dr(const vector <vector<Cells>> board);							//checking if are there any downright move left
bool is_there_dl(const vector <vector<Cells>> board);							//checking if are there any downleft move left
bool is_there_left_b6(const vector <vector<Cells>> board, int size);			//checking if are there any left move left
bool is_there_right_b6(const vector <vector<Cells>> board);						//checking if are there any right move left
bool is_finished_b6(const vector <vector<Cells>> board, int size);				//checking if the board 6 is finished