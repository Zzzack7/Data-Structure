//
// Created by Administrator on 2022/3/21.
//

#ifndef HASH_TABLE_QUAD_HASH_TABLE_H
#define HASH_TABLE_QUAD_HASH_TABLE_H
#define MinTableSize 10

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
void Delete(ElementType Key,HashTable H);
HashTable Rehash(HashTable H);
ElementType Hash(ElementType Key,int TableSize);

enum KindOfEntry{Legitimate,Empty,Deleted};

struct HashEntry{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl{
    int TableSize;
    Cell* TheCells;
};
#endif //HASH_TABLE_QUAD_HASH_TABLE_H
