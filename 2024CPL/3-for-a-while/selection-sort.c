//
// Created by 26247 on 2024/10/13.
//
#include <stdio.h>
// #define LEN 9
// int dictionary[LEN] = {29, 72, 98, 13, 87, 66, 52, 51, 36};

int main(void){
    int dictionary[] = {0};

    //scanf：会指定输入的格式，返回成功读取并赋值的输入项的个数。
    //如果没有读取任何项，或者在读取过程中发生错误，它将返回 EOF（通常是 -1）。
    int len = -1;
    //abbreviated form:the content in the buckets is so complex that {}is nothing but ;
    //通过sacnf的返回值判断什么时候结束了读取
    //stream
    //input failure: EOF (-1)
    //match failure: assigned items ( >= 0)
    int ret;
    while ((ret = scanf("%d", &dictionary[++len])) != EOF);
    printf("%d\n", ret);
    //始终没有返回值：scanf仍然在等待一个整型输入，换行符无法结束读取
    //Ubuntu: ctrl + D 输入行末使用2次————第一次传送已读数据，第二次才输出EOF信号 Clion不适用

    //find the min of each loop
    //outer loop:decide the position that is being weighed.
    for (int i = 0; i < len; i++) {
        int min = dictionary[i];
        int min_index = i;
        //inner loop:find the minimum of the surplus numbers.
        for (int j = i; j < len; j++) {
            if (dictionary[j] < min) {
                min = dictionary[j];
                min_index = j;
            }
        }

        //temp:temporary ____  A common method of swap the value of two numbers.
        int temp = dictionary[i];
        dictionary[i] = dictionary[min_index];
        dictionary[min_index] = temp;
    }

    for (int i = 0; i < len; i++) {
        printf("%d ", dictionary[i]);
    }
    printf("\n");
    return 0;
}
