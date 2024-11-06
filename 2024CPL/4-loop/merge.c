#include <stdio.h>
#define LEN_L 5
#define LEN_R 6

int main(void){
    int L[LEN_L] = {1, 3, 5, 7, 9};
    int R[LEN_R] = {0, 2, 4, 6, 8, 10};

    int l = 0;
    int r = 0;

    //while循环不要忘记更新值
    while (l < LEN_L && r < LEN_R) {
        if (L[l] < R[r]) {
            printf("%d ", L[l]);
            l++;
        } else {
            printf("%d ", R[r]);
            r++;
        }
    }

    //由逻辑修剪程序
    while (l < LEN_L) {
        printf("%d ", L[l]);
        l++;
    }

    while (r < LEN_R) {
        printf("%d ", R[r]);
        r++;
    }

    return 0;
}
