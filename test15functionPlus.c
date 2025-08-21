//函数 进阶1
//<Plus0820>

//函数：1.库函数（header）2.自定义函数
//1.库函数 :(1)IO函数(2)字符串操作函数(3)字符操作函数(4)内存操作函数(5)时间/日期函数(6)数学函数(7)其他库函数
//https://cplusplus.com/reference/ 参照该网址，包含C/C++的库及对应库函数
//https://zh.cppreference.com/ C/C++参考学习网站
//2.自定义函数：
// ret_type fun_name(para1, * )
// {
//  statement;//语句项
// }
// ret_type 返回类型
// fun_name 函数名
// para1    函数参数

//int main(void):明确声明main函数不需要参数
//但int main()实际上自带3个参数 i.e. int main(int argc,char* argv[],char *envp[]) 

#include<stdio.h>
#include<math.h>//sqrt的头文件
#include<stdbool.h>//bool的头文件
#include<string.h>//strlen的头文件
#include"add.h"
//当有头文件内(.h)有一个函数声明，有C文件(.c)有这个函数的定义，而且两个文件名和函数名一致
//可以用 #include"函数名.h“ 从其他文件调用对应函数

int get_max(int x, int y); //函数的声明(有分号)声明告诉信息，具体有没有要看定义(可有可无,函数定义在main后则声明起作用)

//一般是先声明后定义
int get_max(int x, int y)//函数的定义
{
 return (x>y)?(x):(y);//三目操作符 a?b:c 若a真则表达b，若a假则表达c
}
//求函数最大值

//实现成函数，但是不能完成任务
//实参传递给形参时，形参只是实参的临时拷贝
//对于形参的修改无法影响实参（这种情况下需要使用指针）

void Swap1(int x, int y) //x和y是形式参数（只有在函数被调用时才会出现,调用完自动销毁）
{
 int tmp = 0;
 tmp = x;
 x = y;
 y = tmp;
}

//正确的版本
void Swap2(int *px, int *py)
{
 int tmp = 0;
 tmp = *px;//z=num1
 *px = *py;//num1=num2
 *py = tmp;//num2=z(num1)
}
//交换函数

//求素数函数:(算法:判断i是否实素数，当除1以外的小于等于sqrt(i)的数都无法整除i时，i是素数）

//判断闰年函数：（Leap year：1.能被4整除 且 不被100整除  或者 2.能被400整除。((a&&b)||(c))

//二分法binary search 注意：对于数组，如果进行传递实参到形参，不会传递整个数组，而是只会传递数组第一个元素的地址，arr在函数中只作为指针变量
//数组传参实际上是传递数组首元素的地址，而不是整个数组，因此在函数中 sizeof(arr)/sizeof(arr[0])=8/4 or 4/4 =2 or 1(无法在函数中计算数组的元素个数) 

//return 一个+1的值 可以写 return n+1 但不能写 return n++(先返回n 后++没有用,不过++n可以)

bool Is_prime(int i)//bool类型 大小为1字节 C99设定
{
    int j=0;
    for (j=2;j<=sqrt(i);j++)
    {
        if(i%j==0)
        return false;//false=0
    }
    return true;//true=1
}

void new_line()
{
 printf("hehe\n");
}
void three_line()
{
    int i = 0;
 for(i=0; i<3; i++)
   {
    new_line();
  }
}
//嵌套调用：一个函数定义里调用另一个函数（但不能函数定义内部嵌套定义另一个函数，多个return）

int main()
{
 int a= 10;
 int b = 20;
 int max = get_max(a, b);
 printf("max = %d\n", max);

 int num1 = 1;
 int num2 = 2;
 Swap1(num1, num2);//传值调用 (不能操作，无法影响实参)
 printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
 Swap2(&num1, &num2);//传址调用（函数内部可以直接操作函数外部的变量）
 printf("Swap2::num1 = %d num2 = %d\n", num1, num2);

 three_line();
 
 int a1=0;
 int a2=0;
 scanf("%d %d",&a1,&a2);
 printf("Sum=%d\n",add(a1,a2));

 printf("%zu\n",strlen("abcdefg"));//链式访问(适用于函数)
 printf("%d", printf("%d", printf("%d", 43)));//链式访问，printf返回值是字符的个数（43+2(43是2个字符)+1(2是1个字符)
 return 0;
}
