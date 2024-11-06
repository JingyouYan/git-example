//
// Created by 26247 on 2024/10/30.
//
#include <stdio.h>
#define SIZE 50

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);

    int a[SIZE][SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int value[SIZE * SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            value[i * m + j] = a[i][j];
        }
    }
}
