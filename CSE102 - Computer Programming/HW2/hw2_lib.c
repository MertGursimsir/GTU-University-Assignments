/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include <math.h>
#include "hw2_lib.h"


int find_weekday_of_data(int day, int month, int year)
{
    /* DAY OF WEEK WILL BE CALCULATED WITH GAUSS METHOD */

	int weekday, m;
	/* weekday : day-of-week of 1 January
	   m       : month-related offset */

	/******************************************* ERROR CORRECTIONS *******************************************/
	if ( (day == 31) && ((month == 4) || (month == 6) || (month == 9) || (month == 11) ) )
		return -1;
	else if ( (day == 30 || day ==31) && month == 2)
		return -1;
	else if ( !((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) && (month == 2) && (day == 29) )
		return -1;
	else if ( month < 1 || month > 12 )
		return -1;
	else if ( day < 1 || day > 31 )
		return -1;

	/***************************************IMPLEMENTING THE FUNCTION***************************************/
	else{
		weekday = (1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7;

		/* Determining the month-offset for common years and leap years. */
		if (month == 1)
			m = 0;
		else if (month == 2) 
			m = 3;
		else{
			/* for leap years */
			if ( (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0) ){
				switch (month){
					case 3:
					case 11: m = 4;
							 break;
					case 4:
					case 7: m = 0;
							break;
					case 5: m = 2;
							break;
					case 6: m = 5;
							break;
					case 8: m = 3;
							break;
					case 9: 
					case 12: m = 6;
							 break;
					case 10: m = 1;
							 break;
				}
			}
			/* for common years */
			else{
				switch (month){
					case 3:
					case 11: m = 3;
							 break;
					case 4:
					case 7: m = 6;
							break;
					case 5: m = 1;
							break;
					case 6: m = 4;
							break;
					case 8: m = 2;
							break;
					case 9: 
					case 12: m = 5;
							 break;
					case 10: m = 0;
							 break;
				}
			}
		}

		if ((weekday + m + day - 1) % 7 == 0)
			return 7;
		else
			return (weekday + m + day - 1) % 7;
	}
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    int i, days = 0;
	/* i    : for iteration in for loops
	   days : days between given dates */

	/******************************************* ERROR CORRECTIONS *******************************************/
	if ( (start_day == 31) && ((start_month == 4) || (start_month == 6) || (start_month == 9) || (start_month == 11) ) )
		return -1;
	else if ( (start_day == 30 || start_day ==31) && start_month == 2)
		return -1;
	else if ( !((start_year % 100 != 0 && start_year % 4 == 0) || (start_year % 400 == 0)) && (start_month == 2) && (start_day == 29) )
		return -1;
	else if ( (end_day == 31) && ((end_month == 4) || (end_month == 6) || (end_month == 9) || (end_month == 11) ) )
		return -1;
	else if ( (end_day == 30 || end_day ==31) && end_month == 2)
		return -1;
	else if ( !((end_year % 100 != 0 && end_year % 4 == 0) || (end_year % 400 == 0)) && (end_month == 2) && (end_day == 29) )
		return -1;
	else if ( start_month < 1 || start_month > 12 || end_month < 1 || end_month > 12)
		return -1;
	else if ( start_day < 1 || start_day > 31 || end_day < 1 || end_day > 31)
		return -1;

	/***************************************IMPLEMENTING THE FUNCTION***************************************/
	else {
		/* Adding days of years between start and end years without considering leap years. */
	    days += (end_year - start_year - 1) * 365;

	    /* Adding one more day for leap years. */
	    for (i = start_year + 1; i < end_year; i++){
	    	if ((i % 400 == 0) || (i % 100 != 0 && i % 4 == 0))
	    		days++;
	    }

		/* Adding days which are inside the start year. */
	    for (i = start_month; i <= 12; i++){
	    	switch (i){
	    		case 1:
	    		case 3:
	    		case 5:
	    		case 7:
	    		case 8:
	    		case 10:
	    		case 12: days += 31;
	    				 break;
	    		case 4:
	    		case 6:
	    		case 9:
	    		case 11: days += 30;
	    				 break;
	    		case 2: if ((start_year % 400 == 0) || (start_year % 100 != 0 && start_year % 4 == 0))
	    					days += 29;
	    				else
	    					days += 28;
	    				break;
	    	}
	    }
	    days -= start_day;

	    /* Adding days which are inside the end year. */
	    for (i = 1; i < end_month; i++){
	    	switch (i){
	    		case 1:
	    		case 3:
	    		case 5:
	    		case 7:
	    		case 8:
	    		case 10:
	    		case 12: days += 31;
	    				 break;
	    		case 4:
	    		case 6:
	    		case 9:
	    		case 11: days += 30;
	    				 break;
	    		case 2: if ((start_year % 400 == 0) || (start_year % 100 != 0 && start_year % 4 == 0))
	    					days += 29;
	    				else
	    					days += 28;
	    				break;
	    	}
	    }
	    days += end_day;
	}

	return days;
}


double find_angle(double a, double b, double c)
{
    double vb, vc, value, alpha, abs;
    /* vb    : two-thirds of median of side b
       vc    : two-thirds of median of side c
	   value : value that equals to cosine of asked angle
	   alpha : asked angle 
	   abs   : absolute value of a - b to control sides of triangle */

    /******************************************* ERROR CORRECTIONS *******************************************/
    if ( (a - b) < 0)
    	abs = b - a;
    else
    	abs = a - b;
    if ( !(abs < c && (a + b) > c) )
   		return -1;
   	
    /***************************************IMPLEMENTING THE FUNCTION***************************************/
    else{
	    /* Finding the 2 unknown sides of our triangle that is CGB (C is lower left-hand corner and B is lower right-hand corner) */
		vb = ((sqrt(((a*a + c*c - (b*b)/2)) / 2 ) / 3)) * 2;
		vc = ((sqrt(((b*b + a*a - (c*c)/2)) / 2 ) / 3)) * 2;

		/* Finding the value that equals the cosine of asked angle by cosine rule. */
		value = (vb * vb + vc * vc - a * a) / (2 * vb * vc);

		/* Finding asked angle by taking the reverse of cosine function. */
		alpha = acos(value);

	    return alpha;
	}
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
    int i, digit_r11 = 0, digit_r21 = 0, digit_r31 = 0;
	int digit_r12 = 0, digit_r22 = 0, digit_r32 = 0, d_r12 = r12, d_r22 = r22, d_r32 = r32;
	int digit_r13 = 0, digit_r23 = 0, digit_r33 = 0, copy_r13 = r13, copy_r23 = r23, copy_r33 = r33;
	unsigned int copy_r11 = r11, copy_r21 = r21, copy_r31 = r31;
	/* i : For iteration
	   digit_r11, digit_r21, digit_r31, digit_r12, digit_r22, digit_r32, digit_r13, digit_r23, digit_r33 : These variables are digit numbers of inputs. For double type inputs, digit number is left side of the point.
	   d_r12, d_r22, d_r32 : These variables are left side of the point of double type inputs.
	   copy_r11, copy_r21, copy_r31, copy_r13, copy_r23, copy_r33 : These variables are declared because original inputs shouldn't be changed during the calculation of digit numbers.
	*/

	/***************************************CALCULATING DIGIT NUMBERS***************************************/
	while (copy_r11 != 0){
		copy_r11 /= 10;
		digit_r11++;
	}
	while (copy_r21 != 0){
		copy_r21 /= 10;
		digit_r21++;
	}
	while (copy_r31 != 0){
		copy_r31 /= 10;
		digit_r31++;
	}
	/* This if block is for first column's digit numbers shouldn't exceed 5 and they cannot be smaller than zero. */
	if (digit_r11 > 5 || digit_r21 > 5 || digit_r31 > 5){
		printf("You have entered invalid number(s) for column 1.\n");
		return;
	}

	while (d_r12 != 0){
		d_r12 /= 10;
		digit_r12++;
	}
	while (d_r22 != 0){
		d_r22 /= 10;
		digit_r22++;
	}
	while (d_r32 != 0){
		d_r32 /= 10;
		digit_r32++;
	}

	while (copy_r13 != 0){
		copy_r13 /= 10;
		digit_r13++;
	}
	while (copy_r23 != 0){
		copy_r23 /= 10;
		digit_r23++;
	}
	while (copy_r33 != 0){
		copy_r33 /= 10;
		digit_r33++;
	}

	/***************************************PRINTING FIRST ROW OF THE TABLE***************************************/
	printf("\xE2\x95\xAD");
	for (i = 0; i < 47; i++)
		printf("%c", border);
	printf("\xE2\x95\xAE");
	printf("\n|    Row 101    |  Row ABCDEFG  |   Row XYZ123  |\n");
	for (i = 0; i < 49; i++)
		printf("%c", border);


	/***************************************PRINTING SECOND ROW OF THE TABLE***************************************/
	/* For first column's numbers, they have to be centered so spaces are designed according to their digit numbers. */
	switch (digit_r11){
		case 0:
		case 1: printf("\n|       %u       |", r11);
				break;
		case 2: printf("\n|      %u       |", r11);
				break;
		case 3: printf("\n|      %u      |", r11);
				break;
		case 4: printf("\n|      %u     |", r11);
				break;
		case 5: printf("\n|     %u     |", r11);
				break;
	}

	/* For second column's numbers, they have to be aligned to the left with 2 decimal digits and without trailing and leading zeros. */
	/* 	In first if, it is being checked that if first number and second number after the decimal point is zero or not. 
		If they both zero and second number after the decimal point is not being rounded, then number should be printed just as left side of the decimal point. */
	if ((int)(r12 * 10) % 10 == 0){
		if ((int)(r12 * 100) % 10 == 0){
			if ((int)(r12 * 1000) % 10 <= 5){
				printf("%.f", r12);
				for (i = digit_r12; i < 15; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r12);
				for (i = digit_r12; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r12);
			for (i = digit_r12; i < 12; i++)
				printf(" ");
		}
	}
	else{
		if ((int)(r12 * 100) % 10 == 0){
			if ((int)(r12 * 1000) % 10 <= 5){
				printf("%.1f", r12);
				for (i = digit_r12; i < 13; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r12);
				for (i = digit_r12; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r12);
			for (i = digit_r12; i < 12; i++)
				printf(" ");
		}

	}

	/* For third column's numbers, sign number is used and spaces are left accourding to digit number. */
	printf("|%+d", r13);
	for (i = digit_r13; i < 14; i++)
		printf(" ");
	printf("|\n");

	for (i = 0; i < 49; i++)
		printf("%c", border);

	/***************************************PRINTING THIRD ROW OF THE TABLE***************************************/
	/* Algorithms are same. */
	switch (digit_r21){
		case 0:
		case 1: printf("\n|       %u       |", r21);
				break;
		case 2: printf("\n|      %u       |", r21);
				break;
		case 3: printf("\n|      %u      |", r21);
				break;
		case 4: printf("\n|      %u     |", r21);
				break;
		case 5: printf("\n|     %u     |", r21);
				break;
	}

	if ((int)(r22 * 10) % 10 == 0){
		if ((int)(r22 * 100) % 10 == 0){
			if ((int)(r22 * 1000) % 10 <= 5){
				printf("%.f", r22);
				for (i = digit_r22; i < 15; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r22);
				for (i = digit_r22; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r22);
			for (i = digit_r22; i < 12; i++)
				printf(" ");
		}
	}
	else{
		if ((int)(r22 * 100) % 10 == 0){
			if ((int)(r22 * 1000) % 10 <= 5){
				printf("%.1f", r22);
				for (i = digit_r22; i < 13; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r22);
				for (i = digit_r22; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r22);
			for (i = digit_r22; i < 12; i++)
				printf(" ");
		}

	}
	printf("|%+d", r23);
	for (i = digit_r23; i < 14; i++)
		printf(" ");
	printf("|\n");

	for (i = 0; i < 49; i++)
		printf("%c", border);

	/***************************************PRINTING FOURTH ROW OF THE TABLE***************************************/
	/* Algorithms are same. */
	switch (digit_r31){
		case 0:
		case 1: printf("\n|       %u       |", r31);
				break;
		case 2: printf("\n|      %u       |", r31);
				break;
		case 3: printf("\n|      %u      |", r31);
				break;
		case 4: printf("\n|      %u     |", r31);
				break;
		case 5: printf("\n|     %u     |", r31);
				break;
	}

	if ((int)(r32 * 10) % 10 == 0){
		if ((int)(r32 * 100) % 10 == 0){
			if ((int)(r32 * 1000) % 10 <= 5){
				printf("%.f", r32);
				for (i = digit_r32; i < 15; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r32);
				for (i = digit_r32; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r32);
			for (i = digit_r32; i < 12; i++)
				printf(" ");
		}
	}
	else{
		if ((int)(r32 * 100) % 10 == 0){
			if ((int)(r32 * 1000) % 10 <= 5){
				printf("%.1f", r32);
				for (i = digit_r32; i < 13; i++)
					printf(" ");
			}
			else{
				printf("%.2f", r32);
				for (i = digit_r32; i < 12; i++)
					printf(" ");
			}
		}
		else{
			printf("%.2f", r32);
			for (i = digit_r32; i < 12; i++)
				printf(" ");
		}

	}
	printf("|%+d", r33);
	for (i = digit_r33; i < 14; i++)
		printf(" ");
	printf("|\n");

	printf("\xE2\x95\xB0");
	for (i = 0; i < 47; i++)
		printf("%c", border);
	printf("\xE2\x95\xAF\n");
}