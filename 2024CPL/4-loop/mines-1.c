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
            //%c是无法忽略空白符的，需要认为在前面加空格实现！！！
            scanf(" %c", &map[i][j]);
        }
    }

    //增加向量使得表意更清晰
    int vectors[8][2] = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            if (map[i][j] == 'o') {
                for (int k = 0; k < 8; k++) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    //未扩展过棋盘，转而验证新坐标边界值问题（原值后加操作的一般都需要进行验证！！
                    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && map[newI][newJ] == '*') {
                        count++;
                    }
                }
                // sprintf(map[i][j], "%d", count);
                //sprintf不能直接用于修改单个字符，改用char的“整数表示”
                char numbers = '0' + count;
                map[i][j] = numbers;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", map[i][j]);
        }
        //代码的美观需要自己努力~
        printf("\n");
    }
    return 0;
}
