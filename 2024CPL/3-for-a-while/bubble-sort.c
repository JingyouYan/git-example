//
// Created by 26247 on 2024/10/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    int t;
    scanf("%d", &t);
    if (t < 1 || t > 100000) {
        return 1;
    }

    //实现分行读取，每个循环读两行，这是IDE中本身的设定，要好好利用；而每次循环由int n可知n和a[i]的值都会被更新，实现读入多个数组的目的
    int sum = 0;
    while (t--) {
        int n;
        scanf("%d", &n);
        sum += n;

        int a[50000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (abs(a[i]) > 1000000000) {
                return 1;
            }
        }


        //两段代码关键只有数组最后一位数的值和前面所有数的关系区别，无需全部运算
        //也不用找最小了，到这个精度没有意义；一个个比一轮反而是最快的
        bool ascending = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[n - 1] < a[i]) {
                ascending = false;
                break;
            }
        }
        if (ascending) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    if (sum > 1000000) {
        return 1;
    } else {
        return 0;
    }
}
