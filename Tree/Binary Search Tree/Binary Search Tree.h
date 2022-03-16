//
// Created by Administrator on 2022/3/16.
//

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
typedef int ElementType;

struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
