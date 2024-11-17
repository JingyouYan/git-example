//
// Created by 26247 on 2024/11/9.
//
#include <stdio.h>
#define SIZE 1000000

int main(void){
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);

    int a[SIZE] = {0};
    int b[SIZE] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < m; i++) {
        int min = b[i];
        int min_index = i;
        for (int j = i + 1; j < m; j++) {
            if (min > b[j]) {
                min = b[j];
                min_index = j;
            }
        }

        int temp = b[min_index];
        b[min_index] = b[i];
        b[i] = temp;
    }

    if (t < a[0] + b[0]) {
        printf("-1");
        return 0;
    }

    //通过二分法减少查找时间
    int min_gap = t - a[0] - b[0];
    for (int i = 0; i < n; i++) {
        int low = 0;
        int high = m - 1;

        if (a[i] + b[0] > t) {
            break;
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = a[i] + b[mid];
            int gap = t - sum;
            if (gap >= 0) {
                if (gap < min_gap) {
                    min_gap = gap;
                }
                if (gap == 0) {
                    break;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (min_gap == 0) {
            break;
        }
    }

    printf("%d\n", min_gap);
    return 0;
}
