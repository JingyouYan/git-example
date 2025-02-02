//
// Created by 26247 on 2024/12/30.
//
// Created by hfwei on 2024/12/19.

#include <stdio.h>

#include "ll.h"
// target_include_directories(josephus2 PRIVATE ll)    //指定头文件的查找路径：查找这个.c文件，请在ll目录中查找

#define NUM 12

void SitAroundCircle(LinkedList *list, int num);

void KillUntilOne(LinkedList *list);

int GetSurvivor(LinkedList *list);

//也可以找规律用约瑟夫公式计算

int main(void){
    printf("I hate the Josephus game!\n");

    for (int i = 1; i <= 100; i++) {
        //得到了一个没有任何节点的单向链表
        LinkedList list;
        Init(&list);

        //创建一个大小为12的循环单向链表
        SitAroundCircle(&list, i);
        // Print(&list);

        //模拟杀人过程
        KillUntilOne(&list);
        //输出幸存者编号
        int survivor = GetSurvivor(&list);
        printf("%d : %d\n", i, survivor);

        Free(&list);
    }

    return 0;
}

void SitAroundCircle(LinkedList *list, int num){
    for (int i = 1; i <= num; i++) {
        //在尾节点后追加一个节点
        Append(list, i);
    }
}

void KillUntilOne(LinkedList *list){
    Node *node = list->head;

    while (!IsSingleton(list)) {
        //从list链表中把node节点的下一个节点删除
        //在使用delete函数的时候传入的是待删除节点的前驱节点 pre cur next
        Delete(list, node);
        node = node->next;
    }
}

int GetSurvivor(LinkedList *list){ return GetHeadVal(list); }
