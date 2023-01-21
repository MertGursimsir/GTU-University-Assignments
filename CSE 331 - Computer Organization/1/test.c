#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, j, count=0, n, k, *array;

    printf("Please enter size of the array: ");
    scanf("%d", &n);
    printf("Please enter integer k: ");
    scanf("%d", &k);

    array = (int*)calloc(n, sizeof(int));

    printf("Please enter elements:\n");
    for (i = 0; i < n; ++i){
        scanf("%d", &array[i]);
    }

    /////////////////////////////////////////////////////////////
    printf("Pairs:\n");
    for (i = 0; i < n; ++i){
        for (j = i+1; j < n; ++j){
            if ((array[i] + array[j]) % k == 0){
                count++;
                printf("(%d, %d)\n", array[i], array[j]);
            }
        }
    }
    printf("Count: %d\n", count);

    return 0;
}