//
// Created by 26247 on 2024/10/20.
//
#include <stdio.h>

int main(void){
    int length;
    char s[2001];
    //这里读取字符串数组s时不需要加&和[]
    //%2000s指定了输出字符串的最小宽度
    scanf("%d%2000s", &length, s);

    for (int i = 0; i < length; i++) {
        if (s[i] == '?') {
            s[i] = s[length - 1 - i];
        }
    }
    printf("%s\n", s);
    return 0;
}
// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
//
// int main(void){
//     char str[100] = "";
//     scanf("%s", str);
//
//     int len = strlen(str);
//     // int len = 0;
//     // while(str[len] != '\0') {
//     //     len++;
//     // }
//
//     bool is_palindrome = true;
//     //for循环相对于while循环缩小了变量i和j的作用范围
//     //括号内是可以进行多个赋值的，用逗号隔开即可
//     for (int i = 0, j = len - 1; i < len; i++, j--) {
//         if (str[i] != str[j]) {
//             is_palindrome = false;
//             break;
//         }
//     }
//     if (is_palindrome) {
//         printf("Palindrome\n");
//     } else {
//         printf("Not a palindrome\n");
//     }
//     return 0;
// }
