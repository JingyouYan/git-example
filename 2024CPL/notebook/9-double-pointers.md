# double pointers

### 关于const

```c
//invalid1
const int var = 10;
var = 20;

//invalid2 read from right to left
//const限定不能用指针变量间接修改
const int *ptr = &var;
*ptr = 20;
//valid
var = 20;
```

### main(argc, argv)
```c
ls -l -h -a//本质是一个字符串
```
list all files——long format, human readable, all files
