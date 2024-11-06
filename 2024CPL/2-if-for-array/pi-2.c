//
// Created by 26247 on 2024/10/7.
//
#include <stdio.h>
#include <math.h>

int main(void){
    double result1 = log(pow(5280, 3) * pow((236674 + 30303 * sqrt(61)), 3) + 744) / sqrt(427);
    double result2 = 4 * (6 * atan(1.0 / 8) + 2 * atan(1.0 / 57) + atan(1.0 / 239));

    printf("%.15lf\n%.15lf\n", result1, result2);
    return 0;
}
