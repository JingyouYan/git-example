#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 1000000000) {
        if (n == 0) {
            printf("0");
        }
        int original = n;
        int count = 0;
        while (original > 0) {
            original /= 10;
            count++;
        }
        original = n;
        int m = 0;
        while (n > 0) {
            m += (int) pow(n % 10, count);
            n = n / 10;
        }
        if (m == original) {
            printf("%d", count);
        } else {
            printf("0");
        }
        return 0;
    } else {
        return 1;
    }
}
