//
// Created by Administrator on 2022/3/18.
//

#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H

struct AVLNode;

typedef struct AVLNode* AVLTree;
typedef struct AVLNode* Position;
typedef int ElementType;

struct AVLNode{
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int height;
};

AVLTree ViewToRebalance(AVLTree T);
AVLTree ReBalance(AVLTree T);
ElementType Max(ElementType a,ElementType b);
AVLTree MakeEmpty(AVLTree T);
Position Find(ElementType X,AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(ElementType X,AVLTree T);
AVLTree Delete(ElementType X,AVLTree T);
ElementType Retrieve(Position P);
ElementType Height(Position P);
AVLTree SingleRotateWithLeft(Position K2);
AVLTree SingleRotateWithRight(Position K2);
AVLTree DoubleRotateWithLeft(Position K2);
AVLTree DoubleRotateWithRight(Position K2);


#endif //AVL_TREE_AVL_TREE_H
