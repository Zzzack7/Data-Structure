//
// Created by 张书浩 on 2022/3/10.
//
#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"

List MakeEmpty( Position P){
    P->Next=NULL;
    return P;
}
int IsEmpty( Position P ){
    if(P->Next==NULL)
    return 1;
}
int IsLast( Position P ){
    if(P->Next==NULL)
        return 1;
    else
        return 0;
}
Position Find( ElementType X, Position P ){
    while(P->Element!=X)
        P = P->Next;
    if(P->Element==X)
        printf("the Element is exist");
}
void Delete( ElementType X, Position P ){
    Position DeleteNode;

    while(P->Next->Element!=X)
        P = P->Next;
    DeleteNode = P->Next;
    P->Next = DeleteNode->Next;
    free(DeleteNode);
    }
Position FindPrevious( ElementType X, Position P ){
    while(P->Next!=NULL&&P->Next->Element!=X)
        P = P->Next;
    return P;
}
void Add(ElementType X,Position P){
    Position TemCell;
    TemCell = (struct Node*) malloc(sizeof (struct Node));

    while (P->Next!=NULL)
        P = P->Next;
    TemCell->Element = X;
    TemCell->Next = NULL;
    P->Next = TemCell;
}
void Insert( ElementType X, Position P ){
    Position TemCell;

    TemCell = (struct Node*)malloc(sizeof(struct Node));

    TemCell->Element = X;
    TemCell->Next = P->Next;
    P->Next = TemCell;
    }
void DeleteList( Position P ){
    free(P);
}
Position Header( Position P ){
    if(P->Element==NULL)
        return P;
}
Position First( Position P ){
    if(P->Next!=NULL)
        return P->Next;
}
Position Advance( Position P ){
    if(P->Next!=NULL)
        return P->Next;
}
ElementType Retrieve( Position P ){
    if(P->Element!=NULL)
        return P->Element;
}
