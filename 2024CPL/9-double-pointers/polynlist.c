//
// Created by 26247 on 2024/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 11
#define SIZE 10001

void PrintPoly(const char *name, const int *factor, int count);

int main(void){
    int p1, p2;
    scanf("%d%d", &p1, &p2);
    // while ((getchar()) != '\n');

    char name[LEN];
    scanf("%s", name);
    // while ((getchar()) != '\n');

    int factor1[SIZE] = {0}, factor2[SIZE] = {0};
    for (int i = 0; i < p1 + 1; i++) {
        scanf("%d", &factor1[p1 - i]);
    }
    for (int i = 0; i < p2 + 1; i++) {
        scanf("%d", &factor2[p2 - i]);
    }
    // while ((getchar()) != '\n');

    int num = p1 > p2 ? (p1 + 1) : (p2 + 1);
    int common = p1 < p2 ? (p1 + 1) : (p2 + 1);
    //实现P1+P2
    int *plusFactor = (int *) malloc(sizeof(*plusFactor) * num);
    for (int i = 0; i < common; i++) {
        plusFactor[i] = factor2[i] + factor1[i];
    }
    memcpy(plusFactor + common, p1 > p2 ? factor1 + common : factor2 + common, sizeof(*plusFactor) * (num - common));
    PrintPoly(name, plusFactor, num);
    // printf("\n");

    //实现P1-P2
    int *minusFactor = (int *) malloc(sizeof(*minusFactor) * num);
    for (int i = 0; i < common; i++) {
        minusFactor[i] = factor1[i] - factor2[i];
    }
    if (p1 > p2) {
        memcpy(minusFactor + common, factor1 + common, sizeof(*minusFactor) * (num - common));
    } else if (p2 > p1) {
        for (int i = common; i < num; i++) {
            minusFactor[i] = -factor2[i];
        }
    }
    PrintPoly(name, minusFactor, num);

    //实现P1*P2
    int count = p1 + p2 + 1;
    // int factor[count];
    int *factor = (int *) malloc(sizeof(*factor) * count);
    for (int i = 0; i < count; i++) {
        int factorSum = 0;
        for (int j = 0; j <= i; j++) {
            if (j <= p1 && i - j <= p2) {
                factorSum += factor1[j] * factor2[i - j];
            }
        }
        factor[i] = factorSum;
    }
    PrintPoly(name, factor, count);

    free(plusFactor);
    free(minusFactor);
    free(factor);
}

void PrintPoly(const char *name, const int *factor, int count){
    for (int i = count - 1; i >= 0; i--) {
        if (i == 0) {
            if (factor[i] > 0) {
                printf("+");
            }
            if (factor[i] != 0) {
                printf("%d", factor[0]);
            }
            break;
        }
        if (i == 1) {
            if (factor[i] > 0) {
                printf("+");
            }
            if (factor[i] == 1) {
                printf("%s", name);
            } else if (factor[i] == -1) {
                printf("-%s", name);
            } else {
                printf("%d%s", factor[i], name);
            }
            continue;
        }
        if (factor[i] == 1) {
            printf("%s^%d", name, i);
        } else if (factor[i] == -1) {
            printf("-%s^%d", name, i);
        } else if (factor[i] > 1) {
            if (i != count - 1) {
                printf("+");
            }
            printf("%d%s^%d", factor[i], name, i);
        } else if (factor[i] < -1) {
            printf("%d%s^%d", factor[i], name, i);
        }
    }
    printf("\n");
}
