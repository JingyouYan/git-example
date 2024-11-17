//
// Created by 26247 on 2024/11/9.
//
#include <stdbool.h>
#include <stdio.h>

int reverse(int n);

bool isPrime(int n);

bool isAbsolutePrime(int n);

int main(void){
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (isAbsolutePrime(i)) {
            count++;
        }
    }

    printf("%d\n", count);
}

int reverse(int n){
    if (n <= 10) {
        return n;
    } else if (n <= 100) {
        int m = n / 10;
        int reverse = m + n % 10 * 10;
        return reverse;
    } else if (n <= 1000) {
        int m = n / 100;
        int p = n / 10 % 10;
        int reverse = n % 10 * 100 + p * 10 + m;
        return reverse;
    }
}

bool isPrime(int n){
    if (n == 1) {
        return false;
    }
    for (int j = 2; j * j <= n; j++) {
        if (n % j == 0) {
            return false;
        }
    }
    return true;
}

bool isAbsolutePrime(int n){
    if (isPrime(n) && isPrime(reverse(n))) {
        return true;
    }
    return false;
}
