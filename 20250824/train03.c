// 1. 写一个函数返回参数二进制中 1 的个数。(默认是指补码的二进制[算符号位])
#include <stdio.h>
// int count_num_of_1(int n)//存在弊端对于负数不好使
int count_num_of_1(unsigned int n) // 无符号，变成纯比特位处理
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
// key skill:n=n&(n-1),此算法可以逐步消去二进制最小位的1
// Brian Kernighan 算法(循环次数更小)
//  n = 15 (1111)
//  n-1 = 14 (1110)
//  n & (n-1) = 1110

// n = 1110
// n-1 = 1101
// n & (n-1) = 1100

// n = 1100
// n-1 = 1011
// n & (n-1) = 1000

// n = 1000
// n-1 = 0111
// n & (n-1) = 0000  ← 结束

// 延伸应用：
//  如果要判断一个数是不是 2 的 n 次方
//  2^1// 10
//  2^2// 100
//  2^3// 1000
//  if ((n & (n - 1)) == 0)
//  { 即可得出是2^n}

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

////2. 给定2个int(32位)m和n，且他们的二进制表达有多少位(bit)不同
int count_diff_bit1(int m, int n)
{
    int count = 0;
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        if (((m >> i) & 1) != ((n >> i) & 1))
        {
            count++;
        }
    }
    return count;
}

int count_diff_bit2(int m, int n)
{
    int count = 0;
    // ^ 异或操作符
    // 相同为 0，相异为 1
    int ret = m ^ n;
    // 统计一下 ret 中二进制位有几个 1
    while (ret)
    {
        ret = ret & (ret - 1);
        count++;
    }
    return count;
}
// 全局变量，静态变量都是放在静态区
// 全局变量，静态变量不初始化的时候，默认会被初始化为 0
// 局部变量，是放在栈区，不初始化，默认值是随机值
int i0; // 0

int is_leap_year(int y)
{
    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

int main()
{
    // 1.
    int num = 0;
    scanf("%d", &num);

    int n = count_num_of_1(num);
    printf("%d\n", n);
    n = count_num_of_2(num);
    printf("%d\n", n);
    n = count_num_of_3(num);
    printf("%d\n", n);

    // 2.
    int m1 = 0;
    int n1 = 0;
    scanf("%d %d", &m1, &n1);
    int ret = count_diff_bit1(m1, n1);
    printf("%d\n", ret);

    // 3.获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
    // eg.10
    // 00000000000000000000000000001010
    // 奇数位0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    // 偶数位0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
    int i = 0;
    int num1 = 0;
    scanf("%d", &num1);

    // 获取奇数位的数字
    for (i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (num1 >> i) & 1);
    }
    printf("\n");

    // 获取偶数位的数字
    for (i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (num1 >> i) & 1);
    }

    // 4.算术转换的探索
    i0--;                // 0 to -1
    if (i0 > sizeof(i0)) // sizeof 这个操作符计算返回的结果是 size_t 类型的(=4)，是无符号整型的
    //-1(负数)被算数转化为补码的10进制形式(一个极大的数),所以结果不是 < 而是 >
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }

    // 5.给定输出规模，输出对应的X形图案
    int n2 = 0;
    while (scanf("%d", &n2) == 1)
    {
        int i1 = 0;
        int j1 = 0;
        for (i1 = 0; i1 < n2; i1++)
        {
            for (j1 = 0; j1 < n2; j1++)
            {
                if (i1 == j1) // 正对角线
                    printf("*");
                else if (i1 + j1 == n2 - 1) // 反对角线
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    // 6.给定年份和月数，想知道那年那月的具体月天数
    int y = 0;
    int m3 = 0;
    int d = 0;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // days[1]=0使得元素后移，输入数能避免下标数从0起引起的歧义
    while (scanf("%d%d", &y, &m3) == 2)
    {
        int d = days[m3];
        if (is_leap_year(y) == 1)
        {
            d++;
        }
        printf("%d\n", d);
    }
    return 0;
}
