#include <stdio.h>
#include "AVL Tree.h"

int main(){
    AVLTree test=NULL;

    int i,h;
    for(i=0;i<8;i++){
        test = Insert(i,test);
    }
    Delete(5,test);
    ViewToRebalance(test);
    h = Height(test);
    printf("the height is %d\n",h);

}