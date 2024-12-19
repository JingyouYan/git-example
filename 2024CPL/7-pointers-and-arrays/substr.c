//
// Created by 26247 on 2024/12/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100000

int main(void){
    char *str1 = malloc(sizeof(char) * SIZE);
    char *str2 = malloc(sizeof(char) * SIZE);
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            printf("%d ", i);
        }
    }

    free(str1);
    free(str2);
    return 0;
}
