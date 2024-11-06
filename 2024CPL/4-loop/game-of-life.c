//
// Created by 26247 on 2024/10/30.
//
#include <stdio.h>
#define SIZE 6
#include <windows.h>
//棋盘的多种定义方式
int const board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
};
//以行为序列分别定义每行的数组{[0]={0},[1]={[1]=1,[2]=1}
//只命名不为0的点坐标[4][3]=1注意均由逗号分隔开来
//同形状输入：0,0,0,0,0,0,
//          0,1,1,0,0,0,把二维数组看成一个一维数组进行存储
//从底层的角度看，计算机的内存是线性的，没有真正的二维结构。通过这种行优先（或者在某些编程语言中也可以是列优先）的存储方式，就可以把二维数组的元素紧凑地存放在内存中。


int main(void){
    int old_board[SIZE + 2][SIZE + 2] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            old_board[i + 1][j + 1] = board[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", old_board[i][j]);
        }
        //啊啊啊姐这个想要输出二维是需要手动实现滴
        printf("\n");
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            //注意：这里的类型是允许的！！
            printf("%c ", old_board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }


    int new_board[SIZE + 2][SIZE + 2] = {0};


    //为了避免超过新的范围值
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            //常用技巧：多个0/1状态判断变成状态值相加实现判断（格子之间是无差异的）
            int num_of_live_neighbours = old_board[i][j + 1] + old_board[i][j - 1] +
                                         old_board[i + 1][j + 1] + old_board[i + 1][j] + old_board[i + 1][j - 1] +
                                         old_board[i - 1][j] + old_board[i - 1][j + 1] + old_board[i][j - 1];
            //常见操作方式：结果0/1，即判断的逻辑表达式真假，两个直接做等号
            if (old_board[i][j]) {
                new_board[i][j] = (num_of_live_neighbours == 2 || num_of_live_neighbours == 3);
            } else {
                new_board[i][j] = (num_of_live_neighbours == 3);
            }
        }
    }
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            //注意：这里的类型是允许的！！
            printf("%c ", new_board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }

    Sleep(1000);
    //clear the screen
    system("cls");

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            //注意：这里的类型是允许的！！
            old_board[i][j] = new_board[i][j];
        }
    }

    return 0;
}

