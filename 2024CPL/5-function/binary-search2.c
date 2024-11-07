//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>

//写中括号说明类型是整数数组；这里中括号内不能写数字：会被编译器删除，无效；实际上是在取该数组的首地址
int BinarySearch(int key, const int dict[], int length);

#define LEN 10
//文件作用域：全局型、危险
// int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main(void){
    //const避免自己或他人的修改，能加const的地方尽量加上const
    const int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int key;
    scanf("%d", &key);

    //使用调用函数时不再需要说明数据类型
    int index = BinarySearch(key, dictionary, LEN);
    //调用时写完整的数组名即可
    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", BinarySearch(key, dictionary, LEN));
    }
}

//dict:int[]
//dictionary:const int[]
//实参迁就形参，变为int[],会出现UB
int BinarySearch(int key, const int dict[], int length){
    int low = 0;
    int high = length - 1;

    //存储mid值输出的同时，实现找不到时输出-1说明寻找失败
    // int index=-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (key == dict[mid]) {
            return mid;
        } else if (key < dict[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        //label: goto label;
        //函数作用域：可以在该函数内任意位置调用该变量
    }
    return -1;
}
