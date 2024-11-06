//
// Created by 26247 on 2024/10/7.
//
#include<stdio.h>

//由if语句限定输入范围
int main(void){
    int num;
    scanf("%d", &num);
    if (num >= 65 && num <= 90) {
        char asc = num;
        printf("%d %c", num, asc);
    } else {
        return 1;
    }

    return 0;
}
