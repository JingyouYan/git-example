//
// Created by 26247 on 2024/10/29.
//
#include <stdio.h>
#define LEN 10
//macro is only simple text replacement,couldn't execute expressions
int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main(void){
    int key;
    scanf("%d", &key);

    int low = 0;
    int high = LEN - 1;

    //本题中重要的是索引号，而不是取数；判断时再放入字典即可，明显索引到数值，比数值到索引便捷严谨
    //index=-1可以有效保证目标未被找到，同时避免被当成有效索引值
    int index = -1;
    //长时间无输出：陷入了死循环，条件恒成立/每次循环条件变量未更新
    //imagine the scene
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == dictionary[mid]) {
            index = mid;
            //如果不是要找到索引值最小的数，找到第一个即跳出循环，需要使用break，不然如果输入了数组内的数，会陷入第一个if判断恒成立的死循环
            high = mid - 1;
        } else if (key < dictionary[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (index == -1) {
        printf("Not Found\n");
    } else {
        printf("The index of %d is %d.\n", key, index);
    }
    return 0;
}
