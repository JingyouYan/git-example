//
// Created by 26247 on 2024/10/12.
//
#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a >= 1 && b >= a && c >= b && c <= 10000) {
        return 1;
    }
    if (a + b <= c) {
        printf("not triangle");
    } else if (a == b == c) {
        printf("equilateral triangle");
    } else if (a * a + b * b == c * c) {
        printf("right triangle");
    } else {
        //宝脑子不好时就先别写代码了 过段时间再看你就知道是什么蠢样了（）这里该写&&的逻辑符号写成了||debug的时候自己念一念就清楚哩
        if ((a * a + b * b < c * c) && a == b) {
            printf("obtuse isosceles triangle");
        } else if ((a * a + b * b < c * c) && a != b) {
            printf("obtuse triangle");
        } else if ((a * a + b * b > c * c) && (a == b || b == c)) {
            printf("acute isosceles triangle");
        } else {
            printf("acute triangle");
        }
    }
    return 0;
}


//还可以考虑直接单个条件语句判断，不使用嵌套，对功能模块区分更清晰，看着更清楚，不易出错；此外，输入一般来说是不用你去控制的，主要作为一个前置背景
// if (a == b && b == c) {
//     printf("equilateral triangle");
//     return 0;
// }
//
// if (a * a + b * b == c * c) {
//     printf("right triangle");
//     return 0;
// }
//
// if (a * a + b * b > c * c) {
//     printf("acute ");  在acute后部加上空格，使得输出格式符合，不然默认全部连在一起
// } else {
//     printf("obtuse ");
// }
//
// if (a == b || b == c || a == c) {
//     printf("isosceles ");
// }
//
// printf("triangle");
//
// return 0;
// }
