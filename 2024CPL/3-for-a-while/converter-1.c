//
// Created by 26247 on 2024/10/15.
//
#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int num3 = n / 100;
    int num2 = n % 100 / 10;
    int num1 = n % 10;

    if (!(n >= 0 && n <= 999)) {
        return 1;
    }

    if (n <= 10 && n >= 0) {
        switch (n) {
            case 0: printf("zero\n");
                break;
            case 1: printf("one\n");
                break;
            case 2: printf("two\n");
                break;
            case 3: printf("three\n");
                break;
            case 4: printf("four\n");
                break;
            case 5: printf("five\n");
                break;
            case 6: printf("six\n");
                break;
            case 7: printf("seven\n");
                break;
            case 8: printf("eight\n");
                break;
            case 9: printf("nine\n");
                break;
            default: printf("ten\n");
                break;
        }
    }
    if (n > 10 && n < 20) {
        switch (n) {
            case 11: printf("eleven\n");
                break;
            case 12: printf("twelve\n");
                break;
            case 13: printf("thirteen\n");
                break;
            case 14: printf("fourteen\n");
                break;
            case 15: printf("fifteen\n");
                break;
            case 16: printf("sixteen\n");
                break;
            case 17: printf("seventeen\n");
                break;
            case 18: printf("eighteen\n");
                break;
            case 19: printf("nineteen\n");
                break;
        }
    }
    if (n >= 20 && n <= 99) {
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
        }
        switch (num1) {
            case 1: printf("-one");
                break;
            case 2: printf("-two");
                break;
            case 3: printf("-three");
                break;
            case 4: printf("-four");
                break;
            case 5: printf("-five");
                break;
            case 6: printf("-six");
                break;
            case 7: printf("-seven");
                break;
            case 8: printf("-eight");
                break;
            case 9: printf("-nine");
                break;
            default: break;
        }
    }
    if (n >= 100 && n <= 999) {
        //输出尾端记得加上空格（无类似\t表示） 不然编译器会默认连续输出
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
        }

        if (!(num2 == 0 && num1 == 0)) {
            switch (num2) {
                //宝真的要特别注意输出的格式要求，自己读一遍代码，看看结果是怎么样的，能否保证各个领域的典例都可以正常输出
                case 0: printf("and ");
                    break;
                case 2: printf("and twenty");
                    break;
                case 3: printf("and thirty");
                    break;
                case 4: printf("and forty");
                    break;
                case 5: printf("and fifty");
                    break;
                case 6: printf("and sixty");
                    break;
                case 7: printf("and seventy");
                    break;
                case 8: printf("and eighty");
                    break;
                case 9: printf("and ninety");
                    break;
                default: break;
            }
            if (num2 != 1) {
                if (num2 != 0) {
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
            } else {
                switch (num1) {
                    case 0: printf("and ten");
                        break;
                    case 1: printf("and eleven");
                        break;
                    case 2: printf("and twelve");
                        break;
                    case 3: printf("and thirteen");
                        break;
                    case 4: printf("and fourteen");
                        break;
                    case 5: printf("and fifteen");
                        break;
                    case 6: printf("and sixteen");
                        break;
                    case 7: printf("and seventeen");
                        break;
                    case 8: printf("and eighteen");
                        break;
                    case 9: printf("and nineteen");
                        break;
                    default: break;
                }
            }
        }
    }
}
