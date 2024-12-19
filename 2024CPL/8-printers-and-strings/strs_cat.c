//
// Created by 26247 on 2024/12/4.
//
#include <stdio.h>

char *strcat(char *dest, const char *src){
    char *original_dest = dest; // 保存目标字符串的原始地址

    // 先找到目标字符串的末尾，即'\0'所在位置
    while (*dest != '\0') {
        dest++;
    }
    //strlen函数返回的长度不包含'\0',可以用strlen替代；但原写法灵活性更高

    // 将源字符串的字符逐个复制到目标字符串末尾
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0'; // 在连接后的字符串末尾添加结束符'\0'

    return original_dest; // 返回目标字符串的原始地址
}

int main(){
    char dest[20] = "Hello";
    char src[] = " World";
    char *result = strcat(dest, src);
    printf("%s\n", result);
    return 0;
}
