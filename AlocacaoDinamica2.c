#include <stdio.h>
#include <stdlib.h>

int *uniao (int *v1, int n1, int *v2, int n2){
    int *uni, num, i;

    num = n1 + n2;

    uni = (int *)calloc(num, sizeof(int));

    for(i=0; i<n1; i++)
        uni[i] = v1[i];

    for(i=0; i<(n2); i++)
        uni[i+n1] = v2[i];

    return uni;
};

int main()
{
    int *v1, *v2, *v3, n1, n2, i;

    printf("Numero de elementos no vetor 1: ");
    scanf("%d", &n1);
    printf("Numero de elementos no vetor 2: ");
    scanf("%d", &n2);

    v1 = (int *)calloc(n1, sizeof(int));
    for(i=0; i<n1; i++)
        v1[i] = rand()%100;
    v2 = (int *)calloc(n2, sizeof(int));
    for(i=0; i<n2; i++)
        v2[i] = rand()%100;

    v3 = uniao(v1, n1, v2, n2);

    free(v1);
    free(v2);

    printf("\nVetor unido\n");
    for(i=0; i<(n1+n2); i++){
        printf("%d ", v3[i]);
    }

    return 0;
}
