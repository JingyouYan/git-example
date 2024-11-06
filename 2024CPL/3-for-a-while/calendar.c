//
// Created by 26247 on 2024/10/20.
//
#include <stdio.h>

int main(void){
    int m, n;
    scanf("%d%d", &m, &n);

    //注意日期和行列的关系； 特别小心输出空格的数量
    for (int i = 1; i < (n + 5) % 7; i++) {
        printf("    ");
    }
    //找到特殊的2（周一）
    if (n != 2){
        printf("   ");
    }


    for (int i = 1; i <= m; i++) {
        //对日历表上的日期进行分类讨论
        if ((i + n - 2) % 7 == 1) {
            printf("%2d ", i);
        } else if((i + n - 2) % 7 == 0){
            printf(" %2d",i);
        }else {
            printf(" %2d ", i);
        }

        if ((i % 7 + n - 2) % 7 == 0) {
            //小心斜杠方向，避免无效输出
            printf("\n");
        }
    }
    return 0;
}
