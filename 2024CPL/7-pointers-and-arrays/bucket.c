//
// Created by 26247 on 2024/11/20.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100000

int top = -1;
char left_buckets[SIZE];
bool isMatch(char left_bucket, char right_bucket);

// bool isEmpty(top);

int main(void){
    int t;
    scanf("%d", &t);

    while (t--) {
        //记得每次重置top的结果，保证循环间结果的独立
        top = -1;
        char bucket[SIZE] = {'\0'};
        scanf("%s", bucket);

        int len = strlen(bucket);
        bool flag = true;
        //TODO:how to identify the legal buckets
        for (int i = 0; i < len; i++) {
            //像这样一个“对子”的题目使用栈可以使得一对跨越其它项的干扰，各自配对
            if (bucket[i] == '{' || bucket[i] == '[' || bucket[i] == '(') {
                if(top < SIZE - 1) {
                    //top++小心越界
                    left_buckets[++top] = bucket[i];
                }
            } else if (bucket[i] == '}' || bucket[i] == ']' || bucket[i] == ')') {
                // left_buckets[top] != bucket[i]判断条件不足
                if (top == -1 || !isMatch(left_buckets[top], bucket[i])) {
                    flag = false;
                    break;
                } else {
                    top--;
                }
            }
        }

        //记得最终检查是否全部配对完成，没有剩余的作括号
        if (flag && top == -1) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
}

bool isMatch(char left_bucket, char right_bucket){
    if (left_bucket == '{' && right_bucket == '}'
        || left_bucket == '[' && right_bucket == ']'
        || left_bucket == '(' && right_bucket == ')') {
        return true;
        }
    return false;
}
