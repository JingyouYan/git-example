//
// Created by 26247 on 2024/11/2.
//
#include <stdio.h>

int main(void){
    int n, k, b, l;
    scanf("%d%d%d%d", &n, &k, &b, &l);

    int arr[1500];
    for (int i = 0; i < n; i++) {
        arr[i] = l;
    }

    int death = 0;
    int volume = b;
    int step = 0;
    int i = 0;
    while (death < n - 1) {
        if (arr[i]) {
            step++;
            if (step == k) {
                if (volume > 0) {
                    volume--;
                    arr[i]--;
                    if (arr[i] == 0) {
                        death++;
                    }
                } else {
                    volume = b;
                }
                //不要忘记重置step，再从头读一遍代码，看看逻辑错误
                step = 0;
            }
        }
        i = (i + 1) % n;
    }

    for (int j = 0; j < n; j++) {
        if (arr[j]) {
            printf("%d\n", j + 1);
        }
    }

    return 0;
}
