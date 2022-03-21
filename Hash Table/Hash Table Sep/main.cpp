#include <stdio.h>
#include "Hash Table.h"

int main() {
    HashTable H;
    int i ;
    H = InitializeTable(12);
    for(i=0;i<20;i++){
        Insert(i,H);
    }
//    Delete(18,H);
//    DestroyTable(H);
    if(Find(18,H))
        printf("the number exist");
    return 0;
}
