//
// Created by 张书浩 on 2022/3/11.
//

#include <stdlib.h>
#include "Double Linked_List.h"

DList Find( ElementType X, DList L ){
    while(L->Element!=X)
        L=L->Next;
    return L;
}
DList FindPrevious( ElementType X, DList L ){
    while (L->Next->Element!=X)
        L=L->Next;
    return L;
}
ElementType Retrieve( DList L ){
    return L->Element;
}
void Add(ElementType X , DList L){
    DList AddNode;
    AddNode = (struct DNode*) malloc(sizeof (struct DNode));

    AddNode->Element = X;
    AddNode->Prev = L;
    L->Next = AddNode;
    L = AddNode;

}
void Insert( ElementType X, DList L ){
    DList InsertNode;
    InsertNode = (struct DNode*) malloc(sizeof (struct DNode));

    InsertNode->Element = X;
    InsertNode->Prev = L;
    InsertNode->Next = L->Next;
    L->Next->Prev=InsertNode;
    L->Next = InsertNode;
}
void Delete( ElementType X, DList L ){
    DList DeleteNode;

    while(L->Element!=X)
        L = L->Next;
    DeleteNode = L;
    L->Prev->Next=DeleteNode->Next;
    L->Next->Prev=DeleteNode->Prev;
    free(DeleteNode);
}