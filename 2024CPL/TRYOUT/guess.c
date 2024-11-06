#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "Hello, World!";
    unsigned long long int len = strlen(str);
    printf("字符串长度为: %llu\n", len);
    return 0;
}
