#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *rec, tam=5, num, i=0, j=0, c=0;

    rec = (int *)malloc(tam*sizeof(int));

    if(rec == NULL){
        printf("Erro de alocação de memoria!");
    }else{
        for(i=0; i<=tam; i++){
            printf("Digite um valor: ");
            if(scanf("%d", &num)==0){
                printf("FIM DO PROGRAMA!\n\n");
                break;
            } else if(i == tam){
                tam += 5;
                rec = (int *)realloc(rec, tam*sizeof(int));
            }
            rec[i] = num;
            c++;
        }
        printf("Valores digitados\n");
        for(j=0; j<c; j++){
            printf("#%d: \t%d\n", j+1, rec[j]);
        }
    }
    free(rec);

    return 0;
}
