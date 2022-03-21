//
// Created by Administrator on 2022/3/20.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#define MinTableSize (10)

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;
typedef int ElementType;
typedef Position List;

int Hash(ElementType Key, int TableSize);
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
void Delete(ElementType Key,HashTable H);
ElementType Retrieve(Position P);

struct ListNode{
    ElementType Element;
    Position Next;
};
struct HashTbl{
    int TableSize;
    List* TheLists;
};

#endif //HASH_TABLE_HASH_TABLE_H
