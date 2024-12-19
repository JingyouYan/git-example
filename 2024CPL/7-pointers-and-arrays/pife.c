//
// Created by 26247 on 2024/12/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int main(void){
    int n;
    scanf("%d", &n);

    char *life = malloc(sizeof(*life) * SIZE);
    if (life == NULL) {
        return -1;
    }
    memset(life, '.', sizeof(*life) * SIZE);
    scanf("%s", life);

    int len = (int) strlen(life);
    while (n--) {
        //如果不分配一块新的内存空间会导致后面的值受新修改值的影响
        char *new_life = malloc(sizeof(*new_life) * SIZE);
        if (new_life == NULL) {
            return -1;
        }
        memset(new_life, '.', sizeof(*new_life) * SIZE);


        for (int i = 0; i < len; i++) {
            int countA = 0, countB = 0;

            //特别小心边界情况的处理
            //别把i自己算进去了啊喂喂
            for (int j = (i - 3 > 0 ? i - 3 : 0); j < (i + 4 > len ? len : i + 4); j++) {
                if (j != i) {
                    if (*(life + j) == 'A') {
                        countA++;
                    } else if (*(life + j) == 'B') {
                        countB++;
                    }
                }
            }

            switch (*(life + i)) {
                case '.': if (countA >= 2 && countA <= 4 && countB == 0) {
                        *(new_life + i) = 'A';
                    } else if (countB >= 2 && countB <= 4 && countA == 0) {
                        *(new_life + i) = 'B';
                    }
                    break;
                //特别注意这里是不能省略保持原来位置的赋值步骤的！！
                case 'A': if (countB == 0 && countA >= 2 && countA <= 4) {
                        *(new_life + i) = 'A';
                    } else {
                        *(new_life + i) = '.';
                    }
                    break;
                case 'B': if (countA == 0 && countB >= 2 && countB <= 4) {
                        *(new_life + i) = 'B';
                    } else {
                        *(new_life + i) = '.';
                    }
                    break;

                default: break;
            }
        }
        free(life);
        life = new_life;
    }

    for (int i = 0; i < len; i++) {
        printf("%c", *(life + i));
    }

    free(life);
    return 0;
}
