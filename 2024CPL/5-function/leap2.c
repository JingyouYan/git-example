//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>
#include <stdbool.h>
//main函数内不能定义函数
//First,affirm the type of return.
//function declaration函数的声明
//()：参数列表 ；括号内内容：类型重要，命名只是一个形参————function prototype scope函数原型作用域
bool IsLeapYear(int year);

int main(void){
    //一对花括号就是一个block————block scope块作用域
    int year;
    scanf("%d", &year);

    //():function call operator
    //function call expression
    //year here is an actual argument.实参再将值传递给形参
    //call:formal parameter = actual argument.在数组中尤为重要！！！传递只是黏贴
    bool leap = IsLeapYear(year);
    if (leap) {
        printf("This is a Leap Year");
    } else {
        printf("This is not a Leap Year");
    }
    return 0;
}

//function definition函数的实现
bool IsLeapYear(int year){
    //block scope(包括括号内的形参）
    bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // {int year;}这样子就变成合法的了

    //注意输出结果（return值）和函数名前规定的返回类型一致
    return leap;
}
