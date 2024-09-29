//
// Created by 26247 on 2024/9/22.
//
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int num =rand();
    if(num==0) {
        printf("num==0\n");
    }
    else if(num==1) {
            printf("num==1\n");
        }
    else {
            printf("num!=0 and num!=1\n num==%d\n",num);
        }

    return 0;
}