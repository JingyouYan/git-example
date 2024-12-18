//
// Created by 26247 on 2024/11/9.
//
#include <stdio.h>
#include <stdbool.h>


void typeEnglish(int n);

int main(void){
    int n;
    scanf("%d", &n);

    bool flag = true;
    if (n < 0) {
        flag = false;
        n = -n;
    }
    int digit1 = n % 1000;
    //位数太大了，运算效率就低
    //改用先除再取模
    int digit2 = n / 1000 % 1000;
    int digit3 = n / 1000000 % 1000;
    int digit4 = n / 1000000000;

    if (!flag) {
        printf("minus ");
    }

    //小心这里输出的逻辑顺序
    if (digit4 > 0) {
        typeEnglish(digit4);
        printf(" billion ");
    }
    if (digit3 > 0) {
        typeEnglish(digit3);
        printf(" million ");
    }
    if (digit2 > 0) {
        typeEnglish(digit2);
        printf(" thousand ");
    }
    if (digit1 > 0) {
        typeEnglish(digit1);
    }
    if (n == 0) {
        printf("zero");
    }
}

void typeEnglish(int n){
    int num3 = n / 100;
    int num2 = n % 100 / 10;
    int num1 = n % 10;
    if (num3 > 0) {
        switch (num3) {
            case 1: printf("one hundred ");
                break;
            case 2: printf("two hundred ");
                break;
            case 3: printf("three hundred ");
                break;
            case 4: printf("four hundred ");
                break;
            case 5: printf("five hundred ");
                break;
            case 6: printf("six hundred ");
                break;
            case 7: printf("seven hundred ");
                break;
            case 8: printf("eight hundred ");
                break;
            case 9: printf("nine hundred ");
                break;
            default: break;
        }
    }

    if (num2 == 1) {
        switch (num1) {
            case 0: printf("ten");
                break;
            case 1: printf("eleven");
                break;
            case 2: printf("twelve");
                break;
            case 3: printf("thirteen");
                break;
            case 4: printf("fourteen");
                break;
            case 5: printf("fifteen");
                break;
            case 6: printf("sixteen");
                break;
            case 7: printf("seventeen");
                break;
            case 8: printf("eighteen");
                break;
            case 9: printf("nineteen");
                break;
            default: break;
        }
    } else {
        if (num2 > 1) {
            // 20以上
            switch (num2) {
                case 2: printf("twenty");
                    break;
                case 3: printf("thirty");
                    break;
                case 4: printf("forty");
                    break;
                case 5: printf("fifty");
                    break;
                case 6: printf("sixty");
                    break;
                case 7: printf("seventy");
                    break;
                case 8: printf("eighty");
                    break;
                case 9: printf("ninety");
                    break;
                default: break;
            }
        }

        if (num2 > 1 && num1 > 0) {
            printf("-");
        }

        switch (num1) {
            case 1: printf("one");
                break;
            case 2: printf("two");
                break;
            case 3: printf("three");
                break;
            case 4: printf("four");
                break;
            case 5: printf("five");
                break;
            case 6: printf("six");
                break;
            case 7: printf("seven");
                break;
            case 8: printf("eight");
                break;
            case 9: printf("nine");
                break;
            default: break;
        }
    }
}
