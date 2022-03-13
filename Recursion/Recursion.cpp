//
// Created by Administrator on 2022/3/13.
//
#include <stdio.h>
#include <stdlib.h>
#include "Recursion.h"

int Idea(int i){
    if(i<0)
        printf("the last number\n");
    else{
        printf("%d\n",i);
        Idea(i-1);
    }
}

int Fibonacci(int i){
    if(i==0)
        return 0;
    if(i==1)
        return 1;
    return Fibonacci(i-1)+Fibonacci(i-2);
}

int GCD(int m, int n){
    if(m % n == 0)
        return n;
    if(n % m == 0)
        return m;
    return GCD(n,m % n);
}

int Factorial(int i){
    if(i==1)
        return 1;
    return i * Factorial(i-1);
}
