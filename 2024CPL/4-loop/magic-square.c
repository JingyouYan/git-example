//
// Created by 26247 on 2024/10/30.
//
#include <stdio.h>
#define SIZE 999
//999是CLion不能承受的生命之重

int main(void){
    int n;
    scanf("%d", &n);

    int square[SIZE][SIZE] = {0};


    int row = 0, col = n / 2;
    for (int num = 1; num <= n * n; num++) {
        square[row][col] = num;

        int new_row = row - 1;
        int new_col = col + 1;

        if (new_row < 0) {
            new_row = n - 1;
        }
        if (new_col >= n) {
            new_col = 0;
        }

        if (square[new_row][new_col]) {
            new_row = row + 1;
            new_col = col;
            if (new_row >= n) {
                new_row = 0;
            }
        }
        row = new_row;
        col = new_col;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
    return 0;
}
