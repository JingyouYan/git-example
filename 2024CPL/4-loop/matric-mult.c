//
// Created by 26247 on 2024/10/29.
//
#include <stdio.h>

int main(void){
    //样例已经控制，不用二次限制输入范围
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);

    int a[100][100];
    int b[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        // printf("\n");这完全是多余的呀 这里的读入可以想象为由不同空白符隔开的一维数组
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &b[i][j]);
        }
        // printf("\n");这样的操作只会导致多空了两个矩阵的行数捏，读入下一行是自动的呀
    }

    //养成数组初始化的好习惯
    int c[100][100] = {0};

    //特别注意这里用字母量定义边界不要混淆了
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
