//变量与常量，变量的作用域与生命周期
//<Plus0821>

int g=0;
// 变量的作用域与生命周期
// 局部变量：变量所在的局部范围（进入作用域开始，出作用域结束）
// 全局变量：整个工程（整个程序的生命周期）
#define _CRT_SECURE_NO_WARNINGS  //define确保无warning警告(其实本代码无所谓，但其他case碰到一定要放到源文件第一行)
// 局部变量 {}内部定义变量
// 全局变量 {}外部定义变量
// 同范围（大括号内or外）同一个变量只能定义1次
// 全局和局部可以同时定义同一个变量，同时定义时局部优先显示
#include<stdio.h>
#define MAX 100
#define STR "abced"
//常量（4种）
//1.字面常量
//2.const修饰的常变量(加const后后续无法重新赋值)：本质是变量但无法修改，有常量的属性
//3.define定义的标识符标识符常量
//4.枚举常量
enum Color
{
    RED,//枚举常量
    GREEN,
    BLUE
};
int main()
{
    
    // 30;
    // 'w';
    // "abc";
    // 地址或指针是一种常量值(但指针变量不是常量)
    const int b=10;
    // b=20;
    printf("%d\n",MAX);
    enum Color c=RED;
    int num1=0;//赋值0的过程称为初始化
    int num2=0;
    //若int num1; 则num1的值是随机的
    scanf("%d %d",&num1,&num2);
    //scanf输入函数，两个%d对应两个输入整数位
    //对应变量前要加&，表示取变量的对应地址
    int sum=num1+num2;
    printf("%d\n",sum);
    return 0;
}
