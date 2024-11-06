//
// Created by 26247 on 2024/10/7.
//
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void){
    char name[21];
    int pre;
    double frac;
    double factor;
    char unit;
    scanf("%s%d%lf%lf %c", &name, &pre, &frac, &factor, &unit);
    if (pre >= 0 && pre <= (pow(2, 31) - 1) && 'a' <= unit && unit <= 'z') {
        double sciEexp = 1.0 * pre + frac;
        double conv = (pre + frac) * factor;
        //仔细观察输出要求的格式，严格遵守；觉得正常的要命就检查一下符号或者代码输入的时候有没有不小心调成了中文
        printf("%.2s: %d (%.5lf) | %.5E %.5lf %c\n", name, pre, frac, sciEexp, conv, toupper(unit));
        return 0;
    } else {
        return 1;
    }
}
