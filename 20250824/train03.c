//1. 写一个函数返回参数二进制中 1 的个数。(默认是指补码的二进制[算符号位])
#include<stdio.h>
//int count_num_of_1(int n)//存在弊端对于负数不好使
int count_num_of_1(unsigned int n)//无符号，变成纯比特位处理
{
    int count = 0;
    while (n)
    {
        if ((n % 2) == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}
int count_num_of_2(int n)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < 32; i++)
    {
        if (((n >> i) & 1) == 1)
        {
            count++;
        }
    }
    return count;
}
//key skill:n=n&(n-1),此算法可以逐步消去二进制最小位的1
//Brian Kernighan 算法(循环次数更小)
// n = 15 (1111)
// n-1 = 14 (1110)
// n & (n-1) = 1110

// n = 1110
// n-1 = 1101
// n & (n-1) = 1100

// n = 1100
// n-1 = 1011
// n & (n-1) = 1000

// n = 1000
// n-1 = 0111
// n & (n-1) = 0000  ← 结束

int count_num_of_3(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int num = 0;
    scanf("%d", &num);

    int n = count_num_of_1(num);
    printf("%d\n", n);
    n = count_num_of_2(num);
    printf("%d\n", n);
    n = count_num_of_3(num);
    printf("%d\n", n);

    return 0;
}