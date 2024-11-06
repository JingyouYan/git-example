//
// Created by 26247 on 2024/10/21.
//
#include <stdio.h>

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    if (!(n >= 1 && n <= 500 && k >= 1 && k <= 500)) {
        return 1;
    }

    int a[500];
    //非零值需要循环历遍赋值
    for (int i = 0; i < n; i++) {
        a[i] = 1;
    }
    int count = 0;
    int step = 0;
    int i = 0;
    while (count < n - 1) {
        //i不能设置在内部，不然每次循环原有i值都会被清空
        if (a[i] == 1) {
            step++;
            if (step == k) {
                a[i] = 0;
                count++;
                step = 0;
            }
        }
        i = (i + 1) % n;
    }
    for (int j = 0; j < n; j++) {
        if (a[j] == 1) {
            printf("%d", j + 1);
            break;
        }
    }
    return 0;
}
