//
// Created by 26247 on 2024/11/20.
//
#include <stdio.h>
#include <stdlib.h>

// void selectionSort(int *arr, int len);
//
// int getMinIndex(const int *arr, int begin, int end);

void swapVal(int *leftVal, int *rightVal);

int main(void){
    int n, l;
    scanf("%d%d", &n, &l);

    int *values = malloc(sizeof(*values) * n);
    int *maximum = malloc(sizeof(*maximum) * n);

    if (values == NULL || maximum == NULL) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &maximum[i]);
    }

    for (int i = 0; i < n; i++) {
        int max = values[i];
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (values[j] > max) {
                max = values[j];
                max_index = j;
            }
        }
        swapVal(&values[max_index], &values[i]);
        swapVal(&maximum[i], &maximum[max_index]);
    }

    int volume = 0;
    int price = 0;
    int i = 0;
    while (volume < l && i < n) {
        if (maximum[i] > 0) {
            maximum[i]--;
            volume++;
            price += values[i];
        } else {
            i++;
        }
    }

    printf("%d\n", price);

    free(values);
    free(maximum);

    return 0;
}

void swapVal(int *leftVal, int *rightVal){
    int temp = *leftVal;
    *leftVal = *rightVal;
    *rightVal = temp;
}
