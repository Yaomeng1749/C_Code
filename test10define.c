//define定义常量和宏
//define不是关键字，是预处理指令
//<Plus0818>
#include<stdio.h>
#define NUM 100//定义常量
#define Add(x,y) ((x)+(y)) //定义宏，宏具有参数,宏中不需要声明类型 ,标准式可简化为x+y
int main()
{
    printf("%d\n",NUM);
    int a=10;
    int b=20;
    int c=Add(a,b);
    printf("%d\n",c);
    return 0;
}