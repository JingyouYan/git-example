#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char res[10];

    long long int guess;

    //long long相对于long兼容性更强，范围在-2^63,2^63-1
    long long int low = 0;
    long long int high = (int) pow(2, 32);

    //持续执行某些任务的情况下使用while（1）
    //然而，重要的是要确保在适当的条件下提供退出机制，否则程序将会一直运行下去
    while (1) {
        guess = (low + high) / 2;
        printf("%llu\n", guess);
        //重新进行输出
        fflush(stdout);
        scanf("%s", res);

        //更新guess值的方式?为什么res始终取零就可以循环读入？
        switch (res[0]) {
            case 'G': {
                // [insert code here]
                high = guess - 1;
                //结束Switch选择
                break;
            }
            case 'L': {
                // [insert code here]
                low = guess + 1;
                break;
            }
            case 'E': return 0;
            case 'O': return 0;
            default: return 1;
        }
    }
    return 0;
}
