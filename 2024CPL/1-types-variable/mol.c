//
// Created by 26247 on 2024/9/27.
//
#include<stdio.h>
int main(void) {
    const double MOL = 6.02E23;
    const int GRAM_PER_MOL = 32;
    int gram = 6;

    double quantity = 1.0 * gram / GRAM_PER_MOL * MOL;
    printf("quantity = %.3e\nquantity=%.5g\n",quantity,quantity);
    return 0;
}