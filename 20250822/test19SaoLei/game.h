#pragma once
#include<stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 80//雷数
#include<stdlib.h>//RAND_MAX,srand,rand的头文件
#include<time.h>//时间戳的头文件
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);//虽然使用了ROWxCOL但是board依旧ROWSxCOLS(否则就不是这个数组了)
void SetMine(char board[ROWS][COLS], int rows, int cols);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int rows, int cols);
