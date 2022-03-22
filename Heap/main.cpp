#include <stdio.h>
#include "Heap.h"

int main() {
    PriorityQueue H;
    int i;
    H = Initialize(15);
    for(i=15;i>0;i--){
        Insert(i,H);
    }
    if(IsFull(H))
        printf("the Heap is full\n");
    printf("the min number is %d\n", FindMin(H));
    printf("the size of heap is %d\n",H->Size);
    DeleteMin(H);
    printf("the New min number is %d\n", FindMin(H));
    printf("the size of heap is %d\n",H->Size);
    MakeEmpty(H);
    if(IsEmpty(H))
        printf("the Heap is empty\n");
    Destroy(H);
    return 0;
}
