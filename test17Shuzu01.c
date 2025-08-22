// 数组01
// 格式： 数组元素类型 + 数组名 + [数组元素个数],数组类型是:元素类型[数组元素个数] eg int arr[10],arr类型为 int[10]
#include <stdio.h>
//void bubble_sort(int arr[])//arr这里看似是数组，实际是指针变量
void bubble_sort(int arr[],int sz)//[]内写啥无所谓，因为不会用，而且传过去的是首元素地址，且[]不能约掉
{
    //切忌在函数内求数组个数
    int i = 0;
    for (i = 0; i < sz - 1; i++)//一共走(sz-1)趟
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}//Bubblesort

int main()
{

    // 一维数组
    char arr1[] = "abc";            // 有‘\0'
    char arr2[3] = {'a', 'b', 'c'}; // 没有'\0'，arr2[]也一样没有
    char arr4[3] = {'a', 98, 'c'};  // 98会视作ASCII码转化为字符
    // int n=10;
    // int arr1[n]={0};C99之前数组个数只能用常量表示，C99之后才有变量(为了表示变长数组)
    int arr[10] = {0}; // 数组的不完全初始化
    // 计算数组的元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);
    // 对数组内容赋值,数组是使用下标来访问的，下标从0开始。所以：
    int i = 0; // 做下标

    for (i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    } // 输出数组的内容
    printf("\n ");
    for (i = 0; i < sz; ++i)
    {
        printf("&arr[%d] = %p\n", i, &arr[i]);
    } // 输出数组里每个元素的地址(整形元素相邻差4字节)
    // 一位数组在内存中是连续存放的

    // 二维数组
    int arr10[3][4] = {1, 2, 3, 4};     // 三行四列(从左到右从上到下的 一行一行排)
    int arr20[3][4] = {{1, 2}, {4, 5}}; // 通过大括号可以让每个大括号内元素分居单独一行
    int arr30[][4] = {{2, 3}, {4, 5}};  // 二维数组如果有初始化，行可以省略，列不能省略
    // 行和列的下标都是从0开始
    int arr01[3][4];
    i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 4; j++)
        {
            printf("&arr01[%d][%d] = %p\n", i, j, &arr01[i][j]);
        }
    } // 输出数组里每个元素的地址(整形元素相邻差4字节)
    // 二位数组在内存中也是连续存放的

    printf("arr10's row= %zu\n",sizeof(arr10)/sizeof(arr10[0]));//二维数组求行数=总大小除以第一行大小
    printf("arr10's col= %zu\n",sizeof(arr10[0])/sizeof(arr10[0][0]));//二维数组求列数=第一行大小除以第一个元素大小

    int arr02[] = {3, 1, 7, 5, 8, 9, 0, 2, 4, 6};//冒泡排序(升序排序)
    int sz02 = sizeof(arr02) / sizeof(arr02[0]);
    bubble_sort(arr02,sz02); // 是否可以正常排序？不能
    //数组名本质是数组首元素的地址
    for (i = 0; i < sizeof(arr02) / sizeof(arr02[0]); i++)
    {
        printf("%d ", arr02[i]);
    }printf("\n");

    printf("%p\n", arr);//(1)arr就是数组首元素地址
    printf("%p\n", arr+1);//+1后移一位多4个字节
    printf("*arr    = %d\n", *arr); // 第一个元素的值

    printf("%p\n", &arr[0]);//(2)数组首元素地址
    printf("%p\n", &arr[0]+1);//+1后移1位多4个字节

    printf("%p\n", &arr);//(3)数组地址
    printf("%p\n", &arr+1);//整个数组都挪，多40个字(sz=10)
    //看似（1）和（3）一样但是后续意义不同(+1后（1)多4字节（3）多40字节
    //仅在&+数组名【case(3)】 or size(数组名)时数组才是数组本身，其他时候数组名都能当作数组首元素地址
    //只要是arr的就是指针变量(首元素地址),输出字符串时arr也是指针变量[Note:地址是一个常量值]

    printf("%p\n", arr10);//二维数组是首行地址
    printf("%p\n", arr10+1);//+1后第一行后移一位多（4*列数）个字节 (4*4=16)

    //Note:2维数组名也表示数组首元素地址(第一行的地址)如果+1则变成表示第二行的地址
    //地址从低到高排布
    return 0;
}