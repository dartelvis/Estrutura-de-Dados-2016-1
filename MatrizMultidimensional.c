#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lin;

    printf("Numero de linhas: ");
    scanf("%d", &lin);

    int col[lin], i, j;

    int **mm = malloc(lin * sizeof(int*));
    for(i=0; i<lin; i++){
        printf("Numero de colunas na linha %d: ", i);
        scanf("%d", &col[i]);
        mm[i] = malloc(col[i] * sizeof(int));
        for(j=0; j<col[i]; j++)
            mm[i][j] = rand()%50;
    }
    for(i=0; i<lin; i++){
        printf("\nLinha %d\n", i);
        printf("%d \t", mm[i]);
        for(j=0; j<col[i]; j++){
            printf("%d ", mm[i][j]);
        }
        printf("\n");
    }

    return 0;
}
