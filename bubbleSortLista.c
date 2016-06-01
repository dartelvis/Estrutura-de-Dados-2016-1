#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10

typedef struct _node{
    int val;

    struct _node *next;

    struct _node *prev;
}node;

node *bubbleSort(node *inc, int n);

int main()
{
    srand(time(NULL));
    int t, i;
    node *inc, *fnl, *nv, *prnt;
    time_t tI, tF;

    inc=fnl=nv=prnt=NULL;

    tI = time(NULL);

       for(i=0; i<max; i++){
        nv = (node *)malloc(sizeof(node));
        nv->val = rand()%100;
        if(!inc){
            inc = nv;
            nv->prev = NULL;
        }else{
            fnl->next = nv;
            nv->prev = fnl;
        }
        nv->next = NULL;
        fnl = nv;
    }

    for(prnt = inc; prnt!=NULL; prnt=prnt->next)
        printf("%d\t", prnt->val);
    printf("\n");

    inc = bubbleSort(inc, max);

    printf("\n");
    for(prnt = inc; prnt!=NULL; prnt=prnt->next)
        printf("%d\t", prnt->val);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

node *bubbleSort(node *inc, int n){
    int i, j, k;
    node *aux, *ext;

    do{
        ext = inc->next;
        k=0;
        for(i=1; i<n; i++){
            aux = ext;
            if(aux->prev->val > aux->val){
                j = aux->val;
                aux->val = aux->prev->val;
                aux->prev->val = j;
                k = 1;
            }
            ext = ext->next;
        }
    }while(k);

    return inc;
}
