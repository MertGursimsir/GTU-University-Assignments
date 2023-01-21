/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"

int control(int c3, int c2, int c1, int c0){
	/* This function is for indicating if degrees entered properly, each one should occur just once. Returns 1 if inputs are not proper, returns 0 if inputs are proper. */
	if ((c3!=3 && c2!=3 && c1!=3 && c0!=3) || (c3!=2 && c2!=2 && c1!=2 && c0!=2) || (c3!=1 && c2!=1 && c1!=1 && c0!=1) || (c3!=0 && c2!=0 && c1!=0 && c0!=0))
		return 1;
	else
		return 0;
}

void assignment(int n, double t3, double t2, double t1, double t0, int c3, int c2, int c1, double* a){
	/* Assign coefficients to proper degrees. */
	if (c3 == n) *a = t3;
	else if (c2 == n) *a = t2;
	else if (c1 == n) *a = t1;
	else *a = t0;
}

void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	double n7, n6, n5, n4, n3, n2, n1; /* Placeholders for multiplication */

	/* Adding coefficients */
	if (op == '+'){
		*a3 = *a3 + *b3;
		*a2 = *a2 + *b2;
		*a1 = *a1 + *b1;
		*a0 = *a0 + *b0;
	}
	/* Subtracting coefficients */
	else if (op == '-'){
		*a3 = *a3 - *b3;
		*a2 = *a2 - *b2;
		*a1 = *a1 - *b1;
		*a0 = *a0 - *b0;
	} 
	else if (op == '*'){
		/* Multiplying coefficients */
		n7 = *a3 * *b3;
		n6 = (*a3 * *b2) + (*b3 * *a2);
		n5 = (*a3 * *b1) + (*b3 * *a1) + (*a2 * *b2);
		n4 = (*a3 * *b0) + (*b3 * *a0) + (*a1 * *b2) + (*a2 * *b1);
		n3 = (*a2 * *b0) + (*b2 * *a0) + (*a1 * *b1);
		n2 = (*a1 * *b0) + (*b1 * *a0);
		n1 = *a0 * *b0;

		/* Assigning coefficients to pointers that will be returned. */
		*a3 = n7;
		*a2 = n6;
		*a1 = n5;
		*a0 = n4;
		*b3 = n3;
		*b2 = n2;
		*b1 = n1;
	}
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double d0, d1, d2, d3, euclidian_distance = 0.0; /* Dimensions and euclidian distance which is initialized with 0*/
	double sum_d0 = 0.0, sum_d1 = 0.0, sum_d2 = 0.0, sum_d3 = 0.0; /* Sum of dimensions */
	double prev_d0, prev_d1, prev_d2, prev_d3; /* Dimensions of the vector to specify the previous input*/
	int i = 2; /* Counter for loop. Initially 2 because, if code doesn't enter the loop, I want it to be 1 */
	*longest_distance = 0.0;
	printf("*****************4D VECTORS*****************\n");
	printf("--------------------------------------------\n");

	do{
		printf("How many vectors do you want to enter? You can also enter -1 for all dimensions to exit. (Please enter bigger than 0): ");
		scanf("%d", &N);
	}while(N <= 0);

	/* Taking dimensions of the first vector from the user. */
	printf("\n********1. VECTOR********\n");
	printf("Enter dimensions (a b c d): ");
	scanf("%lf %lf %lf %lf", &prev_d0, &prev_d1, &prev_d2, &prev_d3);


	if (!(prev_d0 == -1 && prev_d1 == -1 && prev_d2 == -1 && prev_d3 == -1)){
		sum_d0 += prev_d0;
		sum_d1 += prev_d1;
		sum_d2 += prev_d2;
		sum_d3 += prev_d3;
	
		for (i = 2; i <= N; ++i){
			/* Taking dimensions of other vectors. */
			printf("\n********%d. VECTOR********\n", i);
			printf("Enter dimensions (a b c d): ");
			scanf("%lf %lf %lf %lf", &d0, &d1, &d2, &d3);
			
			if (d0 == -1 && d1 == -1 && d2 == -1 && d3 == -1) break; /* If user enters -1 for each dimension, program will be finished */
			
			sum_d0 += d0;
			sum_d1 += d1;
			sum_d2 += d2;
			sum_d3 += d3;
			
			/* Finding distance between 2 consecutive vectors. */
			distance_between_4d_points(d0 - prev_d0, d1 - prev_d1, d2 - prev_d2, d3 - prev_d3, &euclidian_distance);
			if (euclidian_distance > *longest_distance) *longest_distance = euclidian_distance;
			
			prev_d0 = d0;
			prev_d1 = d1;
			prev_d2 = d2;
			prev_d3 = d3;
		}
	}

	/* Calculating means of the dimensions. */
	*mean_a0 = sum_d0 / (i - 1);
	*mean_a1 = sum_d1 / (i - 1);
	*mean_a2 = sum_d2 / (i - 1);
	*mean_a3 = sum_d3 / (i - 1);
	printf("\n");
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
    /* This function takes the difference of two consecutive 4D vectors and find the euclidean distance between them. */
	*euclidian_distance = sqrt(d0 * d0 + d1 * d1 + d2 * d2 + d3 * d3);
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	int dividerA = 1, dividerB = 1, dividerC = 1, dividerD = 1, dividerE = 1;	/* Divider numbers of 5 parties. */
	int A, B, C, D, E;		/* Placeholders for 5 parties. */
	int seatA = 0, seatB = 0, seatC = 0, seatD = 0, seatE = 0;					/* Seat numbers for 5 parties. */
	int i; /* Counter for loop. */

	printf("*****************D'HONDT METHOD*****************\n");
	printf("------------------------------------------------\n");

	A = *partyA;
	B = *partyB;
	C = *partyC;
	D = *partyD;
	E = *partyE;	

	/* Calculation of seat numbers of each party according to D'Hondt method. */
	for (i = 0; i < numberOfSeats; ++i){
		/* If vote numbers of all parties reach zero, seats will allocate fairly */
		if (*partyA == 0 && *partyB == 0 && *partyC == 0 && *partyD == 0 && *partyE == 0){
			switch (i % 5){
				case 0: seatA++;
						dividerA++;
						*partyA = A / dividerA;
						break;
				case 1: seatB++;
						dividerB++;
						*partyB = B / dividerB;
						break;
				case 2: seatC++;
						dividerC++;
						*partyC = C / dividerC;
						break;
				case 3: seatD++;
						dividerD++;
						*partyD = D / dividerD;
						break;
				case 4: seatE++;
						dividerE++;
						*partyE = E / dividerE;
						break;
			}
		}
		else if (*partyA >= *partyB && *partyA >= *partyC && *partyA >= *partyD && *partyA >= *partyE){
			seatA++;
			dividerA++;
			*partyA = A / dividerA;
		}
		else if (*partyB >= *partyA && *partyB >= *partyC && *partyB >= *partyD && *partyB >= *partyE){
			seatB++;
			dividerB++;
			*partyB = B / dividerB;
		}
		else if (*partyC >= *partyA && *partyC >= *partyB && *partyC >= *partyD && *partyC >= *partyE){
			seatC++;
			dividerC++;
			*partyC = C / dividerC;
		}
		else if (*partyD >= *partyA && *partyD >= *partyB && *partyD >= *partyC && *partyD >= *partyE){
			seatD++;
			dividerD++;
			*partyD = D / dividerD;
		}
		else if (*partyE >= *partyA && *partyE >= *partyB && *partyE >= *partyC && *partyE >= *partyD){
			seatE++;
			dividerE++;
			*partyE = E / dividerE;
		}
	}

	/* Assigning seat numbers to outputs. */
	*partyA = seatA;
	*partyB = seatB;
	*partyC = seatC;
	*partyD = seatD;
	*partyE = seatE;
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	double m1 = 0.0, m2 = 0.0, m3 = 0.0;  /* slopes of the straight that passes through our points and the origin */
	double distance1, distance2, distance3; /* square of the distances to just compare which point is closer to origin */
	int r1, r2, r3;  /* regions of the points */

	printf("*****************ORDER POINTS COUNTER-CLOCKWISE*****************\n");
	printf("----------------------------------------------------------------\n");

	/* Finding slopes, square of the distances and regions of the points. */
	if (*x1 != 0.0)
		m1 = *y1 / *x1;
	if (*x2 != 0.0)
		m2 = *y2 / *x2;
	if (*x3 != 0.0)
		m3 = *y3 / *x3;
	distance1 = *x1 * *x1 + *y1 * *y1;
	distance2 = *x2 * *x2 + *y2 * *y2;
	distance3 = *x3 * *x3 + *y3 * *y3;
	specify_region(x1, y1, &r1);
	specify_region(x2, y2, &r2);
	specify_region(x3, y3, &r3);

	/* Ordering points in counter-clockwise direction. */
	if (r1 > r2 || (r1 == r2 && (m1 > m2 || (m1 == m2 && (distance1 > distance2))))) swap(x1, y1, x2, y2, &r1, &r2, &distance1, &distance2, &m1, &m2);
	if (r1 > r3 || (r1 == r3 && (m1 > m3 || (m1 == m3 && (distance1 > distance3))))) swap(x1, y1, x3, y3, &r1, &r3, &distance1, &distance3, &m1, &m3);
	if (r2 > r3 || (r2 == r3 && (m2 > m3 || (m2 == m3 && (distance2 > distance3))))) swap(x2, y2, x3, y3, &r2, &r3, &distance2, &distance3, &m2, &m3);
	/* EXPLANATION OF THE ALGORITHM : 
	** First, regions will be compared and according to this, points are ordered.
	** If no result can be concluded from regions (if they are same), we will look to slopes. Smaller slopes come first.
	** Lastly, if no result can be concluded from slopes (if they are same), we will compare points' distances to origin.
	*/
}

/* Specifying regions of the points. */
void specify_region(double* x, double* y, int* r){
	if (*x >= 0 && *y >= 0) *r = 1;
	else if (*x < 0 && *y > 0) *r = 2;
	else if (*x <= 0 && *y <= 0) *r = 3;
	else *r = 4;
}

/* Swapping places of two points */
void swap(double* x1, double* y1, double* x2, double* y2, int* r1, int* r2, double* d1, double* d2, double* m1, double* m2){
	double phx, phy, phd, phm; /* placeholders for x, y, distance, slope and region respectively */
	int phr;

	/* Swapping x's and y's */
	phx = *x1;
	phy = *y1;
	*x1 = *x2;
	*y1 = *y2;
	*x2 = phx;
	*y2 = phy;

	/* Swapping regions */
	phr = *r1;
	*r1 = *r2;
	*r2 = phr;

	/* Swapping distances */
	phd = *d1;
	*d1 = *d2;
	*d2 = phd;

	/* Swapping slopes */
	phm = *m1;
	*m1 = *m2;
	*m2 = phm;
}


void number_encrypt (unsigned char* number)
{
	char b7 = '0', b6 = '0', b5 = '0', b4 = '0', b3 = '0', b2 = '0', b1 = '0', b0 = '0';
	/* Assigning initial values to zero*/
	
	printf("*****************NUMBER ENCRYPTION*****************\n");
	printf("---------------------------------------------------\n");

	/* Calling functions */
	get_number_components(*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components(number, b7, b6, b5, b4, b3, b2, b1, b0);

}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	/* Converting our number into binary -> b7 b6 b5 b4 b3 b2 b1 b0 */
	/* Number will be divided by 2, stops as quotient reaches 0 */
	*b0 = one_zero(number);
	number /= 2;
	if (number > 1){
		*b1 = one_zero(number);
		number /= 2;
		if (number > 1){
			*b2 = one_zero(number);
			number /= 2;
			if (number > 1){
				*b3 = one_zero(number);
				number /= 2;
				if (number > 1){
					*b4 = one_zero(number);
					number /= 2;
					if (number > 1){
						*b5 = one_zero(number);
						number /= 2;
						if (number > 1){
							*b6 = one_zero(number);
							number /= 2;
							if (number > 1){
								*b7 = one_zero(number);
								number /= 2;
							}
							else if (number == 1) *b7 = one_zero(number);
						}
						else if (number == 1) *b6 = one_zero(number);
					}
					else if (number == 1) *b5 = one_zero(number);
				}
				else if (number == 1) *b4 = one_zero(number);
			}
			else if (number == 1) *b3 = one_zero(number);
		}
		else if (number == 1) *b2 = one_zero(number);
	}
	else if (number == 1) *b1 = one_zero(number);
}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
	char ph0 = b0, ph1 = b1, ph2 = b2, ph3 = b3, ph4 = b4, ph5 = b5, ph6 = b6, ph7 = b7;
	/* Defining placeholders for bits */

	*number = 0;

	/* Changing bit-7 with bit-2, bit-6 with bit-3, bit-5 with bit-0, bit-4 with bit-1 */
	b7 = ph2;
	b2 = ph7;
	b6 = ph3;
	b3 = ph6;
	b5 = ph0;
	b0 = ph5;
	b4 = ph1;
	b1 = ph4;

	/* Assigning our placeholders to new values of bits */
	ph0 = b0;
	ph1 = b1;
	ph2 = b2;
	ph3 = b3;
	ph4 = b4;
	ph5 = b5;
	ph6 = b6; 
	ph7 = b7;

	/* Doing two circular left shift */
	b7 = ph5;
	b6 = ph4;
	b5 = ph3;
	b4 = ph2;
	b3 = ph1;
	b2 = ph0;
	b1 = ph7;
	b0 = ph6;

	/* Changing our binary number to decimal number */
	if (b7 == '1') *number += 128;
	if (b6 == '1') *number += 64;
	if (b5 == '1') *number += 32;
	if (b4 == '1') *number += 16;
	if (b3 == '1') *number += 8;
	if (b2 == '1') *number += 4;
	if (b1 == '1') *number += 2;
	if (b0 == '1') *number += 1;
}

/* To specify what's the remainder from division of number by 2 */
char one_zero(unsigned char number){
	if (number % 2 == 0) return '0';
	else return '1';
}