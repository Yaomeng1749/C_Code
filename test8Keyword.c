//关键字
//typedef 类型重命名
#include<stdio.h>
typedef unsigned int unit;
typedef struct Node
{
    int data;
    struct Node*next;
}Node;
//extern int g_val;声明外部符号
//extern int Add(int a,int b); 声明外部函数

int main()
{
    register int a=3;//register寄存器（处理极快） ，建议3放到寄存器里，但不保证，适合频繁被使用的数据
    unsigned int num=0;
    unit num2=0;//简化声明过程
    //struct Node n;
    //Node n;//简化结构体
    return 0;
}

//static修饰全局与局部变量和函数
//static修饰局部变量时，局部变量出了作用域不会被销毁，static改变了变量的存储位置（把局部改存到静态区）eg static int a=1;
//static修饰全局变量时，全局变量原本具有外部链接属性，若有static，则其从外部链接属性变为内部链接属性，无法extern (也放到静态区)
//static修饰函数时，函数原本具有外部链接属性，若有static，则其从外部链接属性变为内部链接属性，无法extern
// 栈区(局部变量)  堆区() 静态区(静态变量)[知道程序销毁才会消失]
