#include <stdio.h>
#include <stdlib.h>
#include "Double Linked_List.h"

int main(){
    int a,num;
    DList L;
    L = (struct DNode*) malloc(sizeof (struct DNode));
    L->Element = 100 ;
    L->Prev = NULL;
    L->Next = NULL;
    DList Previous,N;

    for(a=0;a<10;a++){
        Add(a,L);
    }

    Insert(11,L);
    Delete(5,L);

    num = Retrieve(L);
    printf("the Retrieve num is %d\n",num);
    Previous = FindPrevious(4,L);
    printf("the previous num is %d\n",Previous->Element);
    N= Find(4,L);
    printf("the Find num is %d\n",N->Element);

    while(L->Next!=NULL){
        printf("%d\n",L->Element);
        L = L->Next;
    }
}