#include <stdio.h>
#include "Hash Table.h"

int main(){
    HashTable H;
    int i,Temp;
    char state;

    H = InitializeTable(23);
    for(i=23;i<40;i++){
        Insert(i,H);
    }
    Delete(33,H);
    state = H->TheCells[11].Info;
    printf("%d",state);
    Temp = Find(38,H);
    if(Temp>=0||Temp<=23)
        printf("the num exist at %d",Temp);
}