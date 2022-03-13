//
// Created by Administrator on 2022/3/6.
//
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int IsEmpty( Queue Q ){
    if(Q->Size==0)
        return 1;
    else
        return 0;
}

Queue CreateQueue(void){
    Queue Q = (struct QueueRecord*) malloc(sizeof (struct QueueRecord));

    Q->L=NULL;
    Q->R=NULL;
    Q->Size=0;

    return Q;
}

void DisposeQueue(Queue Q){
    MakeEmpty(Q);
    free(Q);
}
void MakeEmpty(Queue Q){
    while (!IsEmpty(Q))
        Dequeue(Q);
}
void Enqueue(ElementType X,Queue Q){
    struct Node* Pointer;
    Pointer = (struct Node*) malloc(sizeof(struct Node));
    Pointer->Element = X;
    Pointer->Next = NULL;

    if(Q->R==NULL){
        Q->R = Pointer;
        Q->L = Pointer;
    }
    else{
        while(Q->R->Next!=NULL)
            Q->R = Q->R->Next;
        Q->R->Next = Pointer;
    }
    Q->Size ++;
}
void Dequeue(Queue Q){
    if(IsEmpty(Q))
        return;
    else{
        struct Node* FirstPointer;
        FirstPointer = Q->L;
        Q->L = FirstPointer->Next;
        free(FirstPointer);

        Q->Size --;
    }
}
ElementType Front(Queue Q){
    if(IsEmpty(Q))
        return 0;
    else{
        struct Node* FrontPoint;
        FrontPoint = Q->L;
        return FrontPoint->Element;
    }
}