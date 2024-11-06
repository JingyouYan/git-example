#include <stdio.h>

int main(void){
    int t, x;
    scanf("%d%d", &t, &x);

    while (t--) {
        int n;
        scanf("%d", &n);

        char board[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &board[i][j]);
            }
        }

        int winner = 0;
        char winners[12] = {'0'};

        for (int i = 0; i < n; i++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            for (int j = 0; j < n; j++) {
                //必须每次重置result的值，否则一旦result等于0，就不会再发生改变
                // result &= (board[i][j] - '0');
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        //同时需要清空其他计数器的值
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        //还会出现board[i][j]==0的情况，else if更安全保险
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    //每次result变为0后，都需要重置使得result！=0
                    result = number;
                }
            }
            if (count1 >= x) {
                winner++;
                winners[0] = '1';
            } else if (count2 >= x) {
                winner++;
                winners[1] = '2';
            } else if (count4 >= x) {
                winner++;
                winners[2] = '4';
            }
        }

        for (int j = 0; j < n; j++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            for (int i = 0; i < n; i++) {
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    result = number;
                }
            }
            if (count1 >= x) {
                winner++;
                winners[3] = '1';
            } else if (count2 >= x) {
                winner++;
                winners[4] = '2';
            } else if (count4 >= x) {
                winner++;
                winners[5] = '4';
            }
        }

        for (int d = 0; d < x; d++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            //这里只使用i,j两个变量对正斜线的历遍方式是错误的，始终在主对角线上移动
            for (int i = d, j = 0; i < x && j < x; i++, j++) {
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    result = number;
                }
            }
            if (count1 >= x) {
                winners[6] = '1';
                winner++;
            } else if (count2 >= x) {
                winners[7] = '2';
                winner++;
            } else if (count4 >= x) {
                winners[8] = '4';
                winner++;
            }
        }

        for (int d = 0; d < x; d++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            for (int j = d, i = 0; i < x && j < x; i++, j++) {
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    result = number;
                }
            }
            if (count1 >= x) {
                winners[6] = '1';
                winner++;
            } else if (count2 >= x) {
                winners[7] = '2';
                winner++;
            } else if (count4 >= x) {
                winners[8] = '4';
                winner++;
            }
        }

        for (int d = 0; d < x; d++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            for (int i = d, j = n - 1; i < n && j >= 0; i++, j--) {
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    result = number;
                }
            }

            if (count1 >= x) {
                winners[9] = '1';
                winner++;
            } else if (count2 >= x) {
                winners[10] = '2';
                winner++;
            } else if (count4 >= x) {
                winners[11] = '4';
                winner++;
            }
        }

        for (int d = 0; d < x; d++) {
            int count1 = 0, count2 = 0, count4 = 0;
            int result = -1;
            for (int i = 0, j = n - 1 - d; i < n && j >= 0; i++, j--) {
                int number = board[i][j] - '0';
                result &= number;
                if (result) {
                    if (board[i][j] == '1') {
                        count1++;
                        count2 = 0;
                        count4 = 0;
                    } else if (board[i][j] == '2') {
                        count2++;
                        count4 = 0;
                        count1 = 0;
                    } else if (board[i][j] == '4') {
                        count4++;
                        count1 = 0;
                        count2 = 0;
                    }
                } else {
                    count1 = 0, count2 = 0, count4 = 0;
                    result = number;
                }
            }

            if (count1 >= x) {
                winners[9] = '1';
                winner++;
            } else if (count2 >= x) {
                winners[10] = '2';
                winner++;
            } else if (count4 >= x) {
                winners[11] = '4';
                winner++;
            }
        }
        if (winner == 0 || winner > 1) {
            printf("draw");
        } else {
            for (int i = 0; i < 12; i++) {
                if (winners[i] != '0') {
                    printf("%c", winners[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}


