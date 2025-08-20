//getchar以及衍生密码程序

//设计一个输入密码确认密码程序(参照test9)
//设计一个三次密码确认失败自动退出程序(参照test9)
#include<stdio.h>
#include<string.h>//strcmp的头文件
int main()
{
    char password[20]={0};
    printf("请输入密码:");
    scanf("%s",password);//字符串不用地址化

    //getchar不同于scanf，getchar可以接受输入，但是在输入缓冲区有内容时只读取输入缓冲区
    //getchar();//直接读取了缓存区scanf阶段带入的\n(字符串部分给了password)避免后面ret读取时给\n读了出问题
    //但是scanf有特性，遇到\n或者空格都会停止读取，所以如果有空格这个机制就没用了
    int ch=0;
    while((ch=getchar())!='\n')
    {
        ;
    }

    printf("请确认密码(Y/N)\n");
    int ret=getchar();
    if('Y'==ret)
    {
    printf("Yes\n");}
    else
    {printf("No\n");}

    //当比较两字符串是否相等，不能用==，要用库函数strcmp
    int i=0;
    memset(password, 0, sizeof(password));  // 正确清零数组
    //password[20]={0};只能用于初始化
    for(i=0;i<3;i++)
    {
        printf("请输入密码：");
        scanf("%s",password);
        if(strcmp(password,"abcdefg")==0)//假定密码是abcdefg
        //当返回值是0时则两字符串相等
        {
            printf("登录成功\n");
            break;
        }
        else
        {
            printf("登录失败\n");
        }
    }
    if(i==3)
    {
        printf("连续三次密码错误，自动退出程序\n");
    }
    return 0;
}