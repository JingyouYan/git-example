//
// Created by 26247 on 2024/10/13.
//
#include <stdio.h>
#include <stdbool.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (!(n >= 1 && n <= 100000)) {
        return 1;
    }

    //定义一个整数数组，再在循环内定义一个变量num，作为数组记录的各个频率的索引，提高了运作效率
    int a[105] = {0};
    for (int i = 0; i < n * 2 - 1; i++) {
        int num;
        scanf("%d", &num);
        a[num]++; //操作数的值+1
    }

    for (int i = 0; i < 105; i++) {
        if (a[i] == 1) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
// #include <stdio.h>
//
// int main(void){
//     int n;
//     scanf("%d\n", &n);
//     if (!(n >= 1 && n <= 100000)) {
//         return 1;
//     }
//
//     int result = 0;
//     for (int i = 0; i < n * 2 - 1; i++) {
//         int num;
//         scanf("%d", &num);
//         result ^= num; // 对每一个读入的数字执行异或操作
//     }
//
//     printf("%d", result); // 最终的result就是唯一出现一次的数字
//     return 0;
// }
