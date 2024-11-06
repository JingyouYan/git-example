//
// Created by 26247 on 2024/10/7.
//
#include<stdio.h>
//macro 编译端改变，便于修改变量，同时避免magic number以及VLA——variable-length array内存不可预知，平台不可迁移等缺点
#define NUM 5

int main(void){
    int numbers[NUM] = {23, 56, 78, 23, 11};
    int min = numbers[0];
    for (int i = 1; i < NUM;) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        i ++;
    }
    printf("min = %d\n", min);
    return 0;
}
//threads&variables 调试功能 add to watches调试代码debug for循环语句中括号内三个条件可通过换行实现分步调试
