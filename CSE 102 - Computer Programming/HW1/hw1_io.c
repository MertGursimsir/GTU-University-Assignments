/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
   	if (a0==1)      	 /* If coefficient is 1, I don't want to print it */
    	printf("x^3");
  	else if (a0==-1)     /* If coefficient is -1, I just want to print -  */
    	printf("-x^3");
  	else if (a0!=0)
   		printf("%.1fx^3", a0);

  	if (a1==1)
    	printf("+x^2");
  	else if (a1==-1)
    	printf("-x^2");
  	else if (a1!=0)
    	printf("%+.1fx^2", a1);

  	if (a2==1)
    	printf("+x");
  	else if (a2==-1)
    	printf("-x");
  	else if (a2!=0)
    	printf("%+.1fx", a2);

  	if (a3==0)
    	printf("\n");
  	else
   		printf("%+.1f\n", a3);
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
	if (a0==1)
		printf("x^4");
	else if (a0==-1)
		printf("-x^4");
	else if (a0!=0)
		printf("%.1fx^4", a0);

	if (a1==1)
		printf("+x^3");
	else if (a1==-1)
		printf("-x^3");
	else if (a1!=0)
		printf("%+.1fx^3", a1);

	if (a2==1)
		printf("+x^2");
	else if (a2==-1)
		printf("-x^2");
	else if (a2!=0)
		printf("%+.1fx^2", a2);

	if (a3==1)
		printf("+x");
	else if (a3==-1)
		printf("-x");
	else if (a3!=0)
		printf("%+.1fx", a3);

	if (a4==0)
		printf("\n");
	else
		printf("%+.1f\n", a4);
}