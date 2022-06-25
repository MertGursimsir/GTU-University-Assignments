#include <stdio.h>

void russian_multiplication(unsigned int* multiplicand, unsigned int* multiplier){
	unsigned int x, y;
	x = 0;
	/*  x : will be our result 
		y : placeholder for last multiplier */

	/* Doing until multiplier is equal to or smaller than 0 */
	while (*multiplier > 0){

		/* Applying Russian Peasant Multiplication Algorithm */
		if (*multiplier % 2 == 1){
			x += *multiplicand;
			printf("%u", *multiplicand);
			if (*multiplier != 1)
				printf(" + ");

		}

		if (*multiplier >= 1)
			y = *multiplier;
		
		*multiplicand *= 2;
		*multiplier /= 2;
	}

	/* Assigning result to our multiplicand that will be returned. */
	*multiplicand = x;
	*multiplier = y;

}

void multiply_polynomials(double*  a3,  double*  a2,  double*  a1,  double*  a0,  double*  b3, double* b2, double* b1, double b0){
	double n7 , n6, n5, n4, n3, n2, n1;
	/* placeholders for our new polynomial */

	/* Multiplying coefficients */
	n7 = *a3 * *b3;
	n6 = (*a3 * *b2) + (*b3 * *a2);
	n5 = (*a3 * *b1) + (*b3 * *a1) + (*a2 * *b2);
	n4 = (*a3 * b0) + (*b3 * *a0) +(*a1 * *b2) + (*a2 * *b1);
	n3 = (*a2 * b0) + (*b2 * *a0) + (*a1 * *b1);
	n2 = (*a1 * b0) + (*b1 * *a0);
	n1 = *a0 * b0;

	/* Assigning coefficients to pointers that will be returned. */
	*a3 = n7;
	*a2 = n6;
	*a1 = n5;
	*a0 = n4;
	*b3 = n3;
	*b2 = n2;
	*b1 = n1;
}

int main(){
	unsigned int multiplicand, multiplier;
	double a3, a2, a1, a0, b3, b2, b1, b0;

	/* Multiplying two numbers with Russian  Peasant  Multiplication  Algorithm */
	printf("Please enter multiplicand: ");
	scanf("%u", &multiplicand);
	printf("Please enter multiplier: ");
	scanf("%u", &multiplier);

	printf("%u * %u = ", multiplicand, multiplier);
	russian_multiplication(&multiplicand, &multiplier);
	printf(" = %u\n", multiplicand);
	printf("Multiplier = %u\n\n", multiplier);


	/* Printing multiplication of 2 polynomials. */
	printf("Please enter first 3rd degree polynomial [a3 a2 a1 a0] : ");
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	printf("Please enter second 3rd degree polynomial [b3 b2 b1 b0] : ");
	scanf("%lf %lf %lf %lf", &b3, &b2, &b1, &b0);
	multiply_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, b0);

	if (a3 == 1)		/* If coefficient is 1, I don't want to print it */
		printf("x^6");
	else if (a3 == -1)	/* If coefficient is -1, I just want to print -  */
		printf("-x^6");
	else
		printf("%.1fx^6", a3);

	if (a2 == 1)
		printf("x^5");
	else if (a2 == -1)
		printf("-x^5");
	else if (a2 != 0)
		printf("%+.1fx^5", a2);

	if (a1 == 1)
		printf("x^4");
	else if (a1 == -1)
		printf("-x^4");
	else if (a1 != 0)
		printf("%+.1fx^4", a1);

	if (a0 == 1)
		printf("x^3");
	else if (a0 == -1)
		printf("-x^3");
	else if (a0 != 0)
		printf("%+.1fx^3", a0);

	if (b3 == 1)
		printf("x^2");
	else if (b3 == -1)
		printf("-x^2");
	else if (b3 != 0)
		printf("%+.1fx^2", b3);

	if (b2 == 1)
		printf("x");
	else if (b2 == -1)
		printf("-x");
	else if (b2 != 0)
		printf("%+.1fx", b2);

	if (b1==0)
    	printf("\n");
  	else
   		printf("%+.1f\n", b1);

	return 0;
}