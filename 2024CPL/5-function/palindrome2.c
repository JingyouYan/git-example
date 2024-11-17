//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>
#include <stdbool.h>
#define LEN 20

//可以写长度也可以不写，因为字符串型数组有结束符'\0'
bool IsPalindrome(const char str[], int len);

int main(void){
    char str[LEN] = {'\0'};
    scanf("%s", str);

    if (IsPalindrome(str,LEN) == true) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
}

bool IsPalindrome(const char str[], int len){
    int i = 0, j = len - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}
