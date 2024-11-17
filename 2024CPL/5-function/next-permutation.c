//
// Created by 26247 on 2024/11/9.
//
#include <stdio.h>
#include <stdbool.h>
#define SIZE 200

//理解出现了错误：最长递减后缀——后缀指的是从i一直到n-1为止
int main(void){
    int n;
    scanf("%d", &n);

    int a[SIZE] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    //实现整个数列递减的判断
    int index = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) {
            index = i;
            break;
        }
    }

    int key = a[index];
    for (int i = n - 1; i > index; i--) {
        if (a[i] > key) {
            int temp = a[i];
            a[i] = key;
            a[index] = temp;
            break;
        }
    }

    for (int i = index + 1, j = n - 1; i < j; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
