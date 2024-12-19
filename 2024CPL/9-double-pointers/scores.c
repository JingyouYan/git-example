//
// Created by 26247 on 2024/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_SCORE 3
#define NUM_OF_MUSICIAN 4

void Print(const int table[][NUM_OF_SCORE], int num_of_musicians);

int main(void){
    //TODO:如何为二维数组用malloc函数分配内存空间
    int (*table)[NUM_OF_SCORE] = malloc(sizeof(*table) * NUM_OF_MUSICIAN);
    free(table);
}

//TODO:understand the pointer structure of double array
void Print(const int table[][NUM_OF_SCORE], int num_of_musicians){
    for (int i = 0; i < num_of_musicians; i++) {
        for (int j = 0; j < NUM_OF_SCORE; j++) {
            //table[i][j]:*( *(table + i) + j)
            //table:int (*)[3]
            //table + i 类型不变，指向第i+1个数组
            //*(table + i) 指向的内存空间不变，但指针类型改变，指向的是第i+1个数组中的第一个元素（首地址）
            //*(table + i) + j:int *
            //*( *(table + i) + j):int
            printf("table[%d][%d]:%d ", i, j, table[i][j]);
        }
    }
}

//argc:argument count
//argv:argument vector
//argv[0]:program name程序自动填充，例如我在Ubuntu系统下输入了ls -l ,即一个命令参数
//argv[1...argc-1]:command-line arguments
//argv[argc]:NULL pointer
int main(int argc, const char *argv[]){
    //把你输入的命令参数，即一个个字符串存起来，并帮你统计收集起来的参数数量
    //配置程序启动时的行为，根据传入的不同参数来执行不同的任务分支。
    //可以方便地实现程序的灵活性和可定制性，用户能够在命令行调用程序时按照自己的需求传入参数，让程序按照期望的方式运行，而不需要重新编译代码。

    //for version with argc
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    //不另外传参数，输出text所在文件路径
    //传默认参数modify running configuration

    //for version with pointers
    //argv:char *[]:char **
    //p:char **
    for (char **p = argv + 1; *p != NULL; p++) {
        printf("%s ", *p);
    }

    //while version
    char **p = argv + 1;
    while (*p != NULL) {
        printf("%s ", *p);
        p++;
    }
    //while (*p++ != NULL)有问题：解引用原值判断是否为null，然后加1，再进行打印，有错位问题
    //改为char **p = argv；;while (*++p != NULL);
}
