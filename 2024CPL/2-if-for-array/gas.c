//
// Created by 26247 on 2024/10/7.
//
#include <stdio.h>
#include <math.h>

int main(void){
    const double R = 8.314;
    double pressure, length, temp, n;

    scanf("%lf%lf%lf", &pressure, &length, &temp);

    n = pressure * pow(length, 3) / (R * temp);
    //.4e才能做到保留五位有效数字，因为e代表使用科学计数法表示，则小数点前必只有一位，则相当于保留小数点后四位即可
    printf("%.5e\n", n);
    return 0;
}
