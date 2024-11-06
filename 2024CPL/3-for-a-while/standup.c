//
// Created by 26247 on 2024/10/17.
//
#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n < 0 || n > 100000) {
        return 1;
    }

    //创建整数型数组，规定数组长度，内部设置为0；未进行初始化则为不定值。
    int a[100001] = {0};
    int s;
    //有时候发现隔行读入输入不成功，可以考虑检查一下ide正在运行的到底是哪个程序捏
    //以社恐值s为索引值，内容为人数（这里的变量设置需要改进，i--s,s--num.
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &s);
        a[i] = s;
    }
    //用于检验输入是否正确储存处理
    // for (int i = 0; i < n + 1; i++) {
    //     printf("%d %d\n", i, a[i]);
    // }

    //单循环不易超时：n^2 > 2n，一般性成立
    /*
     *这里如何统计托的数量有讲究：首先初始化赋值，保证最后能够printf输出；
     *其次s=0的同学是无条件起立的，所以比较现有总人数和社恐值的大小应该从i=1开始
     * 条件判断语句应放在加上满足人数步骤的前面，因为经过条件语句后所有sum都是成立的。这里helper不采取i++,效率过低，追求一步到位。
     */
    int helper = 0;
    int sum = a[0];
    for (int i = 1; i < n + 1; i++) {
        if (sum < i) {
            helper += i - sum;
            sum = i;
        }
        sum += a[i];
    }
    printf("%d\n", helper);
    return 0;
}


