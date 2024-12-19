//
// Created by 26247 on 2024/11/22.
//
#include <stdio.h>
#include <stdbool.h>
#define SIZE 105

int main(void){
    int r, c;
    scanf("%d%d", &r, &c);

    char grid[SIZE][SIZE] = {'\0'};
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
    }

    int sum = 0;
    // int dot[SIZE][SIZE] = {0};
    //TODO:how to judge a square
    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            //找到左顶角，再分别固定四个中心对称的方块跑循环
            if (grid[i][j] == '/' && grid[i + 1][j] == '\\') {
                //特别小心这里的临界条件判断：不重不漏 （条件式的书写还要结合前面写循环的思路
                for (int k = 1; i + k < r && i - k + 1 >= 0 && j + 2 * k - 1 < c; k++) {
                    bool is_square = true;
                    //取一的话避免了左顶点的重复检验但是还有其他三个顶点呀
                    for (int l = 0; l < k; l++) {
                        if (grid[i - l][j + l] != '/' || grid[i + 1 + l][j + 2 * k - 1 - l] != '/'
                            || grid[i + k - l][j + k - 1 - l] != '\\' || grid[i - k + 1 + l][j + k + l] != '\\') {
                            is_square = false;
                            break;
                        }
                    }
                    if (is_square) {
                        sum++;
                    }
                }
            }
        }
    }
    printf("%d\n", sum);
}
