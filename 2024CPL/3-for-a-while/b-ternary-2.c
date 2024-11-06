#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
//注意每次数组大小都应该多开点
#define SIZE 25

int main(void){
    int n;
    scanf("%d", &n);

    while (n--) {
        //读入输入
        char array[SIZE] = "\0";
        scanf("%s", array);

        int l = 0;
        bool legal = true;
        while (array[l] != '\0') {
            if (!(isdigit(array[l])) && array[0] != '-') {
                printf("Radix Error");
                legal = false;
                break;
            }
            l++;
        }

        //这一步很重要！！直接结束这一轮次的while循环，提高程序运行效率
        if (!legal) {
            continue;
        }

        int decimal = atoi(array);
        bool flag = false;
        if (decimal < 0) {
            flag = true;
            //可以直接判断的情况下就没必要用函数增加复杂度
            decimal = -decimal;
        }

        int temp = decimal;
        //取前三个字母效果更好捏~
        int ternary[SIZE];
        for (int i = 0; i < SIZE; i++) {
            ternary[i] = -1;
        }

        while (temp > 0) {
            ternary[l] = temp % 3;
            temp /= 3;
        }

        char ter[SIZE] = {'\0'};

        for (int i = 0; i < SIZE; i++) {
            switch (ternary[i]) {
                case 0: ter[i] = '0';
                    break;
                case 1: ter[i] = '1';
                    break;
                case 2: ter[i] = 'Z';
                    ternary[i + 1]++;
                    break;
                case 3: ter[i] = '0';
                    ternary[i + 1]++;
                    break;
                default: break;
            }
        }

        int i = 0;
        if (flag) {
            while (ter[i] != '\0') {
                if (ter[i] == '1') {
                    ter[i] = 'Z';
                }
                if (ter[i] == 'Z') {
                    ter[i] = '1';
                }
                printf("%c", ter[i]);
                i++;
            }
        } else {
            for (int j = 0; j < SIZE; j++) {
                printf("%c", ter[j]);
            }
        }


        printf("\n");
    }
    return 0;
}
