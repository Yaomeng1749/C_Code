// 结构体01
// 结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型(内置类型）的变量。
/*
struct 大类
{
  成员变量声明;
}（variable-list）;这个可写可不写 或可在main里外里写为: structure 大类 variable-list
*/
#include <stdio.h>
struct Point // 像是图纸（类型）
{
    int x;
    int y;
} p1; // 声明类型的同时定义变量p1(全局)
struct Node
{
    int data;
    struct Point p; // 嵌套
    struct Node *next;
} n1 = {10, {4, 5}, NULL}; // 结构体嵌套初始化
struct Stu
{
    char name[20];
    int age;
};
void print1(struct Stu *ps)// 使用结构体指针访问指向对象的成员
{
    printf("name = %s  age = %d\n", (*ps).name, (*ps).age);
    printf("name = %s  age = %d\n", ps->name, ps->age); // 两种方法访问都可以
}
void print2(struct Stu ps)// 使用结构体.成员变量
{
    printf("name = %s  age = %d\n", ps.name, ps.age);
}
// 如果选择的话，首选print1
// 函数传参的时候，参数是需要压栈的。如果传递一个结构体对象的时候，结构体过大，
// 参数压栈的的系统开销比较大，所以会导致性能的下降。结构体传参的时候，要传结构体的地址。
int main()
{
    struct Point p2;                     // 像是房子（结构体变量）初始化
    struct Node n2 = {20, {5, 6}, NULL}; // 结构体嵌套初始化
    struct Stu s = {"zhangsan", 20};
    printf("%d %d %d %p\n",n2.data,n2.p.x,n2.p.y,n2.next);//访问嵌套结构体
    print1(&s); // 结构体地址传参
    print(s);
    return 0;
}

// 结构体类型的声明
// 结构体初始化
// 结构体成员访问
// 结构体传参