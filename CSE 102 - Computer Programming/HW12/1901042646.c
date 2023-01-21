#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 	What is in binary file (in order)?
	int 	: number of entries

	char 	: identifier for synonym or antonym (a or s)
	int 	: length of the coming string
	string 	: question word
	int 	: occurences of the word in the former run(s) of the program
	double	: possibility of the word from former run(s) of the program

	char	: identifier for synonym or antonym (a or s)
	...
*/

/* Struct that keeps the answers */
typedef struct a{
	char* answer;
	struct a* next;
}answers;

/* Struct that keeps the questions, possibilities, and answers */
typedef struct w{
	char* word;
	int occurance;
	double chance;
	answers* ans;
}question_words;

/* Struct that keeps the addresses of question_words struct */
typedef struct adr{
	question_words* words;
	struct adr* next;
}addresses;

int number_of_answers(FILE *fp){
	int length = 0; 		/* length of the line */
	int word_number = 0;	/* number of words */
	char c; 				/* character that will be read from the file */

	/* getting to beginning of the line */
	do{
		c = fgetc(fp);
	}while(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
	fseek(fp, -1, SEEK_CUR);

	for (c = fgetc(fp); c != '\n' && c != EOF; c = fgetc(fp)){	/* finding number of words */
		if (c == ' ') word_number++;
		length++;
	}
	fseek(fp, -(length+1), SEEK_CUR); /* set the cursor to initial value */
	return word_number-1;
}

int number_of_lines(FILE *fp){
	int l = 0;  /* number of lines */
	char c; 	/* character that will be read from the file */
	while(fscanf(fp, "%c", &c) != EOF){	/* reading the character from the file */
		if (c == '\n') l++; 			/* increasing l by 1 when we enter a new line */
	}
	fseek(fp, 0, SEEK_SET);
	return l+1;
}

void filling_answers(answers* corrects, FILE *fp, int num_of_words){
	int i;		/* counter for loop */
	char *temp;	/* temporary string to hold strings from file */
	temp = (char*)malloc(35);

	for (i=0;i<num_of_words;i++){	/* getting all possible antonym/synonym for a word */
		fscanf(fp,"%s",temp);		/* reading the word */

		/* filling the list */
		corrects->answer = (char*)malloc(strlen(temp));
		strcpy(corrects->answer, temp);

		if (i==num_of_words-1) corrects->next = NULL;	/* indicating end of the list */
		else{											/* allocating memory for next node */
			corrects->next = (answers*)malloc(sizeof(answers));
			corrects=corrects->next;
		}
	}
	free(temp);
}

void upload_save(addresses *wordlist, FILE *savep, char identifier){
	int num_of_records, i,j;	/* number of records in binary file and counters */
	int word_length;			/* length of string in binary file */
	int tempo;					/* temporary value for occurance */
	double tempc;				/* temporary value for chance */
	char sa, c, *q;				/* identifier for synonym or antonym, character for string and string to be read from binary file */
	addresses *head = wordlist;	/* head of the wordlist */

	q = (char*)malloc(50);
	fread(&num_of_records, sizeof(int), 1, savep); /* reading number of records in binary file */

	for (i=0;i<num_of_records;i++){
		wordlist = head;
		fread(&sa, sizeof(char), 1, savep);			/* reading identifier for synonym or antonym */
		fread(&word_length, sizeof(int), 1, savep);	/* reading length of the word */
		for (j=0;j<word_length;j++){
			fread(&c, sizeof(char), 1, savep);		/* reading string character by character */
			q[j] = c;
		}
		q[j] = '\0';
		fread(&tempo, sizeof(int), 1, savep);		/* reading number of occurances of the current word */
		fread(&tempc, sizeof(double), 1, savep);	/* reading chance of the current word */
		if (sa == identifier){
			while (wordlist!=NULL){
				if (strcmp(wordlist->words->word, q) == 0){
					wordlist->words->occurance = tempo;
					wordlist->words->chance = tempc;
					break;
				}
				wordlist = wordlist->next;
			}
		}
	}

	free(q);
}

int filling_lists(addresses *wordlist, char *file_name, int is_first, FILE *savep, char identifier){
	FILE *fp;					/* file pointer */
	char *q, *pass;				/* strings to read from the file */
	int lines, i, num_of_words;	/* line number, counter for loop, number of correct equivalent for 1 word */
	addresses *head = wordlist;

	fp = fopen(file_name, "r");	/* opening the file */

	q = (char*)malloc(50);
	pass = (char*)malloc(10);

	if (fp==NULL) return 1;	/* checking if file exists */
	else{
		lines = number_of_lines(fp);
		for (i=0;i<lines;i++){	/* reading all lines */
			num_of_words = number_of_answers(fp);

			fscanf(fp, "%s", q);
			fscanf(fp, "%s", pass);

			/* Filling the linked list */
			wordlist->words = (question_words*)malloc(sizeof(question_words));
			wordlist->words->word = (char*)malloc(strlen(q));
			strcpy(wordlist->words->word, q);

			wordlist->words->occurance = 0;
			wordlist->words->chance = 1;

			wordlist->words->ans = (answers*)malloc(sizeof(answers));
			filling_answers(wordlist->words->ans, fp, num_of_words);

			if (i==lines-1) wordlist->next = NULL;	/* indicating end of the list */
			else{									/* allocating memory for next node */
				wordlist->next = (addresses*)malloc(sizeof(addresses));
				wordlist = wordlist->next;
			}
		}
		free(q);
		free(pass);
		fclose(fp);
	}
	if (!is_first) upload_save(head, savep, identifier);
	return 0;
}

void add_to_list(addresses *wordlist){
	addresses *head = wordlist;	/* head of the wordlist */
	answers *head2;				/* head for correct answers */
	char *str;					/* user input */
	str = (char*)malloc(50);
	while (1){
		wordlist = head;
		printf("Which word do you want to add your entry to: ");
		scanf("%s", str);
		while (wordlist != NULL){
			if (strcmp(wordlist->words->word, str) == 0){
				printf("Please enter new entry: ");
				scanf("%s", str);

				/* adding new entry to its correct place */
				head2 = wordlist->words->ans;
				while (head2->next != NULL) head2 = head2->next;
				head2->next = (answers*)malloc(sizeof(answers));
				head2->next->answer = (char*)malloc(strlen(str));
				strcpy(head2->next->answer, str);
				head2->next->next = NULL;

				break;
			}
			wordlist = wordlist->next;
		}
		if (wordlist==NULL) printf("That word does not exist, try again.\n");	/* asking new entry if user choice is not valid */
		else break;
	}
	free(str);
}

void update_file(addresses *wordlist, char* sign, char* file_name){
	FILE *fp;
	fp = fopen(file_name, "w");	/* opening file to fill it with */
	while(wordlist != NULL){
		fprintf(fp, "%s %s", wordlist->words->word, sign);	/* printing word and = OR <> to the file */
		while(wordlist->words->ans != NULL){
			fprintf(fp, " %s", wordlist->words->ans->answer);	/* printing correct answers to the file */
			wordlist->words->ans = wordlist->words->ans->next;
		}
		wordlist = wordlist->next;
		if (wordlist != NULL) fprintf(fp, "\n");
	}
	fclose(fp);
}

void ask_question(addresses *synonyms_word_list, addresses *antonyms_word_list, char* question, char q){
	char* answer;							/* answer taken by the user */
	int yes_no, flag = 1;					/* yes_no is for user to decide to add answer as new entry if it is wrong , flag is for identify that answer is wrong */
	addresses *heads = synonyms_word_list;	/* head of the synonyms */
	addresses *heada = antonyms_word_list;	/* head of the antonyms */
	answers *head;							/* head of the answers  */

	answer = (char*)malloc(50);
	if (q=='s'){	/* Asking a Synonym Question */
		printf("What is the synonym of %s?:  ", question);
		scanf("%s", answer);

		while (synonyms_word_list != NULL){
			/* looking to the list for the question word */ 
			if (strcmp(synonyms_word_list->words->word, question) == 0){
				/* looking to the answers */
				head = synonyms_word_list->words->ans;
				while (head != NULL){
					if (strcmp(head->answer, answer) == 0){
						printf("Correct!\n\n");

						/* increasing the occurance of the number by 1 */
						synonyms_word_list->words->occurance = (synonyms_word_list->words->occurance) + 1;

						/* decreasing the chance of occurance of the word */
						(synonyms_word_list->words->chance) = (1.0/synonyms_word_list->words->occurance);

						/* finding same word in the antonym list */
						while(strcmp(antonyms_word_list->words->word, question) != 0) antonyms_word_list = antonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the synonym */
						(antonyms_word_list->words->chance) *= synonyms_word_list->words->occurance;

						flag = 0;
						break;
					}
					head = head->next;
				}
			}
			synonyms_word_list = synonyms_word_list->next;
		}
		if (flag){ /* if input is not between the answers */
			synonyms_word_list = heads;
			printf("Wrong!\n");
			printf("Do you want to add this word as new answer? (0 for no, 1 for yes): ");
			scanf("%d", &yes_no);
			switch(yes_no){
				case 0: /* if user doesn't want to add entry to list, answer is thought as not correct */
						while (strcmp(synonyms_word_list->words->word, question)!=0) synonyms_word_list = synonyms_word_list->next; /* finding question in synonym list */
						(synonyms_word_list->words->occurance)++;	/* increasing number of occurance of the word */
							
						/* word's chance is changed if answer is wrong (1/n times 2 (times 2 is for increasing its chance, n: number of occurances)) */
						(synonyms_word_list->words->chance) = (1.0/synonyms_word_list->words->occurance) * 2;

						/* finding same word in the antonym list */
						while(strcmp(antonyms_word_list->words->word, question) != 0) antonyms_word_list = antonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the synonym */
						(antonyms_word_list->words->chance) *= synonyms_word_list->words->occurance;

						break;
				case 1: /* if user wants to add entry to list, answer is thought as correct */
						while (strcmp(synonyms_word_list->words->word, question)!=0) synonyms_word_list = synonyms_word_list->next; /* finding question in synonym list */
						(synonyms_word_list->words->occurance)++;	/* increasing number of occurance of the word */

						/* decreasing the chance of occurance of the word */
						(synonyms_word_list->words->chance) = (1.0/synonyms_word_list->words->occurance);

						/* finding same word in the antonym list */
						while(strcmp(antonyms_word_list->words->word, question) != 0) antonyms_word_list = antonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the synonym */
						(antonyms_word_list->words->chance) *= synonyms_word_list->words->occurance;

						/* Adding new answer to the list */
						head = synonyms_word_list->words->ans;
						while (head->next != NULL) head = head->next;
						head->next = (answers*)malloc(sizeof(answers));
						head->next->answer = (char*)malloc(strlen(answer));
						strcpy(head->next->answer, answer);
						head->next->next = NULL;

						break;
				default: printf("Invalid input, exiting...\n\n");
			}
		}
	}
	else{ /* Asking a Antonym Question */
		printf("What is the antonym of %s?:  ", question);
		scanf("%s", answer);
		while (antonyms_word_list != NULL){/* looking to the list for the question word */ 
			if (strcmp(antonyms_word_list->words->word, question) == 0){
				/* looking to the answers */
				head = antonyms_word_list->words->ans;
				while (head != NULL){
					if (strcmp(head->answer, answer) == 0){
						printf("Correct!\n\n");

						/* increasing the occurance of the number by 1 */
						(antonyms_word_list->words->occurance)++;
						/* decreasing the chance of occurance of the word */
						(antonyms_word_list->words->chance) = (1.0/antonyms_word_list->words->occurance);

						/* finding same word in the synonym list */	
						while(strcmp(synonyms_word_list->words->word, question) != 0) synonyms_word_list = synonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the antonym */
						(synonyms_word_list->words->chance) *= antonyms_word_list->words->occurance;

						flag = 0;
						break;
					}
					head = head->next;
				}
			}
			antonyms_word_list = antonyms_word_list->next;
		}
		if (flag){	/* if input is not between the answers */
			antonyms_word_list = heada;
			printf("Wrong!\n");
			printf("Do you want to add this word as new answer? (0 for no, 1 for yes): ");
			scanf("%d", &yes_no);
			switch(yes_no){
				case 0: /* if user doesn't want to add entry to list, answer is thought as not correct */
						while (strcmp(antonyms_word_list->words->word, question)!=0) antonyms_word_list = antonyms_word_list->next;/* finding question in antonym list */
						(antonyms_word_list->words->occurance)++;	/* increasing the occurance of the number by 1 */

						/* word's chance is changed if answer is wrong (1/n times 2 (times 2 is for increasing its chance, n: number of occurances)) */
						(antonyms_word_list->words->chance) = (1.0/antonyms_word_list->words->occurance) * 2;

						/* finding same word in the synonym list */	
						while(strcmp(synonyms_word_list->words->word, question) != 0) synonyms_word_list = synonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the antonym */
						(synonyms_word_list->words->chance) *= antonyms_word_list->words->occurance;
						break;
				
				case 1: /* if user wants to add entry to list, answer is thought as correct */
						while (strcmp(antonyms_word_list->words->word, question)!=0) antonyms_word_list = antonyms_word_list->next;/* finding question in antonym list */
						(antonyms_word_list->words->occurance)++;	/* increasing the occurance of the number by 1 */

						/* decreasing the chance of occurance of the word */
						(antonyms_word_list->words->chance) = (1.0/antonyms_word_list->words->occurance);

						/* finding same word in the synonym list */	
						while(strcmp(synonyms_word_list->words->word, question) != 0) synonyms_word_list = synonyms_word_list->next;
						/* increasing word's chance as multiple of number of occurance of the antonym */
						(synonyms_word_list->words->chance) *= antonyms_word_list->words->occurance;

						/* adding answer as new entry */
						head = antonyms_word_list->words->ans;
						while (head->next != NULL) head = head->next;
						head->next = (answers*)malloc(sizeof(answers));
						head->next->answer = (char*)malloc(strlen(answer));
						strcpy(head->next->answer, answer);
						head->next->next = NULL;

						break;
				default: printf("Invalid input, exiting...\n\n");
			}
		}
	}
	free(answer);
}

void calculate_possibility(addresses *synonyms_word_list, addresses *antonyms_word_list){
	double random_num, max, temp;			/* random value (between 0 and max chance), max chance, and temporary value for chance */
	char *question, q = 'a';				/* string for question and q for identify 's'ynonym or 'a'ntonym */
	addresses *heads = synonyms_word_list;	/* head of the synonym list */
	addresses *heada = antonyms_word_list;	/* head of the antonym list */

	question = (char*)malloc(50);

	/* Determine max chance in both synonym and antonym lists */
	max = antonyms_word_list->words->chance;
	antonyms_word_list = antonyms_word_list->next;
	while (antonyms_word_list != NULL){
		if (antonyms_word_list->words->chance > max) max = antonyms_word_list->words->chance;
		antonyms_word_list = antonyms_word_list->next;
	}
	while (synonyms_word_list != NULL){
		if (synonyms_word_list->words->chance > max) max = synonyms_word_list->words->chance;
		synonyms_word_list = synonyms_word_list->next;
	}

	random_num = ((rand()%(100*(int)max)) / (double)100);	/* choosing a random (real) number between 0 and max chance */

	synonyms_word_list = heads;
	antonyms_word_list = heada;
	temp = max;
	while (antonyms_word_list != NULL){	/* LOOKING AT ANTONYM WORDS' CHANCES */
		/* choosing between the chances : it must be smallest chance which is bigger than random number */
		if (antonyms_word_list->words->chance >= random_num && antonyms_word_list->words->chance <= temp){
			temp = antonyms_word_list->words->chance;
			strcpy(question, antonyms_word_list->words->word);
		}
		antonyms_word_list = antonyms_word_list->next;
	}
	while (synonyms_word_list != NULL){	/* LOOKING AT SYNONYM WORDS' CHANCES */
		/* choosing between the chances : it must be smallest chance which is bigger than random number */
		if (synonyms_word_list->words->chance >= random_num && synonyms_word_list->words->chance <= temp){
			temp = synonyms_word_list->words->chance;
			strcpy(question, synonyms_word_list->words->word);
			q = 's';	/* changing q because it was initially 'a' */
		}
		synonyms_word_list = synonyms_word_list->next;
	}
	synonyms_word_list = heads;
	antonyms_word_list = heada;
	ask_question(synonyms_word_list, antonyms_word_list, question, q);
	free(question);
}

void update_bin(addresses *synonyms_word_list, addresses *antonyms_word_list, char *session){
	FILE *binary;							/* file pointer for binary file */
	int entry=0, word_length, i;			/* number of entries in binary file, length of the 1 word, and counter */
	char c;									/* char to be written to the file */
	addresses *heads = synonyms_word_list;	/* head of the synonym list */
	addresses *heada = antonyms_word_list;	/* head of the antonym list */

	binary = fopen(session, "wb");	/* opening binary file to read */

	/* Finding total number of entries including words which have chance rate different than 1 OR number of occurance is not 0 */
	while (synonyms_word_list!=NULL){
		if (synonyms_word_list->words->chance != 1 || synonyms_word_list->words->occurance != 0) entry++;
		synonyms_word_list = synonyms_word_list->next;
	}
	while (antonyms_word_list!=NULL){
		if (antonyms_word_list->words->chance != 1 || antonyms_word_list->words->occurance != 0) entry++;
		antonyms_word_list = antonyms_word_list->next;
	}

	fwrite(&entry, sizeof(int), 1, binary);	/* WRITING NUMBER OF ENTRIES TO THE BINARY FILE */
	antonyms_word_list = heada;
	synonyms_word_list = heads;

	c = 's';
	while (synonyms_word_list!=NULL){
		/* Writing words in the synonym list to the file */
		if (synonyms_word_list->words->chance != 1 || synonyms_word_list->words->occurance != 0){
			fwrite(&c, sizeof(char), 1, binary);					/* WRITING IDENTIFIER (A FOR ANTONYM, S FOR SYNONYM) TO THE FILE */
			word_length = strlen(synonyms_word_list->words->word);	/* determining length of the word */
			fwrite(&word_length, sizeof(int), 1, binary);			/* WRITING LENGTH OF THE WORD TO THE FILE */
			for (i=0; i<word_length;i++){
				fwrite(&((synonyms_word_list->words->word)[i]), sizeof(char), 1, binary);	/* WRITING WORD ITSELF TO THE BINARY FILE CHARACTER BY CHARACTER */
			}
			fwrite(&(synonyms_word_list->words->occurance), sizeof(int), 1, binary);		/* WRITING OCCURANCE OF THE WORD TO THE FILE */
			fwrite(&(synonyms_word_list->words->chance), sizeof(double), 1, binary);		/* WRITING CHANCE OF THE WORD TO THE FILE */
		}
		synonyms_word_list = synonyms_word_list->next;
	}
	c = 'a';
	while (antonyms_word_list!=NULL){
		/* Writing words in the antonym list to the file with the same logic as in the synonym writings */
		if (antonyms_word_list->words->chance != 1 || antonyms_word_list->words->occurance != 0){
			fwrite(&c, sizeof(char), 1, binary);
			word_length = strlen(antonyms_word_list->words->word);
			fwrite(&word_length, sizeof(int), 1, binary);
			for (i=0; i<word_length;i++){
				fwrite(&((antonyms_word_list->words->word)[i]), sizeof(char), 1, binary);
			}
			fwrite(&(antonyms_word_list->words->occurance), sizeof(int), 1, binary);
			fwrite(&(antonyms_word_list->words->chance), sizeof(double), 1, binary);
		}
		antonyms_word_list = antonyms_word_list->next;
	}
	fclose(binary);
}

int main(){
	char *username, c, *session;			/* username, character to skip, and binary save file */
	int choice, choice_as, status, is_first;/* user choices, status value returned by scanf, and identifier if the program runs for the first time for a user */
	FILE *savep;							/* file pointer for binary file */
	addresses *synonyms_word_list;			/* synonym list, holds words in the synonym.txt */
	addresses *antonyms_word_list;			/* antonym list, holds words in the antonym.txt */
	
	username = (char*)malloc(30);
	printf("Welcome, please enter your name: ");
	scanf("%s", username);

	session = (char*)malloc(strlen(username)+10);
	strcpy(session, username);
	free(username);
	strcat(session, ".worddat");
	savep = fopen(session, "rb");
	if (savep == NULL) is_first = 1;
	else is_first = 0;

	synonyms_word_list = (addresses*)malloc(sizeof(addresses));
	antonyms_word_list = (addresses*)malloc(sizeof(addresses));
	if (filling_lists(synonyms_word_list, "synonyms.txt", is_first, savep, 's')){ printf("Synonyms file does not exist.\n"); return 0;}
	if(!is_first){
		fclose(savep);
		savep = fopen(session, "rb");
	}
	if (filling_lists(antonyms_word_list, "antonyms.txt", is_first, savep, 'a')){ printf("Antonyms file does not exist.\n"); return 0;}
	if (!is_first) fclose(savep);

	do{
		/* Getting input */
		printf("Please choose: \n");
		printf("1 - New question\n");
		printf("2 - Add a word\n");
		printf("3 - Exit\n");
		printf("Your choice: ");
		status = scanf("%d", &choice);
		/* Checking possible errors */
		if (status != 1){
			printf("You have entered invalid input.\n\n");
			do{	/* reading remaining characters if input is not an integer */
				scanf("%c", &c);
			}while(c != '\n');
		} 
		else{
			switch(choice){
				case 1:	calculate_possibility(synonyms_word_list, antonyms_word_list);	/* calculating possibilities and asking the question afterwards */
						break;
				case 2: printf("Which file do you want to add your word (0 for antonym, 1 for synonym): ");
						status = scanf("%d", &choice_as);
						if (status != 1){
							printf("You have entered invalid input.\n\n");
							do{scanf("%c", &c);}while(c != '\n');
						}
						else{
							switch (choice_as){
								case 0:	add_to_list(antonyms_word_list);	/* taking the word and adding it to antonym list */
										break;
								case 1: add_to_list(synonyms_word_list);	/* taking the word and adding it to synonym list */
										break;
								default: printf("You have entered invalid input.\n\n");
							}
						}
						break;
				case 3:	printf("Goodbye!\n");
						break;
				default: printf("You have entered invalid input.\n\n");
			}
		}
	}while(choice != 3);

	/* Upgrading text files and binary file */
	update_file(synonyms_word_list, "=" , "synonyms.txt");
	update_file(antonyms_word_list, "<>", "antonyms.txt");
	update_bin(synonyms_word_list, antonyms_word_list, session);

	return 0;
}