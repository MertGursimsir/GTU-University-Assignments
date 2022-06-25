/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
	double term_c3, term_c2, term_c1, term_c0;  /* Temporal coefficients */
	double a3, a2, a1, a0;  /* Coefficients of first polynomial */
	double b3, b2, b1, b0; /* Coefficients of second polynomial */
	int c3, c2, c1, c0; /* Degree of coefficient */
	char a;  /* To provide errors occurs in scanf */
	char operator;
	
	printf("*****************OPERATE POLYNOMIALS*****************\n");
	printf("-----------------------------------------------------\n");

	/******************GETTING FIRST POLYNOMIAL******************/
	printf("Enter first polynomial as \"(3, a), (2, b), (1, c), (0, d)\" :\n");

	while (scanf("(%d, %lf), (%d, %lf), (%d, %lf), (%d, %lf)", &c3, &term_c3, &c2, &term_c2, &c1, &term_c1, &c0, &term_c0) != 8 || control(c3, c2, c1, c0)){
		printf("You have entered invalid input. Please enter properly as \"(3, a), (2, b), (1, c), (0, d)\":\n");
		/* Providing errors that might happen because of scanf. */
		do{
			a = getchar();
		}while(a != '\n');
	}

	assignment(3, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &a3);
	assignment(2, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &a2);
	assignment(1, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &a1);
	assignment(0, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &a0);

	do{
			a = getchar();
	}while(a != '\n');


	/******************GETTING SECOND POLYNOMIAL******************/
	printf("\nEnter second polynomial as \"(3, a), (2, b), (1, c), (0, d)\" :\n");

	while(scanf("(%d, %lf), (%d, %lf), (%d, %lf), (%d, %lf)", &c3, &term_c3, &c2, &term_c2, &c1, &term_c1, &c0, &term_c0) != 8 || control(c3, c2, c1, c0)){
		printf("You have entered invalid input. Please enter properly as \"(3, a), (2, b), (1, c), (0, d)\":\n");
		do{
			a = getchar();
		}while(a != '\n');
	}

	assignment(3, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &b3);
	assignment(2, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &b2);
	assignment(1, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &b1);
	assignment(0, term_c3, term_c2, term_c1, term_c0, c3, c2, c1, &b0);

	do{
			a = getchar();
	}while(a != '\n');


	/******************GETTING THE OPERATOR******************/
	printf("\nEnter the operator (+, -, *): ");
	scanf("%c", &operator);

	

	/* Checking if operator is entered properly. */
	while (!(operator == '+' || operator == '-' || operator == '*')){
		printf("Please enter proper operation (+, -, *): ");
		do{
			a = getchar();
		}while(a != '\n');
		scanf("%c", &operator);
	}
	
	do{
			a = getchar();
	}while(a != '\n');

	operate_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0, operator);

	/* Printing coefficients. */
	if (operator == '*'){
		printf("\n***COEFFICIENTS OF TERMS FROM BIGGEST DEGREE TO SMALLEST DEGREE***\n");
		printf("First coefficient   (x^6)     : %f\n", a3);
		printf("Second coefficient  (x^5)     : %f\n", a2);
		printf("Third coefficient   (x^4)     : %f\n", a1);
		printf("Fourth coefficient  (x^3)     : %f\n", a0);
		printf("Fifth coefficient   (x^2)     : %f\n", b3);
		printf("Sixth coefficient   (x)       : %f\n", b2);
		printf("Seventh coefficient (constant): %f\n\n\n", b1);
	}
	else{
		printf("\n***COEFFICIENTS OF TERMS FROM BIGGEST DEGREE TO SMALLEST DEGREE***\n");
		printf("First coefficient  (x^3)     : %f\n", a3);
		printf("Second coefficient (x^2)     : %f\n", a2);
		printf("Third coefficient  (x)       : %f\n", a1);
		printf("Fourth coefficient (constant): %f\n\n\n", a0);
	}
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=0, partyB=0, partyC=0, partyD=0, partyE=0, numberOfSeats=0;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=0.0, y1=0.0, x2=0.0, y2=3.0, x3=0.0, y3=0.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=0;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
