// 函数的递归recursion与迭代iteration
// 1.递归：（自己调用自己）大事化小
// 存在限制条件，当满足这个限制条件的时候，递归便不再继续。每次递归调用之后越来越接近这个限制条件
// 递归层次太深会出现栈溢出现象[stack overflow](无法无限递归)
// 2.迭代：不断重复某段逻辑，其中的一种就是循环
// return 多个数——————return 数组

//<Plus0821>

// 函数应该高内聚低耦合：功能单一(变量少)降低与其他代码的关联度

// 调用func((v1,v2),(v3,v4),v5,v6),实参的个数是4个，因为比如(v1,v2)是逗号表达式,当1个实参算
// eg1:接受一个整型值（无符号），按照顺序打印它的每一位。例如：输入：1234，输出 1 2 3 4
#include <stdio.h>
void print(int n)
{
    if (n > 9)
    {
        print(n / 10); // 自己调用自己
        // n是整型，10也是，是整型除法(只保留结果整数部分，小数部分不参与四舍五入直接砍掉)
    }
    printf("%d ", n % 10);
}

// eg2:编写函数不允许创建临时变量，求字符串的长度。(指针解决)

// char* str用于声明str是指向字符类型的指针变量
//*str则是对str进行解引操作符,等价于str所指向的变量
int Strlen(const char *str) // 这个不是strlen大小写不同
// 可写为Strlen(char* arr)参数部分写成指针形式 或者 Strlen(char arr[])参数部分写成数组形式
{
    if (*str == '\0') // 指针变量指向空符(当前字符位无效)则当前长度为0
        return 0;
    else
        return 1 + Strlen(str + 1); // str作为存储数组地址的指针变量，实际也是存储数组第一位的地址
    // str+1意味着后移到下一个字符，然后继续判断，是\0就长度不变终止测量，不是就长度加一然后看字符串下一位
}

// eg3:阶乘   递归fac(n)=1 if n<=1 else =n*fac(n-1)
//           迭代 for循环 result *= i

// eg4:斐波那契数列 迭代比递归更合适
int fib1(int n)
{
    if (n <= 2)
        return 1;
    else
        return fib1(n - 1) + fib1(n - 2);
} // 递归版本
int fib2(int n)
{
    int result;
    int pre_result;
    int next_older_result;
    result = pre_result = 1;
    while (n > 2)
    {
        n -= 1;
        next_older_result = pre_result;
        pre_result = result;
        result = pre_result + next_older_result;
    }
    return result;
} // 迭代版本

// eg5:求最大公因数——辗转相除法 a*b=lcm*gcd

// eg6返回多个值
//(1)数组返回
void test(int arr[]) // 等效于int* arr
{
    arr[0] = 3;
    arr[1] = 4;
}
//(2)双指针返回
void test2(int *px, int *py)
{
    *px = 3;
    *py = 4;
}
//(3)全局变量
// int a1=0;
// int a2=0;
// void test3()
// {
//     a1=3;
//     a2=4;
// }

int main()
{
    int num = 1234;
    print(num);

    char arr[] = "abcdef"; //[a,b,c,d,e,f,\0] 其实可以把*p写成arr[]，因为arr[]放函数参数里可以直接当成指针变量
    int len = Strlen(arr); // 这两行里 arr[]可写为 *p,arr可写为p
    printf("%d\n", len);

    int arr1[2] = {0};
    test(arr1);
    int n = sizeof(arr1) / sizeof(arr1[0]); // 数组长度
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]); // 用%d输出整型
    }

    int a = 0;
    int b = 0;
    test2(&a, &b);

    return 0;
}
