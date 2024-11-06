//
// Created by 26247 on 2024/10/31.
//
#include <stdio.h>

int main(void){
    int decimal;
    scanf("%d", &decimal);

    //除了%.32d使得int至少输出32位，不足补0；这里通过初始化实现
    //区别于%32d左端添加空格补足
    int binary[32] = {0};
    //注意结束的判断条件临界值
    for (int i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    for (int i = 31; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    return 0;
}
