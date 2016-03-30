#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main()
{
    int opc, vlr, in=1, z=0, ch=0, vz=0;
    fila *inc, *fnl;

    do{
        printf("Lista\n\n");
        printf("1-Inicializar\n2-Inserir\n3-Remover\n4-Verificar se esta cheia\n5-Verificar se esta vazia\n9-Sair\n\n:: ");
        scanf("%d", &opc);
        printf("\n");

        switch(opc){
            case 1:
                if(in==1){
                    inc = ini();
                    fnl = inc;
                    in = 0;
                    printf("Lista Inicializada\n\n");
                }else{
                    printf("Lista ja iniciada\n\n");
                }
                break;
            case 2:
                if(cheio(z)!=1){
                    printf("Digite um numero: ");
                    scanf("%d", &vlr);
                    fnl = push(fnl, vlr);
                    z++;
                    if(z == 1)
                        inc = fnl;
                    printf("Inserido\n\n");
                } else{
                printf("Lista cheia. Impossivel inserir\n\n");
                }
                break;
            case 3:
                if(vazio(z)){
                    inc = pop(inc);
                    z--;
                printf("Removido\n\n");
                }else{
                    printf("Lista vazia. Impossivel remover\n\n");
                }
                break;
            case 4:
                ch = cheio(z);
                if(ch == 1)
                    printf("Lista esta cheia\n\n");
                else
                    printf("Lista nao esta cheia\n\n");
                break;
            case 5:
                vz = vazio(z);
                if(vz == 1)
                    printf("Lista esta vazia\n\n");
                else
                    printf("Lista nao esta vazia\n\n");
                break;
            case 9:
                printf("Fim da lista\n\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    }while(opc!=9);

    system("pause");

    return 0;
}

fila* ini(){
    return NULL;
}

fila * push(fila *fnl, int val){
    fila *nv;
    nv = (fila *)malloc(sizeof(fila));
    nv -> num = val;
    nv -> prox = NULL;
   return nv;
}

fila * pop(fila *inc){
    fila *pri;
    pri = inc -> prox;
    free(inc);
    return pri;
}

int cheio(int z){
 int che;
    if(z == TAM)
        che = 1;
    return che;
}

int vazio(int z){
 int vaz;
    if(z == 0)
        vaz = 1;
    return vaz;
}
