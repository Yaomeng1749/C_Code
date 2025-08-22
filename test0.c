//本文件主要处理一些疑问的测试
#include<stdio.h>
int main()
{
    char ret='2';
    printf("ret=%c\n",ret);
    ret='\0';
    printf("ret=%c\n",ret);//字符变量，无论是0还是'\0' 都是输出空格字符
    
    scanf("%c",&ret);
    printf("ret=%d\n",ret);//用%d则会输出对应ASCII码
    
    scanf("%d",&ret);//scanf用%d会接收数字，当成ASCII码然后转成字符
    printf("ret=%d\n",ret);//用%d则会输出对应ASCII码
    printf("ret=%c\n",ret);//当成ASCII码然后转成字符
    
    int rei=5;
    scanf("%d",&rei);
    printf("rei=%d\n",rei);//对于整型变量，输入字符时就会被认定为输入无效
    return 0;
}