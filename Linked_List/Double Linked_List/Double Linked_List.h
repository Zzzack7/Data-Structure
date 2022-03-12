//
// Created by 张书浩 on 2022/3/11.
//

#ifndef LINKED_LIST_DOUBLE_DOUBLE_LINKED_LIST_H
#define LINKED_LIST_DOUBLE_DOUBLE_LINKED_LIST_H
struct DNode;
typedef struct DNode *PtrToDNode;
typedef PtrToDNode DList;
typedef int ElementType;

struct DNode
{
    ElementType Element;
    struct DNode *Prev;
    struct DNode *Next;
};

DList Find( ElementType X, DList L );
DList FindPrevious( ElementType X, DList L );
ElementType Retrieve( DList L );
void Add(ElementType X , DList L);
void Insert( ElementType X, DList L );
void Delete( ElementType X, DList L );

#endif //LINKED_LIST_DOUBLE_DOUBLE_LINKED_LIST_H
