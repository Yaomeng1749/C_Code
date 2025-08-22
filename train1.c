// 字符串逆序（递归实现）
#include <stdio.h>
// #include<string.h>不让用就自己创

int mystrlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

// //非递归法
// void reverse(char arr[])
// {
//     int left = 0;
//     int right = mystrlen(arr) - 1;   // 最后一个有效下标
//     while (left < right)
//     {
//         char tmp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = tmp;

//         left++;
//         right--;
//     }
// }

// 递归法一
//  void reverse(char* str)
//  {
//      char tmp = *str;                 //1
//      int len = mystrlen(str);
//      *str = *(str + len - 1);         //2
//      *(str + len - 1) = '\0';         //3
//      if (mystrlen(str + 1) >= 2)
//          reverse(str + 1);            //4
//      *(str + len - 1) = tmp;
//  }

// 递归法二
void reverse(char arr[], int left, int right)
{
    char tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
    if (left < right)
        reverse(arr, left + 1, right - 1);
}

int main()
{
    char arr[] = "abcdefg"; // [a b c d e f g \0]
    // reverse(arr);
    int left = 0;
    int right = mystrlen(arr)-1;//下标是0到size-1
    reverse(arr, left, right);
    printf("%s\n", arr);

    return 0;
}