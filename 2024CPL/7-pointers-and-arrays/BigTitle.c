//
// Created by 26247 on 2024/12/1.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 4096

int main(void){
    char *str = malloc(SIZE * sizeof(*str));
    for (int i = 0; i < SIZE; i++) {
        *(str + i) = '\0';
    }
    fgets(str, SIZE, stdin);

    bool begin = true;
    for (int i = 0; *(str + i) != '\0'; i++) {
        if (begin && isalpha(*(str + i))) {
            printf("%c", toupper(*(str + i)));
            begin = false;
        } else if (isspace(*(str + i))) {
            printf(" ");
            begin = true;
        } else if (!begin && isalpha(*(str + i))) {
            printf("%c", tolower(*(str + i)));
        }
    }
    free(str);
    return 0;
}
