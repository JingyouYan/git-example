#include <stdio.h>
#include <stdbool.h>

int main(void){
    int n;
    scanf("%d", &n);


    int count = 0;
    //outer loop:identify the primes in the n respectively;  inner loop:seek for the divisor's existence.
    //the values we initialize should adjust to the context.
    for (int i = 2; i <= n; i++) {
        //you'd better minimalize the scope of variable.
        //在每次外层循环迭代时，primes的值不会自动重置为true，因为它不是在每次判断新的数是否为质数时重新初始化
        //同时更容易发现值在哪里发生了改动
        bool primes = true;
        //pay attention to the border value,like whether to use = or not.
        for (int j = 2; j * j <= n; j++) {
            if (i % j == 0) {
                primes = false;
                //this break will lead the inner loop stops and continue the outer loop.
                break;
            }
        }
        if (primes) {
            count++;
            printf("%d\n", i);
        }
    }
    return 0;
}

// #include <stdio.h>
// #include <stdbool.h>
//
// int main(void){
//     int n = 0;
//     scanf("%d", &n);
//
//     int count = 0;
//     //申明变量的作用域scope越小越好（下可知）
//     for (int i = 2; i <= n; i++) {
//         bool prime = true; //如果对布尔变量prime的定义放在外层，则与for循环并列，布尔值始终为真
//         for (int j = 2; j * j <= n; j++) {
//             if (i % j == 0) {
//                 prime = false;
//                 break; //这里的break只是结束当前j所对应值的操作,break终止的是它所缀的最小单位函数过程的终止
//             }
//         }
//         //很多时候else语句都是不必要的，单列的if反而更能体现代码逻辑，步骤块
//         //(prime)意味着prime非0，即为真
//         //关注逻辑顺序，特别是多个循环语句和if语句嵌套式，良好的代码风格就格外重要
//         if (prime) {
//             printf("%d ", i); //这里引号内末尾所缀空格可以让输出有序化
//             count++;
//         }
//     }
//     printf("\n%d\n", count);
//     return 0;
// }
