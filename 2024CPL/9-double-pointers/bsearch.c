//
// Created by 26247 on 2024/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000005

int compare(const void *a, const void *b);

// void *bsearch(const void *key, const void *base, size_t num, size_t size);

int main(void){
    int n, q;
    scanf("%d%d", &n, &q);
    //malloc返回的是通用的无符号指针，而我们需要指向int类型的指针
    int *arr = (int *) malloc(sizeof(*arr) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    while (q--) {
        int element;
        scanf("%d", &element);

        int *result = bsearch(&element, arr, n, sizeof(*arr), compare);
        if (result == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", (int) (result - arr));
        }
    }
    free(arr);
    return 0;
}

int compare(const void *a, const void *b){
    return *(int *) a - *(int *) b;
}
