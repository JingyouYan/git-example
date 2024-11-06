//
// Created by 26247 on 2024/10/20.
//
#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (!(n >= 1 && n <= 2000)) {
        return 1;
    }

    int array[2000] = {0};
    for (int i = 1; i <= n; i++) {
        int j = i;
        for (; j <= n; j++) {
            if (j % i == 0) {
                //可简化为array[i]^=1
                if (array[j] == 0) {
                    array[j] = 1;
                } else {
                    array[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (array[i] == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}
