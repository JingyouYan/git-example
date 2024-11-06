//
// Created by 26247 on 2024/10/7.
//
#include <stdio.h>
#include <math.h>

int main(void){
    int p, q;
    scanf("%d%d", &p, &q);
    double derta = pow(q / 2.0, 2) + pow(p / 3.0, 3);
    if (derta >= 0) {
        //cbrt函数相对于pow函数允许底数为负数，指数位为小数的输入；底数为0，指数为负数同样会出现问题
        double answer = cbrt(-q / 2.0 + sqrt(derta)) + cbrt(-q / 2.0 - sqrt(derta));
        printf("%.3lf\n", answer);
        return 0;
    } else {
        return 1;
        // double r = sqrt(-pow(p / 3.0, 3));
        // double angle = acos(-q / (2 * r)) / 3;
        // double answer = -2 * pow(r, 1.0 / 3) * cos(angle);
        // printf("%.3lf\n", answer);
        // return 0;
    }
}
