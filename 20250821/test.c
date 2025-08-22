//三子棋游戏
//测试游戏逻辑
//#include<stdio.h>
#include"game.h"
void menu()//菜单函数
{
    printf("************************\n");
    printf("***** 1. play 0. exit ***\n");
    printf("************************\n");
}

void game()
{
    char ret=0;
    char board[ROW][COL]={0};
    InitBoard(board,ROW,COL);//初始化
    DisplayBoard(board,ROW,COL);
    while(1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board,ROW,COL);//玩家下棋并输出
        ret=IsWin(board,ROW,COL);//判断输赢
        if (ret!='C')
        break;
        printf("%c\n",ret);

        ComputerMove(board, ROW, COL);
        DisplayBoard(board,ROW,COL);//电脑下棋并输出
        ret=IsWin(board,ROW,COL);//判断输赢
        if (ret!='C')
        break;
        printf("%c\n",ret);
    }
    if(ret=='*')
    printf("玩家赢！\n");
    else if(ret=='#')
    printf("电脑赢\n");
    else
    printf("平局\n");
    DisplayBoard(board,ROW,COL);
}
int main()
{
    srand((unsigned int)time(NULL));//设置随机数的生成起点
    int input = 0;
    do
    {
        menu(); // 打印菜单
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("三子棋\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误!\n");
            break;
        }
    } while (input);

    return 0;
}
