//
// Created by 26247 on 2024/12/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StrCpy0(char *dest, const char *src);

void StrCpy1(char *dest, const char *src);

void StrCpy2(char *dest, const char *src);

char *StrCpyStd(char *src1, const char *src2);

//避免空间大小不足的情况
char *StrNCpyStd(char *src1, const char *src2);

void PrintStr(const char *src);

int main(void){
    // char src[] = "Hello World";
    // char dest[100];
    // StrCpy1(dest, src);
    // PrintStr(dest);
    const char *src = "Hello World";
    char *dest = malloc(strlen(src) + 1);
    strlen(StrCpyStd(dest, src));
    //可以融合为一行代码，相对更流程
    // PrintStr(dest);
    StrCpy0(dest, src);
    StrCpy1(dest, src);
    //打印结果若为“dest = %s”，则说明在text区域中,src后面的那块区域就是这一串代码段
    printf("dest = %s\n", dest);
    free(dest);
}

void StrCpy0(char *dest, const char *src){
    while ((*dest = *src) != '\0') {
        src++;
        dest++;
    }
    //该函数结束时指向'\0'，验证
    printf("%s\n", dest);
}

void StrCpy1(char *dest, const char *src){
    //C中赋值表达式是从右到左进行的，b=c,a=b
    while ((*dest++ = *src++) != '\0');
    //*dest = *src
    //*dest !='\0'
    //src++
    //dest++
    //该函数结束时指向'\0'后面的一个字符（垃圾值），与这里的运算顺序有关
    printf("%s\n", dest);
}

//这里指针的值是被拷贝到函数内层中的，内部的++不会影响外部dest指针和src指针的指向
void StrCpy2(char *dest, const char *src){
    //由于'\0'字符对应的ASCII码值为0，在C语言中会被判断为假；
    //有适用语言，在Java中成立，Python中不成立
    while ((*dest++ = *src++));
}

//返回字符串的指针：设计上的巧思
//为了实现写法上的流畅
char *StrCpyStd(char *src1, const char *src2){
    for (char *p = src1; (*p++ = *src2++) != '\0';);
    return src1;
}


char *StrNCpyStd(char *src1, const char *src2){
    int i = 0;
    for (char *p = src1; (*p++ = *src2++) != '\0' && i < strlen(src1); i++);
    return src1;
}

void PrintStr(const char *src){
    printf("%s\n", src);
}
