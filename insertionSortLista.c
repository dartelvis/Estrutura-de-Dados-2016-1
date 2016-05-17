#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int t;
    time_t tI, tF;

    tI = time(NULL);

    inc = insertionSort(inc);

    tF = time(NULL);
    t = difftime(tF, tI);
    printf("\n\n%d", t);

    return 0;
}

int *insertionSort(node *inc){
    int key;
    node *i, *j;

    for(j = inc->next; j!=NULL; j=j->next){
        key = j;
        i = j->prev;
        while(i->prev!=NULL && i->val>key){
            i->next->val = i->val;
            i = i->prev;
        }
        i->next = key;
    }
    return int;
}
