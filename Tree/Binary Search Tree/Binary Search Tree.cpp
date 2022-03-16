//
// Created by Administrator on 2022/3/16.
//
#include <stdio.h>
#include <stdlib.h>
#include "Binary Search Tree.h"

SearchTree MakeEmpty(SearchTree T){
    if(T!=NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
Position Find(ElementType X,SearchTree T){
    if(T==NULL)
        return NULL;
    if(X<T->Element)
        Find(X,T->Left);
    else if(X>T->Element)
        Find(X,T->Right);
    return T;
}
Position FindMin(SearchTree T){
    if(T==NULL)
        return NULL;
    else if(T->Left==NULL)
        return T;
    else
        FindMin(T->Left);
}
Position FindMax(SearchTree T){
    if(T==NULL)
        return NULL;
    else if(T->Right==NULL)
        return T;
    else
        FindMax(T);
}
SearchTree Insert(ElementType X, SearchTree T){
    if(T==NULL){
        T = (struct TreeNode*) malloc(sizeof (struct TreeNode));
        if(T==NULL)
            printf("out of space");
        else{
            T->Element = X;
            T->Left=T->Right=NULL;
        }
    }
    else if(X<T->Element)
        Insert(X,T->Left);
    else if(X>T->Element)
        Insert(X,T->Right);
    return T;
}
SearchTree Delete(ElementType X, SearchTree T){
    Position TemCell;

    if(T==NULL)
        printf("the tree is NULL");
    else if(X<T->Element)
        T->Left = Delete(X,T->Left);
    else if(X>T->Element)
        T->Right = Delete(X,T->Right);
    else if(T->Left&&T->Right){
        TemCell = FindMin(T->Right);
        T->Element = TemCell->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else{
        TemCell = T;
        if(T->Left==NULL)
            T = T->Right;
        else if(T->Right==NULL)
            T = T->Left;
        free(TemCell);
    }
    return T;
}
ElementType Retrieve(Position P);