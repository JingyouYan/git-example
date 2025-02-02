#ifndef LL_H
#define LL_H
#include <stdbool.h>

// types; macros (#define); function declarations;
// function implementations (short, simple, inline)

//类型包括 类型本身（类型名） 类型的大小（内存布局） 类型要求（内存运算等）
typedef struct node {
    int val; // void *val;
    struct node *next; //只用了类型名信息，非循环定义
} Node;

typedef struct ll {
    Node *head;
    Node *tail;
    // int size;
} LinkedList;

//函数接受一个链表时一般都以指针的形式，而非链表结构体的本身
void Init(LinkedList *list);

void Free(LinkedList *list);

bool IsEmpty(LinkedList *list);

bool IsSingleton(LinkedList *list);

void Print(LinkedList *list);

void Append(LinkedList *list, int n);

void Prepend(LinkedList *list, int n);

void Insert(LinkedList *list, Node *prev, int n);

void Delete(LinkedList *list, Node *prev);

int GetHeadVal(LinkedList *list);

Node *Search(LinkedList *list, int n);

#endif  // LL_H


