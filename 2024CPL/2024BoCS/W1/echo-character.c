//
// Created by 26247 on 2024/10/31.
//
#include <stdio.h>

int main(void){
    char str[101];
    //可不读入换行符，实现只读入一行数据
    scanf("%[^\n]", str);

    for (int i = 0; str[i] != '\0'; i++) {
        //tab即为制表符
        if (!(str[i] == ' ')) {
            //输出不用对%c进行特殊处理，历次输出即可
            printf("%c", str[i]);
        }
    }

    return 0;
}
