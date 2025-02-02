#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

// enumeration枚举
//在底层enum是以整数形式存储的。意味着可以进行MALE=5这样的操作
//在默认情况下，枚举常量的值从 0 开始依次递增
//很危险，由于底层按整数保存，这里写.gender ='M'也不会报错，即使范围已经超限
typedef enum gender {
  MALE,
  FEMALE,
  UNKNOWN,
  KINDS_OF_GENDER, //末尾常量即种类数，相当于一个符号常数
} Gender; //命名gender使得含义更清晰

//通过typedef给struct score取别名Score
typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

// member, field
// tag：指musician
// alignment：内存对齐
//自身对齐internal padding：对于一个字节长度为n的量，必须存储在n的倍数的地址位上。例如int
//结构体整体对齐trailing padding：地址为其中字节数最长的类型的倍数
//内部填充 尾填充
typedef struct musician {
  char *name;
  Gender gender;
  char *first_album;
  //一个结构体的成员是一个结构体，是很常见的
  Score score;

  // struct{
  //     int papers;
  //     double funding;
  //     int awards;
  //     char *text;
  // }year_end_summary;整个结构体会占据24个字节的内存，但实际使用时只会调用里面的一个量
  //为了优化内存空间，改用union：允许多个成员共用一块内存空间，使用对象由调用者决定
  //节省内存空间：系统底层编程时使用
  union {
    int papers;
    double funding;
    int awards;
    char *text;
  } year_end_summary;

  enum {
    PAPERS,
    FUNDING,
    AWARDS,
    TEXT,
    KIND_OF_YEAR_END_SUMMARY,
  } kinds;
} Musician;

void Print(Musician *m);

int CompareMusicianByName(const void *left, const void *right);

int main(void){
  printf("Sizeof(Musician) = %zu\n", sizeof(Musician));
  //这里offsetof是一个宏macro，可以看做一个函数，求距首地址的偏移量
  //用于计算结构体中一个成员相对于结构体起始地址的偏移量。
  printf("Offset of c_score = %zu\n", offsetof(Musician, score));

  //新定义的类型叫struct musician
  //按照结构体内声明顺序定义
  struct musician luo = {
    "Dayou Luo",
    MALE,
    "ZhiHuZheYe",
    90,
    80,
    70,
    .year_end_summary.papers = 20,
    .kinds = PAPERS,
  };

  //更合理的方式：通过.对结构体内类型进行访问赋值
  //.:成员访问运算符member-access operator
  struct musician cui = {
    .name = "Jian Cui",
    .gender = MALE,
    .first_album = "XinChangZhengLuShangDeYaoGun",
    //需要两次访问
    .score = {
      .c_score = 100,
      .java_score = 90,
      .python_score = 80,
    },
    .year_end_summary.funding = 100000000,
    .kinds = FUNDING,
  };

  Musician zhang = {
    .name = "Chu Zhang",
    .gender = MALE,
    .first_album = "YiKeBuKenMeiSuDeXin",
    .score = {
      .c_score = 100,
      .java_score = 90,
      .python_score = 80,
    },
    .year_end_summary.awards = 2,
    .kinds = AWARDS,
  };

  Musician guo = zhang;

  Musician musicians[] = {luo, cui, zhang};
  int size = sizeof(musicians) / sizeof(*musicians);
  for (int i = 0; i < size; ++i) {
    Print(musicians + i);
  }
  qsort(musicians, size, sizeof *musicians, CompareMusicianByName);
  for (int i = 0; i < size; ++i) {
    Print(musicians + i);
  }

  return 0;
}

// void Print(Musician m){
//     //在需要重复调用该结构体是粘贴可能影响运算性能，我们选择指针去间接访问，而非直接黏贴
//     printf("%s\t", m.name);
// }
//修改为(*m).name 由于优先级问题，必加括号
void Print(Musician *m){
  printf("%s\t%d\t%s\t%d\t%d\t%d\n",
         // .: member access operator
         m->name, // ->: arrow operator
         m->gender,
         m->first_album,
         m->score.c_score, //看起来结构更清晰，而且 score本身就不是指针，不能用->进行操作
         m->score.java_score,
         m->score.python_score);
  switch (m->kinds) {
    case PAPERS: break;
    case FUNDING: break;
    case AWARDS: break;
    case TEXT: break;
    default: break;
  }
}

// left, right: Musician *
int CompareMusicianByName(const void *left, const void *right){
  const Musician *m1 = (Musician *) left;
  const Musician *m2 = (Musician *) right;

  //注意你自己前面定义name的时候他的类型就是char *
  //想要逆序输出直接在strcmp前加负号即可
  return strcmp(m1->name, m2->name);

  //依赖于name是struct中的第一个项，它和整个结构体的首地址是重合的
  //  char *const *m1_name_ptr = left;
  //  char *const *m2_name_ptr = right;
  //
  //  return strcmp(*m1_name_ptr, *m2_name_ptr);
}
