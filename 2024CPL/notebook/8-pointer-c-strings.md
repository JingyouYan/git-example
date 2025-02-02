# 8-pointer-c-strings

## c-strings
  字面量：用于表示固定值的一种符号表示法
  对于字符串来说，即原值（包含空白符）+末尾'\0'
  若数组开小了一位，会导致不再是C语言中的字符串，而是普通数组。
  这里特别关注**值的修改方法**:
    signal:SIGSEV——段错误segmentation fault
    每调用一个函数，保存在栈区，malloc申请的区域在堆中；而字面量被保存在一个只读区域，即text区域，除了存放代码，还会保存一些代码中的常量（*这里保存的常量是指那些直接嵌入在代码中的常量值，不同于data 区域存放程序中初始化的全局变量和静态变量等数据，允许读写*）
    指针修改只是从栈区指向text区中字符串常量的首地址，而字符串数组均保存在stack区域，允许修改（字符数组是在栈上分配的）

## presedence
    后缀++ > 前置++
    1. () [] . ->             *left to right 左结合*
    2. + - ! ~ & * sizeof     *right to left 右结合*
    3. * / %                  *left to right*
   
   例如array[i][j]，读作这是一个大小为i的数组，每个元素存储一个大小为j的数组
## usage of const
  const char * const p
  第一个const：指针指向的内容不可变
  第二个const：指针不可变