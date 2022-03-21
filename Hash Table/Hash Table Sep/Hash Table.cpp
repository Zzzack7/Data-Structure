//
// Created by Administrator on 2022/3/20.
//
#include "Hash Table.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Hash(ElementType Key, int TableSize){
        return Key % 10;
}
HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;

    if(TableSize<MinTableSize){
        printf("the size is too small");
        return NULL;
    }
    H = (struct HashTbl*) malloc (sizeof (struct HashTbl));
    if(H==NULL)
        printf("out of space");

    H->TableSize = TableSize;
    H->TheLists =  (struct ListNode** ) malloc(sizeof (List)*H->TableSize);
    for(i=0;i<TableSize;i++){
        H->TheLists[i]= (struct ListNode*) malloc(sizeof (struct ListNode));
        if(H->TheLists==NULL)
            printf("out of space");
        else
            H->TheLists[i]->Next = NULL;
    }
    return H;
}
void DestroyTable(HashTable H){
    free(H);
}
Position Find(ElementType Key, HashTable H){
    Position P;
    List L;

    L = H->TheLists[Hash(Key,H->TableSize)];
    P = L->Next;
    while(P!=NULL&&P->Element!=Key)
        P = P->Next;
    return P;
}
void Insert(ElementType Key, HashTable H){
    Position Pos,NewCell;
    List L;

    Pos = Find(Key,H);
    if(Pos == NULL){
        NewCell = (struct ListNode*) malloc(sizeof (struct ListNode));
        if(NewCell==NULL)
            printf("out of space");
        else{
            L = H->TheLists[Hash(Key,H->TableSize)];
            NewCell->Element = Key;
            NewCell->Next = L->Next;
            L->Next = NewCell;
        }
    }
}
void Delete(ElementType Key,HashTable H){
    Position TemCell;
    List L;

    TemCell = Find(Key,H);
    if(TemCell == NULL)
        printf("not exist this element");
    else{
        L = H->TheLists[Hash(Key,H->TableSize)];
        L->Next = TemCell->Next;
        free(TemCell);
    }
}
ElementType Retrieve(Position P);
