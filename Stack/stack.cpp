//
// Created by Administrator on 2022/3/6.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct StackRecord{
    ElementType Element;
    struct StackRecord* Next;
};
int IsEmpty( Stack S ){
    if(S->Next==NULL)
        return 1;
    else
        return 0;
}

Stack CreateStack( ){
    Stack s;

    s = (Stack)malloc(sizeof(Stack));
    s->Element = MaxElements;
    s->Next =NULL;
}
//define the Create operation

void DisposeStack( Stack S ){
    MakeEmpty(S);
    free(S);
}
//define the Dispose operation
void MakeEmpty( Stack S ){
    while(!IsEmpty(S))
        Pop(S);
}
void Push( ElementType X, Stack S ){
    struct StackRecord* Node;
    Node = (struct StackRecord*) malloc(sizeof(struct StackRecord*));
    Node->Element=X;
    Node->Next = S->Next;
    S->Next = Node;
}
//the main operation of Stack -- push

ElementType Top( Stack S ){
    return S->Next->Element;
}
//find the top of the stack element

void Pop( Stack S ){
    if(IsEmpty(S))
        return;
    else{
        struct StackRecord* FirstCell;
        FirstCell = S->Next;
        S->Next=FirstCell->Next;
        free(FirstCell);
    }
}
//the main operation of Stack -- pop

int SearchStack( ElementType X,Stack S ){
    struct StackRecord* SearchPoint;
    SearchPoint = (struct StackRecord*) malloc(sizeof(struct StackRecord*));
    while(!IsEmpty(S)){
        SearchPoint = S->Next;
        if(SearchPoint->Element==X)
            return 1;
        S->Next = SearchPoint->Next;
    }
    return 0;
}
//add a operation to find the element

