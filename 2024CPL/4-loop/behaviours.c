//
// Created by 26247 on 2024/10/29.
//
#include <stdio.h>

int main(void){
    int n;
    scanf("%d\n", &n);

    int a[18] = {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 16, 0};

    int CalculationAnd = -1;
    int CalculationOr = 0;
    int CalculationXor = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        CalculationAnd &= a[x];
        CalculationOr |= a[x];
        CalculationXor ^= a[x];
    }
    printf("%d %d %d ", CalculationAnd, CalculationOr, CalculationXor);
    return 0;
}
