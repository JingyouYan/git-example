//
// Created by 26247 on 2024/10/13.
//
#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);

    //位数
    int num_of_digits = 0;

    //有两种处理特殊的0的做法，一种逻辑算式实现，一种使用do-while语句实现（使用if会让代码丑陋）
    while (num > 0 || num_of_digits == 0) {
        num /= 10;
        num_of_digits++;
    }
    printf("%d\n", num_of_digits);
    return 0;
}
