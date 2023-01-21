#include <stdio.h>
#include <stdlib.h>

#define L 50 /* max number of inputs for palindrome array */
#define MAX 1000  /* suitable number for cos series */

int check_palindrome(int a[], int n, int l){
	if (n == l)  /* If length of the array is 0, it is palindrome */
		return 1;
	else if (a[n] != a[l])  /* If first and last values of array is not equal, array is not palindrome*/
		return 0;
	else if (l > n - 1)
		return check_palindrome(a, n+1, l-1);
	else return 1;
}

int search_element(int arr[], int input_number, int n){
	if (n == 0) /* If length is 0, number is not in the array */
		return 0;
	else if (input_number == arr[0]) /* checking if number is first value of the array*/
		return 1;
	else 
		return search_element(&arr[1], input_number, n-1);
}

/*
float cos_calculation(int n, float x){
	if (n > MAX)
		return 1;
	else
		return 1 - (x * x / (((2 * n) - 1) * (2 * n)) * cos_calculation(n + 1, x));
}
*/

int main(){
	/* variables for palindrome check */
	int palindrome[L];
	int i, input;
	int flag1; /* 1 if array is palindrome, 0 if not */

	/* variables for number searching */
	int random[20];
	int sought_number;
	int flag2; /* 1 if number is in the array, 0 if not */

	/* variables for cosine */
	int n;
	float x;
	float result;

	/* PALINDROME */
	printf("*****************PALINDROME*****************\n");
	printf("How many numbers do you want to enter?: ");
	scanf("%d", &input); /* Getting input number */
	for (i = 0; i < input; ++i){ /* Filling array with inputs */
		printf("Please enter %d. number: ", i+1);
		scanf("%d", &palindrome[i]);
	}
	flag1 = check_palindrome(palindrome, 0, input-1);
	if (flag1 == 1) printf("Your input is a palindrome.\n");
	else printf("Your input is not a palindrome.\n");

	/* SEARCHING */
	printf("\n\n\n*************SEARCH THE NUMBER*************\n");
	printf("Your array:\n");
	for (i = 0; i < 20; ++i){ /* filling and printing the array */
		random[i] = rand() % 100;
		printf("%d ", random[i]);
		if (i == 9) printf("\n");
	}
	printf("\nSearching number: "); /* getting searching number */
	scanf("%d", &sought_number);
	flag2 = search_element(random, sought_number, 20);
	if (flag2 == 1) printf("Number is in the array.\n");
	else printf("Number is not in the array.\n");

	/*
	printf("\n\n\nEnter the x value: ");
	scanf("%f", &x);
	printf("Enter the n value (smaller than %d): ", MAX);
	scanf("%d", &n);
	result = cos_calculation(n, x);
	printf("cos(%d, %f) = %f\n", n, x, result);*/

	return 0;
}