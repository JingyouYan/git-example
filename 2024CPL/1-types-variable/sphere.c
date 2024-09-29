//
// Created by 26247 on 2024/9/27.
//
#include<stdio.h>
#include <math.h>

int main(void) {
    const double PI = 3.14159;
    int radius = 100;
    //surfaceArea
    //add 4.0使范围在实数内
    //magic number
    double surfaceArea = 4 * PI * pow(radius,2);
    double volume = 4.0 / 3 * PI * pow(radius,3);

    //15:width
    //.4:precision
    //_:flag
    printf("%-15.4f:surfaceArea\n%-15.4f:volume\n",surfaceArea,volume);
    return 0;
}
