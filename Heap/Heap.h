//
// Created by Administrator on 2022/3/22.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H
#define MinPQSize 10
#define MinData -32767
typedef int ElementType;
struct HeapStruct;
typedef HeapStruct * PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

struct HeapStruct{
    int Capacity;
    int Size;
    ElementType *Elements;
};

#endif //HEAP_HEAP_H
