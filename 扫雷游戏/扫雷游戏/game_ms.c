#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("\t------------------------\n");
	printf("\t----  MINESWEEPING  ----\n");
	printf("\t------------------------\n");
	printf("\t----     1.play     ----\n");
	printf("\t----     0.quit     ----\n");
	printf("\t------------------------\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };	// 存放布置的雷的信息
	char show[ROWS][COLS] = { 0 };	// 存放排查雷的信息

	// 棋盘的初始化
	// mine初始化全为'0'(未布置雷)
	// show初始化全为'*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	// 布置雷
	SetMine(mine, ROW, COL);

	// 打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	// 排查雷
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do 
	{
		system("cls");
		menu();
		printf("请输入选项：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("pause");
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			break;
		}
	} while (input);
	system("cls");
	printf("已成功退出游戏\n");

	return 0;
}