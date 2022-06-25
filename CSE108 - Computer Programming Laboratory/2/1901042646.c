#include <stdio.h>
#include <math.h>

#define PI 3.14

/* DECLERATIONS OF FUNCTIONS */
void multi_calculator();
void standard_calculator();
void a_p_calculator();
void rectangle();
void triangle();
void circle();
void temperature_calculator();


/*IMPLEMENTING THE FUNCTIONS */
void multi_calculator(){
	/* TAKE USER INPUT AND EXECUTE SUITABLE FUNCTION */
	int user_choice;
	printf("Enter the calculator type:\n");
	printf("1. Standard Calculator\n");
	printf("2. Area & Perimeter Calculator\n");
	printf("3. Temperature Calculator\n-----------------------------------\n");
	scanf("%d", &user_choice);
	switch (user_choice){
		case 1: standard_calculator();
				break;
		case 2: a_p_calculator();
				break;
		case 3: temperature_calculator();
				break;
		default: printf("You have entered invalid number.");
	}
}

void standard_calculator(){
	int user_choice_1, user_choice_2, complex_real_1, complex_i_1, complex_real_2, complex_i_2, num1, num2;
	/* complex_real_1 and complex_real_2 : real part of the first and second complex numbers
	   complex_i_1 and complex_i_2 : imaginary part of the first and second complex numbers
	   num1 and num2 : integer numbers
	*/
	printf("Enter the number type:\n");
	printf("1. Integer\n");
	printf("2. Complex\n-----------------------------------\n");
	scanf("%d", &user_choice_1);

	printf("Enter the calculation type:\n");
	printf("1. Addition\n");
	printf("2. Multiplication\n-----------------------------------\n");
	scanf("%d", &user_choice_2);

	/* CALCULATING MULTIPLICATION AND ADDITION OF INTEGER NUMBERS */
	if (user_choice_1 == 1){
		printf("Please enter the first number: ");
		scanf("%d", &num1);
		printf("Please enter the second number: ");
		scanf("%d", &num2);
		if (user_choice_2 == 1)
			printf("Addition of the numbers = %d \n", num1 + num2);
		else if (user_choice_2 == 2)
			printf("Multiplication of the numbers = %d \n", num1 * num2);
	}
	/* CALCULATING MULTIPLICATION AND ADDITION OF COMPLEX NUMBERS */
	else if (user_choice_1 == 2){
		printf("Please enter the first complex number (real part first):\n ");
		scanf("%d", &complex_real_1);
		scanf("%d", &complex_i_1);
		printf("Please enter the second complex number (real part first):\n ");
		scanf("%d", &complex_real_2);
		scanf("%d", &complex_i_2);
		if (user_choice_2 == 1)
			printf("Addition of the numbers = %d + (%di) \n", complex_real_1+complex_real_2 , complex_i_1+complex_i_2);
		else if (user_choice_2 == 2)
			printf("Multiplication of the numbers = %d + (%di) \n", (complex_real_1*complex_real_2)-(complex_i_1*complex_i_2) , (complex_real_1*complex_i_2)+(complex_real_2*complex_i_1));
	}
	
}

void a_p_calculator(){
	/* CHOOSING THE SHAPE */
	int user_choice;
	printf("Enter the shape type:\n");
	printf("1. Rectangle\n");
	printf("2. Triangle\n");
	printf("3. Circle\n--------------------------------------\n");
	scanf("%d", &user_choice);
	switch (user_choice){
		case 1: rectangle();
				break;
		case 2: triangle();
				break;
		case 3: circle();
				break;
		default: printf("You have entered invalid number.");
	}
}

void rectangle(){
	/* CALCULATING AREA AND PERIMETER OF THE RECTANGLE */
	double side_1, side_2;
	printf("Please enter two sides of the rectangle:\n");
	scanf("%lf", &side_1);
	scanf("%lf", &side_2);
	printf("Perimeter of the rectangle = %.2f\n", (2*side_1) + (2*side_2));
	printf("Area of the rectangle = %.2f \n", side_1 * side_2);
}

void triangle(){
	/* CALCULATING AREA AND PERIMETER OF THE TRIANGLE
	   AREA OF THE TRIANGLE WILL BE CALCULATED WITH HERON'S FORMULA
	*/
	double side_1, side_2, side_3, s, area;
	printf("Please enter three sides of triangle: \n");
	scanf("%lf", &side_1);
	scanf("%lf", &side_2);
	scanf("%lf", &side_3);
	printf("Perimeter of the triangle = %.2lf \n", side_1 + side_2 + side_3);
	s = (side_1 + side_2 + side_3) / 2;
	area = sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));
	printf("Area of the triangle = %.2lf \n", area);
}

void circle(){
	/* CALCULATING AREA AND PERIMETER OF THE CIRCLE */
	double radius;
	printf("Please enter the radius of circle: \n");
	scanf("%lf", &radius);
	printf("Perimeter of the circle = %.2lf \n", 2 * PI * radius);
	printf("Area of the circle = %.2lf \n", PI * (radius * radius));
}

void temperature_calculator(){
	int user_choice; 
	double fahrenheit, kelvin;

	/* TAKING USER INPUTS */
	printf("Enter the calculation type: \n");
	printf("1. Fahrenheit to Kelvin\n");
	printf("2. Kelvin to Fahrenheit\n-----------------------------------\n");
	scanf("%d", &user_choice);

	/* DOING CALCULATIONS */
	/* KELVIN = ((5/9) * (FAHRENHEIT - 32) + 273.15) 
	   FAHRENHEIT = ((9/5) * (KELVIN - 273.15) + 32)
	*/
	if (user_choice == 1){
		printf("Please enter the temperature in Fahrenheit: \n");
		scanf("%lf", &fahrenheit);
		kelvin = ((5.0/9.0) * (fahrenheit - 32.0)) + 273.15;
		printf("Result = %.6lf \n", kelvin);
	}
	else if (user_choice == 2){
		printf("Please enter the temperature in Kelvin: \n");
		scanf("%lf", &kelvin);
		fahrenheit = ((9.0/5.0) * (kelvin - 273.15)) + 32.0;
		printf("Result = %.6lf \n", fahrenheit);
	}
}

int main(){
	/* CALLING multi_calculator THAT RUNS ALL FUNCTIONS ACCORDING TO USER */
	multi_calculator();
	return 0;
}