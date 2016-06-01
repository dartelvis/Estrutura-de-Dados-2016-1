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

    selectionSort(num, max);

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

int selectionSort(int num[], int n){
    int i, j, k, menor;

    for(i=0; i<(n-1); i++){
        menor = i;
        for(j=(i+1); j<n; j++){
            if(num[j]<num[menor])
                menor = j;
        }
        if(i != menor){
            k = num[i];
            num[i] = num[menor];
            num[menor] = k;
        }
    }

    return;
}
