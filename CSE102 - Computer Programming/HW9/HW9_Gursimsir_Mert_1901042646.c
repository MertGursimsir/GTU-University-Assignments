#include <stdio.h>

/* STRUCT DEFINITION */
typedef struct{
	char name[20];
	int age;
	int label;
}bank;

/* FUNCTION DEFINITIONS */
void process(bank *customer, int *people);  /* to process customer in the beginning of the queue */
void decide_place(bank *customer, bank temp, int people, int max);  /* general function to decide the place of the new customer in the line */
int control(bank *customer, int i, int lab, int max); /* to decide if there are more than maximum amount of customers in the line */
void employee(bank *customer, int i, int *index); /* to decide the place of the employee */
void retired(bank *customer, int i, int *index); /* to decide the place of the retired */
void student(bank *customer, int i, int *index); /* to decide the place of the student */
void unemployed(bank *customer, int i, int *index); /* to decide the place of the unemployed */
void other(bank *customer, int i, int *index); /* to decide the place of the other people */

void process(bank *customer, int *people){
	int i;
	printf("Proceed customer is %s.\n", customer[0].name);  /* Printing name of the proceed customer */
	for (i = 0; i < *people - 1; ++i)  /* Loop for forward the line */
		customer[i] = customer[i+1];
	(*people)--;
}

void decide_place(bank *customer, bank temp, int people, int max){  /* people: number of people in the line , max: max number of people in the line which are consecutive */
	int i, j, index = -1, num = 0, flag = 0;
	/*  index : place of the given person in the line 
		num : number of occurences of the given person in the a portion of the line
		flag : to determine if is there any person in the line with same label */

	if (people == 1) customer[0] = temp;  /* if there is no person in the line, we just add that person to the beginning */
	else{
		if (people == 2){ /* if there are 2 people, place of the person will be determined according to precedence */
			if (customer[0].label > temp.label) index = 0;
			else index = 1;
		}
		else{
			for (i = people - 2; i >= 0; --i){  /* Loop for finding last occurence of the label with given person's label */
				if (customer[i].label == temp.label){
					flag = 1;
					for (j = i - (max-1); j < i && j >= 0; ++j) /* Loop for finding occurence number consecutively */
						if (customer[j].label == temp.label) num++;	
					if (++num < max) index = i + 1;
					break;
				}
			}
		}
		if (index == -1){ /* if place couldn't be found */
			for (i = 0; i < people-1 && index == -1 ; ++i){
				if (customer[i].label != temp.label){ /* we can skip same labels because we learnt that there is no occurence with same label or there is max amount of people consecutively*/
					switch (temp.label){
						case 0: if (flag == 0) index = 0; /* adding person tp the beginning if there is no employee */
								else employee(customer, i, &index); /* determining place */
								break;
						case 1:	if (flag == 0){ /* if there is no retired in the line */
									if (control(customer, 0, 0, 5)) index = 5; /* adding person to the end of the first line if there is second line created by employees */
									else {
										j = 0;
										while (customer[j].label == 0 && j < people-1) j++; /* finding place (after the employees) */
										index = j;
									}
								}
								else retired(customer, i, &index); /* determining place */
								break;
						case 2:	if (flag == 0){
									switch (customer[i].label){ 
										case 0: if (control(customer, i, 0, 5)) index = i + 5; /* if employees are more than 5 consecutively, student can go between them properly */
												break;
										case 1: if (control(customer, i, 1, 3)) index = i + 3; /* if retireds are more than 3 consecutively, student can go between them properly */
												break;
										default: index = i;
									}
									if (customer[i].label > customer[i+1].label){ /* if people entered the new line */
										if (customer[i].label < 2) index = i+1; /* if there is no proper place in the first line, person goes to the end of the line */
										else index = i;  /* if there is proper place in the first line, person goes to that place */
									}
								}
								else student(customer, i, &index); /* determining place */
								break;
						case 3: if (flag == 0){
									switch (customer[i].label){
										case 0: if (control(customer, i, 0, 5)) index = i + 5; /* if employees are more than 5 consecutively, unemployed can go between them properly */
												break;
										case 1: if (control(customer, i, 1, 3)) index = i + 3; /* if retireds are more than 3 consecutively, unemployed can go between them properly */
												break;
										case 2: if (control(customer, i, 2, 3)) index = i + 3; /* if students are more than 3 consecutively, unemployed can go between them properly */
												break;
										default: index = i;
									}
									if (customer[i].label > customer[i+1].label){ /* if people entered the new line */
										if (customer[i].label < 3) index = i+1; /* if there is no proper place in the first line, person goes to the end of the line */
										else index = i; /* if there is proper place in the first line, person goes to that place */
									}
								}
								else unemployed(customer, i, &index); /* determining place */
								break;
						case 4: other(customer, i, &index); /* determining place */
								break;				
					}
				}
			}
		}
		if (index == -1) customer[people-1] = temp; /* if given person didn't obey any of the rules, it should go end of the line */
		else{
			for (i = people-1; i > index; --i)  /* Loop for forwarding the line starting from index */
				customer[i] = customer[i-1];
			customer[index] = temp; /* assigning given person to proper place in the line */
		}
	}
}

int control(bank *customer, int i, int lab, int max){ /* i: where we are in the line , lab: label , max: max number of people in the line which are consecutive */
	int j, flag = 1; /* flag: to determine if the person exceeded its max, 0 for didn't exceed, 1 for exceeded */
	for (j = i; j <= i + max; ++j) /* Loop for determining if the given labeled person exceeds its max */
		if (customer[j].label != lab){
			flag = 0;
			break;
		} 
	return flag;
}

void employee(bank *customer, int i, int *index){ /* i: where we are in the line , index: place that the given person should be */
	if (customer[i].label > customer[i+1].label && customer[i+1].label != 0) *index = i+1; /* if we entered new line, 0 must be in the beginning of that line */
	else{
		switch (customer[i].label){ /* if the given index exceeds its max, then given person should enter between them */
			case 1: if (control(customer, i, 1, 3)) (*index) = i + 3;
					break;
			case 2: if (control(customer, i, 2, 3)) (*index) = i + 3;
					break;
			case 3: if (control(customer, i, 3, 2)) (*index) = i + 2;
					break;
			case 4: if (control(customer, i, 4, 2)) (*index) = i + 2;
					break;
		}
	}
}

void retired(bank *customer, int i, int *index){
	if (customer[i].label == 0 && (customer[(i)+1].label != 1 && customer[(i)+1].label != 0)){
		*index = i+1; /* if there is no employee or retired after the employee, retired person should enter after employee*/
	}
	else if (customer[i].label > customer[i+1].label && customer[i+1].label > 1){ 
		*index = i+1; /* if we entered new line and this line doesn't start with employee or retired, retired person should enter */
	} 
	else{
		switch (customer[i].label){ /* if the given index exceeds its max, then given person should enter between them */
			case 0: if (control(customer, i, 0, 5)) (*index) = i + 5;
					break;
			case 2: if (control(customer, i, 2, 3)) (*index) = i + 3;
					break;
			case 3: if (control(customer, i, 3, 2)) (*index) = i + 2;
					break;
			case 4: if (control(customer, i, 4, 2)) (*index) = i + 2;
					break;
		}
	}
}

void student(bank *customer, int i, int *index){
	if (customer[i].label == 1 && customer[i+1].label != 1 && customer[i+1].label != 2){
		*index = i + 1; /* if current label is 1, student can enter after that if next person is not retired and not student*/
	}
	else if (customer[i].label == 0 && customer[i+1].label > 2){
		*index = i + 1; /* if current label is 0, student can enter after that if next person's precedence is lower */
	}
	else if (customer[i].label > customer[i+1].label && customer[i+1].label > 2){ /* if we entered the new line and next person's precedence is lower, student can enter to the new line */
		*index = i+1;
	}
	else{
		switch (customer[i].label){ /* if the given index exceeds its max, then given person should enter between them */
			case 0: if (control(customer, i, 0, 5)) (*index) = i + 5;
					break;
			case 1: if (control(customer, i, 1, 3)) (*index) = i + 3;
					break;
			case 3: if (control(customer, i, 3, 2)) (*index) = i + 2;
					break;
			case 4: if (control(customer, i, 4, 2)) (*index) = i + 2;
					break;
		}
	}
}

void unemployed(bank *customer, int i, int *index){
	if (customer[i].label != 4 && customer[i+1].label < customer[i].label){ 
		*index = i+1; /* if we entered new line and next person's precedence is lower, unemployed can enter to the new line */
	}
	else if (customer[i].label == 4 && customer[i-1].label != 3 && customer[i-1].label != 4){
		*index = i; /* unemployed can go before the 4 labeled people if there is no unemployed or 4 labeled people between */
	}
	else{
		switch (customer[i].label){ /* if the given index exceeds its max, then given person should enter between them */
			case 0: if (control(customer, i, 0, 5)) (*index) = i + 5;
					break;
			case 1: if (control(customer, i, 1, 3)) (*index) = i + 3;
					break;
			case 2: if (control(customer, i, 2, 3)) (*index) = i + 3;
					break;
			case 4: if (control(customer, i, 4, 2)) (*index) = i + 2;
					break;
		}
	}
}

void other(bank *customer, int i, int *index){
	if (customer[i].label > customer[i+1].label) *index = i+1; /* 4 labeled person can enter to the end of the line if line ends with 3 labeled person at most */
	else{													   /* there is no need to consider if line already ends with 4 labeled person because we don't send 4 labeled people to this function */
		switch (customer[i].label){ /* if the given index exceeds its max, then given person should enter between them */
			case 0: if (control(customer, i, 0, 5)) (*index) = i + 5;
					break;
			case 1: if (control(customer, i, 1, 3)) (*index) = i + 3;
					break;
			case 2: if (control(customer, i, 2, 3)) (*index) = i + 3;
					break;
			case 3: if (control(customer, i, 3, 2)) (*index) = i + 2;
					break;
		}
	}	
}

int main(){
	bank customer[50], temp; /* customer: line , temp: input*/
	int choice, people = 0, i; /* choice: user's choice for what she/he wants to do , people: number of people , i: for the loop */

	printf("***********Banking System (for 50 people at most) ***********\n");
	do{
		printf("Current sequence: ");
		/* Printing current sequence */
		for (i = 0; i < (people - 1); ++i)
			printf("%d-", customer[i].label);
		if (people > 0) printf("%d", customer[people-1].label);

		/* Printing and getting the choice */
		printf("\n0-Exit\n");
		printf("1-Add customer\n");
		printf("2-Process customer\n");
		scanf("%d", &choice);

		if (choice == 1){
			people++;
			/* Getting person's infos*/
			printf("Please enter the name of the customer: ");
			scanf("%s", temp.name);
			printf("Please enter the age of the customer: ");
			scanf("%d", &(temp.age));
			printf("Please enter the label of the customer: ");
			scanf("%d", &(temp.label));

			/* Sending person's infos to decide_place function to determine its place */
			switch (temp.label){
				case 0: decide_place(customer, temp, people, 5);
						break;
				case 1:	decide_place(customer, temp, people, 3);
						break;
				case 2: decide_place(customer, temp, people, 3);
						break;
				case 3: decide_place(customer, temp, people, 2);
						break;
				case 4: decide_place(customer, temp, people, 2);
						break;				
			}
		}
		else if (choice == 2){
			if (people == 0) printf("There is not any customer in bank system sequence.\n");
			else process(customer, &people);
		}
		if (people == 50) people--; /* If max amount of people is reached, we can continue by eliminating the last person in the line */
		printf("\n");
	}while(choice != 0);
	printf("Good-Bye!\n");

	return 0;
}