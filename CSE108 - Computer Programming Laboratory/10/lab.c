#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char title[50], author[30], subject[50];
	int id, pub;
}Book;

void add(Book *books, int counter){ /* adding new book to the struct array */
	printf("Please enter book title = ");
	scanf("%s", books[counter-1].title);
	printf("Please enter book author = ");
	scanf("%s", books[counter-1].author);
	printf("Please enter book subject = ");
	scanf("%s", books[counter-1].subject);
	printf("Please enter book year = ");
	scanf("%d", &books[counter-1].pub);
	books[counter].id = counter;
}

void getbytitle(Book *books, int counter){ 
	int i, flag = 0;
	char temptitle[50]; /* wanted title */
	printf("Enter a books title = ");
	scanf("%s", temptitle);
	for (i = 0; i < counter; i++){ /* looking in the array for the title and print */
		if (strcmp(books[i].title, temptitle) == 0){
			flag = 1;
			printf("Book found\n");
			printf("Title => %s\n", books[i].title);
			printf("Author => %s\n", books[i].author);
			printf("Subject => %s\n", books[i].subject);
			printf("Year => %d\n", books[i].pub); 
		}
	}
	if(flag==0) printf("Book is not found\n");

}

void getbyauthor(Book *books, int counter){
	int i, flag = 0;
	char tempauthor[30]; /* wanted author */
	printf("Enter a books author = ");
	scanf("%s", tempauthor);
	for (i = 0; i < counter; i++){ /* looking in the array for the author and print  */
		if (strcmp(books[i].author, tempauthor) == 0){
			flag = 1;
			printf("Book found\n");
			printf("Title => %s\n", books[i].title);
			printf("Author => %s\n", books[i].author);
			printf("Subject => %s\n", books[i].subject);
			printf("Year => %d\n", books[i].pub); 
		}
	}
	if(flag==0) printf("Book is not found");

}

void getbysubject(Book *books, int counter){
	int i, flag = 0;
	char tempsubject[50]; /* wanted subject */
	printf("Enter a books subject = ");
	scanf("%s", tempsubject);
	for (i = 0; i < counter; i++){ /* looking in the array for the subject and print  */
		if (strcmp(books[i].subject, tempsubject) == 0){
			flag = 1;
			printf("Book found\n");
			printf("Title => %s\n", books[i].title);
			printf("Author => %s\n", books[i].author);
			printf("Subject => %s\n", books[i].subject);
			printf("Year => %d\n", books[i].pub); 
		}
	}
	if(flag==0) printf("Book is not found");

}

void sortyear(Book *books, int counter){
	int i,j;
	Book *temp; /* temporary struct array */
	temp = (Book *)calloc(counter, sizeof(Book));
	printf("List of Books\n*****************************\n");
	temp[0] = books[0]; /* sorting the temp array by year */
	for (i=1; i<counter; ++i){
		if (books[i].pub < temp[i-1].pub){ 
			for (j = i-1; j < counter-1; j++){
				temp[j+1] = temp[j];
			}
			temp[i-1] = books[i];
		}
		else temp[i].pub = books[i].pub;
	}
	for (i=0; i<counter; i++){ /* assigning books array to temp array and printing */
		books[i] = temp[i];
		printf("%d. Book;\n", i+1);
		printf("Title => %s\n", books[i].title);
		printf("Author => %s\n", books[i].author);
		printf("Subject => %s\n", books[i].subject);
		printf("Year => %d\n", books[i].pub);
		printf("****************************\n");
	}
	free(temp);
}

void sortid(Book *books, int counter){
	int i,j;
	Book *temp; /* temporary struct array */
	temp = (Book *)calloc(counter, sizeof(Book));
	printf("List of Books\n*****************************\n");
	temp[0] = books[0];
	for (i=1; i<counter; ++i){ /* sorting the temp array by id */
		if (books[i].id < temp[i-1].id){
			for (j = i-1; j < counter-1; j++){
				temp[j+1] = temp[j];
			}
			temp[i-1] = books[i];
		}
		else temp[i].id = books[i].id;
	}
	for (i=0; i<counter; i++){ /* assigning books array to temp array and printing */
		books[i] = temp[i];
		printf("%d. Book;\n", i+1);
		printf("Title => %s\n", books[i].title);
		printf("Author => %s\n", books[i].author);
		printf("Subject => %s\n", books[i].subject);
		printf("Year => %d\n", books[i].pub);
		printf("****************************\n");
	}
	free(temp);
}

int main(){
	Book *Books, temp;
	int menu, submenu, counter=0; /* choices and elements number of the array */
	Books = (Book *)calloc(30, sizeof(Book)); /* dynamically allocate memory for array */

	do{

		printf("**************************\n");
		printf("MENU\n");
		printf("\t1. Add New Book\n");
		printf("\t2. List Books\n");
		printf("\t3. EXIT\n\n");
		printf("Choose = ");
		scanf("%d", &menu);
		printf("**************************\n");
		if (menu==3) printf("GOOD-BYE\n");
		else if (menu<1 && menu>3) printf("TRY AGAIN\n");
		else{
			if (menu == 1){
				counter++;
				add(Books, counter);
			}
			else if (menu == 2){
				printf("SUBMENU\n");
				printf("\t1. Get by Title\n");
				printf("\t2. Get by Author\n");
				printf("\t3. Get by Subject\n");
				printf("\t4. Sorted List by Year (DESC)\n");
				printf("\t5. List All Books\n");
				printf("\t6. EXIT SUBMENU\n\n");
				printf("Choose = ");
				scanf("%d", &submenu);
				printf("**************************\n");
				if (submenu == 1) getbytitle(Books, counter);
				else if (submenu == 2) getbyauthor(Books, counter);
				else if (submenu == 3) getbysubject(Books, counter);
				else if (submenu == 4) sortyear(Books, counter);
				else if (submenu == 5) sortid(Books, counter);
			}
		}
	}while(menu!=3);

	free(Books);
	return 0;
}