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

    radixSort(num, max);

    for(i=0; i<max; i++)
        printf("%d\t", num[i]);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

int radixSort(int vet[], int n){
	int i, exp = 1, m = 0, bucket[n], temp[n];

	for(i=0; i<n; i++){
		if(vet[i] > m)
			m = vet[i];
	}

	while((m/exp) > 0){
		for (i = 0; i < n; i++)
			bucket[i] = 0;

		for(i = 0; i < n; i++)
			bucket[(vet[i] / exp) % 10]++;

		for(i = 1; i < n; i++)
			bucket[i] += bucket[i-1];

		for(i = (n - 1); i >= 0; i--)
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];

		for(i = 0; i < n; i++)
			vet[i] = temp[i];

		exp *= 10;
	}
}
