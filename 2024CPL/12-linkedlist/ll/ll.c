//
// Created by 26247 on 2024/12/30.
//
//
// Created by hfwei on 2024/12/20.
//
//include <ll.h>在系统路径中查找文件（安装编译器时）
//include"ll/ll.h"把路径信息硬编码在文件中，不合适
#include "ll.h" //先在你创建的工程目录中查找，再到系统路径中去查找；前提：同一文件夹下
// add_executable(josephus2 josephus2.c ll/ll.c) 依赖于两个.c文件

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// function implementations函数实现

void Init(LinkedList *list){
    list->head = NULL;
    list->tail = NULL;
}

void Free(LinkedList *list){
    //不需要额外移动指针，极其方便
    while (!IsEmpty(list)) {
        Delete(list, list->head);
    }
}

bool IsEmpty(LinkedList *list){ return list->head == NULL; } //确为充要条件

bool IsSingleton(LinkedList *list){
    //后者空链表同样满足
    return (!IsEmpty(list)) && list->head == list->tail;
}

int GetHeadVal(LinkedList *list){
    //不清楚调用者情况，做一些预防措施
    if (IsEmpty(list)) {
        return -1;
    }
    return list->head->val;
}

void Print(LinkedList *list){
    if (IsEmpty(list)) {
        return;
    }
    Node *node = list->head;

    do {
        //顺着next指针不断往下扫描，打印node成员value的值
        printf("%d ", node->val);
        node = node->next;
    } while (node != list->head); //node != list->tail无法打印尾节点
    printf("\n");
}

void Append(LinkedList *list, int n){
    //先创建一个新的节点
    Node *node = malloc(sizeof *node);
    //malloc必须检查
    if (node == NULL) {
        return;
    }
    node->val = n;

    if (IsEmpty(list)) {
        list->head = node;
        list->tail = node;
        //空指针不能解引用，->符号运算错误
        list->tail->next = list->head;
    } else {
        //指针调整，代码的顺序至关重要
        list->tail->next = node; // (1)
        list->tail = node; // (2)
        //也可以写作node->next 含义是一样的
        list->tail->next = list->head; // (3)
    }
}

void Delete(LinkedList *list, Node *prev){
    //边界条件：空链表 只有一个节的链表 要删除的节点current是头节点/尾节0点
    if (IsEmpty(list)) {
        return;
    }

    if (IsSingleton(list)) {
        //释放掉头节点，原来基础上创建一个空链表
        free(list->head);
        Init(list);
        return;
    }

    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next = next;

    if (cur == list->head) {
        //删完后还要重新设置头节点-
        list->head = next;
    }

    if (cur == list->tail) {
        list->tail = prev;
    }

    //释放已删除节点所占用的内存空间
    //注意，这里节点内存空间的分配是在主函数进行的，而其释放/删除是在函数中进行的，要特别小心
    free(cur);
}
