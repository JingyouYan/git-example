#include <stdio.h>

int main(void){
    // int i = -1;
    // int *ptr_1_int = &i;
    // unsigned int *ptr_1_uint = &i;
    //
    // printf("%d\n%d\n", *ptr_1_int, *ptr_1_uint);

    int hex = 0x61626364;
    //char *指向一个字节大小，这里指的就是‘64’这个字节的地址
    char *ptr_hex = &hex;
    printf("%d\n", *(ptr_hex + 1));
}
//
// Created by 26247 on 2024/11/20.
//
