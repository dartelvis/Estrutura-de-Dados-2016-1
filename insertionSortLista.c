#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10

typedef struct _node{
    int val;

    struct _node *next;

    struct _node *prev;
}node;

node *insertionSort(node *inc, int n);

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

    inc = insertionSort(inc, max);

    printf("\n");
    for(prnt = inc; prnt!=NULL; prnt=prnt->next)
        printf("%d\t", prnt->val);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d sec", t);

    return 0;
}

node *insertionSort(node *inc, int n){
    int i, j, key;
    node *aux, *ext;
    ext = inc->next;

    for(j=1; j<n; j++){
        aux = ext;
        key = aux->val;
        i = j-1;
        while(i>=0 && aux->prev->val > key){
            aux->val = aux->prev->val;
            aux = aux->prev;
            i--;
        }
        aux->val = key;
        ext = ext->next;
    }

    return inc;
}
