//
// Created by 张书浩 on 2022/3/10.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
typedef int ElementType;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

List MakeEmpty( Position P );
int IsEmpty( Position P );
int IsLast( Position P );
Position Find( ElementType X,Position P );
void Delete( ElementType X,Position P);
Position FindPrevious( ElementType X,Position P);
void Add(ElementType X,Position P);
void Insert( ElementType X, Position P );
void DeleteList( Position P);
Position Header( Position P );
Position First( Position P );
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif //LINKED_LIST_LINKED_LIST_H
