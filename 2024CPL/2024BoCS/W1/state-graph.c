//
// Created by 26247 on 2024/11/9.
//
#include <stdio.h>

int main(void){
    int s, i, n, t, o;
    scanf("%d%d%d%d%d", &s, &i, &n, &t, &o);

    switch (s) {
        case 0: if (o == i) {
                printf("1");
            } else {
                printf("0");
            }
            break;
        case 1: if (o == i) {
                printf("1");
            } else if (o == n) {
                printf("2");
            } else {
                printf("0");
            }
            break;
        case 2: if (o == i) {
                printf("1");
            } else if (o == t) {
                printf("3");
            } else {
                printf("0");
            }
            break;
        case 3: if (o == i) {
                printf("1");
            } else {
                printf("0");
            }
            break;
        default: break;
    }

    return 0;
}
