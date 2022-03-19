//
// Created by Administrator on 2022/3/18.
//
#include "AVL Tree.h"
#include <stdio.h>
#include <stdlib.h>

AVLTree ViewToRebalance(AVLTree T){
    ReBalance(T);
    if(T->Left!=NULL&&T->Right!=NULL){
        ViewToRebalance(T->Left);
        ViewToRebalance(T->Right);
    }
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}
ElementType Max(ElementType a,ElementType b){
    if(a>b)
        return a;
    return b;
}
ElementType Height(Position P){
    if(P == NULL)
        return -1;
    else
        return P->height;
}

AVLTree MakeEmpty(AVLTree T){
    Position P;
    if(T->Left!=NULL){
        T = T->Left;
        MakeEmpty(T);
    }
    else if(T->Right!=NULL){
        T = T->Right;
        MakeEmpty(T);
    }
    P = T;
    free(P);
}

Position Find(ElementType X,AVLTree T){
    if(X<T->Element)
        Find(X,T->Left);
    else if(X>T->Element)
        Find(X,T->Right);
    else if(X==T->Element)
        return T;
    return NULL;
}

Position FindMin(AVLTree T){
    if(T->Left!=NULL)
        FindMin(T->Left);
    return T;
}

Position FindMax(AVLTree T){
    if(T->Right!=NULL)
        FindMax(T->Right);
    return T;
}

AVLTree Insert(ElementType X,AVLTree T){
    if(T==NULL){
        T = (struct AVLNode*)malloc(sizeof (struct AVLNode));
        T->Element = X;
        T->height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X<T->Element){
        T->Left = Insert(X,T->Left);
        if(Height(T->Left) - Height(T->Right)==2){
            if(X<T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(X>T->Element){
        T->Right = Insert(X,T->Right);
        if(Height(T->Right) - Height(T->Left)==2){
            if(X>T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AVLTree Delete(ElementType X,AVLTree T){
    Position TemCell;
    if(T==NULL)
        printf("the tree is NULL");
    else if(X<T->Element){
        T->Left = Delete(X,T->Left);
    }
    else if(X>T->Element){
        T->Right = Delete(X,T->Right);
    }
    else if(T->Element==X&&T->Left&&T->Right){
        TemCell = FindMin(T->Right);
        T->Element = TemCell->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else{
        TemCell = T;
        if(T->Left==NULL){
            T = T->Right;
        }
        else if(T->Right==NULL){
            T = T->Left;
        }
        free(TemCell);
    }
    return T;
}

ElementType Retrieve(Position P){
    if(P!=NULL)
        return P->Element;
    else
        return -1;
}
AVLTree ReBalance(AVLTree T){
    if(T!=NULL){
        if(Height(T->Left) - Height(T->Right)==2){
            if(Height(T->Left->Left) > Height(T->Left->Right))
                SingleRotateWithLeft(T);
            else
                DoubleRotateWithLeft(T);
        }
        else if(Height(T->Right) - Height(T->Left)==2){
            if(Height(T->Right->Right)> Height(T->Right->Left))
                SingleRotateWithRight(T);
            else
                DoubleRotateWithRight(T);
        }
    }
    T->height = Max(Height(T->Left), Height(T->Right))+1;
    return T;
}
AVLTree SingleRotateWithLeft(Position K2){
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->height = Max(Height(K2->Left),Height(K2->Right))+1;
    K1->height = Max(Height(K1->Left), Height(K1->Right))+1;

    return K1;
}

AVLTree SingleRotateWithRight(Position K2){
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->height = Max(Height(K2->Left),Height(K2->Right))+1;
    K1->height = Max(Height(K1->Left), Height(K1->Right))+1;

    return K1;
}

AVLTree DoubleRotateWithLeft(Position K3){
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

AVLTree DoubleRotateWithRight(Position K3){
    K3->Right = SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}
