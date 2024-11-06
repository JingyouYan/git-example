//
// Created by 26247 on 2024/10/31.
//
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char str[101];
    fgets(str, 101, stdin);
    //输出有效长度的strlen()
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            str[i] = (char) toupper(str[i]);
        }
        printf("%c", str[i]);
    }
    //区别于%lld
    printf("%llu", strlen(str));
    return 0;
}
