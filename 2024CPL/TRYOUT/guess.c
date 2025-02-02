//
// Created by 26247 on 2024/12/20.
//
#include <stdio.h>
#define LEN 11
#define SIZE 10001

int main(void){
    int p1, p2;
    scanf("%d%d", &p1, &p2);

    char name[LEN];
    scanf("%s", name);

    int factor1[SIZE], factor2[SIZE];
    for (int i = 0; i < p1 + 1; i++) {
        scanf("%d", &factor1[i]);
    }
    for (int i = 0; i < p2 + 1; i++) {
        scanf("%d", &factor2[i]);
    }

    //实现P1*P2
    int count = p1 + p2 + 1;
    int factor[count];
    for (int i = 0; i < count; i++) {
        int factorSum = 0;
        for (int j = 0; j <= i; j++) {
            if (j <= p1 && i - j <= p2) {
                factorSum += factor1[j] * factor2[i - j];
            }
        }
        factor[i] = factorSum;
    }

    for (int i = count - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d\n", factor[i]);
            break;
        }

        if (factor[i] == 1) {
            if (i == 1) {
                printf("%d%s", factor[i], name);
            } else {
                printf("%s^%d", name, i);
            }
        } else if (factor[i] == -1) {
            if (i == 1) {
                printf("%d%s", factor[i], name);
            } else {
                printf("-%s^%d", name, i);
            }
        } else if (factor[i] > 1 && i != count) {
            if (i == 1) {
                printf("%d%s", factor[i], name);
            } else {
                printf("+%d%s^%d", factor[i], name, i);
            }
        } else if (factor[i] < -1) {
            if (i == 1) {
                printf("%d%s", factor[i], name);
            } else {
                printf("%d%s^%d", factor[i], name, i);
            }
        }
    }
}
