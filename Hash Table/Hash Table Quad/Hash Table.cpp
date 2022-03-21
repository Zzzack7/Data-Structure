//
// Created by Administrator on 2022/3/21.
//
#include "Hash Table.h"
#include <stdlib.h>
#include <stdio.h>
HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;

    if(TableSize<MinTableSize){
        printf("Table size too small");
        return NULL;
    }
    H = (struct HashTbl*) malloc(sizeof (struct HashTbl));
    if(H==NULL){
        printf("out of space");
    }
    H->TableSize = TableSize;
    H->TheCells = (Cell*) malloc(sizeof (Cell)*H->TableSize);
    if(H->TheCells==NULL)
        printf("out of space");
    for(i=0;i<H->TableSize;i++){
        H->TheCells[i].Info = Empty;
    }
    return H;
}
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H){
    Position CurrentPo;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPo = Hash(Key,H->TableSize);
    while(H->TheCells[CurrentPo].Info!=Empty&&H->TheCells[CurrentPo].Element!=Key){
        CurrentPo = 2* ++CollisionNum - 1;
        if(CurrentPo>H->TableSize)
            CurrentPo -= H->TableSize;
    }
    return CurrentPo;
}
void Insert(ElementType Key,HashTable H){
    Position Pos;

    Pos = Find(Key,H);
    if(H->TheCells[Pos].Info!=Legitimate){
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

void Delete(ElementType Key,HashTable H){
    Position Pos;

    Pos = Find(Key,H);
    if(H->TheCells[Pos].Info==Legitimate){
        H->TheCells[Pos].Info = Deleted;
    }
}
HashTable Rehash(HashTable H);
ElementType Hash(ElementType Key,int TableSize){
    return Key % 10;
}