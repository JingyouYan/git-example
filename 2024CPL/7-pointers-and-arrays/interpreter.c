#include <stdio.h>

int main(void){
    unsigned int X;
    //一般习惯于读取无符号整数的%x
    scanf("%x", &X);

    printf("%d\n", (int) X);
    printf("%u\n", X);
    //利用指针间接操作指向数据类型实现转换
    //简单的类型转换只是改变了编译器对这个值的解释方式，但没有改变内存中的数据存储格式
    printf("%.6f\n", *(float *) &X);
    printf("%.3e\n", *(float *) &X);

    return 0;
}
