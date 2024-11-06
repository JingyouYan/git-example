//
// Created by 26247 on 2024/10/28.
//
#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", a & b, a | b, a ^ b, ~a, a << b, a >> b);

    //return a & 1 << b错误？
    int DigitsB = (a >> b) & 1;
    printf("%d\n", DigitsB);

    int num_of_digits = 0;
    int num = a;
    while (num > 0) {
        num /= 2;
        num_of_digits++;
    }
    int weight = 0;
    while (a) {
        weight += a & 1;
        a >>= 1;
    }
    printf("%d\n", weight);
    return 0;
    // int weight = 0;
    // for (int i = 0; i < num_of_digits; i++) {
    //     weight += a & (1 << i);
    // }
    // printf("%d", weight-1);
    // return 0;
}
