/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/

#include <stdio.h>
#include "hw1_lib.h"


double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
	double integral, y, x, sum;  
  /* sum : summation of y values, 
	x   : current x value of the function, 
	y   : value of the function at current x  */

  sum = 0;
  x = xs + delta;

  while (x <= xe){
    y = ((a0 * x + a1) * x + a2) * x + a3;
  	/* To find y value of the right end-point of current rectangle. */

    sum += y;

    x += delta;
  }

  integral = delta * sum;
  /* To find areas of rectangles. */

  return integral;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
	double integral, y, x, sum;  
  /* sum : summation of y values, 
	x   : current x value of the function, 
	y   : value of the function at current x  */

	sum = 0;
	x = xs + delta;

  while (x <= xe){   		
   	y = (((a0 * x + a1) * x + a2) * x + a3) * x + a4;
   	/* To find y value of the right end-point of current rectangle. */
   		
   	sum += y;

   	x += delta;
  }

  integral = delta * sum;
  /* To find areas of rectangles. */

  return integral;
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
	/* Root will be calculated with Newton method. */

  double iteration, derivative, x_value, y_value;
  /*  iteration  : For iteration. Iteration will be done 100 times to have more accurrate values.
      derivative : Derivative of the polynomial. 
      x_value    : Any x value of the polynomial. It will be taken as middle point of the given range.
      y_value    : Value of the polynomial itself. */
    
  x_value = (xe + xs) / 2;
  iteration = 0;
    
  while (iteration < 100){
    y_value = ((((a0 * x_value) + a1) * x_value) + a2) * x_value + a3;

    derivative = (3 * a0 * x_value + 2 * a1) * x_value + a2;
      
    x_value = x_value - (y_value / derivative);
      
    iteration++;
 	}		

  return x_value;
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
	/* Root will be calculated with Newton method. */

  double iteration, derivative, x_value, y_value;
  /*  iteration  : For iteration. I will do iteration 100 times to have more accurrate values.
      derivative : Derivative of the polynomial. 
    	x_value    : Any x value of the polynomial. It will be taken as middle point of the given range.
    	y_value    : Value of the polynomial itself. */
    
  x_value = (xe + xs) / 2;
  iteration = 0;
    
  while (iteration < 100){
    y_value = (((((a0 * x_value) + a1) * x_value) + a2) * x_value + a3) * x_value + a4;

    derivative = ((4 * a0 * x_value + 3 * a1) * x_value + 2 * a2) * x_value + a3;
      
    x_value = x_value - (y_value / derivative);
      
    iteration++;
  }

  return x_value;
}