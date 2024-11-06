//
// Created by 26247 on 2024/10/7.
//
#include <stdio.h>


int main(void){
    //,隔开表示命名同类型的不同变量
    int year,month,day;

    scanf("%d%d%d", &year, &month, &day);

    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    //不同功能的代码分块写
    int dayMonth;
    if (month == 2) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            dayMonth = 29;
        } else {
            dayMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        dayMonth = 30;
    } else {
        dayMonth = 31;
    }

    //条件语句用括号表示运算顺序，是不可以随便加的
    if (dayMonth >= day && year >= 1900 && year <= 2599 && month >= 1 && month <= 12) {
        printf("%d\n", jdn);
        return 0;
    } else {
        return 1;
    }
}
