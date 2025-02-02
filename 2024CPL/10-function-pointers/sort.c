//
// Created by 26247 on 2024/12/20.
//
// Created by hengxin on 2024/12/04.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

//语义上可以理解为typedef int (*)(const void *, const void *) comp
typedef int (*CompareFunctionPtr)(const void *, const void *);

//碰到函数指针，先给它一个类型别名
int (*ChooseCompareFunction(bool))(const void *, const void *); //相当于CompareFunctionPtr ChooseCompareFunction(bool)

int CompareInts(const void *left, const void *right);

int CompareStrs(const void *left, const void *right);

int CompareStrsWrong(const void *left, const void *right);

void PrintInts(const int integers[], size_t len);

void PrintStrs(const char *str[], size_t len);

int StrCmpStd(const char *s1, const char *s2);


int main(){
  int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
  int size_of_integers = sizeof integers / sizeof *integers;

  PrintInts(integers, size_of_integers);
  // TODO: Sort integers using qsort
  CompareFunctionPtr comp = CompareInts;
  //  定义一个函数指针int (*comp)(const void *, const void *) = CompareInts;
  qsort(integers, size_of_integers, sizeof *integers,
        comp);
  PrintInts(integers, size_of_integers);

  const char *names[] = {
    "Luo Dayou",
    "Cui Jian",
    "Dou Wei",
    "Zhang Chu",
    "Wan Qing",
    "Li Zhi",
    "Yao",
    "ZuoXiao",
    "ErShou Rose",
    "Hu Mage",
  };
  size_t size_of_names = sizeof names / sizeof *names;

  PrintStrs(names, size_of_names);
  // TODO: Sort strings using qsort
  comp = CompareStrs;
  qsort(names, size_of_names, sizeof *names,
        comp);
  //  qsort(names, size_of_names, sizeof *names,
  //        CompareStrsWrong);
  PrintStrs(names, size_of_names);
}

// left, right: int *  （实际类型）
//特别注意这里：我们是迫于qsort对于类型的要求选择写了const void *，但我们要关注实际应用时这个指针是什么类型的
int CompareInts(const void *left, const void *right){
  int left_val = *(const int *) left; //转化为实际指针类型
  int right_val = *(const int *) right;

  //return left_val-right_val是错误的 会导致大正数-小负数 超限
  //超级妙的写法！ 两者一般非此即彼
  return (left_val > right_val) - (left_val < right_val);
}

// left, right: char **
//注意添加const的位置
int CompareStrs(const void *left, const void *right){
  char *const *left_str_ptr = left;
  char *const *right_str_ptr = right;

  return strcmp(*left_str_ptr, *right_str_ptr);
}

//这个错误的版本是按内存地址的高低排序的，且比较的是每个字符串的最低位地址
//它会导致尝试比较的是存储在这些指针位置的字节，而非实际字符串的内容。
int CompareStrsWrong(const void *left, const void *right){
  char *pp1 = left;
  char *pp2 = right;
  return strcmp(pp1, pp2);
}

void PrintInts(const int integers[], size_t len){
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", integers[i]);
  }
  printf("\n");
}

void PrintStrs(const char *str[], size_t len){
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%s\n", str[i]);
  }
  printf("\n");
}

int StrCmpStd(const char *s1, const char *s2){
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }

  const unsigned char s1_char = *((const unsigned char *) s1);
  const unsigned char s2_char = *((const unsigned char *) s2);

  return *((const unsigned char *) s1) -
         *((const unsigned char *) s2);
}

int CompareStrsCI(const void *p, const void *arg);

int (*ChooseCompareFunction(bool is_sensitive))(const void *, const void *){
  return is_sensitive ? CompareStrs : CompareStrsCI; //函数名前可以不加& 会自动进行隐式转化
}
