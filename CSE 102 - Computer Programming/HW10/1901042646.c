#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*!!
	for this program, coder thought that in the given text file last line will be empty as in the example text file
	line with double commas ",," is ignored (deleted) as said in the homework forum
	with these 2 exceptions, tasks can be done
 !!*/

typedef struct{	/* Defining structure */
	double budget;
	int genre;
	char* name;
	double score;
	int year;
}Movie;

int number_of_lines(char *text){
	FILE *fp;	/* file pointer    */
	int l = 0;  /* number of lines */
	char c, t; 	/* character that will be read from the file */
	fp = fopen(text, "rt");  /* opening the file to read */
	if (fp == NULL){		 /* checking if file exists  */
		printf("This file does not exist.\n");
		return -1;
	} 
	else{
		while(fscanf(fp, "%c", &c) != EOF){	/* reading the character from the file */
			if (c == '\n') l++; 			/* increasing l by 1 when we enter a new line */
			t = c;
		}
	}
	fclose(fp);
	if (t != '\n') return l+1;
	else return l;
}

int line_size(FILE *fp){
	int length = 0; /* length of the line */
	char c; 		/* character that will be read from the file */
	c = fgetc(fp);
	while (c != '\n' && c != EOF){ /* finding length of the line */
		c = fgetc(fp);
		length++;
	}
	fseek(fp, -(length+1), SEEK_CUR); /* set the cursor to initial value */
	return length;
}

int check_heading(char* heading, Movie *infos, char *temp, int i, char **temp_genres, int *g){
	int j = 0;	/* counter for loop */
	double b;	/* budget value */

	if (strcmp(heading, "budget") == 0){ /* if heading is budget */
		if (strcmp(temp, "unknown") == 0) infos[i].budget = -1; /* value is -1 for unknown budgets */
		else infos[i].budget = strtod(temp, NULL);				/* assigning budget value to our struct */
	}
	else if (strcmp(heading, "genre") == 0){ /* if heading is genre */
		for (j = 0; j < *g; ++j){ /* loop for checking if genre is existed before */
			if (strcmp(temp, temp_genres[j]) == 0){ 
				infos[i].genre = j+1;	/* assigning genre value for movie */
				break;
			}
		}
		if (j == *g){	/* if there is no this type of genre, add this to array */
			(*g)++;		
			infos[i].genre = *g;
			strcpy(temp_genres[j], temp);
		}
	}
	else if (strcmp(heading, "name") == 0){		/* if heading is name */
		infos[i].name = temp; 
	} 					
	else if (strcmp(heading, "score") == 0) infos[i].score = strtod(temp, NULL);	/* if heading is score */
	else if (strcmp(heading, "year") == 0) infos[i].year = (int)strtod(temp, NULL);	/* if heading is year */
}

char** read_movies(FILE *fp, Movie *infos, char *heading1, char *heading2, char *heading3, char *heading4, char *heading5, int total_lines, int *num_of_elements, int *num_of_genres){
	char *line;							/* line to be read from the file */
	int currentline, i,j, g = 0, flag;	/* size of the current line, 2 counters for the loop, genre value, and flag for identifying if movie is existed before respectively */			
	char *t1, *t2, *t3, *t4, *t5;		/* temporary values for the information about the movies */
	char **temp_genres = malloc(total_lines*sizeof(char *)); /* temporary array for genres */
	char **genres;	/* array for genres with less size than temp_genres */

	for (i = 0; i < total_lines; ++i) /* allocate memory for every element for our array of pointers */
		temp_genres[i] = malloc(sizeof(char)*20);
	i = 0;

	fgetc(fp); /* reading 2 extra characters to prevent possible errors caused by end of lines */
	fgetc(fp);
	currentline = line_size(fp); /* size of the current line */
	line = (char *)malloc(currentline*sizeof(char)); /* allocating memory for the current line */

	while (fgets(line, currentline, fp) != NULL){	/* reading lines */
		t1 = strtok(line, ",");						/* dividing line properly */
		t2 = strtok(NULL, ",");
		t3 = strtok(NULL, ",");
		t4 = strtok(NULL, ",");
		t5 = strtok(NULL, ",");

		if (t1 != NULL && t2 != NULL && t3 != NULL && t4 != NULL && t5 != NULL){
			/* send our informations to function that will decide to where that information is going */
			check_heading(heading1, infos, t1, i, temp_genres, &g);
			check_heading(heading2, infos, t2, i, temp_genres, &g);
			check_heading(heading3, infos, t3, i, temp_genres, &g);
			check_heading(heading4, infos, t4, i, temp_genres, &g);
			check_heading(heading5, infos, t5, i, temp_genres, &g);
		}

		/* TO CHECK IF NAME IS EXISTED BEFORE */
		for (j = 0; j < i; ++j){
			if (strcmp(infos[j].name, infos[i].name) == 0){
				if (strcmp(heading1, "name") != 0) check_heading(heading1, infos, t1, j, temp_genres, &g);
				if (strcmp(heading2, "name") != 0) check_heading(heading2, infos, t2, j, temp_genres, &g);
				if (strcmp(heading3, "name") != 0) check_heading(heading3, infos, t3, j, temp_genres, &g);
				if (strcmp(heading4, "name") != 0) check_heading(heading4, infos, t4, j, temp_genres, &g);
				if (strcmp(heading5, "name") != 0) check_heading(heading5, infos, t5, j, temp_genres, &g);
				i--;
				break;
			}
		}
		i++;
		fgetc(fp);
		fgetc(fp);
		currentline = line_size(fp);
		line = (char *)malloc(currentline*sizeof(char));
	}
	*num_of_elements = i;
	*num_of_genres = g;
	genres = malloc(g*sizeof(char*));	/* allocating less memory to genres than temp_genres to use memory efficiently */
	for (i = 0; i < g; ++i)				/* allocating memory for every element for our genres array */
		genres[i] = malloc(sizeof(char)*20);
	for (i = 0; i < g; ++i)				/* assigning values to our genres array from temp_genres array */
		strcpy(genres[i], temp_genres[i]);
	for(i = 0; i < total_lines; ++i)
		free(temp_genres[i]);
	free(temp_genres);
	return genres;
}

void single_selection(Movie *sorted, char **genres, int l, char *parameter){
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, and counter respectively */
	char c;							/* character to skip */
	do{
		printf("\nEnter value: ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 0 || choice >= l){ /* CATCHING POSSIBLE ERRORS */
			printf("%d", l);
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			if (strcmp(parameter, "budget") == 0){	/* unknown values for budget are not included */
				if (sorted[choice].budget != -1) printf("%-15.2f %-15s %-100s %-.1f\t %-d\n\n", sorted[choice].budget, genres[sorted[choice].genre-1], sorted[choice].name, sorted[choice].score, sorted[choice].year);
				else{
					i = choice;
					while (sorted[i].budget == -1) i++;
					choice += i;
					printf("%-15.2f %-15s %-100s %-.1f\t %-d\n\n", sorted[choice].budget, genres[sorted[choice].genre-1], sorted[choice].name, sorted[choice].score, sorted[choice].year);
				}
			}
			else if (sorted[choice].budget == -1) /* Printing wanted index's values */
				printf("%-15s %-15s %-100s %-.1f\t %-d\n\n", "unknown", genres[sorted[choice].genre-1], sorted[choice].name, sorted[choice].score, sorted[choice].year);
			else printf("%-15.2f %-15s %-100s %-.1f\t %-d\n\n", sorted[choice].budget, genres[sorted[choice].genre-1], sorted[choice].name, sorted[choice].score, sorted[choice].year);
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void multiple_selection(Movie *sorted, char **genres, int l, char* parameter){
	int start, end, error, status1, status2, i; /* start and end inputs, error flag for invalid input, status values returned by scanf and counter respectively */
	char c;										/* character to skip */
	do{
		printf("\nEnter start value: "); /* getting input */
		status1 = scanf("%d", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		printf("Enter end value: "); /* getting input */
		status2 = scanf("%d", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 0 || start >= l || end < 0 || end >= l || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\nMovies between %d and %d, sorted by %s\n\n", start, end, parameter);
			for (i = start; i <= end; ++i){
				if (strcmp(parameter, "budget") == 0){ /* unknown values for budget are not included */
					if (sorted[i].budget != -1) printf("%-15.2f %-15s %-100s %-.1f\t %-d\n\n", sorted[i].budget, genres[sorted[i].genre-1], sorted[i].name, sorted[i].score, sorted[i].year);
					else end++;
				}
				else if (sorted[i].budget == -1) /* Printing wanted indexes' values */
					printf("%-15s %-15s %-100s %-.1f\t %-d\n\n", "unknown", genres[sorted[i].genre-1], sorted[i].name, sorted[i].score, sorted[i].year);
				else printf("%-15.2f %-15s %-100s %-.1f\t %-d\n\n", sorted[i].budget, genres[sorted[i].genre-1], sorted[i].name, sorted[i].score, sorted[i].year);
			}
		}
	}while(error);
}

void budget_sort(Movie *sorted, char **genres, int l){
	Movie temp;	/* temporary structure for changing values */
	int i, j, choice, error, status;	/* 2 counters, user input, error flag for invalid input, and status value returned by scanf */
	char c;								/* character to skip */
	for (i = 1; i < l; ++i){ /* sorting the structure by budget */
		for (j = 0; j < i; ++j){
			if (sorted[i].budget < sorted[j].budget){
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	do{
		printf("\n\n1. Single Selection\n"); /* Getting input */
		printf("2. Multiple Selection\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 2){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: single_selection(sorted, genres, l, "budget");
						break;
				case 2: multiple_selection(sorted, genres, l, "budget");
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void genre_sort(Movie *sorted, char **genres, int l){
	Movie temp;	/* temporary structure for changing values */
	int i, j, choice, error, status;	/* 2 counters, user input, error flag for invalid input, and status value returned by scanf */
	char c;								/* character to skip */
	for (i = 1; i < l; ++i){ 			/* sorting the structure by genre */
		for (j = 0; j < i; ++j){
			if (strcmp(genres[sorted[i].genre - 1], genres[sorted[j].genre - 1]) < 0){
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	do{
		printf("\n\n1. Single Selection\n");	/* Getting input */
		printf("2. Multiple Selection\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 2){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: single_selection(sorted, genres, l, "genre");
						break;
				case 2: multiple_selection(sorted, genres, l, "genre");
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void name_sort(Movie *sorted, char **genres, int l){
	Movie temp;/* temporary structure for changing values */
	int i, j, choice, error, status; 	/* 2 counters, user input, error flag for invalid input, and status value returned by scanf */
	char c;								/* character to skip */
	for (i = 1; i < l; ++i){ 			/* sorting the structure by genre */
		for (j = 0; j < i; ++j){
			if (strcmp(sorted[i].name, sorted[j].name) < 0){
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	do{
		printf("\n\n1. Single Selection\n");	/* Getting input */
		printf("2. Multiple Selection\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 2){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: single_selection(sorted, genres, l, "name");
						break;
				case 2: multiple_selection(sorted, genres, l, "name");
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void score_sort(Movie *sorted, char **genres, int l){
	Movie temp;	/* temporary structure for changing values */
	int i, j, choice, error, status;	/* 2 counters, user input, error flag for invalid input, and status value returned by scanf */
	char c;								/* character to skip */
	for (i = 1; i < l; ++i){			/* sorting the structure by genre */
		for (j = 0; j < i; ++j){
			if (sorted[i].score < sorted[j].score){
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	do{
		printf("\n\n1. Single Selection\n"); /* Getting input */
		printf("2. Multiple Selection\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 2){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: single_selection(sorted, genres, l, "score");
						break;
				case 2: multiple_selection(sorted, genres, l, "score");
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void year_sort(Movie *sorted, char **genres, int l){
	Movie temp;	/* temporary structure for changing values */
	int i, j, choice, error, status;	/* 2 counters, user input, error flag for invalid input, and status value returned by scanf */
	char c;								/* character to skip */
	for (i = 1; i < l; ++i){			/* sorting the structure by genre */
		for (j = 0; j < i; ++j){
			if (sorted[i].year < sorted[j].year){
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	do{
		printf("\n\n1. Single Selection\n");	/* Getting input */
		printf("2. Multiple Selection\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 2){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: single_selection(sorted, genres, l, "year");
						break;
				case 2: multiple_selection(sorted, genres, l, "year");
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void first_option(Movie *infos, char **genres, int num_of_elements, int num_of_genres){
	int choice, error, status;	/* input of choice, error flag for invalid input, and status value returned by scanf respectively */
	char c;						/* character to skip */
	do{
		printf("\n\n1. Budget\n");
		printf("2. Genre\n");
		printf("3. Name\n");
		printf("4. Score\n");
		printf("5. Year\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 5){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			switch(choice){
				case 1: budget_sort(infos, genres, num_of_elements);
						break;
				case 2: genre_sort(infos, genres, num_of_elements);
						break;
				case 3: name_sort(infos, genres, num_of_elements);
						break;
				case 4: score_sort(infos, genres, num_of_elements);
						break;
				case 5: year_sort(infos, genres, num_of_elements);
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
}

void second_option(char **genres, int num_of_genres){
	int i;
	printf("\n\n");
	for (i = 0; i < num_of_genres; ++i) /* printing genres */
		printf("%s\n", genres[i]);
}

void third_option(Movie *infos, int num_of_elements){
	int choice_year, selection, error, status1, status2, flag = 0; /* 2 inputs, error flag for invalid input, status values returned by scanf, and flag if there is an input respectively*/
	int i;	/* counter */
	char c;	/* character to skip */
	do{
		error = 0;
		flag = 0;		
		printf("Enter a year: ");		/* Getting input */
		status1 = scanf("%d", &choice_year); 
		if (status1 != 1){		/* catching possible errors */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			do{					/* reading remaining characters if input is not an integer */
				scanf("%c", &c);
			}while(c != '\n');
		}
		else{
			printf("Until (0) or Since (1) %d: ", choice_year);	/* Getting input */
			status2 = scanf("%d", &selection);
			if (status2 != 1 || selection < 0 || selection > 1){	/* catching possible errors */
				printf("You have entered invalid input. Try again.\n\n");
				error = 1;
			}
			else{
				error = 0;
				if (selection == 0){
					for (i = 0; i < num_of_elements; ++i){	/* finding the years less than or equal to given year */
						if (infos[i].year <= choice_year){
							printf("%s\n", infos[i].name);
							flag = 1;
						}
					}
				}
				else if (selection == 1){
					for (i = 0; i < num_of_elements; ++i){	/* finding the years bigger than given year */
						if (infos[i].year > choice_year){
							printf("%s\n", infos[i].name);
							flag = 1;							
						}
					}
				}
				if (flag == 0){	/* if there is no year for the given input */
					printf("\nTRY AGAIN\n\n");
					error = 1;
				}
			}
			if (status2 != 1){	/* catching possible errors */
				do{
					scanf("%c", &c);
				}while(c != '\n');
			}
		}
	}while(error);
}

void fourth_option(Movie *infos, int num_of_elements){
	int selection, error, status1, status2, flag;	/* input, error flag for invalid input, status values returned by scanf, and flag if there is an input respectively*/
	int i;					/* counter */
	double choice_score;	/* input */
	char c;					/* character to skip */
	do{
		error = 0;
		flag = 0;
		printf("Enter a score: ");	/* Getting input */
		status1 = scanf("%lf", &choice_score);
		if (status1 != 1){	/* catching possible errors */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
		else{
			printf("Less (0) or Greater (1) %f: ", choice_score);	/* Getting input */
			status2 = scanf("%d", &selection);
			if (status2 != 1 || selection < 0 || selection > 1){
				printf("You have entered invalid input. Try again.\n\n");
				error = 1;
			}
			else{
				error = 0;
				if (selection == 0){
					for (i = 0; i < num_of_elements; ++i){	/* finding the scores less than given score */
						if (infos[i].score < choice_score){
							printf("%s\n", infos[i].name);
							flag = 1;
						}
					}
				}
				else if (selection == 1){
					for (i = 0; i < num_of_elements; ++i){	/* finding the scores greater than given score */
						if (infos[i].score > choice_score){
							printf("%s\n", infos[i].name);
							flag = 1;							
						}
					}
				}
				if (flag == 0){	/* if there is no movie for the given input */
					printf("\nTRY AGAIN\n\n");
					error = 1;
				}
			}
			if (status2 != 1){	/* catching possible errors */
				do{
					scanf("%c", &c);
				}while(c != '\n');
			}
		}
	}while(error);
}

void fifth_option(Movie *infos, char **genres, int num_of_elements){
	char *wanted_name, *buffer;	/* buffer to get input in a random size, and wanted_name is exact size for given name */
	int i, flag=0;				/* counter and flag for being sure name exists */
	do{
		buffer = (char *)malloc(200*sizeof(char));			/* Allocating memory for buffer */
		printf("\nPlease enter the name of the movie: ");	/* Getting input*/
		scanf(" %[^\n]%*c", buffer);
		wanted_name = (char *)malloc(strlen(buffer)*sizeof(char));	/* Allocating exact size for wanted_name */
		strcpy(wanted_name, buffer);
		free(buffer);
		for (i = 0; i < num_of_elements; ++i){	/* Finding the movie and print its informations */
			if (strcmp(wanted_name, infos[i].name) == 0){
				if (infos[i].budget == -1) printf("Budget: Unknown\n");
				else printf("Budget: %f\n", infos[i].budget);
				printf("Genre:  %s\n", genres[infos[i].genre - 1]);
				printf("Name:   %s\n", infos[i].name);
				printf("Score:  %.1f\n", infos[i].score);
				printf("Year:   %d\n", infos[i].year);
				flag = 1;
			}
		}
		if (flag == 0) printf("There is no such movie. Try again.");
	}while(!flag);
	free(wanted_name);
}

void sixth_option(Movie *infos, int num_of_elements){
	double total_scores = 0;	/* total of all scores */
	int i;						/* counter */
	for (i = 0; i < num_of_elements; ++i)	/* adding all scores */
		total_scores += infos[i].score;
	printf("Average: %f\n", total_scores/num_of_elements);
}

void seventh_option(Movie *infos, char **genres, int num_of_elements, int num_of_genres){
	int i, j, total;	/* 2 counters and total for each genre */
	for (i = 0; i < num_of_genres; ++i){		/* loop for genres */
		total = 0;
		for (j = 0; j < num_of_elements; ++j){	/* loop for movies*/
			if (infos[j].genre == i+1) total++;	/* adding each genres */
		}
		printf("%-15s %d\n", genres[i], total);
	}
}

void options(Movie *infos, char **genres, int num_of_elements, int num_of_genres){
	int choice, status;	/* input of choice and status value returned by scanf respectively */
	char c;				/* character to skip */
	do{
		/* LIST OF OPTIONS */
		printf("***********************************************************************************\n");
		printf("1. List of the Sorted Data\n");
		printf("2. List of the Genres\n");
		printf("3. List of the Movie Through the Years\n");
		printf("4. List of the Movie Through the Scores\n");
		printf("5. All Informations of a Single Movie\n");
		printf("6. Average of the IMDB Scores\n");
		printf("7. Frequence of the Genres\n");
		printf("8. Exit\n\n");
		printf("Please select an operation: ");
		status = scanf("%d", &choice);

		if (status != 1 || choice < 1 || choice > 8) /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
		else{
			switch(choice){
				case 1: first_option(infos, genres, num_of_elements, num_of_genres);
						break;
				case 2: second_option(genres, num_of_genres);
						break;
				case 3: third_option(infos, num_of_elements);
						break;
				case 4: fourth_option(infos, num_of_elements);
						break;
				case 5: fifth_option(infos, genres, num_of_elements);
						break;
				case 6: sixth_option(infos, num_of_elements);
						break;
				case 7: seventh_option(infos, genres, num_of_elements, num_of_genres);
						break;
			}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(choice != 8);
	printf("Good-Bye!\n");
}

void archive(char *text){
	Movie *infos;		/* array of structure Movie */
	FILE *fp;			/* file pointer */
	int i;
	int l, first_line;	/* number of lines and length of the first line respectively */
	int num_of_elements;/* number of valid elements for the array of structure Movie in the end */
	int num_of_genres;	/* number of genres */
	char *headings;		/* string for first line */
	char *heading1, *heading2, *heading3, *heading4, *heading5; /* headings */
	char **genres;

	l = number_of_lines(text);
	if (l == -1) return; /* exit if there is no file */
	else{
		infos = (Movie *)calloc(l, sizeof(Movie));	/* allocating memory for structure */

		fp = fopen(text, "rt");		/* opening the file to read */
		first_line = line_size(fp);	/* length of the first line */
		headings = (char *)malloc(first_line*sizeof(char));	/* allocating memory for headings */

		fgets(headings, first_line, fp);	/* reading first line */
		heading1 = strtok(headings, ",");	/* dividing first line into headings */
		heading2 = strtok(NULL, ",");
		heading3 = strtok(NULL, ",");
		heading4 = strtok(NULL, ",");
		heading5 = strtok(NULL, ",");

		genres = read_movies(fp, infos, heading1, heading2, heading3, heading4, heading5, l, &num_of_elements, &num_of_genres);
		free(headings);

		fclose(fp);
	}
	options(infos, genres, num_of_elements, num_of_genres); /* send what we collected to function that will execute options */
	free(infos);
	free(genres);
}

int main(){
	archive("Movies.txt"); /* Starting our program with 1 single argument which is name of the file */
	return 0;
}