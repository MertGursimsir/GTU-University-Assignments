#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* structu that keeps information about countries */
typedef struct{
	char *country;
	char *capital;
	int population;
	bool driving_side; /* True indicates right side and False indicates left side */
}traffic;

/* linked list */
typedef struct node{
	char *country;
	char *capital;
	int population;
	bool driving_side;
	struct node *next;
}linked_list;

void write_to_file(traffic *transport, int size){
	FILE *fp; 	/* file pointer */
	int i;		/* counter for loop */
	fp = fopen("traffic.txt", "wt");	/* opening the file for writing */

	for (i=0; i<size; ++i){
		/* writing to file properly according to driving sides */
		if (transport[i].driving_side)
			fprintf(fp, "%s %s %d Right\n", transport[i].country, transport[i].capital, transport[i].population);
		else
			fprintf(fp, "%s %s %d Left\n", transport[i].country, transport[i].capital, transport[i].population);
	}
	fclose(fp);
}

linked_list* reading(int size){
	FILE *fp;
	linked_list *ll, *head, *prev;	/* 	ll: linked list pointer to move, 
										head: head of the linked list 
										prev: previous node */
	char side[10];	/* string for driving side */
	int i;			/* counter for loop */
	fp = fopen("traffic.txt", "rt");	/* opening the file for reading */

	ll = head = (linked_list*)malloc(sizeof(linked_list));
	for (i=0; i<size; i++){
		/* allocating memory for strings */
		ll->country = malloc(20);
		ll->capital = malloc(20);

		/* reading the file and filling the linked list's nodes */
		fscanf(fp, "%s", ll->country);
		fscanf(fp, "%s", ll->capital);
		fscanf(fp, "%d", &ll->population);
		fscanf(fp, "%s", side);
		if (strcmp(side, "Right")) ll->driving_side = true;
		else ll->driving_side = false;
		ll->next = (linked_list*)malloc(sizeof(linked_list));
		prev = ll->next;
		ll = ll->next;
	}
	prev->next = NULL;
	fclose(fp);
	return head;

}

void printing(linked_list *ll){
	while (ll->next!=NULL){
		/* printing the linked list */
		printf("Country: %20s", ll->country);
		printf("  Capital: %20s", ll->capital);
		printf("  Population: %-20d", ll->population);
		printf("Driving Side: ");
		if(ll->driving_side) printf("Left\n");
		else printf("Right\n");
		ll=ll->next;
	}
}

int main(){
	int input, i=1, flag;	/* input, indicator for size of the struct, and flag for driving side */		
	traffic *transport;		/* struct array */
	linked_list *ll;		/* linked list */
	transport = (traffic*)calloc(1, sizeof(traffic));

	do{
		/* MENU */
		printf("\n1: Enter new record\n");
		printf("2: Write to the file\n");
		printf("3: Read from the file\n");
		printf("4: Print the linked list\n");
		printf("5: Exit\n");
		printf("Your choice: ");
		scanf("%d",&input);
		switch(input){
			case 1:	/* allocating traffic array according to inputs */
					transport = (traffic*)realloc(transport, sizeof(traffic)*(i));
					transport[i-1].country = (char*)malloc(20);
					transport[i-1].capital = (char*)malloc(20);

					/* getting inputs and filling the struct */
					printf("Country name: ");
					scanf("%s", transport[i-1].country);
					printf("Capital: ");
					scanf("%s", transport[i-1].capital);
					printf("Population of %s: ", transport[i-1].country);
					scanf("%d", &transport[i-1].population);
					printf("Do people in %s drive on the right side? (Yes:1, No:0): ", transport[i-1].country);
					scanf("%d", &flag);
					if (flag == 1) transport[i-1].driving_side = true;
					else transport[i-1].driving_side = false;
					i++;
					break;
			case 2:	write_to_file(transport, i-1);	/* writing to file */
					break;
			case 3:	ll = reading(i-1);	/* reading from file */
					break;
			case 4:	printing(ll);	/* printing the linked list */
					break;
		}
	}while(input!=5);
	printf("Good-Bye!\n");
	free(transport);
	free(ll);
	return 0;
}