//
// Created by 26247 on 2024/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int GetMinIndex(char *array[], int begin, int end);

//函数声明里参数的const限定只有在函数定义中才有实际效果。
//开头是声明，后面才是定义
void Swap(const char **left, const char **right);

void PrintArray(char *array[], int length);

void SelectionSort(char *array[], int length);

int main(void){
    //C语言中声明符和运算符默认优先级相同了
    char *musician1[LEN] = {}; //一个数组，里面存的是指向char *的指针
    char (*musician2)[LEN] = {}; //一个指针，指向存储char类型数据的数组
}

int GetMinIndex(const char *array[], int begin, int end){
    const char *min = array[begin];
    int minIndex = begin;
    for (int i = begin; i < end; i++) {
        if (strcmp(array[i], min) < 0) {
            minIndex = i;
            min = array[i];
        }
    }
    return minIndex;
}

void Swap(const char **const left, const char **const right){
    //strcpy代价太大，需要三次操作；相比证书数组交换地址解引用的值，这里选择直接修改指针的指向
    //可以从指向哪里一层层讨论
    char *temp = *left;
    *left = *right;
    *right = temp;
}

//const int * const array:这个指针始终指向该区域，同时不能通过指针去修改指向的变量
void PrintArray(const char *array[], int length){
    // *(array+1)=1;Cannot assign to readonly type const int
    //除了首地址被保护，由于array+1指针类型等也是相同的，仍然不可以修改值
    for (int i = 0; i < length; i++) {
        printf("%s ", *(array + i));
    }
    printf("\n");
}

void SelectionSort(char *array[], int length){
    for (int i = 0; i < length; i++) {
        int minIndex = GetMinIndex(array, i, length);
        //arr:char *[]
        //arr+i:char **
        Swap(array + i, array + minIndex);
    }
    PrintArray(array, length);
}
