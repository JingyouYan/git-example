//
// Created by 26247 on 2024/12/20.
//
#include <stdio.h>
#include <string.h>
#define NUM 1000
#define LEN 22
#define SIZE 11

double Average(const int a[], int n);

void swapVal(double *left, double *right);

void swapStr(char arr2[][LEN], int i, int j);

int getMinIndex(const double *arr, int begin, int end);

void newSelectionSort(double *score, char arr2[][LEN], int len);

void printArray(const char arr[][LEN], int len);

int main(void){
    int n;
    scanf("%d", &n);

    char originalName[NUM][LEN] = {'\0'};

    double result1[NUM] = {0};
    double result2[NUM] = {0};
    double result3[NUM] = {0};

    int i = 0;
    //n的值后面还要使用，需要新的参量辅助恢复
    int count = n;
    while (count--) {
        scanf("%s", originalName[i]);
        int score1[SIZE] = {0};
        int score2[SIZE] = {0};
        int score3[SIZE] = {0};
        for (int j = 0; j < SIZE; j++) {
            //每次清空playerName，相当于“缓冲”掉这个字符，否则会一直待在输入流中导致下次读取错误的数据、位置
            char playerName[LEN] = {'\0'};
            //已经规定了输入格式就不用重复写了,精简很多
            scanf("%s %d %d %d", playerName, &score1[j], &score2[j], &score3[j]);
            // scanf("%d", &score2[j]);
            // scanf("%d", &score3[j]);
        }
        result1[i] = Average(score1, SIZE);
        result2[i] = Average(score2, SIZE);
        result3[i] = Average(score3, SIZE);
        i++;
    }

    //how to print the team name according to the scores
    char name[NUM][LEN] = {'\0'};
    memcpy(name, originalName, sizeof(originalName));
    newSelectionSort(result1, name, n);
    printArray(name, n);
    memcpy(name, originalName, sizeof(originalName));
    newSelectionSort(result2, name, n);
    printArray(name, n);
    newSelectionSort(result3, originalName, n);
    printArray(originalName, n);
}

double Average(const int a[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum * 1.0 / n;
}

void swapVal(double *left, double *right){
    double temp = *left;
    *left = *right;
    *right = temp;
}

void swapStr(char arr2[][LEN], int i, int j){
    char temp[LEN];
    strcpy(temp, arr2[i]);
    strcpy(arr2[i], arr2[j]);
    strcpy(arr2[j], temp);
}

int getMinIndex(const double *arr, int begin, int end){
    double min = arr[begin];
    int minIndex = begin;
    //小心边界问题
    for (int i = begin + 1; i <= end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// void newSelectionSort(double *score, char arr2[][LEN], int len){
//     for (int i = 0; i < len; i++) {
//         int min_index = getMinIndex(score, i, len - 1);
//         swapVal(score + i, score + min_index);
//         //swapVal期望的是一个指向字符数组内部第一个字符的指针
//         swapStr(*(arr2 + i), *(arr2 + min_index));
//     }
// }
void newSelectionSort(double *score, char arr2[][LEN], int len){
    for (int i = 0; i < len; i++) {
        int min_index = getMinIndex(score, i, len - 1);
        swapVal(score + i, score + min_index);
        swapStr(arr2, i, min_index);
    }
}

//当声明多维数组作为函数参数时，除了第一维可以省略大小（因为编译器可以通过传递的指针和其他信息推断），其余维度的大小必须明确指定。
void printArray(const char arr[][LEN], int len){
    for (int i = len - 1; i >= 0; i--) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}
