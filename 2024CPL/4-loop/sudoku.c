//
// Created by 26247 on 2024/10/30.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define SIZE 9

int main(void){
    bool success = true;
    int sudoku[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
            if (!(sudoku[i][j] >= 1 && sudoku[i][j] <= 9)) {
                success = false;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        //超妙！！实现每一行读入布尔量型数组，修改其中的值变成事情真假而非数值不等分别取值的问题，大大简化
        //同时，实现了索引值即数值，所以会需要将数组的范围扩大+1
        bool rows[SIZE + 1] = {false};
        for (int j = 0; j < SIZE; j++) {
            if (rows[sudoku[i][j]]) {
                success = false;
                break;
            }
            rows[sudoku[i][j]] = true;
        }
    }

    //注意一个细节问题：外层循环优先，与行优先相符，所以二维数组的表示在这里是[j][i],如果选择直接复制代码就会出现大问题哦
    for (int j = 0; j < SIZE; j++) {
        bool cols[SIZE + 1] = {false};
        for (int i = 0; i < SIZE; i++) {
            if (cols[sudoku[i][j]]) {
                success = false;
                break;
            }
            cols[sudoku[i][j]] = true;
        }
    }

    //正确实现块的遍历！！
    for (int BlockRow = 0; BlockRow < SIZE; BlockRow += 3) {
        for (int BlockCol = 0; BlockCol < SIZE; BlockCol += 3) {
            //实现了行优先，一个个按行一个个读入小九宫格块
            //注意：什么才是使得一维可行的，那就是1-9这几个数字，它是平面的；而表示数字坐标的通过多重循环实现二维
            bool blocks[SIZE + 1] = {false};
            for (int row = BlockRow; row < BlockRow + 3; row++) {
                for (int col = BlockCol; col < BlockCol + 3; col++) {
                    if (blocks[sudoku[row][col]]) {
                        success = false;
                        break;
                    }
                    blocks[sudoku[row][col]] = true;
                }
                //多次break，及时跳出循环，提高程序运行效率
                if (!success) {
                    break;
                }
            }
            if (!success) {
                break;
            }
        }
        if (!success) {
            break;
        }
    }
    if (success) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

// //唯一的坐标 cells[SIZE*SIZE] sudoku[i][j],这里没有成功地将二维转化，始终成立，需要仿照前面的写法
//     for (int i = 1, j = 1; i < SIZE && j < SIZE; i += 3, j += 3) {
//         bool cells[SIZE+1][SIZE+1] = {false};
//         if (cells[i - 1][j - 1] || cells[i - 1][j] || cells[i - 1][j + 1] ||
//             cells[i][j - 1] || cells[i][j] || cells[i][j + 1] ||
//             cells[i + 1][j - 1] || cells[i + 1][j] || cells[i + 1][j + 1]) {
//             success = false;
//             break;
//             }
//         cells[i][j] = true;
//     }


// //
// // Created by 26247 on 2024/10/30.
// //
// #include <stdio.h>
// #include <stdbool.h>
// #define SIZE 9
//
// int main(void){
//     bool success = true;
//     int sudoku[SIZE][SIZE];
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             scanf("%d", &sudoku[i][j]);
//             if (!(sudoku[i][j] >= 1 && sudoku[i][j] <= 9)) {
//                 success = false;
//             }
//         }
//     }
//
//这一段把行列一起判断逻辑是很混乱的，if语句的判断是不完整的，应该分开实现。
//     for (int i = 0; i < SIZE; i++) {
//         int frequency = 0;
//
//         for (int j = 0; j < SIZE; j++) {
//             for (int k = 0; k < SIZE; k++) {
//                 if (sudoku[j][k] == i) {
//                     frequency++;
//                     if (frequency > j + 1) {
//                         success = false;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//
//     for (int i = 0; i < SIZE; i += 3) {
//         for (int j = 0; j < SIZE; j += 3) {
//             int sum = sudoku[i][j] + sudoku[i + 1][j] + sudoku[i - 1][j] +
//                       sudoku[i][j + 1] + sudoku[i + 1][j + 1] + sudoku[i - 1][j + 1] +
//                       sudoku[i][j - 1] + sudoku[i + 1][j - 1] + sudoku[i - 1][j - 1];
//             int mult = sudoku[i + 1][j] * sudoku[i][j] * sudoku[i - 1][j] *
//                        sudoku[i][j + 1] * sudoku[i + 1][j + 1] * sudoku[i - 1][j + 1] *
//                        sudoku[i][j - 1] * sudoku[i + 1][j - 1] * sudoku[i - 1][j - 1];
//             if (!(sum == 45 && mult == 362880)) {
//                 success = false;
//                 break;
//             }
//         }
//     }
//
//     if (success) {
//         printf("YES");
//     } else {
//         printf("NO");
//     }
//     return 0;
// }
//
//


