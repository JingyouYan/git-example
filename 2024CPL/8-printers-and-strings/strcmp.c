//
// Created by 26247 on 2024/12/18.
//
#include <stdio.h>

int Strcmp(const char *s1, const char *s2);

int StrcmpStd(const char *s1, const char *s2);

int StrNCmp(const char *s1, const char *s2, int n);

int main(void){
    char s1[] = "Hello world";
    char s2[] = "Hello worle";
    printf("%d\n", Strcmp(s1, s2));
}

int Strcmp(const char *s1, const char *s2){
    //没有处理两个字符串相等的情况,实际上包含了8种情况,但讨论后容易发现不需要再写
    while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0')) {
        s1++;
        s2++;
        //不可合并，会导致比较位置不对
        //无论比较结果如何，在整个表达式计算完成后，s1和s2的值会分别加 1
    }
    return *(const unsigned char *) s1 - *(const unsigned char *) s2;
}

int StrcmpStd(const char *s1, const char *s2){
    for (; *s1 == *s2; s1++, s2++) {
        if (*s1 == '\0') {
            return 0;
        }
    }

    return *(const unsigned char *) s1 - *(const unsigned char *) s2;
}

int StrNCmp(const char *s1, const char *s2, int n){
    for (; 0 < n; s1++, s2++, n--) {
        if (*s1 != *s2) {
            return (*(unsigned char *) s1 < *(unsigned char *) s2) ? -1 : 1;
        } else if (*s1 == '\0') {
            return 0;
        }
    }
}
