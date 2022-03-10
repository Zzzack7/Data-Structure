#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"

int main() {
    int a,b,locate;
    a=0;
    linear_list_t *l = Create();
//    a = Length(l);
//    printf("the length is %d",a);
//    for(b=0;b<10;b++){
//        Insert(l,a,b);
//        a+=2;
//    }
//    for(b=0;b<=10;b++){
//        int c= Get(l,b);
//        printf("%d\n",c);
//    }
//    Insert(l,15,4);

    for(b=0;b<10;b++){
        Insert(l,a,b);
        a+=2;
    }
    Remove(l,5);
//    locate = Locate(l,12);
//    printf("the element is at %d\n",locate);
    for(b=0;b<10;b++){
        int c= Get(l,b);
        printf("%d\n",c);
    }
//    Set_null(l);
//    Destroy(l);
//    printf("%d",l->a[4]);
}
