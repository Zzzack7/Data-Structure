//
// Created by Administrator on 2022/3/22.
//
#include "Heap.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue Initialize(int MaxElements){
    PriorityQueue H;

    if(MaxElements<MinPQSize)
        printf("Priority queue size is too small");

    H = (struct HeapStruct*) malloc(sizeof (struct HeapStruct));
    if(H==NULL)
        printf("Out of space");

    H->Elements = (ElementType*) malloc(sizeof (ElementType)*(MaxElements+1));
    if(H->Elements == NULL)
        printf("Out of space");
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;

    return H;
}
void Destroy(PriorityQueue H){
    free(H);
}
void MakeEmpty(PriorityQueue H){
    int i = H->Capacity;
    int j;
    for(j=1;j<=i;j++){
        H->Elements[j]=0;
    }
    H->Size = 0;
}
void Insert(ElementType X,PriorityQueue H){
    int i;

    if(IsFull(H)){
        printf("the heap is full");
        return;
    }
    for(i=++H->Size;H->Elements[i/2]>X;i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}
ElementType DeleteMin(PriorityQueue H){
    int i,Child;
    ElementType MinElement,LastElement;

    if(IsEmpty(H)){
        printf("the Heap is Empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for(i=1;i*2<=H->Size;i=Child){
        Child = i * 2;
        if(Child!=H->Size&&H->Elements[Child]>H->Elements[Child+1])
            Child++;
        if(LastElement>H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}
ElementType FindMin(PriorityQueue H){
    return H->Elements[1];
}
int IsEmpty(PriorityQueue H){
    if(H->Size==0)
        return 1;
    return 0;
}
int IsFull(PriorityQueue H){
    if(H->Size==H->Capacity)
        return 1;
    return 0;
}