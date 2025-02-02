# Function as First-Class Citizen

### property：arg; return vals; assignment; in array 
---

- 如何将函数转化为一个一等公民？
  可以用为一等公民的指针间接实现转换。
- 为什么要转化为一等公民？
 1. 函数可以作为参数传递 2. 函数可以作为返回值。最直白的例子：**integration**
```c
double integrate(double (*f)(double), double a, double b);
```
注意传入函数需要与参数要求完全匹配：传入double，返回double
```c
double yi = f(xi);
double yi = (*f)(xi);
```
这两种写法都是对的，C语言中实际调用函数时函数名会被自动隐式转换为函数指针，故是否解引用无影响。
来看个更夸张的示例：

```c
double yi = (******f)(xi); //反复解引用，在函数指针函数间不断转化，无效
```
