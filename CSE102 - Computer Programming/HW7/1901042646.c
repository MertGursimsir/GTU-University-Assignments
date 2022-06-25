#include <stdio.h>
#include <string.h>

/*!! This must be changed if words that have more than 30 letters are used in the text. !!*/
#define L 30  /* Length of the words */

void fix_spelling_error(char* t, char* d);
char* find_best_correction(char* word, char* d);
int choose_match(char matches[][L], int matching_words, char* word);
void vowel_consonant(int* vc_word, int* vc_correct, char* correct, char* word);
int is_same(char* word, char* d, char* correct);

void fix_spelling_error2(char* t, char* d);
char* find_best_correction2(char* word, char* d);
int choose_match2(char matches[][L], int matching_words, char* word);
int find_index_of_difference(char* word, char* correct);
int vowel_consonant2(int* vc_word, int* vc_correct, char* correct, char* word, int start_index);
char* find_1_mistake(char* word, char* d);

/*****************************************************************************************/
/* PROGRAM BY ASSUMING THAT A MAXIMUM OF 1 LETTER OF MISTAKE IS MADE IN MISSPELLED WORDS */
/*****************************************************************************************/
void fix_spelling_error(char* t, char* d){ /* t: name of text file, d: name of dictionary file */
	FILE *text; /* text file for reading */
	char c; /* character that to be read from the file */
	char word[L]; /* for words from the file */
	char write[L]; /* corrected word */
	int length = 0; /* length of the word that has been read*/
	int cursor = 0; /* to indicate where we are in the file */

	text = fopen(t, "r+t"); /* Opening file for reading and writing */

	if (text == NULL) printf("The file does not exist.\n"); /* for being sure that file exist */
	else{
		while (fscanf(text, "%c", &c) != EOF){ /* Reading characters one by one */

			if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57)){ /* Checking if character is letter or number */
				word[length] = c; /* Adding character to word that will be controlled */
				length++; 
			}
			else{
				/* Sending string to controller function if string is a "word" */	
				word[length] = '\0'; /* ending the word */
				strcpy(write, find_best_correction(word, d)); /* sending word to controller function */
				fseek(text, cursor, SEEK_SET); /* put cursor in the proper place */
				fprintf(text, "%s", word); /* writing correct version of the word */
				fprintf(text, "%c", c);
				cursor += strlen(word) + 1;
				word[0] = '\0'; /* reset the word */
				length = 0;
			}
		}
	}
	/* Closing file */
	fclose(text);
}

int is_same(char* word, char* d, char* correct){ /* returns 1 if there is a exact match to the given word in the file named "d" */
	FILE *dictionary; /* dictionary file for reading */
	int i; /* for the loop*/
	dictionary = fopen(d, "rt"); /* Opening file for reading */
	/****************CHECK IF THERE IS A EXACT MATCH TO WORD IN OUR DICTIONARY****************/
	if (dictionary == NULL) printf("The file does not exist.\n");  /* for being sure that file exist */
	else{
		while (fscanf(dictionary, "%s", correct) != EOF){  /* reading words one by one to find exact match */
			for(i = 0; i < strlen(correct); ++i){ /* making the word in the dictionary lowercase */
				if (correct[i] >= 65 && correct[i] <= 90)
					correct[i] += 32;
			}
			if (strcmp(correct, word) == 0){
				fclose(dictionary);
				return 1;
			}
		}	
	}
	fclose(dictionary);
	return 0;
}

char* find_best_correction( char* word,  char* d){ /* word to be corrected and name of the dictionary file respectively */
	FILE *dictionary; /* dictionary file for reading */
	char correct[L]; /* array for correct word */
	char matches[3][L]; /* matches, 3 at most */
	int difference = 0; /* letter difference between wrong word and correct word */
	int matching_words = 0;  /* number of matching words */
	int i; /* for the loop*/
	int flag = 0; /* flag to clarify that word itself is in the dictionary*/
	int big[L], counter = 0; /* array to keep uppercase letters and counter to indicate the index of this array */

	for (i = 0; i < strlen(word); ++i){  /* Making all the letters in the word lowercase and add index to array big */
		if (word[i] >= 65 && word[i] <= 90){
			word[i] += 32;
			big[counter] = i;
			counter++;
		}
	}

	flag = is_same(word, d, correct);
	if (flag == 1 || strlen(word) == 1){ /* returning word if there is a exact match or if word is consist of just one letter */
		for (i = 0; i < counter; ++i){ /* make the letters that have been lowered, uppercase again in received word */
			word[big[i]] -= 32; 
		}
		return word;
	}

	/****************FINDING CLOSE WORD IF THERE IS NO EXACT MATCH****************/
	else{
		dictionary = fopen(d, "rt");
		if (dictionary == NULL) printf("The file does not exist.\n");  /* for being sure that file exist */
		else{

			while (fscanf(dictionary, "%s", correct) != EOF){
				for(i = 0; i < strlen(correct); ++i){ /* making the word in the dictionary lowercase */
					if (correct[i] >= 65 && correct[i] <= 90)
						correct[i] += 32;
				}
				if (strlen(correct) == strlen(word)){ 
					for(i = 0; i < strlen(correct); ++i) /* finding the difference(s) between correct word and wrong word */
						if (correct[i] != word[i]) difference++;
					
					if (difference == 1){
						strcpy(matches[matching_words], correct); /* copying correct word to our array */
						matching_words++;
					}
					difference = 0;
					if (matching_words == 3) break;
				}
			}
			fclose(dictionary);

			/* If there is (are) matching word(s), find best with choosing between the matches */
			if (matching_words != 0) strcpy(word, matches[choose_match(matches, matching_words, word)]); 

			for (i = 0; i < counter; ++i) word[big[i]] -= 32; /* make the letters that have been lowered, uppercase again in received word*/
			return word;
		}
	}
}

int choose_match(char matches[][L], int matching_words, char* word){
	int vc_word1 = 0, vc_correct1 = 0; /* variables to identify if difference is consonant or vowel */ 
	int vc_word2 = 0, vc_correct2 = 0; /* 1 for vowel, 0 for consonant */
	int vc_word3 = 0, vc_correct3 = 0;
	int x = 1;  /* index of the matching word, initially 1 because second occurance has priority */

	if (matching_words == 1) x = 0; /* if there is only 1 matching word, index is just 0*/

	else if (matching_words == 2){
		vowel_consonant(&vc_word1, &vc_correct1, matches[0], word);
		vowel_consonant(&vc_word2, &vc_correct2, matches[1], word);
		if ( (vc_word1 == 0 && vc_correct1 == 1) && !(vc_word2 == 0 && vc_correct2 == 1) ) x = 0;
		/* If first match's difference turns from consonant to vowel and second one's doesn't, first one will be taken; else second one will be taken */
	}

	else if (matching_words == 3){
		vowel_consonant(&vc_word1, &vc_correct1, matches[0], word);
		vowel_consonant(&vc_word2, &vc_correct2, matches[1], word);
		vowel_consonant(&vc_word3, &vc_correct3, matches[2], word);
		/* If second match's difference turns from consonant to vowel, it will be taken*/
		if (vc_word2 == 0 && vc_correct2 == 1) x = 1; 

		/* If first and third matchs' differences turn from consonant to vowel second occurance, which is third match, will be taken */
		else if ((vc_word1 == 0 && vc_correct1 == 1) && (vc_word3 == 0 && vc_correct3 == 1)) x = 2;
		
		/* If just first match's difference turn from consonant to vowel, it will be taken */
		else if (vc_word1 == 0 && vc_correct1 == 1) x = 0;

		/* If just third match's difference turn from consonant to vowel, it will be taken */
		else if (vc_word3 == 0 && vc_correct3 == 1) x = 2;
	}
	return x;

}

/* Finding if difference letter is consonant or not */
void vowel_consonant(int* vc_word, int* vc_correct, char* correct, char* word){
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	int i, j;
	for(i = 0; i < strlen(word); ++i){
		if (correct[i] != word[i]){ /* Finding difference */
			for(j = 0; j < 5; ++j){
				if (vowels[j] == word[i]){
					*vc_word = 1; /*Letter in wrong word is vowel */
				}
				if (vowels[j] == correct[i]){
					*vc_correct = 1; /* Letter in correct word is vowel */
				}
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------------------*/

/******************************************************************************************/
/* PROGRAM BY ASSUMING THAT MAXIMUM OF 2 LETTERS OF MISTAKES ARE MADE IN MISSPELLED WORDS */
/******************************************************************************************/
void fix_spelling_error2(char* t, char* d){ /* t: name of text file, d: name of dictionary file */
	FILE *text; /* text file for reading */
	char c; /* character that to be read from the file */
	char word[L]; /* for words from the file */
	char write[L]; /* corrected word */
	int length = 0; /* length of the word that has been read*/
	int cursor = 0; /* to indicate where we are in the file */

	text = fopen(t, "r+t"); /* Opening file for reading and writing */

	if (text == NULL) printf("The file does not exist.\n"); /* for being sure that file exist */
	else{
		while (fscanf(text, "%c", &c) != EOF){ /* Reading characters one by one */

			if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57)){ /* Checking if character is letter or number */
				word[length] = c; /* Adding character to word that will be controlled */
				length++; 
			}
			else{
				/* Sending string to controller function if string is a "word" */	
				word[length] = '\0'; /* ending the word */
				strcpy(write, find_best_correction2(word, d)); /* sending word to controller function */
				fseek(text, cursor, SEEK_SET); /* put cursor in the proper place */
				fprintf(text, "%s", word); /* writing correct version of the word */
				fprintf(text, "%c", c);
				cursor += strlen(word) + 1;
				word[0] = '\0'; /* reset the word */
				length = 0;
			}
		}
	}
	/* Closing file */
	fclose(text);
}

char* find_best_correction2( char* word, char* d){ /* word to be corrected, and name of the dictionary file */
	FILE *dictionary; /* dictionary file for reading */
	char placeholder1[L], placeholder2[L]; /* placeholders for word */
	char correct[L]; /* array for corrected string */
	char matches[3][L];  /* matches, 3 at most */
	int matching_words = 0;   /* number of matching words */
	int big[L], counter = 0; /* array to keep uppercase letters and counter to indicate the index of this array */
	int difference = 0; /* letter difference between wrong word and correct word */
	int i; /* for the loop */

	/* Assigning placeholder to word */
	strcpy(placeholder1, word);
	strcpy(placeholder2, word);


	for (i = 0; i < strlen(word); ++i){  /* Making all the letters in the word lowercase and add index to array big */
		if (word[i] >= 65 && word[i] <= 90){
			word[i] += 32;
			big[counter] = i;
			counter++;
		}
	}
	if (is_same(word, d, correct) == 0 && strlen(word) != 1){ /* Checking if there is an exact match to word in the dictionary or if word is consist of just 1 letter */
		strcpy(placeholder1, find_1_mistake(placeholder1, d)); /* Checking if there is just 1 mistake in the word */
		if (strcmp(placeholder1, placeholder2) == 0){ /* if placeholders are same, this means placeholder1 didn't change so there are more than 1 mistakes in the word */
			dictionary = fopen(d, "rt"); /* Opening file for reading */
			if (dictionary == NULL) printf("The file does not exist.\n");
			else{
				while (fscanf(dictionary, "%s", correct) != EOF){
					for(i = 0; i < strlen(correct); ++i){ /* making the word in the dictionary lowercase */
						if (correct[i] >= 65 && correct[i] <= 90)
							correct[i] += 32;
					}
					if (strlen(correct) == strlen(word)){ 
						for(i = 0; i < strlen(correct); ++i) /* finding the difference(s) between correct word and wrong word */
							if (correct[i] != word[i]) difference++;
						
						if (difference == 2){
							strcpy(matches[matching_words], correct);
							matching_words++;
						}
						difference = 0;
						if (matching_words == 3) break;
					}
				}
				fclose(dictionary);

				/* If there is (are) matching word(s), find best with choosing between the matches */
				if (matching_words != 0) strcpy(word, matches[choose_match2(matches, matching_words, word)]); 

				for (i = 0; i < counter; ++i) word[big[i]] -= 32; /* make the letters that have been lowered, uppercase again in received word*/
				return word;
			}
		}
		else{
			/* Returning word that has 1 mistake that has been corrected */
			strcpy(word, placeholder1);
			return word;
		} 
	}
	else{
		/* Making the word lowercase again and return it if there is an exact match or word is just 1 letter */
		for (i = 0; i < counter; ++i) word[big[i]] -= 32;
		return word;
	}
}
/* Correct word with 1 mistake */
char* find_1_mistake( char* word,  char* d){ /* word to be corrected and name of the dictionary file respectively */
	FILE *dictionary; /* dictionary file for reading */
	char correct[L]; /* array for correct word */
	char matches[3][L]; /* matches, 3 at most */
	int difference = 0; /* letter difference between wrong word and correct word */
	int matching_words = 0;  /* number of matching words */
	int i; /* for the loop*/
	int big[L], counter = 0; /* array to keep uppercase letters and counter to indicate the index of this array */

	for (i = 0; i < strlen(word); ++i){  /* Making all the letters in the word lowercase and add index to array big */
		if (word[i] >= 65 && word[i] <= 90){
			word[i] += 32;
			big[counter] = i;
			counter++;
		}
	}

	dictionary = fopen(d, "rt");
	if (dictionary == NULL) printf("The file does not exist.\n");  /* for being sure that file exist */
	else{
		while (fscanf(dictionary, "%s", correct) != EOF){
			for(i = 0; i < strlen(correct); ++i){ /* making the word in the dictionary lowercase */
				if (correct[i] >= 65 && correct[i] <= 90)
					correct[i] += 32;
			}
			if (strlen(correct) == strlen(word)){ 
				for(i = 0; i < strlen(correct); ++i) /* finding the difference(s) between correct word and wrong word */
					if (correct[i] != word[i]) difference++;
				
				if (difference == 1){
					strcpy(matches[matching_words], correct);
					matching_words++;
				}
				difference = 0;
				if (matching_words == 3) break;
			}
		}
		fclose(dictionary);

		/* If there is (are) matching word(s), find best with choosing between the matches */
		if (matching_words != 0) strcpy(word, matches[choose_match(matches, matching_words, word)]); 

		for (i = 0; i < counter; ++i) word[big[i]] -= 32; /* make the letters that have been lowered, uppercase again in received word */
		return word;
	}
}

int choose_match2(char matches[][L], int matching_words, char* word){
	int vc_word1_1 = 0, vc_correct1_1 = 0, vc_word1_2 = 0, vc_correct1_2 = 0; /* variables to identify if difference is consonant or vowel */ 
	int vc_word2_1 = 0, vc_correct2_1 = 0, vc_word2_2 = 0, vc_correct2_2 = 0; /* 1 for vowel, 0 for consonant */
	int vc_word3_1 = 0, vc_correct3_1 = 0, vc_word3_2 = 0, vc_correct3_2 = 0;
	int cv1_1, cv1_2, cv2_1, cv2_2, cv3_1, cv3_2; /* variables to identify if mistakes are turning consonant to vowel when they are corrected. 1 for yes, 0 for no */
	int x = 1; /* index of the matching word, initially 1 because second occurance has priority */

	if(matching_words == 1) x = 0; /* if there is only 1 matching word, index is just 0*/

	else if(matching_words == 2){
		/* Finding if mistake is turning from consonant to vowel starting from index defined by last parameter */
		cv1_1 = vowel_consonant2(&vc_word1_1, &vc_correct1_1, matches[0], word, 0);
		cv1_2 = vowel_consonant2(&vc_word1_2, &vc_correct1_2, matches[0], word, find_index_of_difference(word, matches[0]) + 1);
		cv2_1 = vowel_consonant2(&vc_word2_1, &vc_correct2_1, matches[1], word, 0);
		cv2_2 = vowel_consonant2(&vc_word2_2, &vc_correct2_2, matches[1], word, find_index_of_difference(word, matches[1]) + 1);
		if (cv1_1 && cv1_2 && (!cv2_1 || !cv2_1)) x = 0; 
		/* Matching word is first one if its mistakes are turning from consonant to vowel but second one's not */

	}
	else if(matching_words == 3){
		cv1_1 = vowel_consonant2(&vc_word1_1, &vc_correct1_1, matches[0], word, 0);
		cv1_2 = vowel_consonant2(&vc_word1_2, &vc_correct1_2, matches[0], word, find_index_of_difference(word, matches[0]) + 1);
		cv2_1 = vowel_consonant2(&vc_word2_1, &vc_correct2_1, matches[1], word, 0);
		cv2_2 = vowel_consonant2(&vc_word2_2, &vc_correct2_2, matches[1], word, find_index_of_difference(word, matches[1]) + 1);
		cv3_1 = vowel_consonant2(&vc_word3_1, &vc_correct3_1, matches[2], word, 0);
		cv3_2 = vowel_consonant2(&vc_word3_2, &vc_correct3_2, matches[2], word, find_index_of_difference(word, matches[2]) + 1);
		if (cv2_1 && cv2_2) x = 1;		/* Matching word is second match if its mistakes are turning from consonant to vowel */
		else if (cv3_1 && cv3_2) x = 2; /* If not, matching word is third match if its mistakes are turning from consonant to vowel */
		else if (cv1_1 && cv1_2) x = 0; /* If not, matching word is first match if its mistakes are turning from consonant to vowel */ 
	}
	return x;
}

/* Finding index of difference between the wrong word and correct word */
int find_index_of_difference(char* word, char* correct){
	int i;
	for(i = 0; i < strlen(word); ++i){
		if (correct[i] != word[i]){
			return i;
		}
	}
}

/* Finding if difference letter is consonant or not starting from start_index */
int vowel_consonant2(int* vc_word, int* vc_correct, char* correct, char* word, int start_index){
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	int i, j;
	for(i = start_index; i < strlen(word); ++i){
		if (correct[i] != word[i]){ /* Finding difference */
			for(j = 0; j < 5; ++j){
				if (vowels[j] == word[i]){
					*vc_word = 1; /*Letter in wrong word is vowel */
				}
				if (vowels[j] == correct[i]){
					*vc_correct = 1; /* Letter in correct word is vowel */
				}
			}
			if (*vc_word == 0 && *vc_correct == 1) return 1; /* If mistake's turning from consonant to vowel, return 1 */
			else return 0;
		}
	}
}


int main(){
	/* Name of files */
	char text[] = "text.txt";
	char dictionary[] = "dictionary.txt";

	/* Calling function that corrects words that have maximum of 1 letter of mistake */
	fix_spelling_error(text, dictionary);

	/*  If function that corrects words that have maximum of 2 letters of mistakes is wanted to be called, 
		you can remove below line out of comment, and delete "fix_spelling_error(text, dictionary)" line */
	/* fix_spelling_error2(text, dictionary);*/

	return 0;
}