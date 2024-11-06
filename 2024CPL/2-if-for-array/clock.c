//
// Created by 26247 on 2024/10/11.
//
#include <stdio.h>

int main(void){
    int hour, minute;
    scanf("%d:%d", &hour, &minute);
    if (hour >= 0 && hour <= 11 && minute >= 0 && minute <= 59) {
        printf("%.2d:%.2d a.m.", hour, minute);
        return 0;
    } else if (hour >= 13 && hour <= 23 && minute >= 0 && minute <= 59) {
        hour -= 12;
        printf("%.2d:%.2d p.m.", hour, minute);
        return 0;
        //特别小心这里判断hour等于12需要写作==
    } else if (hour == 12 && minute >= 0 && minute <= 59) {
        printf("%.2d:%.2d p.m.", hour, minute);
        return 0;
    } else {
        return 1;
    }
}
