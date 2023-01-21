#include <stdio.h>
#include <string.h>

typedef struct{
	float x1, y1, x2, y2, x3, y3, m;
}line;

typedef struct{
	float midterm, final, homework;
}grades;

typedef struct{
	char name[20], surname[20];
	int id;
	grades g;
}student;

typedef struct{
	char name[40], platform[10][10];
	float score;
}games;

void slope_point(line user){
	float b; /* b value for the line equation "y=mx+b" */
	user.m = (user.y2 - user.y1)/(user.x2 - user.x1); /* calculating slope */
	b = user.y1 - user.m * user.x1; /* calculating b value */
	user.y3 = user.m * user.x3 + b; /* calculating y coordinate of the 3rd point */

	/* printing y3 and slope */
	printf("y3 value: %f\n", user.y3);
	printf("slope   : %f\n\n", user.m);
}

void average(student *people, int num){
	int i;
	float m_t = 0, f_t = 0, hw_t = 0; /* total for midterm, final, homework respectively */
	grades mean;
	for (i=0; i<num; i++){ /* adding grades */
		m_t += people[i].g.midterm;
		f_t += people[i].g.final;
		hw_t += people[i].g.homework;
	}
	/* assigning and printing average values */
	mean.midterm = m_t/num;
	mean.final = f_t/num;
	mean.homework = hw_t/num;
	printf("\nAverage of midterms: %f\n", mean.midterm);
	printf("Average of finals: %f\n", mean.final);
	printf("Average of homeworks: %f\n\n", mean.homework);
}

void find_id(student *people, int num){
	int i; 
	int id_w, flag=0; /* wanted id and flag if student exists with that id */
	printf("Please enter wanted id: ");
	scanf("%d", &id_w);
	for (i = 0; i<num; ++i){ /* finding specified id */
		if (people[i].id == id_w){
			flag = 1;
			/* printing informations */
			printf("For id %d:\n",id_w);
			printf("Name: %s\n", people[i].name);
			printf("Surname: %s\n", people[i].surname);
			printf("Midterm grade: %f\n", people[i].g.midterm);
			printf("Final grade: %f\n", people[i].g.final);
			printf("homework grade: %f", people[i].g.homework);
			break;
		}
	}
	if (flag == 0) printf("There is no student with id %d.", id_w);
}

void avg_score(games play[], int num){
	int i;
	float total=0;
	for (i=0; i<num;++i){ /* calculating total of scores */
		total += play[i].score;
	}
	printf("Average of the scores of the games: %f\n", total/num); /* printing average */
}

void print_pl(games play[], int numg, int count, int nump[], char temp_p[][10]){
	int i, j, k;
	for (i=0; i<count; i++){
		printf("\n%s games: ", temp_p[i]); /* printing platforms  */
		for (j = 0; j<numg;++j){
			for (k=0; k<nump[j]; ++k){
				if (strcmp(play[j].platform[k], temp_p[i]) == 0){
					printf("%s, ", play[j].name);
				}
			}
		}
	}
}

void platform_games(games play[], int numg, int nump[]){
	char temp_p[10][10];
	int count = 0;
	int i, j, k;
	for (i=0; i<numg; ++i){ /* finding platforms */
		for (j=0; j<nump[i]; ++j){
			for (k=0; k<count; ++k){
				if (strcmp(play[i].platform[j], temp_p[k]) != 0){
					strcpy(temp_p[k], play[i].platform[j]);
					count++;
				} 
			}
		}
	}
	print_pl(play, numg, count, nump, temp_p);
}

/*
void platform_games(games play[], int numg, int nump[]){
	char temp_p[10][10];
	int count = 0, flag = 1;
	int i, j, k;
	for (i=0; i<numg; ++i){
		for (j=0; j<nump[i]; ++j){
			for (k=0; k<count; ++k){
				if (strcmp(play[i].platform[j], temp_p[k]) == 0){
					flag=0;
				}
			}
			if (flag == 1){
				strcpy(temp_p[count], play[i].platform[j]);
				count++;
			}
			flag=1;
		}
	}
	print_pl(play, numg, count, nump, temp_p);
}
*/

int main(){
	/* variable for 1st program */
	line user;

	/* variables for 2nd program */
	int num_of_students, i;
	student people[50];

	/* variables for 3rd program */
	games play[50];
	int num_of_games, num_of_platforms[50], j;

	/* Getting points and finding y coordinate of the 3rd point and slope of the line */
	printf("**************LINE************\n");
	printf("Please enter x1: ");
	scanf("%f", &user.x1);
	printf("Please enter y1: ");
	scanf("%f", &user.y1);
	printf("Please enter x2: ");
	scanf("%f", &user.x2);
	printf("Please enter y2: ");
	scanf("%f", &user.y2);
	printf("Please enter x3: ");
	scanf("%f", &user.x3);
	slope_point(user);

	/* Student-Grade System*/
	printf("*************STUDENT SYSTEM*************\n");
	printf("Please enter the number of students: ");
	scanf("%d", &num_of_students); /* Getting number of students */
	/* Getting inputs for each student */
	for (i = 0; i < num_of_students; ++i){
		printf("FOR %d. STUDENT\n", i+1);
		printf("Please enter student's name: ");
		scanf("%s", people[i].name);
		printf("Please enter student's surname: ");
		scanf("%s", people[i].surname);
		printf("Please enter student's id number: ");
		scanf("%d", &people[i].id);
		printf("Please enter student's midterm grad: ");
		scanf("%f", &people[i].g.midterm);
		printf("Please enter student's final grad: ");
		scanf("%f", &people[i].g.final);
		printf("Please enter student's homework grad: ");
		scanf("%f", &people[i].g.homework);
	}
	average(people, num_of_students);
	find_id(people, num_of_students);

	/* Games */
	printf("\n\n************GAMES*************\n");
	printf("Please enter number of games: ");
	scanf("%d", &num_of_games);
	for (i=0; i<num_of_games; ++i){
		printf("FOR %d. GAME:\n", i+1);
		printf("Please enter name of the game: ");
		scanf("%s", play[i].name);
		printf("Please enter number of platforms: ");
		scanf("%d", &num_of_platforms[i]);
		for (j=0; j<num_of_platforms[i];j++){
			printf("Please enter %d. platform: ", j+1);
			scanf("%s", play[i].platform[j]);
		}
		printf("Please enter score of the game: ");
		scanf("%f", &play[i].score);
	}
	avg_score(play, num_of_games);
	platform_games(play, num_of_games, num_of_platforms);


	
	return 0;
}
