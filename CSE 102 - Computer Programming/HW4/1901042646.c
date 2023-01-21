/*
	"-ansi -pedantic-errors -lm" flags are used during compilation
*/

#include <stdio.h>
#include <math.h>

void write_polynomial(){
	float coefficient, absc;
	int degree, counter;
	/* 	coefficient : coefficient of current term of polynomial
		absc		: absolute value of coefficient
		degree		: degree of the polynomial
		counter		: counter for the loop  */

	printf("Enter your polynomial [n a_n a_n-1 a_n-2 ... a_0] : ");
	scanf("%d", &degree);

	/* Loop will be executed "degree + 1" times to take and write all terms of the polynomial */
	for (counter = degree + 1; counter > 0; --counter){
		scanf("%f", &coefficient);
		absc = fabs(coefficient);

		/* DETERMINING COEFFICIENT DIGITS (our coefficient ---> a.bc)*/
		/* If c is bigger than 5 or it is equal to 5 and there are numbers rightside of c bigger than 0 , I want to round b up. If b is 9 initially, so a will be increased by 1 */
		if (   (int)(absc * 100) % 10 > 5   ||  ( (int)(absc * 100) % 10 == 5 && (int)(absc * 100) != absc * 100 ) ){
			if ((int)(absc * 10) % 10 == 9)
				absc = (int)(absc + 1);
			else
				absc = (int)((absc + 0.1) * 10) / (float)10;
		}
		/* If c is smaller than 5 or it is equal to 5 and there is no number other than 0 rightside of c, I will take just a.b. If a.b is zero than just a is enough. */
		else {
			if (  (int)(absc * 10) == 0 )
				absc = 0;
			else 
				absc = (int)(absc * 10) / 10.0;
		}

		if (coefficient < 0)
			coefficient = -absc;
		else
			coefficient = absc;


		if (counter == degree + 1)
			printf("p(x) = ");

		/**** FIRST CONDITION ****/
		/* Only 2 terms will be written at most if degree is 1  /-/ This condition is taken seperately because exponent shouldn't be written if it is 1 */
		if (degree == 1){
			/* Writing term with x */
			if (counter == degree + 1){
				if (coefficient == 1)    /* If coefficient is 1, I don't want to print it */
					printf("x");

				else if (coefficient == -1)    /* If coefficient is -1, I just want to print - */
					printf("-x");

				else if ((int)coefficient == coefficient && coefficient != 0) 
					printf("%.fx", coefficient);

				else if (coefficient != 0)
					printf("%.1fx", coefficient);
			}
			/* Writing constant value */
			else{
				if (coefficient == 0)
					printf("\n");
				else if ((int)coefficient == coefficient)
					printf("%+.f\n", coefficient);
				else
					printf("%+.1f\n", coefficient);
			}
		}

		/**** SECOND CONDITION ****/
		/* If degree is 0, only 1 term will be written */
		else if (degree == 0)
			if ((int)coefficient == coefficient)
				printf("%.f\n", coefficient);
			else
				printf("%.1f\n", coefficient);
		
		/**** OTHER CONDITIONS ****/
		/* Writing the term with biggest exponent */
		else if (counter == degree + 1){
			if (coefficient == 1)
				printf("x^%d", degree);
			else if (coefficient == -1)
				printf("-x^%d", degree);
			else if ((int)coefficient == coefficient && coefficient != 0)
				printf("%.fx^%d", coefficient, degree);
			else if (coefficient != 0)
				printf("%.1fx^%d", coefficient, degree);
		}

		/* Writing other terms */
		else if (counter > 2){
			if (coefficient == 1)
				printf("+x^%d", counter - 1);
			else if (coefficient == -1)
				printf("-x^%d", counter - 1);
			else if ((int)coefficient == coefficient && coefficient != 0)
				printf("%+.fx^%d", coefficient, counter - 1);
			else if (coefficient != 0)
				printf("%+.1fx^%d", coefficient, counter - 1);
		}

		/* Writing the term with exponent 1 */
		else if (counter == 2){
			if (coefficient == 1)
				printf("+x");
			else if (coefficient == -1)
				printf("-x");
			else if ((int)coefficient == coefficient && coefficient != 0)
				printf("%+.fx", coefficient);
			else if (coefficient != 0)
				printf("%+.1fx", coefficient);
		}

		/* Writing constant value */
		else{
			if (coefficient == 0)
				printf("\n");
			else if ((int)coefficient == coefficient)
				printf("%+.f\n", coefficient);
			else
				printf("%+.1f\n", coefficient);
		}
	}

}

void palindrome_armstrong(){
	int number, ph1, ph2, ph3, counter, sum_arm = 0, digit_num = 0, reversed = 0;
	/* 	number 		  : integer input taken from user 
		ph1, ph2, ph3 : placeholders to not to change original number
		counter 	  : counter for loop
		sum_arm		  : sum of cubes of input's digits
		digit_num	  : number of input's digits 
		reversed	  : reverse of the input  */

	printf("Please enter a number : ");
	scanf("%d", &number);

	while (number < 0){
		printf("Please enter a \"positive\" number : ");
		scanf("%d", &number);
	}

	ph1 = number;
	ph2 = number;
	ph3 = number;
	
	/* Finding digit number of the input */
	while (ph2 != 0){
		digit_num++;
		ph2 /= 10;
	}

	/* Taking "digit_num"th degree of every digit and add it to sum_arm */
	while (ph1 != 0){
		sum_arm += pow(ph1 % 10, digit_num);
		ph1 /= 10;
	}

	for (counter = digit_num; counter > 0; --counter){
		reversed += (ph3 % 10) * pow(10, counter - 1); /* Taking every digit, multiply it with proper power of 10 and add it to reversed to make the input reversed */
		ph3 /= 10;
	}

	if (reversed == number && sum_arm == number)
		printf("This number is both Palindrome and Armstrong number.\n");
	else if (reversed == number)
		printf("This number is only Palindrome number.\n");
	else if (sum_arm == number)
		printf("This number is only Armstrong number.\n");
	else 
		printf("This number does not satisfy any special cases.\n");

}

void prime_numbers(){
	int n1, n2, min, max, i, j, flag = 1, sum = 0;
	/*	n1, n2 : number inputs
		min    : minimum one among 2 numbers
		max    : maximum one among 2 numbers
		i      : indicator of every number between n1 and n2 
		j	   : indicator for loop to find out if current number is divisible by it 
		flag   : 1 if number is prime, 0 if number is not prime
		sum    : sum of prime numbers between n1 and n2 */

	printf("Please enter first integer number : ");
	scanf("%d", &n1);
	while (n1 < 0){
		printf("Your input is negative. Please enter positive integer number : ");
		scanf("%d", &n1);	
	}

	printf("Please enter second integer number : ");
	scanf("%d", &n2);
	while (n2 < 0){
		printf("Your input is negative. Please enter positive integer number : ");
		scanf("%d", &n2);	
	}

	if (n1 > n2){
		max = n1;
		min = n2;
	}
	else{
		min = n1;
		max = n2;
	}

	for (i = min + 1; i < max; ++i){
		if (i >= 2){
			for (j = 2; j < i; ++j){
				if (i % j == 0)
					flag = 0;
			}
			if (flag == 1)
				sum += i;
			flag = 1;
		}
	}

	if (sum == 0)
		printf("There is no prime number between your inputs.\n");
	else
		printf("Sum of prime numbers between %d and %d : %d\n", n1, n2, sum);

}


/*******CALLING FUNCTIONS IN MAIN*******/
int main(){
	printf("**********************************************************\n");
	printf("--------------------WRITING POLYNOMIAL--------------------\n");
	printf("**********************************************************\n");
	write_polynomial();

	printf("\n**********************************************************\n");
	printf("---------DECIDING PALINDROME AND ARMSTRONG NUMBER---------\n");
	printf("**********************************************************\n");
	palindrome_armstrong();

	printf("\n**********************************************************\n");
	printf("---------------FINDING SUM OF PRIME NUMBERS---------------\n");
	printf("**********************************************************\n");
	prime_numbers();
	return 0;
}