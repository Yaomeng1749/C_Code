//字符类型
//<Plus0819>
//<Plus0823>
// char 字符数据型。1字节
// short 短整型。2
// int 整型。4
// long 长整型。4 sizeof(long)>=sizeof(int)
// longlong 更长整型。 8
   // 对于整数常量  没有前缀 → 默认是十进制，比如 100。
   // 		      前缀 0 → 八进制，比如 012 表示十进制的 10。
   // 		      前缀 0x 或 0X → 十六进制，比如 0x1A 表示十进制的 26。(8位16进制就是int上限)
                              //int4字节,1位16进制=4位2进制=4bit，2位16=1字节，8位16=4字节

// float 单精度浮点. 4
// double 双精度浮点. 8
// 浮点数在内存中不能精确保存

extern int g;//调用share.c中声明的全局变量
#include<stdio.h>
int a=10;
int main()
{
    //向内存申请空间
    int age=20; 
    double price=66.6;
    char ch='w';
    printf("%zu\n",sizeof(char));
    printf("%d\n",sizeof(int));
    printf("%d\n",g);
    return 0;
}
// %d 以十进制整数输出（有上限
// %zu 针对无符号输出（如sizeof ，避免报错
// bit比特(1:8)byte字节 (1:1024)kb(1:1024)mb(1:1024)gb(1:1024)tb(1:1024)pb
