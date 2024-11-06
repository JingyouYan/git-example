// #include <stdio.h>
// #include <stdbool.h>
//
// int main(void){
//     int a = 1;
//     int judge = (a > 0);
//     printf("%d\n", judge);
// }
//
// Created by 26247 on 2024/10/30.
//
#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    char map[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    char new_map[n + 2][n + 2] = {' '};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_map[i + 1][j + 1] = map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (new_map[i][j] == 'o') {
                new_map[i][j] = (new_map[i - 1][j - 1] = '*') + (new_map[i - 1][j] = '*') + (
                                    new_map[i - 1][j + 1] = '*') +
                                (new_map[i][j - 1] = '*') + (new_map[i][j + 1] = '*') +
                                (new_map[i + 1][j - 1] = '*') + (new_map[i + 1][j] = '*') + (
                                    new_map[i + 1][j + 1] = '*');
            }
        }
    }

    char ultimate_map[n][n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ultimate_map[i][j] = new_map[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", ultimate_map[i][j]);
        }
    }
    return 0;
}
