#include <stdio.h>
#include <math.h>

/* structures */
typedef struct{
	double m[3][3];
	double determinant;
}matrix;

typedef struct{
	double x,y,z;
}vector;

typedef struct{
	double a, b, c, d;
}third_order_polynomial;

typedef struct{
	double a, b, c, d, e, f, g, h;
	double value;
	char cons;
}polynomial;


void print_matrix(matrix initial_matrix){
	int i, j;
	/* printing initial_matrix */
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; ++j){
			printf("%.4f    ", initial_matrix.m[i][j]);
		}
		printf("\n");
	}
}

void determinant_of_matrix(matrix* initial_matrix){
	double x, y, z;

	/* calculating determinants with 4 values */
	x = (*initial_matrix).m[1][1] * (*initial_matrix).m[2][2] - (*initial_matrix).m[1][2] * (*initial_matrix).m[2][1];
	y = (*initial_matrix).m[1][0] * (*initial_matrix).m[2][2] - (*initial_matrix).m[1][2] * (*initial_matrix).m[2][0];
	z = (*initial_matrix).m[1][0] * (*initial_matrix).m[2][1] - (*initial_matrix).m[1][1] * (*initial_matrix).m[2][0];
	
	/* assigning determinant */
	(*initial_matrix).determinant = (*initial_matrix).m[0][0] * x - (*initial_matrix).m[0][1] * y + (*initial_matrix).m[0][2] * z;
}

double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec){
	double teta;
	double magnitude_1, magnitude_2;
	double scalarp;

	/* finding new vector */
	output_vec -> x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	output_vec -> y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	output_vec -> z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;

	/* finding angle*/
	magnitude_1 = sqrt(vec_1.x*vec_1.x + vec_1.y*vec_1.y + vec_1.z+vec_1.z);
	magnitude_2 = sqrt(vec_2.x*vec_2.x + vec_2.y*vec_2.y + vec_2.z+vec_2.z);
	scalarp = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z + vec_2.z;
	if (magnitude_1*magnitude_2 == 0)
		return 0;
	else{
		teta = acos(scalarp / (magnitude_1*magnitude_2));
		return teta;
	}
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b){
	polynomial output;

	double n7, n6, n5, n4, n3, n2, n1;
	/*  (multiplying)*/
	n7 = p1.a * p2.a;
	n6 = (p1.a * p2.b) + (p2.a * p1.b);
	n5 = (p1.a * p2.c) + (p2.a * p1.c) + (p1.b * p2.b);
	n4 = (p1.a * p2.d) + (p2.a * p1.d) + (p1.c * p2.b) + (p1.b * p2.c);
	n3 = (p1.b * p2.d) + (p2.b * p1.d) + (p1.c * p2.c);
	n2 = (p1.c * p2.d) + (p2.c * p1.d);
	n1 = p1.d * p2.d;
	/* coefficients of the integral */
	output.a = n7 / 7;
	output.b = n6 / 6;
	output.c = n5 / 5;
	output.d = n4 / 4;
	output.e = n3 / 3;
	output.f = n2 / 2;
	output.g = n1;
	/* returning polynomial and assigning its values */
	output.value = output.a * pow(b, 7) + output.b * pow(b, 6) + output.c * pow(b, 5) + output.d * pow(b, 4) + output.e * pow(b, 3) + output.f * pow(b, 2) + output.g * b;
	output.value -= output.a * pow(a, 7) + output.b * pow(a, 6) + output.c * pow(a, 5) + output.d * pow(a, 4) + output.e * pow(a, 3) + output.f * pow(a, 2) + output.g * a;
	output.cons = 'C';
	return output;
}

int main(){
	int i,j; /* variables for 1st part */
	matrix initial_matrix;

	vector vec_1, vec_2, output_vec; /* variables for 2nd part */
	double teta;

	third_order_polynomial p1, p2; /* varibles for 3rd part */
	polynomial output;
	int begin, end;

	/* MATRIX */
	/* get input for the matrix*/
	printf("==========MATRIX==========\n");
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("Enter %d. row and %d. column: ", i, j);
			scanf("%lf", &(initial_matrix.m[i][j]));
		}
	}
	print_matrix(initial_matrix);
	determinant_of_matrix(&initial_matrix);
	printf("Determinant: %f", initial_matrix.determinant);

	/**************************************************************/
	/* VECTORS */
	/* getting inputs */
	printf("\n\n==========VECTORS==========\n");
	printf("Enter x dimension for the first vector: ");
	scanf("%lf", &vec_1.x);
	printf("Enter y dimension for the first vector: ");
	scanf("%lf", &vec_1.y);
	printf("Enter z dimension for the first vector: ");
	scanf("%lf", &vec_1.z);
	printf("Enter x dimension for the second vector: ");
	scanf("%lf", &vec_2.x);
	printf("Enter y dimension for the second vector: ");
	scanf("%lf", &vec_2.y);
	printf("Enter z dimension for the second vector: ");
	scanf("%lf", &vec_2.z);
	/* finding angle and printing new vector */
	teta = find_orthogonal(vec_1, vec_2, &output_vec);
	printf("x: %f\ny: %f\nz: %f\nangle: %f", output_vec.x, output_vec.y, output_vec.z, teta);


	/**************************************************************/
	/* INTEGRALS */
	/* getting inputs */
	printf("\n\n==========INTEGRALS==========\n");
	printf("Enter coefficient of x^3 for first polynomial: ");
	scanf("%lf", &p1.a);
	printf("Enter coefficient of x^2 for first polynomial: ");
	scanf("%lf", &p1.b);
	printf("Enter coefficient of x for first polynomial: ");
	scanf("%lf", &p1.c);
	printf("Enter coefficient of constant for first polynomial: ");
	scanf("%lf", &p1.d);
	printf("Enter coefficient of x^3 for second polynomial: ");
	scanf("%lf", &p2.a);
	printf("Enter coefficient of x^2 for second polynomial: ");
	scanf("%lf", &p2.b);
	printf("Enter coefficient of x for second polynomial: ");
	scanf("%lf", &p2.c);
	printf("Enter coefficient of constant for second polynomial: ");
	scanf("%lf", &p2.d);
	printf("Enter the beginning of the interval: ");
	scanf("%d", &begin);
	printf("Enter the ending of the interval: ");
	scanf("%d", &end);
	/* finding new polynomial and printing */
	output = get_integral(p1, p2, begin, end);
	printf("%fx^7%+fx^6%+fx^5%+fx^4%+fx^3%+fx^2%+fx+%c\n", output.a, output.b,output.c,output.d,output.e,output.f,output.g,output.cons);
	printf("Integral value: %f", output.value);



	return 0;
}