//
// Created by 26247 on 2024/9/29.
//
#include<stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    int min;
    scanf("%d%d", &a, &b);
    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    printf("min = %d\n", min);
    return 0;
}
