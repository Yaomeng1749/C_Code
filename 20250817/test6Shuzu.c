//数组

//<Plus0819>
#include<stdio.h>
int main()
{
    int arr[10]={10,23,42,4,5,5,7,46};
    //数组下标从0开始（C语言） ，数组的中括号里要常量（const这种不行）
    //arr[8]访问的就是第九个元素
    int i=0;
    int sz=sizeof(arr)/sizeof(arr[0]);//sizeof只能输出字节长度，arr10个int元素，一共40个字节，arr[0] 4个字节，只有相除才能得到size
    printf("%d\n",sz);
    while(i<10)
    {
         printf("%d ",arr[i]);
         i=i+1;
    }
    return 0;
}
