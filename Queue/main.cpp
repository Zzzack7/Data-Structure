#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
    Queue test;
    test = (struct QueueRecord*) malloc(sizeof (struct QueueRecord));
    test = CreateQueue();
    int a, b;

//    a = IsEmpty(test);
//    if(a==1)
//        printf("the Queue is empty");
    for(b=1;b<=20;b+=2){
        Enqueue(b,test);
    }
    Enqueue(11,test);
//    b = Front(test);
    Dequeue(test);
    while(test->L!=NULL){
        printf("the num is %d\n",test->L->Element);
        test->L = test->L->Next;
    }
    //DisposeQueue(test);

//    a = IsEmpty(test);
//    if(a==1)
//        printf("the Queue is empty");
//    else
//        printf("the Queue is exist element");
}
