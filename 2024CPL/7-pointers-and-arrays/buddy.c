//
// Created by 26247 on 2024/11/23.
//
#include <stdio.h>
#include <math.h>
#define MAX 30
int blocks[MAX];

int allocateSize(int m);

int inputQ();

void inputA(int id, int memory);

int n, q;
int node;

int main(void){
    scanf("%d%d", &n, &q);

    while (q--) {
        //在处理输入的时候不要想着一步到位，按类型分别读入远比设置新数组简便
        char op;
        scanf(" %c", &op);
        if (op == 'Q') {
            inputQ;
        } else if (op == 'A') {
            int id, mem;
            scanf("%d%d", &id, &mem);
            inputA(id, mem);
        }
    }
}

int allocateSize(int m){
    return (int) ceil(log2(m));
}

int inputQ(){
    return node;
}

void inputA(int id, int memory){
    memory = allocateSize(memory);
    node = n - memory + 1;
}
