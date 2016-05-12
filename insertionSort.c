#include <stdio.h>
#include <stdlib.h>
#define max 10

int main()
{
    int num[max], i;

    for(i=0; i<max; i++)
        num[i] = rand()%100;

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    printf("\n");

    num[0] = insertionSort(num, max);

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    return 0;
}

int insertionSort(int num[max], int n){
    int i, j, key;

    for(j=1; j<n; j++){
        key = num[j];
            i = j-1;
        while(i>=0 && key<num[i]){
            num[i+1] = num[i];
            i-= 1;
        }
        num[i+1] = key;
    }
    return num[0];
}
