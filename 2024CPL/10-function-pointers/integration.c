//
// Created by 26247 on 2024/12/20.
//
// Created by hfwei on 2024/12/04.
// A nice function pointer example on Riemann integration:
// https://en.wikipedia.org/wiki/Function_pointer

#include <stdio.h>
#include <math.h>

#define NUM_OF_PARTITIONS 1000000

//注意传入函数需要与参数要求完全匹配：传入double，返回double
double Integrate(double low, double high, double (*f)(double));

double Square(double x);

int main(){
    double low = 0.0;
    double high = 1.0;
    double integration = 0.0;

    integration = Integrate(low, high, sin);
    printf("Sin(0.0 ... 1.0) = %f\n", integration);

    integration = Integrate(low, high, cos);
    printf("Cos(0.0 ... 1.0) = %f\n", integration);

    integration = Integrate(low, high, Square);
    printf("Square(0.0 ... 1.0) = %f\n", integration);

    //这里特别注意几个符号的优先级，根据需要再添加括号调整操作顺序
    double (*funcs[])(double) = {sin, cos, Square};
    for (int i = 0; i < 3; ++i) {
        printf("Integration: %f\n", Integrate(low, high, funcs[i]));
    }

    return 0;
}

double Integrate(double low, double high, double (*f)(double)){
    double interval = (high - low) / NUM_OF_PARTITIONS;

    double sum = 0.0;
    for (int i = 0; i < NUM_OF_PARTITIONS; i++) {
        double xi = low + i * interval;
        //或(*f)(xi) 两种写法都是对的，C语言中实际调用函数时函数名会被自动隐式转换为函数指针，故是否解引用无影响。
        //只有两种函数不会发生隐式转换
        //sizeof: sizeof(int)=4 sizeof(f):UB 不会把函数名转化为函数指针占8个字节（X64）
        //&取地址符： & sin——取sin这个函数所在的地址，而非指针的地址；地址是右值，地址的地址是无意义的
        double yi = f(xi);
        //    double yi = (*******f)(xi);是一样的，没有区别
        sum += yi * interval;
    }

    return sum;
}

double Square(double x){
    return x * x;
}
