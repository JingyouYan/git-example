//
// Created by 26247 on 2024/11/7.
//
#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int number){
    // bool isPrime = true;
    //布尔变量往往在函数定义中可以省略参数，不用加以传递

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            //isPrime = false;
            //break;
            //这一步代码直接实现了返回bool值并跳出循环函数两个步骤，甚至还实现了整个函数功能的完成
            return false;
        }
    }
    return true;
}

int main(void){
    int number;
    scanf("%d", &number);

    // for (int i = 1; i <= number; i++) {
    //     if (IsPrime(i)) {
    //         printf("%d ", i);
    //     }
    // }
    return IsPrime(number);
}
