#include <stdio.h>
#include <stdlib.h>
#include "Double Linked_List.h"

int main(){
    int a,num;
    DList L;
    L = (struct DNode*) malloc(sizeof (struct DNode));
    DList Previous,N;

    for(a=0;a<10;a++){
        Add(a,L);
    }

//    Insert(11,L);
//    Delete(5,L);

//    num = Retrieve(L);
//    Previous = FindPrevious(4,L);
//    N= Find(4,L);

    while(L->Next!=NULL){
        printf("%d\n",L->Element);
        L = L->Next;
    }
}