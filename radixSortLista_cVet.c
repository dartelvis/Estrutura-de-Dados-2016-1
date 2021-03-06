#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 10

typedef struct _node{
    int val;

    struct _node *next;

    struct _node *prev;
}node;

void mostraLista(node *lst);

node *criaLista(node *inc, int n);

node *radixSort(node *inc, int n);

int main()
{
    srand(time(NULL));
    int t, i;
    node *lst;
    time_t tI, tF;

    tI = time(NULL);

    lst=NULL;

    lst = criaLista(lst, max);

    mostraLista(lst);

    lst = radixSort(lst, max);

    mostraLista(lst);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d seg", t);

    return 0;
}

node *criaLista(node *inc, int n){
    int i;
    node *fnl, *nv;

    for(i=0; i<n; i++){
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

    return inc;
}

void mostraLista(node *lst){
    node *prnt;

    printf("\n");
    for(prnt = lst; prnt!=NULL; prnt=prnt->next)
        printf("%d\t", prnt->val);
    printf("\n");

    return;
}

node *radixSort(node *lst, int n){
	int i, exp = 1, m = 0, bucket[n], temp[n];
    node *aux, *fnl;

    aux=lst;
    while(aux){
        fnl = aux;
        aux = aux->next;
    }

	for(aux=lst; aux!=NULL; aux = aux->next){
		if(aux->val > m)
			m = aux->val;
	}

	while((m/exp) > 0){
        aux = lst;

        for (i = 0; i < n; i++)
			bucket[i] = 0;

		for(i = 0; i < n; i++){
			bucket[(aux->val / exp) % 10]++;
            aux = aux->next;
		}

		for(i = 1; i < n; i++)
			bucket[i] += bucket[i-1];

        aux = fnl;
		for(i = (n - 1); i >= 0; i--){
			temp[--bucket[(aux->val / exp) % 10]] = aux->val;
            aux = aux->prev;
		}

        aux = lst;
		for(i = 0; i < n; i++){
			aux->val = temp[i];
            aux = aux->next;
        }

		exp *= 10;
	}

    return lst;
}
