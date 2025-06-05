#pragma once

// 头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 常量参数设置
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

// 函数声明

// 初始化棋盘函数
void InitBoard(char board[ROWS][COLS], int r, int c, char set);

// 打印棋盘函数
void DisplayBoard(char board[ROWS][COLS], int r, int c);

// 布置雷函数
void SetMine(char mine[ROWS][COLS], int r, int c);

// 排查雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);