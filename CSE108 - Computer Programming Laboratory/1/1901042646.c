/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>

/* IMPLEMENTATION OF FUNCTIONS */
void trigonometry_calculation(int a, int b, int c)
{
    double sin, cos, tan;
    sin = (double)a / (double)c;
    cos = (double)b / (double)c;
    tan = (double)a / (double)b;
    printf("sinx = %.2lf\n", sin);
    printf("cosx = %.2lf\n", cos);
    printf("tanx = %.2lf\n\n", tan);
    return;
}

void trigonometry(int a, int b, int c)
{
    trigonometry_calculation(a, b, c);
    return;
}

unsigned long int age_calculation(int x)
{
    unsigned long int seconds = x * 365 * 24 * 3600;
    return seconds;
}

void age(int x)
{
    unsigned long int seconds;
    seconds = age_calculation(x);
    printf("You are %lu seconds.\n", seconds);
    return;
}

/* MAIN FUNCTION THAT STARTS EVERYTHING */
int main()
{   
    /* DECLERATIONS */
    int a, b, c;
    int your_age;

    /* TAKING INPUTS AND CALLING THE FUNCTIONS */
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    trigonometry(a, b, c);


    printf("Your age: ");
    scanf("%d", &your_age);
    age(your_age);

    return 0;
}