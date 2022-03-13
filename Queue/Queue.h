//
// Created by Administrator on 2022/3/6.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#define MaxElements -1
typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord* Queue;

struct Node{
    ElementType Element;
    struct Node* Next;
};

struct QueueRecord{
    struct Node* L;
    struct Node* R;
    int Size;
};

int IsEmpty( Queue Q);
Queue CreateQueue();
void DisposeQueue( Queue Q);
void MakeEmpty( Queue Q);
void Enqueue(ElementType X,Queue Q);
void Dequeue(Queue Q);
ElementType Front(Queue Q);

#endif //QUEUE_QUEUE_H
