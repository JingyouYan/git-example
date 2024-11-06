//
// Created by 26247 on 2024/10/23.
//
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n > 10000 || n < 0) {
        return 1;
    }

    while (n--) {
        //注意定义的数组类型
        char num[15];
        //无需进行循环输入，那是对于整数数组的做法，字符串存入字符数组会自动单个字符编译成一位，同时记得不用加&
        scanf("%s", num);

        int length = 0;
        // for (int i = 0; num[i] != '\0'; i++) {
        //     length++;
        // }
        //i++无意义，改用while更合理； 但需要想到一个很妙的写法，如下：
        while (num[length] != '\0') {
            length++;
        }

        int sum = 0;
        bool ternary = true;
        //一种读取字符串典型使用的方法
        for (int j = 0; j < length; j++) {
            if (num[j] != '0' && num[j] != '1' && num[j] != 'Z') {
                //注意结果要换行输出
                printf("Radix Error\n");
                ternary = false;
                break;
            } else {
                if (isalpha(num[j])) {
                    sum -= pow(3, length - j - 1);
                } else {
                    num[j] = atoi(num[j]);
                    // sum += pow(3, length - j - 1) * num[j];还需要转换数据类型容易出错
                    sum += pow(3, length - j - 1) * (num[j] - '0');
                }
            }
        }
        if (ternary) {
            printf("%d\n", sum);
        }
    }
    return 0;
}
