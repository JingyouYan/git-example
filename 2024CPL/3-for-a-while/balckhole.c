//
// Created by 26247 on 2024/10/17.
//
#include <stdio.h>
//#include <stdlib.h>用于标注abs绝对值函数，可加在&整体外，保证输入为正

int main(void){
    int num;
    scanf("%d", &num);

    int sum = 0;
    int num0 = 0;

    while (num0 != 495) {
        //注意：digit的值需要根据循环后的新num更新，应该在循环内定义；
        //最后应该注意，特别是while循环，不要忘记每个循环结束后的操作，不然无法跳出：num= num0
        int digit1 = num / 100;
        int digit2 = num % 100 / 10;
        int digit3 = num % 10;

        if (!((digit1 != digit2 && digit1 != digit3) && (num >= 100 && num <= 999))) {
            return 1;
        }

        int max_num, middle_num, min_num;
        if (digit1 < digit2 && digit2 < digit3) {
            max_num = digit3;
            middle_num = digit2;
            min_num = digit1;
        } else if (digit1 < digit3 && digit3 < digit2) {
            max_num = digit2;
            middle_num = digit3;
            min_num = digit1;
        } else if (digit2 < digit3 && digit3 < digit1) {
            max_num = digit1;
            middle_num = digit3;
            min_num = digit2;
        } else if (digit2 < digit1 && digit1 < digit3) {
            max_num = digit3;
            middle_num = digit1;
            min_num = digit2;
        } else if (digit3 < digit1 && digit1 < digit2) {
            max_num = digit2;
            middle_num = digit1;
            min_num = digit3;
        } else {
            max_num = digit1;
            middle_num = digit2;
            min_num = digit3;
        }

        int num1 = max_num * 100 + middle_num * 10 + min_num;
        int num2 = min_num * 100 + middle_num * 10 + max_num;
        num0 = num1 - num2;

        int difference = num - num0;
        num = num0;
        if (difference > 0) {
            sum += difference;
        }
    }
    printf("%d\n", sum);
    return 0;
}
