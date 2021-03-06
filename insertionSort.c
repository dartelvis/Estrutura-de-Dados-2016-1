#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10

int main()
{
    srand(time(NULL));
    int num[max], t, i;
    time_t tI, tF;

    tI = time(NULL);

    for(i=0; i<max; i++)
        num[i] = rand()%100;

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    printf("\n\n");

    insertionSort(num, max);

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

int insertionSort(int num[], int n){
    int i, j, key;

    for(j=1; j<n; j++){
        key = num[j];
        i = j-1;
        while(i>=0 && num[i]>key){
            num[i+1] = num[i];
            i--;
        }
        num[i+1] = key;
    }

    return;
}
