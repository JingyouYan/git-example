//
// Created by 26247 on 2024/10/7.
//
#include<stdio.h>

//注意检查50,20取余在输出时候会出现的问题
int main(void){
    int change;
    scanf("%d", &change);
    if (change >= 0 && change <= 10000) {
        int fifty = change / 50;
        int twenty = change % 50 / 20;
        int ten = change % 50 % 20 / 10;
        int five = change % 10 / 5;
        int one = change % 5;

        printf("%d\n%d\n%d\n%d\n%d\n", fifty, twenty, ten, five, one);

        return 0;
    } else {
        return 1;
    }
}
