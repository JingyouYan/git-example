//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>

int main(void){
    int n, t;
    scanf("%d%d", &n, &t);

    int sum = 0;
    int number = 0;
    //9位内int类型完全可实现
    for (int i = 0; i < n; i++) {
        number = number * 10 + t;
        sum += number;
    }

    printf("%d", sum);
    return 0;
}
