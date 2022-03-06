#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    struct StackRecord* test;
    int a,num,b;
    test =  CreateStack();
//    if(IsEmpty(test)){
//        printf("the Stack is empty");
//    }
    for(a=2;a<=20;a+=3){
        Push(a,test);
    }
//    num= Top(test);
//    printf("the Top number is %d",num);

//    b = SearchStack(5,test);
//    if(b==1)
//        printf("the number is exist in Stack");
//    else
//        printf("the number isn't exist");


}
