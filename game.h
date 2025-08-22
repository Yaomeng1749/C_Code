//游戏代码的函数声明，符号定义
#pragma once
#include<stdio.h>//game.c和test.c都要用这个，直接在.h头文件声明了一块用就行
#include<stdlib.h>//RAND_MAX,srand,rand的头文件
#include<time.h>//时间戳的头文件
#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col);//前两个声明变量，后两个是形参

//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋,找没下的地方随机下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢：1.玩家赢(*) 2.电脑赢(#) 3.平局(Q) 4游戏继续(C)
char IsWin(char board[ROW][COL], int row, int col);