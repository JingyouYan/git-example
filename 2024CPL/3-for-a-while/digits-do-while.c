//
// Created by 26247 on 2024/10/13.
//
//
// Created by 26247 on 2024/10/13.
//
#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);

    int num_of_digits = 0;

    //不要复制黏贴代码，会带来很糟糕的事情！！！
    //注意在for循环括号内定义并初始化的变量离开循环无法输出结果哦
    do {
        num /= 10;
        num_of_digits++;
    } while (num > 0);

    printf("%d\n", num_of_digits);
    return 0;
}
