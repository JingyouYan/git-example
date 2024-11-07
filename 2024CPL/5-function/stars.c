//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>
//函数的功能：1.封装：隐藏一些细节  2.实现重复的功能
//void不可以作为赋值类型，但可以作为函数的返回值：空
//interpretation：没有返回值，不代表没有输出；自身就是一个功能块
void PrintCharacter(char c, int count);
//(void):不接受任何外界参数  （）：参数类型大小不确定
void NewLine(void);

int main(void){
    int lines;
    scanf("%d", &lines);

    for (int i = 0; i < lines; i++) {
        //     for (int j = 0; j < lines - 1 - i; j++) {
        //         printf(" ");
        //     }
        PrintCharacter(' ', lines - 1 - i);

        // for (int j = 0; j < 2 * i + 1; j++) {
        //     printf("*");
        // }
        PrintCharacter('*', 2 * i + 1);

        if (i < lines - 1) {
            //这里不能在括号内加void：在main函数内调用函数，括号内默认为传参
            NewLine();
        }
    }
}

void PrintCharacter(char c, int count){
    for (int i = 0; i < count; i++) {
        printf("%c", c);
    }
    //类型为void的函数无需return，但仍可以使用return语句：用于终止函数
}

void NewLine(void){
    printf("\n");
}
