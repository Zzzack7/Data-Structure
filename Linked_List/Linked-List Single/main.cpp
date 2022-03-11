#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"

int main() {
    Position P;
    P = (struct Node*) malloc(sizeof (struct Node));
    Position Q;
    Q = (struct Node*) malloc(sizeof (struct Node));

    int i,num;
    for(i=1;i<11;i++){
       Add(i,P);
    }
//    MakeEmpty(P);

//    num = IsEmpty(P);
//    if(num == 1)
//        printf("the list is Empty");

//    num = IsLast(P);
//    if(num == 1)
//        printf("is the last");
//    else
//        printf("isn't the last");

//    Q = FindPrevious(6,P);

//    Delete(4,P);

        while(P->Next!=NULL){
        printf("%d\n",P->Element);
        P = P->Next;
    }

//    Find(11,P);

//    printf("the previous num is %d",Q->Element);
}
