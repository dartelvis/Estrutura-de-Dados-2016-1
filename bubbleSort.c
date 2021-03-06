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

    bubbleSort(num, max);

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

int bubbleSort(int num[], int n){
    int i, j, k;

    do{
        j=0;
        for(i=1; i<n; i++){
            if(num[i-1]>num[i]){
                k = num[i];
                num[i] = num[i-1];
                num[i-1] = k;
                j = 1;
            }
        }
    }while(j);

    return;
}
