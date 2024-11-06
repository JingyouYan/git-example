//
// Created by 26247 on 2024/10/15.
//
#include <stdio.h>

int main(void){
    //CLion不会帮你补充大括号的后半部分，写的时候慎之又慎！！
    int n;
    scanf("%d", &n);
    if (!(n <= 25 && n >= 1)) {
        return 1;
    }

    //这里如果没有将阶乘值初始化，会导致默认为一个garbage value，无法参与正常的*=循环！！
    int factorial = 1;
    int num = 0;
    //公式理解出现了错误，和取模即每个数值分别取模后的值累加再再次取模，乘同理，可以防止计算中数值的溢出
    //重复取模不会改变运算结果，只是导致运算复杂性提高
    //每个i值对应的循环，factorial的值不会被重置，而是累加，这样才得出了正确的结果，使factorial的定义域也在计算机性能之内
    for (int i = 1; i <= n; i++) {
        factorial = factorial * i % 10007;
        num += factorial; //这里可以略去%，因为num值是不会溢出的，将%留给更有需要的数;同时减少计算的复杂性
    }
    //结束循环后factorial的值也发生了变化哦
    printf("%d", num % 10007);
    return 0;
}
