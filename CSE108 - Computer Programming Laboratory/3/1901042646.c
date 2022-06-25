#include <stdio.h>

/******************IMPLEMENTING FUNCTIONS******************/
int find_max_distance(int num_inputs){
	int counter, number, previous = 0, max = 0;
	/*  counter  : to specify the current input number 
		number   : user input
		previous : previous number entered
		max      : maximum difference between two consecutive user entered numbers */

	printf("Please enter %d numbers :\n", num_inputs);

	/* This loop will be executed specified number of times in parameter of this function. */
	for (counter = 1; counter <= num_inputs; ++counter){
		printf("%d : ", counter);
		scanf("%d", &number);

		if (counter == 2 || number - previous > max)
			max = number - previous;

		previous = number;
	}
		
	return max;
}

void find_odd_average(){
	int number = 0, sum = 0, num_odd = 0, counter = 1;
	double average;
	/*  number  : user input, initially 0
		sum     : sum of user entered odd numbers
		num_odd : number of user entered odd numbers
		counter : to specify the current input number 
		average : average of user untered odd numbers */

	printf("Please enter positive numbers (and -1 to stop entering) :\n");

	/* This loop will be executed until user enters -1 */
	do{ 
		if (number % 2 != 0){  /* Checking if input is odd */
			num_odd += 1;
			sum += number;
		}
		printf("%d : ", counter);
		scanf("%d", &number);
		counter++;
	}while(number != -1);

	/* Checking if user didn't enter any odd number. */
	if (num_odd == 0)
		printf("You haven't entered any odd number.\n");
	else{
		average = (double)sum / num_odd;  /* Calculating average by dividing sum to number of odd numbers*/
		printf("Average of odd numbers : %.2f\n", average);
	}
}

/******************CALLING FUNCTIONS IN MAIN******************/
int main(){
	/* Finding maximum difference between two consecutive user entered numbers. */
	int max;
	max = find_max_distance(5);
	printf("Max distance between two consecutive nums : %d\n\n", max);

	/* Finding average of user entered odd numbers. */
	find_odd_average();

	return 0;
}