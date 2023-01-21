#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* You can check line 1277 to see movies sorted by year-budget in descending order 
* You can change file name which is sent to the function in line 1288
* -ansi -pedantic-errors flags are used during compilation
*/

/* Defining structures that will be used as linked list */
typedef struct node1{
	int budget, year;
	char *name;
	struct node1 *next;
}Movie_Budget;
typedef struct node2{
	double score;
	char *genre, *name;
	struct node2 *next;
}Movie_Name;

int line_size(FILE *fp){
	int length = 0; /* length of the line */
	char c; 		/* character that will be read from the file */
	for (c = fgetc(fp); c != '\n' && c != EOF; c = fgetc(fp))	/* finding length of the line */
		length++;
	fseek(fp, -(length+1), SEEK_CUR); /* set the cursor to initial value */
	return length;
}

int number_of_lines(char *text){
	FILE *fp;	/* file pointer    */
	int l = 0;  /* number of lines */
	char c; 	/* character that will be read from the file */
	fp = fopen(text, "rt");  /* opening the file to read */
	if (fp == NULL){		 /* checking if file exists  */
		return -1;
	} 
	else{
		while(fscanf(fp, "%c", &c) != EOF){	/* reading the character from the file */
			if (c == '\n') l++; 			/* increasing l by 1 when we enter a new line */
		}
	}
	fclose(fp);
	return l+1;
}

int decompose(char* str, int length, Movie_Budget *temp1, Movie_Name *temp2){
	int i;							/* counter for loop */
	int selection = 0;				/* 0 for budget, 1 for genre, 2 for name, 3 for score, 4 for year */
	int b=0, g=0, n=0, s=0, y=0;	/* indexes of the budget, genre, name, score, year respectively */
	char *tb, *tg, *tn, *ts, *ty;	/* temporary values for every heading */
	tb = (char*)calloc(15, sizeof(char));	/* allocating memory */
	tg = (char*)calloc(15, sizeof(char));
	tn = (char*)calloc(200, sizeof(char));
	ts = (char*)calloc(10, sizeof(char));
	ty = (char*)calloc(6, sizeof(char));
	if(str[0] == '\n') return 0;
	for (i = 0; i < length; ++i){	/* decomposing string into budget, genre, name, score, and year */
		if (str[i] == ',') selection++;
		else{
			switch (selection){
				case 0: tb[b] = str[i];
						b++;
						break;
				case 1: tg[g] = str[i];
						g++;
						break;
				case 2: tn[n] = str[i];
						n++;
						break;
				case 3: ts[s] = str[i];
						s++;
						break;
				case 4: ty[y] = str[i];
						y++;
						break;
			}
		}
	}
	tb[b] = tg[g] = tn[n] = ts[s] = ty[y] = '\0';
	if (tb[0] == 0 || tg[0] == 0 || tn[0] == 0 || ts[0] == 0 || ty[0] == 0){
		/* if any one of the labels is not filled, line is invalid */
		free(tb);
		free(tg);
		free(tn);
		free(ts);
		free(ty);
		return 0;
	}
	/* Filling the first linked list */
	if (strcmp("unknown", tb) == 0)temp1->budget = -1;
	else temp1->budget = strtod(tb, NULL);
	temp1->year = strtod(ty, NULL);
	temp1->name = (char*)calloc(strlen(tn)+1, sizeof(char));
	strcpy(temp1->name, tn);
	temp1->next = NULL;

	/* Filling the second linked list, no need to fill its name section */
	temp2->score = strtod(ts, NULL);
	temp2->genre = (char*)calloc(strlen(tg)+1, sizeof(char));
	strcpy(temp2->genre, tg);
	temp2->next = NULL;

	/* Freeing what we have created in this function */
	free(tb);
	free(tg);
	free(tn);
	free(ts);
	free(ty);
	return 1;
}

void sorted_insert(Movie_Budget **movies_ll1, Movie_Budget *temp1){
	Movie_Budget *pe, *ce;	/* previous entry and current entry respectively */
	pe = ce = *movies_ll1;	/* assigning pointers to the beginning */
	while(ce!=NULL && ce->year > temp1->year){	/* finding the place of our node */
		pe = ce;
		ce = ce->next;
	}
	if (ce == NULL){	/* adding our node to the end */
		pe->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
		pe->next->budget = temp1->budget;
		pe->next->year   = temp1->year;
		pe->next->name   = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
		strcpy(pe->next->name, temp1->name);
		pe->next->next = NULL;
		return;
	}
	else if (ce==pe){	/* if match for year is with the first entry */
		while(ce!=NULL && ce->year == temp1->year && ce->budget > temp1->budget){
			pe = ce;
			ce = ce->next;
		}
		if (ce==pe){	/* adding our node to the beginning */
			pe = (Movie_Budget*)malloc(sizeof(Movie_Budget));
			pe->budget = temp1->budget;
			pe->year   = temp1->year;
			pe->name   = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
			strcpy(pe->name, temp1->name);
			pe->next = ce;
			*movies_ll1 = pe;
			return;
		}
	}
	else{	/* going in the linked list to the proper place for our new node */
		while(ce!=NULL && ce->year == temp1->year && ce->budget > temp1->budget){
			pe = ce;
			ce = ce->next;
		}
	}
	/* adding our node according to budget and year*/	
	pe->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
	pe->next->budget = temp1->budget;
	pe->next->year   = temp1->year;
	pe->next->name   = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
	strcpy(pe->next->name, temp1->name);
	pe->next->next = ce;
}

void remove_entry(Movie_Budget **movies_ll1, char* same_name){
	Movie_Budget *current, *previous;	/* current entry and previous entry to that */
	current = previous = *movies_ll1;
	while (strcmp(current->name, same_name) != 0 && current!=NULL){	/* finding the entry that will be removed */
		previous = current;
		current = current->next;
	}
	if (current==NULL);
	else{
		if (current != previous) previous->next = current->next;	/* relinking remaining entries */
		else *movies_ll1 = current->next;							/* removed entry is the first entry */

		free(current);												/* freeing removed entry */}
}

Movie_Budget* budget_sorted_list(Movie_Budget *movies_ll1){
	Movie_Budget *head, *prev, *budget_sorted = (Movie_Budget*)malloc(sizeof(Movie_Budget));
	head = prev = budget_sorted;	/* head of the list, previous node to where we are currently, and current node respectively */

	/* filling first node */
	budget_sorted->name = (char*)malloc(strlen(movies_ll1->name)+1);
	strcpy(budget_sorted->name, movies_ll1->name);
	budget_sorted->budget = movies_ll1->budget;
	budget_sorted->year   = movies_ll1->year;
	budget_sorted->next   = NULL;
	movies_ll1 = movies_ll1->next;

	while (movies_ll1 != NULL){
		/* checking the whole budget sorted list to insert the every movie node to its correct place */
		while (budget_sorted != NULL){
			if (movies_ll1->budget < budget_sorted->budget){
				if (budget_sorted==prev){
					/* inserting to the head */
					head = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					head->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(head->name, movies_ll1->name);
					head->budget = movies_ll1->budget;
					head->year = movies_ll1->year;
					head->next = budget_sorted;
				}
				else{
					/* inserting to the middle */
					prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(prev->next->name, movies_ll1->name);
					prev->next->budget = movies_ll1->budget;
					prev->next->year   = movies_ll1->year;
					prev->next->next   = budget_sorted;
				}
				break;
			}
			prev = budget_sorted;
			budget_sorted = budget_sorted->next;
		}
		if (budget_sorted == NULL){
			/* inserting to the end */
			prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
			prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
			strcpy(prev->next->name, movies_ll1->name);
			prev->next->budget = movies_ll1->budget;
			prev->next->year   = movies_ll1->year;
			prev->next->next = NULL;
		}
		/* going to the next node */
		prev = budget_sorted = head;
		movies_ll1 = movies_ll1->next;
	}
	return head;
}

Movie_Budget* name_sorted_list(Movie_Budget *movies_ll1){
	Movie_Budget *head, *prev, *name_sorted = (Movie_Budget*)malloc(sizeof(Movie_Budget));
	head = prev = name_sorted;	/* head of the list, previous node to where we are currently, and current node respectively */

	/* filling first node */
	name_sorted->name = (char*)malloc(strlen(movies_ll1->name)+1);
	strcpy(name_sorted->name, movies_ll1->name);
	name_sorted->budget = movies_ll1->budget;
	name_sorted->year   = movies_ll1->year;
	name_sorted->next   = NULL;
	movies_ll1 = movies_ll1->next;

	while (movies_ll1 != NULL){
		/* checking the whole name sorted list to insert the every movie node to its correct place */
		while (name_sorted != NULL){
			if (strcmp(movies_ll1->name, name_sorted->name) < 0){
				if (name_sorted==prev){
					/* inserting to the head */
					head = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					head->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(head->name, movies_ll1->name);
					head->budget = movies_ll1->budget;
					head->year = movies_ll1->year;
					head->next = name_sorted;
				}
				else{
					/* inserting to the middle */
					prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(prev->next->name, movies_ll1->name);
					prev->next->budget = movies_ll1->budget;
					prev->next->year   = movies_ll1->year;
					prev->next->next   = name_sorted;
				}
				break;
			}
			prev = name_sorted;
			name_sorted = name_sorted->next;
		}
		if (name_sorted == NULL){
			/* inserting to the end */
			prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
			prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
			strcpy(prev->next->name, movies_ll1->name);
			prev->next->budget = movies_ll1->budget;
			prev->next->year   = movies_ll1->year;
			prev->next->next = NULL;
		}
		/* going to the next node */
		prev = name_sorted = head;
		movies_ll1 = movies_ll1->next;
	}
	return head;
}

Movie_Budget* year_sorted_list(Movie_Budget *movies_ll1){
	Movie_Budget *head, *prev, *year_sorted = (Movie_Budget*)malloc(sizeof(Movie_Budget));
	head = prev = year_sorted;	/* head of the list, previous node to where we are currently, and current node respectively */

	/* filling first node */
	year_sorted->name = (char*)malloc(strlen(movies_ll1->name)+1);
	strcpy(year_sorted->name, movies_ll1->name);
	year_sorted->budget = movies_ll1->budget;
	year_sorted->year   = movies_ll1->year;
	year_sorted->next   = NULL;
	movies_ll1 = movies_ll1->next;

	while (movies_ll1 != NULL){
		/* checking the whole year sorted list to insert the every movie node to its correct place */
		while (year_sorted != NULL){
			if (movies_ll1->year < year_sorted->year){
				if (year_sorted==prev){
					/* inserting to the head */
					head = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					head->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(head->name, movies_ll1->name);
					head->budget = movies_ll1->budget;
					head->year = movies_ll1->year;
					head->next = year_sorted;
				}
				else{
					/* inserting to the middle */
					prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
					prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
					strcpy(prev->next->name, movies_ll1->name);
					prev->next->budget = movies_ll1->budget;
					prev->next->year   = movies_ll1->year;
					prev->next->next   = year_sorted;
				}
				break;
			}
			prev = year_sorted;
			year_sorted = year_sorted->next;
		}
		if (year_sorted == NULL){
			/* inserting to the end */
			prev->next = (Movie_Budget*)malloc(sizeof(Movie_Budget));
			prev->next->name = (char*)malloc(strlen(movies_ll1->name)+1);
			strcpy(prev->next->name, movies_ll1->name);
			prev->next->budget = movies_ll1->budget;
			prev->next->year   = movies_ll1->year;
			prev->next->next = NULL;
		}
		/* going to the next node */
		prev = year_sorted = head;
		movies_ll1 = movies_ll1->next;
	}
	return head;
}

Movie_Name* score_sorted_list(Movie_Name *movies_ll2){
	Movie_Name *head, *prev, *score_sorted = (Movie_Name*)malloc(sizeof(Movie_Name));
	head = prev = score_sorted;	/* head of the list, previous node to where we are currently, and current node respectively */

	/* filling first node */
	score_sorted->name = (char*)malloc(strlen(movies_ll2->name)+1);
	strcpy(score_sorted->name, movies_ll2->name);
	score_sorted->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
	strcpy(score_sorted->genre, movies_ll2->genre);
	score_sorted->score = movies_ll2->score;
	score_sorted->next   = NULL;
	movies_ll2 = movies_ll2->next;

	while (movies_ll2 != NULL){
		/* checking the whole score sorted list to insert the every movie node to its correct place */
		while (score_sorted != NULL){
			if (movies_ll2->score < score_sorted->score){
				if (score_sorted==prev){
					/* inserting to the head */
					head = (Movie_Name*)malloc(sizeof(Movie_Name));
					head->name = (char*)malloc(strlen(movies_ll2->name)+1);
					strcpy(head->name, movies_ll2->name);
					head->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
					strcpy(head->genre, movies_ll2->genre);
					head->score = movies_ll2->score;
					head->next = score_sorted;
				}
				else{
					/* inserting to the middle */
					prev->next = (Movie_Name*)malloc(sizeof(Movie_Name));
					prev->next->name = (char*)malloc(strlen(movies_ll2->name)+1);
					strcpy(prev->next->name, movies_ll2->name);
					prev->next->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
					strcpy(prev->next->genre, movies_ll2->genre);
					prev->next->score = movies_ll2->score;
					prev->next->next   = score_sorted;
				}
				break;
			}
			prev = score_sorted;
			score_sorted = score_sorted->next;
		}
		if (score_sorted == NULL){
			/* inserting to the end */
			prev->next = (Movie_Name*)malloc(sizeof(Movie_Name));
			prev->next->name = (char*)malloc(strlen(movies_ll2->name)+1);
			strcpy(prev->next->name, movies_ll2->name);
			prev->next->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
			strcpy(prev->next->genre, movies_ll2->genre);
			prev->next->score   = movies_ll2->score;
			prev->next->next = NULL;
		}
		/* going to the next node */
		prev = score_sorted = head;
		movies_ll2 = movies_ll2->next;
	}
	return head;
}

Movie_Name* genre_sorted_list(Movie_Name *movies_ll2){
	Movie_Name *head, *prev, *score_sorted = (Movie_Name*)malloc(sizeof(Movie_Name));
	head = prev = score_sorted;	/* head of the list, previous node to where we are currently, and current node respectively */

	/* filling first node */
	score_sorted->name = (char*)malloc(strlen(movies_ll2->name)+1);
	strcpy(score_sorted->name, movies_ll2->name);
	score_sorted->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
	strcpy(score_sorted->genre, movies_ll2->genre);
	score_sorted->score = movies_ll2->score;
	score_sorted->next   = NULL;
	movies_ll2 = movies_ll2->next;

	while (movies_ll2 != NULL){
		/* checking the whole genre sorted list to insert the every movie node to its correct place */
		while (score_sorted != NULL){
			if (strcmp(movies_ll2->genre, score_sorted->genre) < 0){
				if (score_sorted==prev){
					/* inserting to the head */
					head = (Movie_Name*)malloc(sizeof(Movie_Name));
					head->name = (char*)malloc(strlen(movies_ll2->name)+1);
					strcpy(head->name, movies_ll2->name);
					head->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
					strcpy(head->genre, movies_ll2->genre);
					head->score = movies_ll2->score;
					head->next = score_sorted;
				}
				else{
					/* inserting to the middle */
					prev->next = (Movie_Name*)malloc(sizeof(Movie_Name));
					prev->next->name = (char*)malloc(strlen(movies_ll2->name)+1);
					strcpy(prev->next->name, movies_ll2->name);
					prev->next->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
					strcpy(prev->next->genre, movies_ll2->genre);
					prev->next->score = movies_ll2->score;
					prev->next->next   = score_sorted;
				}
				break;
			}
			prev = score_sorted;
			score_sorted = score_sorted->next;
		}
		if (score_sorted == NULL){
			/* inserting to the end */
			prev->next = (Movie_Name*)malloc(sizeof(Movie_Name));
			prev->next->name = (char*)malloc(strlen(movies_ll2->name)+1);
			strcpy(prev->next->name, movies_ll2->name);
			prev->next->genre = (char*)malloc(strlen(movies_ll2->genre)+1);
			strcpy(prev->next->genre, movies_ll2->genre);
			prev->next->score   = movies_ll2->score;
			prev->next->next = NULL;
		}
		/* going to the next node */
		prev = score_sorted = head;
		movies_ll2 = movies_ll2->next;
	}
	return head;
}

void single_selection_budget(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Budget *budget_sorted, *head;	/* movies sorted by budget, and head of this list */
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, counter, and length of the list respectively */
	int num_of_unknowns;			/* number of unknowns */
	char c;							/* character to skip */
	head = budget_sorted = budget_sorted_list(movies_ll1);
	do{
		num_of_unknowns = 0;
		budget_sorted = head;
		printf("\nEnter value (at least 1 -- unknown budgets are not included): ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 1 || choice > l){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			/* passing the unknown budgets */
			while(budget_sorted->budget == -1){	budget_sorted=budget_sorted->next; num_of_unknowns++;}
			if (num_of_unknowns + choice <= l){
				for (i=0; i<choice-1; i++) budget_sorted = budget_sorted->next;	/* going to intended budget */
				while(strcmp(budget_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", budget_sorted->budget, movies_ll2->genre, budget_sorted->name, movies_ll2->score, budget_sorted->year);
			}
			else{printf("You are out of range, try again.\n"); error=1;}
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
	free(head);
}

void multiple_selection_budget(Movie_Budget *movies_ll1, Movie_Name *movies_ll2){
	Movie_Budget *budget_sorted, *head_b;		/* movies sorted by budget, and head of this list */
	Movie_Name *head = movies_ll2;				/* head of the movies_ll2 */
	int start, end, error, status1, status2, i; /* start and end inputs, error flag for invalid input, status values returned by scanf and counter respectively */
	int flag=0;									/* flag for identify that movie exists */
	char c;										/* character to skip */
	head_b = budget_sorted = budget_sorted_list(movies_ll1);
	do{
		budget_sorted = head_b;
		printf("\nEnter start value (your input is included): "); /* getting input */
		status1 = scanf("%d", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}
		printf("Enter end value (your input is included): "); /* getting input */
		status2 = scanf("%d", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 0 || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			continue;
		}
		/* getting the start value budget */
		while (budget_sorted!=NULL && budget_sorted->budget < start) budget_sorted = budget_sorted->next;
		if (budget_sorted == NULL){printf("There is no movie between these budgets, try again.\n"); error = 1;}
		else{
			error = 0;
			printf("\nMovies which have budgets between %d and %d:\n\n", start, end);
			while(budget_sorted!=NULL && budget_sorted->budget <= end){	/* getting the intended budget */
				while(strcmp(budget_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", budget_sorted->budget, movies_ll2->genre, budget_sorted->name, movies_ll2->score, budget_sorted->year);
				budget_sorted = budget_sorted->next;
				movies_ll2 = head;
				flag = 1;
			}
			if (flag == 0){error = 1; printf("There is no movie between these budgets, try again.\n");}
		}
	}while(error);
	free(head_b);
}

void single_selection_genre(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Name *genre_sorted;		/* movies sorted by genres */
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, counter, and length of the list respectively */
	char c;							/* character to skip */
	genre_sorted = genre_sorted_list(movies_ll2);
	do{
		printf("\nEnter value (at least 1): ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 1 || choice > l){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			for (i=0; i<choice-1; i++) genre_sorted = genre_sorted->next;	/* going to intended genre */
			while(strcmp(genre_sorted->name, movies_ll1->name) != 0) movies_ll1 = movies_ll1->next;	/* getting the same movie in first linked list for year and budget */
			printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", movies_ll1->budget, genre_sorted->genre, genre_sorted->name, genre_sorted->score, movies_ll1->year);
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
	free(genre_sorted);
}

void multiple_selection_genre(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Name *genre_sorted;					/* sorted linked list by genres */
	Movie_Budget *head = movies_ll1;			/* head of the movies_ll1 */
	int start, end, error, status1, status2, i; /* start and end inputs, error flag for invalid input, status values returned by scanf and counter respectively */
	char c;										/* character to skip */
	genre_sorted = genre_sorted_list(movies_ll2);
	do{
		printf("\nEnter start value (your input is included): "); /* getting input */
		status1 = scanf("%d", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		printf("Enter end value (your input is included): "); /* getting input */
		status2 = scanf("%d", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 1 || start > l || end > l || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			for(i=0; i<start-1; i++) genre_sorted=genre_sorted->next;	/* iterating the nodes to the start value */
			for(i=0; i<end-start+1;i++){								/* printing nodes between start value and end value */
				while(strcmp(genre_sorted->name, movies_ll1->name) != 0) movies_ll1 = movies_ll1->next;	/* getting the same movie in first linked list for year and budget */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", movies_ll1->budget, genre_sorted->genre, genre_sorted->name, genre_sorted->score, movies_ll1->year);
				movies_ll1 = head;
				genre_sorted = genre_sorted->next;
			}
		}
	}while(error);
	free(genre_sorted);
}

void single_selection_name(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Budget *name_sorted;		/* movies sorted by name */
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, counter, and length of the list respectively */
	char c;							/* character to skip */
	name_sorted = name_sorted_list(movies_ll1);
	do{
		printf("\nEnter value (at least 1): ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 1 || choice > l){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			for (i=0; i<choice-1; i++) name_sorted = name_sorted->next;	/* going to intended name */
			while(strcmp(name_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
			printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", name_sorted->budget, movies_ll2->genre, name_sorted->name, movies_ll2->score, name_sorted->year);
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
	free(name_sorted);
}

void multiple_selection_name(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Budget *name_sorted;					/* movies sorted by name */
	Movie_Name *head = movies_ll2;				/* head of the second linked list */
	int start, end, error, status1, status2, i; /* start and end inputs, error flag for invalid input, status values returned by scanf and counter respectively */
	char c;										/* character to skip */
	name_sorted = name_sorted_list(movies_ll1);
	do{
		printf("\nEnter start value (your input is included): "); /* getting input */
		status1 = scanf("%d", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		printf("Enter end value (your input is included): "); /* getting input */
		status2 = scanf("%d", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 1 || start > l || end > l || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			for(i=0; i<start-1; i++) name_sorted=name_sorted->next;		/* iterating the nodes to the start value */
			for(i=0; i<end-start+1;i++){								/* printing nodes between start value and end value */
				while(strcmp(name_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", name_sorted->budget, movies_ll2->genre, name_sorted->name, movies_ll2->score, name_sorted->year);
				movies_ll2 = head;
				name_sorted = name_sorted->next;
			}
		}
	}while(error);
	free(name_sorted);
}

void single_selection_score(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Name *score_sorted, *head;/* movies sorted by scores, and head of this list */
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, counter, and length of the list respectively */
	char c;							/* character to skip */
	head = score_sorted = score_sorted_list(movies_ll2);
	do{
		score_sorted = head;
		printf("\nEnter value (at least 1): ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 1 || choice > l){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			for (i=0; i<choice-1; i++) score_sorted = score_sorted->next;	/* going to intended score */
			while(strcmp(score_sorted->name, movies_ll1->name) != 0) movies_ll1 = movies_ll1->next;	/* getting the same movie in first linked list for year and budget */
			printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", movies_ll1->budget, score_sorted->genre, score_sorted->name, score_sorted->score, movies_ll1->year);
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
	free(head);
}

void multiple_selection_score(Movie_Budget *movies_ll1, Movie_Name *movies_ll2){
	Movie_Name *score_sorted, *head_s;	/* movies sorted by score, and head of this list  */
	Movie_Budget *head = movies_ll1;	/* head of the movies_ll1 */
	double start, end; 					/* start and end inputs */
	int error, status1, status2, i; 	/* error flag for invalid input, status values returned by scanf and counter respectively */
	int flag = 0;						/* flag for identify that movie exists */
	char c;								/* character to skip */
	head_s = score_sorted = score_sorted_list(movies_ll2);
	do{
		score_sorted = head_s;
		printf("\nEnter start value (your input is included): "); /* getting input */
		status1 = scanf("%lf", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}
		printf("Enter end value (your input is included): "); /* getting input */
		status2 = scanf("%lf", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 0 || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			continue;
		}
		/* getting the start value budget */
		while (score_sorted!=NULL && score_sorted->score < start) score_sorted = score_sorted->next;
		if (score_sorted == NULL){printf("There is no movie between these scores, try again.\n"); error = 1;}
		else{
			error = 0;
			printf("\nMovies which have score between %f and %f:\n\n", start, end);
			while(score_sorted!=NULL && score_sorted->score <= end){	/* getting the intended score */
				while(strcmp(score_sorted->name, movies_ll1->name) != 0) movies_ll1 = movies_ll1->next;	/* getting the same movie in first linked list for budget and year */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", movies_ll1->budget, score_sorted->genre, score_sorted->name, score_sorted->score, movies_ll1->year);
				score_sorted = score_sorted->next;
				movies_ll1 = head;
				flag = 1;
			}
			if (flag == 0){error = 1; printf("There is no movie between these scores, try again.\n");}
		}
	}while(error);
	free(head_s);
}

void single_selection_year(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	Movie_Budget *year_sorted, *head;/* movies sorted by year, and head of this list */
	int choice, error, status, i;	/* input of choice, error flag for invalid input, status value returned by scanf, counter, and length of the list respectively */
	char c;							/* character to skip */
	head = year_sorted = year_sorted_list(movies_ll1);
	do{
		year_sorted = head;
		printf("\nEnter value (at least 1): ");
		status = scanf("%d", &choice);
		if (status != 1 || choice < 1 || choice > l){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
		}
		else{
			error = 0;
			printf("\n%d. Movie\n\n", choice);
			for (i=0; i<choice-1; i++) year_sorted = year_sorted->next;	/* going to intended year */
			while(strcmp(year_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
			printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", year_sorted->budget, movies_ll2->genre, year_sorted->name, movies_ll2->score, year_sorted->year);
		}
		if (status != 1){ /* reading remaining characters if input is not an integer */
			do{
				scanf("%c", &c);
			}while(c != '\n');
		}
	}while(error);
	free(head);
}

void multiple_selection_year(Movie_Budget *movies_ll1, Movie_Name *movies_ll2){
	Movie_Budget *year_sorted, *head_year;		/* movies sorted by year, and head of this list */
	Movie_Name *head = movies_ll2;				/* head of the movies_ll2 */
	int start, end, error, status1, status2, i; /* start and end inputs, error flag for invalid input, status values returned by scanf and counter respectively */
	int flag=0;									/* flag for identify that movie exists */
	char c;										/* character to skip */
	head_year = year_sorted = year_sorted_list(movies_ll1);
	do{
		year_sorted = head_year;
		printf("\nEnter start value (your input is included): "); /* getting input */
		status1 = scanf("%d", &start);
		if (status1 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}
		printf("Enter end value (your input is included): "); /* getting input */
		status2 = scanf("%d", &end);
		if (status2 != 1){ /* CATCHING POSSIBLE ERRORS */
			error = 1;
			printf("You have entered invalid input. Try again.\n\n");
			do{
				scanf("%c", &c);
			}while(c != '\n');
			continue;
		}

		if (start < 0 || end < start){ /* CATCHING POSSIBLE ERRORS */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			continue;
		}
		/* getting the start value year */
		while (year_sorted!=NULL && year_sorted->year < start) year_sorted = year_sorted->next;
		if (year_sorted == NULL){printf("There is no movie between these years, try again.\n"); error = 1;}
		else{
			error = 0;
			printf("\nMovies which have year between %d and %d:\n\n", start, end);
			while(year_sorted!=NULL && year_sorted->year <= end){	/* getting the intended year */
				while(strcmp(year_sorted->name, movies_ll2->name) != 0) movies_ll2 = movies_ll2->next;	/* getting the same movie in second linked list for score and genre */
				printf("%-15d %-15s %-150s %-.1f\t %-d\n\n", year_sorted->budget, movies_ll2->genre, year_sorted->name, movies_ll2->score, year_sorted->year);
				year_sorted = year_sorted->next;
				movies_ll2 = head;
				flag = 1;
			}
			if (flag == 0){error = 1; printf("There is no movie between these years, try again.\n");}
		}
	}while(error);
	free(head_year);
}

void sort(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l, char *heading){
	int choice, error, status;	/* user input, error flag for invalid input, and status value returned by scanf */
	char c;						/* character to skip */
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
				case 1: if (strcmp(heading, "budget")==0) single_selection_budget(movies_ll1, movies_ll2, l);
						else if (strcmp(heading, "genre")==0) single_selection_genre(movies_ll1, movies_ll2, l);
						else if (strcmp(heading, "name")==0) single_selection_name(movies_ll1, movies_ll2, l);
						else if (strcmp(heading, "score")==0) single_selection_score(movies_ll1, movies_ll2, l);
						else if (strcmp(heading, "year") ==0) single_selection_year(movies_ll1, movies_ll2, l);
						break;
				case 2: if (strcmp(heading, "budget")==0) multiple_selection_budget(movies_ll1, movies_ll2);
						else if (strcmp(heading, "genre")==0) multiple_selection_genre(movies_ll1, movies_ll2,l);
						else if (strcmp(heading, "name")==0) multiple_selection_name(movies_ll1, movies_ll2, l);
						else if (strcmp(heading, "score")==0) multiple_selection_score(movies_ll1, movies_ll2);
						else if (strcmp(heading, "year")==0) multiple_selection_year(movies_ll1, movies_ll2);
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

void first_option(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
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
				case 1: sort(movies_ll1, movies_ll2, l, "budget");
						break;
				case 2: sort(movies_ll1, movies_ll2, l, "genre");
						break;
				case 3: sort(movies_ll1, movies_ll2, l, "name");
						break;
				case 4: sort(movies_ll1, movies_ll2, l, "score");
						break;
				case 5: sort(movies_ll1, movies_ll2, l, "year");
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

void third_option(Movie_Budget *movies_ll1){
	int choice_year, selection, error, status1, status2, flag = 0; /* 2 inputs, error flag for invalid input, status values returned by scanf, and flag if there is an input respectively*/
	char c;	/* character to skip */
	Movie_Budget *year_sorted, *head;	/* head of the first linked list */
	head = year_sorted = year_sorted_list(movies_ll1);
	do{
		year_sorted = head;
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
			printf("Until (0) or Since (1) %d (%d included): ", choice_year, choice_year);	/* Getting input */
			status2 = scanf("%d", &selection);
			if (status2 != 1 || selection < 0 || selection > 1){	/* catching possible errors */
				printf("You have entered invalid input. Try again.\n\n");
				error = 1;
			}
			else{
				error = 0;
				if (selection == 0){
					/* finding the years less than or equal to given year */
					while (year_sorted!=NULL){
						if(year_sorted->year <= choice_year){printf("%s\n", year_sorted->name); flag=1;}
						else if (year_sorted->year > choice_year) break;
						year_sorted = year_sorted->next;
					}
				}
				else if (selection == 1){
					/* finding the years bigger than or equal to given year */
					while (year_sorted!=NULL){
						if(year_sorted->year >= choice_year){printf("%s\n", year_sorted->name); flag=1;}
						year_sorted = year_sorted->next;
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
	free(head);
}

void fourth_option(Movie_Name *movies_ll2){
	int selection, error, status1, status2, flag = 0; /* input, error flag for invalid input, status values returned by scanf, and flag if there is an input respectively*/
	double choice_score;	/* score input */
	char c;	/* character to skip */
	Movie_Name *score_sorted, *head;	/* head of the first linked list */
	head = score_sorted = score_sorted_list(movies_ll2);
	do{
		score_sorted = head;
		error = 0;
		flag = 0;		
		printf("Enter a score: ");		/* Getting input */
		status1 = scanf("%lf", &choice_score); 
		if (status1 != 1){		/* catching possible errors */
			printf("You have entered invalid input. Try again.\n\n");
			error = 1;
			do{					/* reading remaining characters if input is not an integer */
				scanf("%c", &c);
			}while(c != '\n');
		}
		else{
			printf("Less (0) or Greater (1) %f (%f included): ", choice_score, choice_score);	/* Getting input */
			status2 = scanf("%d", &selection);
			if (status2 != 1 || selection < 0 || selection > 1){	/* catching possible errors */
				printf("You have entered invalid input. Try again.\n\n");
				error = 1;
			}
			else{
				error = 0;
				if (selection == 0){
					/* finding the scores less than or equal to given score */
					while (score_sorted!=NULL){
						if(score_sorted->score <= choice_score){printf("%s\n", score_sorted->name); flag=1;}
						else if (score_sorted->score > choice_score) break;
						score_sorted = score_sorted->next;
					}
				}
				else if (selection == 1){
					/* finding the scores bigger than or equal to given score */
					while (score_sorted!=NULL){
						if(score_sorted->score >= choice_score){printf("%s\n", score_sorted->name); flag=1;}
						score_sorted = score_sorted->next;
					}
				}
				if (flag == 0){	/* if there is no score for the given input */
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
	free(head);
}

void fifth_option(Movie_Budget *movies_ll1, Movie_Name *movies_ll2){
	char *str, flag = 1;			/* movie name, and flag to control the loop */
	Movie_Budget *head = movies_ll1;/* head of the movies_ll1 */
	str = (char*)malloc(200);		/* allocating memory for str */
	do{
		movies_ll1 = head;
		/* getting input */
		printf("Please enter the name of the movie: ");
		scanf(" %[^\n]%*c", str);
		while(movies_ll1!=NULL){
			/* searching list for the movie */
			if(strcmp(movies_ll1->name, str)==0){
				while(strcmp(movies_ll2->name, str) != 0) movies_ll2=movies_ll2->next; /* searching the second list for genre and score */
				/* printing the informations */
				if (movies_ll1->budget == -1) printf("Budget: Unknown\n");
				else printf("Budget: %d\n", movies_ll1->budget);
				if ((movies_ll2->genre)[0] >= 'a' && (movies_ll2->genre)[0] <= 'z') printf("Genre : %c%s\n", (movies_ll2->genre)[0]-32, movies_ll2->genre + 1);
				else printf("Genre : %s\n", movies_ll2->genre);
				if (str[0] >= 'a' && str[0] <= 'z') printf("Name  : %c%s\n", str[0]-32, str+1);
				else printf("Name  : %s\n", str);
				printf("Score : %.1f\n", movies_ll2->score);
				printf("Year  : %d\n\n", movies_ll1->year);
				flag = 0;
				break;
			}
			movies_ll1=movies_ll1->next;
		}
		if (flag == 1) printf("This film does not exist, try again.\n"); 
	}while(flag);
	free(str);
}

void sixth_option(Movie_Name *movies_ll2, int l){
	double total=0; /* total of the scores */
	while (movies_ll2!=NULL){total += movies_ll2->score; movies_ll2=movies_ll2->next;}
	printf("Average: %f\n\n", total/l);
}

void seventh_option(Movie_Name *movies_ll2, char **genres, int num_of_genres){
	int *frequency;	/* holds frequency numbers of every genre */
	int i;			/* counter for loop */
	Movie_Name *head = movies_ll2;
	frequency = (int*)calloc(num_of_genres, sizeof(int));	/* allocating memory for frequency */
	for (i=0; i<num_of_genres;i++){
		/* searching the array and increase the number for each genre when it occurs */
		while (movies_ll2!=NULL){if(strcmp(movies_ll2->genre, genres[i])==0) frequency[i]++; movies_ll2=movies_ll2->next;} 
		movies_ll2 = head;
	}
	for (i=0; i<num_of_genres;i++){
		/* printing frequency of genres */
		printf("%-20s   %d\n", genres[i], frequency[i]);
	}
	free(frequency);
}

void menu_part(Movie_Budget *movies_ll1, Movie_Name *movies_ll2, int l){
	int choice, status;	/* input of choice and status value returned by scanf respectively */
	char c;				/* character to skip */
	int i;				/* counter for loop*/
	Movie_Name *head = movies_ll2;	/* head of the second linked list */
	int num_of_genres=0;/* total number of genres */
	int flag = 1;		/* flag to identify if genre occurs in the linked list before */
	char **temp_genres = malloc(l*sizeof(char *));	/* temporary array for genres */
	char **genres;									/* array for genres with less size than temp_genres */

	for (i = 0; i < l; ++i) temp_genres[i] = malloc(sizeof(char)*20);	/* allocate memory for every element for our array of pointers */
	while(movies_ll2!=NULL){											/* filling our dynamically allocated array with genres (every genre has to appear just 1 time) */
		for(i=0;i<num_of_genres;i++){ if (strcmp(movies_ll2->genre, temp_genres[i]) == 0) flag = 0;}
		if (flag == 1){ strcpy(temp_genres[num_of_genres], movies_ll2->genre); num_of_genres++;}
		flag=1;  movies_ll2=movies_ll2->next;
	}
	genres = malloc(num_of_genres*sizeof(char*));	/* allocating exact size for genres */
	for (i = 0; i < num_of_genres; ++i){genres[i] = malloc(sizeof(char)*20); strcpy(genres[i], temp_genres[i]);}	/* filling the genres array */
	for (i = 0; i < l; ++i) free(temp_genres[i]);	/* freeing temporary array */
	free(temp_genres);

	movies_ll2=head;
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
				case 1: first_option(movies_ll1, movies_ll2, l);
						break;
				case 2: for(i=0; i<num_of_genres;i++) printf("%s\n", genres[i]);
						break;
				case 3: third_option(movies_ll1);
						break;
				case 4: fourth_option(movies_ll2);
						break;
				case 5: fifth_option(movies_ll1, movies_ll2);
						break;
				case 6: sixth_option(movies_ll2, l);
						break;
				case 7: seventh_option(movies_ll2, genres, num_of_genres);
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

void program(char *text){
	Movie_Budget *movies_ll1, *temp1;			/* linked list that will be sorted by year/budget and a temporary node */
	Movie_Name *movies_ll2, *temp2, *t;			/* other linked list for movies and temporary nodes */
	FILE *fp;									/* file pointer */
	int lines, length, i, flag=-1, flag2=0;		/* number of lines in text file, length of the line, counter for loop, and flags to identify first assignment and existance of the movie */
	int num_of_nodes;							/* number of nodes */
	char *str;									/* string to be read from the text file */

	lines = number_of_lines(text);
	if (lines == -1) printf("There is not a file named %s.\n", text);	/* checking if file exists */
	else{
		fp = fopen(text, "rt");

		/* Reading First Line - Headings */
		length = line_size(fp);
		str = (char*)calloc(length+1, sizeof(char));
		fgets(str, length+1, fp);	/* getting the line */
		fgetc(fp);					/* extra character reading for end of line */
		free(str);					/* freeing string */

		/* Reading All Lines and Filling Linked Lists */
		for (i = 0; i < lines; ++i){
			length = line_size(fp);
			str = (char*)calloc(length+1, sizeof(char));
			fgets(str, length+1, fp);

			temp1 = (Movie_Budget*)malloc(sizeof(Movie_Budget));	/* allocating memory for temporary nodes */
			temp2 = (Movie_Name*)malloc(sizeof(Movie_Name));

			if (decompose(str, length, temp1, temp2) != 0){			/* decomposing the read line */
				if (flag == -1){									/* assign values for the linked lists first time */
					movies_ll1 = (Movie_Budget*)malloc(sizeof(Movie_Budget));	/* allocating memory for linked lists */
					movies_ll2 = (Movie_Name*)malloc(sizeof(Movie_Name));

					/* Filling Linked Lists With The Nodes That Are Read */
					movies_ll1->budget = temp1->budget;
					movies_ll1->year   = temp1->year;
					movies_ll1->name   = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
					strcpy(movies_ll1->name, temp1->name);
					movies_ll1->next = NULL;
					movies_ll2->score = temp2->score;
					movies_ll2->name = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
					strcpy(movies_ll2->name, temp1->name);
					movies_ll2->genre = (char*)calloc(strlen(temp2->genre)+1, sizeof(char));
					strcpy(movies_ll2->genre, temp2->genre);
					movies_ll2->next = NULL;
					flag = 0;
				}
				else{
					t = movies_ll2;
					while (t!=NULL){
						if (strcmp(t->name, temp1->name) == 0){	/* checking if name exists in the list */
							flag2 = 1;
							/* changing values with the new entry for second linked list */
							t->score = temp2->score;
							t->genre = (char*)calloc(strlen(temp2->genre)+1, sizeof(char));
							strcpy(t->genre, temp2->genre);
							break;
						}
						t = t->next;
					}
					if (flag2 != 1){	/* if there is no match with the name in the linked lists */
						/* creating new node and add it to end of the second linked list */
						t = movies_ll2;	
						while(t->next != NULL) t = t->next;
						t->next = (Movie_Name*)malloc(sizeof(Movie_Name));
						t->next->score = temp2->score;
						t->next->name = (char*)calloc(strlen(temp1->name)+1, sizeof(char));
						strcpy(t->next->name, temp1->name);
						t->next->genre = (char*)calloc(strlen(temp2->genre)+1, sizeof(char));
						strcpy(t->next->genre, temp2->genre);
						t->next->next = NULL;

						/* insert our data to sorted linked list */
						sorted_insert(&movies_ll1, temp1);
					}
					else{
						remove_entry(&movies_ll1, temp1->name);	/* remove the existence */
						sorted_insert(&movies_ll1, temp1);		/* adding the movie with new informations */
					}
				}
			}
			fgetc(fp);
			free(str);
			free(temp1->name);
			free(temp2->genre);
			free(temp1);
			free(temp2);
			flag2 = 0;
		}
		fclose(fp);
		num_of_nodes = 0;
		temp1 = movies_ll1;
		while(temp1!=NULL){
			num_of_nodes++;
			temp1=temp1->next;
		}

		/* YOU CAN DELETE COMMENT SPECIFIER FOR SUBSEQUENT 3 LINES TO SEE MOVIES SORTED BY YEAR-BUDGET */
		/*i=1;
		temp1=movies_ll1;
		while(temp1!=NULL){ printf("%4d--->%15d %4d %s\n",i,temp1->budget,temp1->year,temp1->name);temp1=temp1->next;i++;}*/

		menu_part(movies_ll1, movies_ll2, num_of_nodes);
	}
	
}

int main(){
	program("Movies.txt");	/* Starting our program with 1 single argument which is name of the file */
	return 0;
}