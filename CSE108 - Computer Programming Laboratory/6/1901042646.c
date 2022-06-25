#include <stdio.h>
#include <string.h>

void calculation(int x, int y, int matrix[][y]){
	int i, j;
	int a = 1;
	/* Calculation of each index with formula 2 * (a^2) - 3 */
	for ( i = 0; i < x; ++i){
		for (j = 0; j < y; ++j){
			matrix[i][j] = (2 * a * a) - 3;
			a = a + 1;
		}
	}
}


void average_finder(int x, int y, int (*matrix)[y], double* average){
	int i, j;
	int counter = 0;
	int sum = 0;
	for ( i = 0; i < x; ++i){
		for (j = 0; j < y; ++j){
			if ( (i + j) % 2 == 0){ /* Indexes that sums are even number*/
				sum += matrix[i][j];  /* Summation of elements*/
				counter++;
			}
		}
	}
	*average = (double)sum / counter; /* Calculating average */
}

void interview(const char s1, const char s2, char* s3){
	char s[3]; /* To combine 2 characters given*/
	s[0] = s1;
	s[1] = s2;
	s[2] = '\0';

	s3 = strcat(s3, s); /* Combining string s with our resulting string */
}

int main(){
	/* Variables for part 1 : arrays, average*/
	int matrix1[3][5];
	int matrix2[4][9];
	double average;

	/* Variables for part 2 : strings, result, string, length of string that has maximum characters*/
	char string1[21];
	char string2[21];
	char result[41];
	int i, j, max;

	
	/* ===================AVERAGE FINDER PART =====================*/
	printf("AVERAGE FINDER\n\n");
	printf("Matrix 1:\n");
	calculation(3, 5, matrix1);
	/* Printing each indexes*/
	/************************/
	for ( i = 0; i < 3; ++i){
		for (j = 0; j < 5; ++j){
			printf("%4d    ", matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix 2:\n");
	calculation(4, 9, matrix2);
	for ( i = 0; i < 4; ++i){
		for (j = 0; j < 9; ++j){
			printf("%4d    ", matrix2[i][j]);
		}
		printf("\n");
	}

	average_finder(3, 5, matrix1, &average);
	printf("\nResult 1: %.1lf\n", average);
	average_finder(4, 9, matrix2, &average);
	printf("Result 2: %.1lf\n\n\n", average);


	/*================= CONCATENATION OF STRINGS PART =================*/
	printf("CONCATENATION OF STRINGS\n\n");

	/* Getting inputs */
	printf("Enter first string (max 20 characters long): ");
	scanf("%s", string1);
	printf("Enter second string (max 20 characters long): ");
	scanf("%s", string2);

	/* Finding string that has maximum character */
	if (strlen(string1) > strlen(string2)) max = strlen(string1);
	else max = strlen(string2);
	result[0] = '\0';
	/* Combine strings*/
	for(i = 0; i < max; ++i){
		interview(string1[i], string2[i], result);
	}
	/* Adding extra letters in string2 to result if it has more character than string1 */
	if (strlen(string1) < strlen(string2))
		strcat(result, &string2[strlen(string1)]);

	printf("Result string: %s\n", result);

	return 0;
}