//随机猜数字游戏

#include<stdio.h>
#include<stdlib.h>//RAND_MAX,srand,rand的头文件
#include<time.h>//时间戳的头文件
void game()
{
    int guess=0;
    int ret=rand()%100+1;//限定在1～100
    //rand一般是生成1个0～32767（RAND_MAX）之间的随机数，但是只使用rand无法做到完全随机，同文件多次打开的随机结果都是固定的
    //printf("%d\n",ret);
    while(1)
    {
        scanf("%d",&guess);
        if(guess<ret)
        printf("猜小了\n");
        else if(guess>ret)
        printf("猜大了\n");
        else
        {
            printf("你猜对了！\n");
            break;
        }

    }
}

//指针中 int* p=NULL空指针 对标的就是 int a=0

int main()
{
    //需要srand函数来设置一个随机的起点
    srand((unsigned int)time(NULL));//不想用time的参数，用空指针NULL
    //强制转time_t(也是一种整形)为unsigned int
    //最终成功得到时间戳，作为srand的生成起点，再用rand调用srand
    game();
    return 0;
}
