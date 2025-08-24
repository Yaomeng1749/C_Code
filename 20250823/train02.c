// 1.小青蛙跳台阶（要么跳1要么跳2，给定n算出上楼方法数）
#include <stdio.h>
#include <ctype.h>//islower,topper,isupper,islower头文件

int fib(int n)
{
    if (n <= 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
// 例子2:
// 题目描述
// 有一个整数序列（可能有重复的整数），现删除指定的某一个整数，输出删除指定整数之后的序列。
// 序列中未被删除数字的前后位置没有发生改变。

// 数据范围： 序列长度和序列中的值都满足 1 ≤ n ≤ 50

// 输入描述：
// 	1.	第一行输入一个整数 N (0 ≤ N ≤ 50)。
// 	2.	第二行输入 N 个整数，输入用空格分隔。
// 	3.	第三行输入想要进行删除的一个整数。

// 输出描述：
// 输出为一行，删除指定数字之后的序列。

int main()
{
    int n1 = 0;
    // 输入
    scanf("%d", &n1);
    // 计算
    int m1 = fib(n1);
    // 输出
    printf("%d\n", m1);

    int n = 0;
    scanf("%d", &n);
    int arr[n]; // C99，可变长数组
    // 接收 n 个数字
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // 这个可以一行以内输入完迭代的所有元素(只要空格空开)
    }

    int del = 0;
    // 接收删除的值
    scanf("%d", &del);

    int j = 0; // j 作为下标锁定的位置，是用来存放不删除的数据
    for (i = 0; i < n; i++)
    {
        if (arr[i] != del)
        {
            arr[j++] = arr[i]; // 先替换，j再后移
        }
    }

    // 输出删除指定数字后的序列
    for (i = 0; i < j; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

//题目3:
// KiKi 想完成字母大小写转换，有一个字符，判断它是否为大写字母，如果是，将它转换成小写字母；反之则转换为大写字母。

// 输入描述：
// 多组输入，每一行输入一个字母。

// 输出描述：
// 针对每组输入，输出单独占一行，输出字母的对应形式。
    char ch = 0;

    while (scanf("%c", &ch) == 1)//输入成功
    //或者写 scanf("%c", &ch) != EOF
    {
        if (ch >= 'a' && ch <= 'z')//或者写 islower(ch)
            printf("%c\n", ch - 32);//或者写 toupper(ch)
        else
            printf("%c\n", ch + 32);//每次输入有\n会被读进来

        getchar(); // 处理 \n
    }

//题目4:
    char ch1 = 0;
    // %c的前面加空格
    // 跳过下一个字符之前的所有空白字符(如此便不需要再使用getchar，因为直接给\n跳了)

    while (scanf(" %c", &ch1) == 1)
    {
        if ((ch1 >= 'A' && ch1 <= 'Z') || (ch1 >= 'a' && ch1 <= 'z'))
            printf("%c is an alphabet.\n", ch1);
        else
            printf("%c is not an alphabet.\n", ch1);
    }

    return 0;
}
