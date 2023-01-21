#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 2  /* N must be bigger than 1 */

typedef enum{left, right, up, down, giveup}way;

void filling_board(int (*board)[N]){
	int i, random_i, j, random_j, temp, counter = 0;	/*  i, j : counters for loops // 
															random_i, random_j : randomly choosen row and column numbers respectively
															temp : to hold the variable inside the choosen element of the board while swapping elements 
															counter : for numbers of the board*/
	/* Assigning numbers to board from 0 to (N*N)-1 */
	for(i = 0; i < N; ++i)
		for(j = 0; j < N; ++j){
			board[i][j] = counter;
			counter++;
		}
	
	/* Changing every elements of the board randomly */
	for(i = 0; i < N; ++i)
		for(j = 0; j < N; ++j){
			random_i = rand() % N;
			random_j = rand() % N;
			temp = board[i][j];
			board[i][j] = board[random_i][random_j];
			board[random_i][random_j] = temp;
		}
}

void printing_board(int (*board)[N]){
	int i, j, k;   /* counters for loops */

	/* Printing asterisk characters for borders */
	printf("\n");
	for(k = 0; k < N; ++k) printf("*********");
	printf("*\n");

	for(i = 0; i < N; ++i){
		/* Printing lines and putting * between each number */
		printf("*");
		for(j = 0; j < N; ++j){
			if (board[i][j] == 0) printf("        *");
			else printf("%5d   *", board[i][j]);
		}

		/* Printing asterisk characters for borders */
		printf("\n");
		for(k = 0; k < N; ++k) printf("*********");
		printf("*\n");
	}
}

bool is_solved(int (*board)[N]){
	int i, j, flag = 1, counter = 1;	/*  i, j : counters for loop 
											flag : to control if board is ordered correctly 
											counter : to check the elements one by one */
	/* Checking if board is ordered */
	for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
			if (board[i][j] == counter) counter++;
			else if (board[i][j] != 0) flag = 0;
		}
		if (flag == 0) break;
	}
	
	if (flag == 1) return true;
	else return false;
}

int movement(way direction, int row, int column, int (*board)[N]){
	int i, temp, flag = 0;  /*  i : counter for loop, 
								temp : to hold the variable inside the specific element while swapping elements 
								flag : identifier if the move can be implemented */
	int row_zero, column_zero;  /* row and column number of zero respectively */

	/* Perform the movement. */
	switch (direction){
		case left:  for(i = 0; i < column; ++i) /* Decide if move can be done by finding the gap */
						if (board[row][i] == 0){
							column_zero = i;
							flag = 1;
							break;
						}
					if (flag == 1) /* If move can be done, changing the elements properly */
						for(i = column_zero + 1; i <= column; ++i){
							temp = board[row][i];
							board[row][i] = board[row][i-1];
							board[row][i-1] = temp;
						}
					break;

		case right: for(i = column + 1; i < N; ++i)
						if (board[row][i] == 0){
							column_zero = i;
							flag = 1;
							break;
						}
					if (flag == 1)
						for(i = column_zero - 1; i >= column; --i){
							temp = board[row][i];
							board[row][i] = board[row][i+1];
							board[row][i+1] = temp;
						}
					break;

		case up:	for(i = 0; i < row; ++i)
						if (board[i][column] == 0){
							row_zero = i;
							flag = 1;
							break;
						}
					if (flag == 1)
						for(i = row_zero + 1; i <= row; ++i){
							temp = board[i][column];
							board[i][column] = board[i-1][column];
							board[i-1][column] = temp;
						}
					break;

		case down:	for(i = row + 1; i < N; ++i)
						if (board[i][column] == 0){
							row_zero = i;
							flag = 1;
							break;
						}
					if (flag == 1)
						for(i = row_zero - 1; i >= row; --i){
							temp = board[i][column];
							board[i][column] = board[i+1][column];
							board[i+1][column] = temp;
						}
					break;
	}
	return flag;
}

int main(){
	int board[N][N];  /* Our board */
	int row, column, input; /* row, column and action variables respectively */
	int flag; /* flag : identifier if the move can be implemented */
	way direction;  /* enumerated type for direction */

	printf("=================WELCOME TO SLIDING PUZZLE GAME=================\n");
	/* Filling the board randomly */
	do{
		filling_board(board);
	}while((is_solved(board)));

	do{
		/* Printing the board */
		printing_board(board);

		/* Getting inputs */
		printf("\nDIRECTION (0: left, 1: right, 2: up, 3: down, 4: give up): ");
		scanf("%d", &input);
		while(input < 0 || input > 4){
			printf("Please enter between 0 and 4 (0: left, 1: right, 2: up, 3: down, 4: give up): ");
			scanf("%d", &input);
		}
		direction = (way)input;
		if (direction == giveup) break;

		printf("ROW (0 - %d): ", N-1);
		scanf("%d", &row);
		while(row < 0 || row > N-1){
			printf("Please enter between 0 - %d: ", N-1);
			scanf("%d", &row);
		}

		printf("COLUMN (0 - %d): ", N-1);
		scanf("%d", &column);
		while(column < 0 || column > N-1){
			printf("Please enter between 0 - %d: ", N-1);
			scanf("%d", &column);
		}

		/* Performing the choosen action */
		flag = movement(direction, row, column, board);
		if (flag != 1) printf("You have entered invalid input.\n"); /* If move cannot be done, an appropriate message will be shown. */
	}while(!(is_solved(board)));

	/* Ending the program for 2 options */
	if (direction == giveup) printf("So long! Good luck next time.\n");
	else{
		printing_board(board);
		printf("Congratulations! You have completed the puzzle.\n");
	}

	return 0;
}