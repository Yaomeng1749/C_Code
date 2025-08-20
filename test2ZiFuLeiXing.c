//字符类型

// char 字符数据型。1字节
// short 短整型。2
// int 整型。4
// long 长整型。4 sizeof(long)>=sizeof(int)
// longlong 更长整型。 8
// float 单精度浮点. 4
// double 双精度浮点. 8
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