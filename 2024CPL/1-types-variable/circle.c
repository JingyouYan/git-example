//
// Created by 26247 on 2024/9/27.
//
#include <stdio.h>
int main(void) {
    int radius = 10;
    //&radius:address-of
    //double:实数，双精度浮点数
    double circumference = 2 * 3.14159 * radius;
    double area = 3.14159 * radius * radius;
    //identifiers:do not start with numbers,_,which are reserved by C;meaningful,in form
    //.2f%:转换符，控制浮点数小数点后2位
    printf("circumference = %.2f\narea=%.2f\n",circumference,area);
    return 0;

}