//
// Created by 26247 on 2024/9/29.
//
#include<stdio.h>

int main(void) {
    int leap = 0;
    int year;
    scanf("%d", &year);

    //if(year%4==0&&year%4!=0||year%400==0)
    //&&:and
    //||:or
    //!:not
    //short-circuit 第二个条件被短路
    if (year % 4 != 0) {
        leap = 0;
    } else if (year % 100 != 0) {
        leap = 1;
    } else if (year % 400 != 0) {
        leap = 0;
    } else {
        leap = 1;
    }
    /*
     *充要条件避免了重复分支体的情形，条件除了给定顺序外尽量由宽泛到具体
     * if (year % 4 = 0 && year % 100 != 0) || (year % 400 = 0){
     * leap = 1;
     * }else{
     * leap = 0;
     * }
     */
    //不要依赖于运算符的优先级，老老实实用括号分隔开
    //not>and>or ! && ||
    //逻辑运算按短路求值：将便于计算的前置，以加快运算效率
    //else语句可省：原语句leap=0，else不做处理本身=0，去除冗余
    //可使leap=逻辑表达式，结果自然只有0和1
    if (leap) {
        //identical to leap!=0 true
        printf("it is a leap year");
    } else {
        printf("it is not a leap year");
    }
    printf("%d", leap);
    return 0;
}
