/*
	"-ansi -pedantic-errors" flags are used during compilation
*/

#include <stdio.h>

void calculate_fibonacci_sequence(){
	int num_terms, counter, term, n_term, term_ph;
	char control;
	/*  num_terms : number of terms in fibonacci sequence
		counter   : counter for the loop
		term      : current term of the fibonacci sequence
		n_term    : next term of the fibonacci sequence
		term_ph   : placeholder for term
		control   : control variable to check if user enters any unsuitable character or '*' */

	printf("Please enter term(s) number : ");

	while (1){
		/* Assigning first two terms */
		term = 1;
		n_term = 1;

		/* Assigning input that will be taken to the zero to avoid possible errors */
		num_terms = 0;

		scanf("%d", &num_terms);
		control = getchar();

		/* Ending the program with '*' input */
		if (control == '*'){
			printf("Good-Bye!\n");
			break;
		}

		/* Controlling if user entered any unsuitable character */
		else if (control != '\n')
			printf("Please enter \"numeric\" term(s) number : ");

		/* Controlling if user entered any negative number */
		else if (num_terms <= 0)
			printf("Please enter \"positive\" term(s) number : ");

		/* Printing fibonacci sequence */
		else{
			printf("\nFibonacci sequence :\n");

			for (counter = 0; counter < num_terms; ++counter){
				printf("%d\n", term);
				term_ph = term;
				term = n_term;
				n_term += term_ph;
			}

			printf("\nPlease enter term(s) number : ");
		}

	}
}	

void decide_perfect_harmonic_number(){
	int number, counter, sum, num_divisor;
	float harmonic; 
	double sum_harmonic;
	char control;
	/*	number  	 : taken number from user
		counter 	 : counter for the loop
		sum     	 : sum of natural number divisors
		num_divisor  : number of divisors
		harmonic     : harmonic mean
		sum_harmonic : denominator of harmonic mean
		control      : control variable to check if user enters '*' */

	printf("Please enter input number : ");

	while(1){
		/* Assigning all the values to 0 for initialization */
		sum = 0;
		sum_harmonic = 0;
		num_divisor = 0;

		scanf("%d", &number);
		control = getchar();

		/* Ending the program with '*' input */
		if (control == '*'){
			printf("Good-Bye!\n");
			break;
		}

		else{
			printf("Natural Number Divisors : ");

			/* Finding natural number divisors of given number except itself */
			for (counter = 1; counter <= number / 2; counter++){
				/* Check if number is divisible by current counter */
				if (number % counter == 0){
					printf("%d, ", counter);
					sum += counter;
					sum_harmonic += (double)1/counter;
					num_divisor++;
				}
			}

			/* For number itself */
			num_divisor++;
			printf("%d\n", number);
			
			if (sum == number)
				printf("Is Perfect Number? : Yes\n");
			else 
				printf("Is Perfect Number? : No\n");

			/* Adding number itself to denominator of the harmonic mean */
			sum_harmonic += (double)1 / number;

			harmonic = num_divisor / sum_harmonic;

			if ((int)harmonic == harmonic) /* Checking if harmonic mean is integer or not */
				printf("Is Harmonic Divisor Number? : Yes\n");
			else
				printf("Is Harmonic Divisor Number? : No\n");
			
			printf("\nPlease enter input number : ");
		}
	}
}

void difference_max_min(){
	double n1, n2, i, max, min;
	/*	n1  : first number input
		n2  : for other 4 number inputs
		i   : for iteration
		max : maximum number among inputs
		min : minimum number among inputs */

	printf("Please enter 5 numbers : ");
	scanf("%lf ", &n1);
	max = n1;
	min = n1;

	for (i = 0; i < 4; ++i){
		scanf("%lf", &n2);
		if (n2 > max)
			max = n2;
		else if (n2 < min)
			min = n2;
	}
	
	if ((int)max == max)  /* Write without decimal point if max number is integer */
		printf("Maximum number is : %.f\n", max);
	else
		printf("Maximum number is : %.1f\n", max);
	if ((int)min == min)  /* Write without decimal point if min number is integer */
		printf("Minimum number is : %.f\n", min);
	else
		printf("Minimum number is : %.1f\n", min);
	
	if ((int)(max - min) == max - min)  /* Write without decimal point if max-min is integer */
		printf("Difference between maximum and minimum is : %.f\n", max - min);
	else
		printf("Difference between maximum and minimum is : %.1f\n", max - min);
}

void bmi_calculation(){
	double weight, height, bmi; 
	/* bmi : body mass index   //  weight : weight of the user in kg  //  height : height of the user in meter */

	printf("Please enter weight (kg) : ");
	scanf("%lf", &weight);
	printf("Please enter height (m) : ");
	scanf("%lf", &height);

	bmi = weight / (height * height);

	if (bmi < 16.0)
		printf("Your category : Severely Underweight\n");
	else if (bmi < 18.5)
		printf("Your category : Underweight\n");
	else if (bmi < 25.0)
		printf("Your category : Normal\n");
	else if (bmi < 30.0)
		printf("Your category : Overweight\n");
	else 
		printf("Your category : Obese\n");
}

/* Calling functions in main. */
int main(){
	printf("********************************************************\n");
	printf("--------------CALCULATE FIBONACCI SEQUENCE--------------\n");
	printf("********************************************************\n");
	calculate_fibonacci_sequence();

	printf("\n********************************************************\n");
	printf("------------DECIDING PERFECT HARMONIC NUMBER------------\n");
	printf("********************************************************\n");
	decide_perfect_harmonic_number();

	printf("\n********************************************************\n");
	printf("---------FINDING DIFFERENCE BETWEEN MAX AND MIN---------\n");
	printf("********************************************************\n");
	difference_max_min();

	printf("\n********************************************************\n");
	printf("---------------BODY MASS INDEX CALCULATOR---------------\n");
	printf("********************************************************\n");
	bmi_calculation();

	return 0;
}