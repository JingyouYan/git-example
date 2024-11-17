//
// Created by 26247 on 2024/11/9.
//
#include <stdio.h>
#include <stdbool.h>

int main(void){
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);

    bool flag = true;
    for (int i = 2; i <= 40; i++) {
        //隐含要求：检查输入的合法性——是否每一位数都小于进制数
        if (!(p % 10 < i && q % 10 < i && r % 10 < i && p / 10 < i && q / 10 < i && r / 10 < i)) {
            // break;会导致整个for循环结束，而不是单次for循环结束
            continue;
        }
        int decimalP = i * (p / 10) + p % 10;
        int decimalQ = i * (q / 10) + q % 10;
        int decimalR = i * (r / 10) + r % 10;
        if (decimalP * decimalQ == decimalR) {
            printf("%d\n", i);
            flag = false;
            break;
        }
    }

    if (flag) {
        printf("0");
    }
}
