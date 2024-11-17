//
// Created by 26247 on 2024/11/17.
//
#include <stdio.h>
#define LEN 5

void selectionSort(int arr[], int len);

int getMinIndex(const int arr[], int begin, int end);

void swapVal(int *left_val, int *right_val);

void oldSwap(int arr[], int left_index, int right_index);

void printArray(const int arr[], int len);

int main(void){
    int array[LEN] = {5, 2, 8, 1, 9};

    printArray(array,LEN);
    printf("\n");
    selectionSort(array,LEN);
    printArray(array,LEN);

    return 0;
}

void selectionSort(int *arr, int len){
    for (int i = 0; i < len; i++) {
        int min_index = getMinIndex(arr, i, len - 1);
        swapVal(&arr[i], &arr[min_index]);
    }
}

int getMinIndex(const int *arr, int begin, int end){
    int min = arr[begin];
    int minIndex = begin;
    for (int i = begin; i < end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void oldSwap(int arr[], int left_index, int right_index){
    //在数组上作操作，而非单纯值的拷贝
    int temp = arr[left_index];
    arr[left_index] = arr[right_index];
    arr[right_index] = temp;
}

void swapVal(int *left_val, int *right_val){
    //我得到的是两个指针变量，得到了变量的地址，操作的就不再是值的拷贝，而是对应到了变量，因此实现了间接操作其对应变量
    int temp = *left_val;
    *left_val = *right_val;
    *right_val = temp;
}

void printArray(const int arr[], int len){
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
