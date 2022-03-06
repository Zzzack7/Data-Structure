//
// Created by Administrator on 2022/3/6.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define MaxElements -1
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord* Stack;



int IsEmpty( Stack S );
Stack CreateStack();
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
int SearchStack( ElementType X,Stack S );

#endif //STACK_STACK_H
