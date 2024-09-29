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
    //if((year % 4 = 0 && year % 100 != 0)||year % 400 == 0){
    //leap=1;}
    printf("%d", leap);
    return 0;
}
