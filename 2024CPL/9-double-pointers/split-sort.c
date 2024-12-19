//
// Created by 26247 on 2024/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10100
#define LEN 100
#define NUM 100

int GetMinIndex(const char (*array)[], int begin, int end);

void Swap(const char **left, const char **right);

void SelectionSort(char (*array)[], int length);

int main(void){
    char string0[SIZE] = {'\0'};
    scanf("%s", string0);
    char (*string)[LEN] = malloc(NUM * sizeof(*string));
    //记得每次调用malloc对应的是stdlib.h标准库函数，后面学的qsort bsearch大多也是滴
    //记得检查是否分配成功，是否free
    if (string == NULL) {
        return 1;
    }
    memset(string, '\0', strlen(string0) + 1);

    char divide;
    scanf("%c", &divide);

    int count = 0;
    int index = 0;
    for (int i = 0; i < strlen(string0); i++) {
        if (string0[i] == divide) {
            count++;
            index = 0;
        } else {
            *(*(string + count) + index++) = string0[i + count];
        }
    }

    int n = count + 1; //字符串的个数
    SelectionSort(string, n);

    for (int i = 0; i < n; i++) {
        printf("%s", string[i]);
        printf("\n");
    }

    free(string);
}

int GetMinIndex(const char (*array)[], int begin, int end){
    const char *min = *(array + begin);
    int minIndex = begin;
    for (int i = begin; i < end; i++) {
        if (strcmp(*(array + i), min) < 0) {
            minIndex = i;
            min = array[i];
        }
    }
    return minIndex;
}

void Swap(const char **left, const char **right){
    //赋值式两端要保持类型一致
    const char *temp = *left;
    *left = *right;
    *right = temp;
}

void SelectionSort(char (*array)[], int length){
    for (int i = 0; i < length; i++) {
        int minIndex = GetMinIndex(array, i, length);
        Swap((const char **) (array + i), (const char **) (array + minIndex));
    }
}