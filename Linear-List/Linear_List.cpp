//
// Created by Administrator on 2022/3/9.
//
#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"


linear_list_t *Create(void){
    linear_list_t *L;
    L = (linear_list_t*) malloc(sizeof (linear_list_t*));
    if(L)
        L->a_len = 0;
    return L;
}

void Destroy(linear_list_t *L){
    free(L);
}
void Set_null(linear_list_t *L){
    L->a_len=0;
}
int Length(linear_list_t *L){
    return L->a_len;
}

elem_t Get(linear_list_t *L, int i){
    if(i>L->a_len||i<0)
        return SUBSCRIPT;
    else
        printf("the number is ");
        return L->a[i];
}

error_t Insert(linear_list_t *L, elem_t x, int i){
    if(i>MAXSIZE||i<0)
        return OVERFLOW;
    else{
        int num=L->a_len;
        int j=i;
        if(i>0&&i<L->a_len) {
            while (i <= L->a_len) {
                L->a[num] = L->a[num-1];
                num--;
                i++;
            }
        }
        L->a[j]=x;
        L->a_len++;
    }
}
error_t Remove(linear_list_t *L, int i){
    if(i>MAXSIZE)
        return OVERFLOW;
    else{
        while(i<L->a_len){
            int num = i;
            L->a[num]=L->a[num+1];
            num++;
            i++;
        }
        L->a_len--;
    }
}
int Locate(linear_list_t *L, elem_t x){
    int num;
    for(num=0;num<=L->a_len;num++) {
        if (L->a[num] == x)
            return num;
    }
    return -1;
}