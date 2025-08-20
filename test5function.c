// 函数
#include <stdio.h>    //库要放在所有之前(包括函数)
int Add(int x, int y) // 返回类型，函数名，函数参数
{
    // int z=0;
    // z=x+y;
    // return z;
    return (x + y);
}

void test()
{
    printf("hello,world\n");
}
// 不需要任何返回到函数，使用void

int main()
{
    test();
    int num1 = 0;
    int num2 = 0;
    scanf("%d %d", &num1, &num2); // scanf不要忘了地址
    // sum=num1+num2;
    int sum = Add(num1, num2);
    printf("sum=%d\n", sum);
    return 0;
}