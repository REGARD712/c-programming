#define _CRT_SECURE_NO_WARNINGS	

#include "game.h"

// 初始化棋盘函数
void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
}

// 打印棋盘函数
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	int i = 0;
	int j = 0;

	// 分隔线
	printf("--------------------\n");

	// 打印列数
	for (i = 0; i <= c; i++)
	{
		printf("%d ", i);
	}
	printf("\n");	// 打印完列数后换行

	for (i = 1; i <= r; i++)
	{
		// 打印行数
		printf("%d ", i);
		for (j = 1; j <= c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// 布置雷函数
void SetMine(char mine[ROWS][COLS], int r, int c)
{
	// 随机布置雷
	int count = EASY_COUNT;
	
	// 以布置的雷的个数为条件
	// 成功布置一个雷就减1
	// 当count为0时(布置完毕)就结束循环
	while (count)
	{
		// 生成随机的坐标(x,y范围：1~9)
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		// 计算 m~n 之间的取模数
		// rand() % (n-m+1) + m

		// 判断该处是否有布置雷
		if (mine[x][y] == '0')//'0'表示该处无雷
		{
			// 将雷布置在此处
			mine[x][y] = '1';
			count--;		// 雷的个数减1
		}
	}
}

// 统计雷个数函数
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int c = 0;

	// 遍历以坐标(x,y)为中心的九宫格坐标
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			// 判断是否有雷
			if (mine[x + i][y + j] == '1')
			{
				c++;
			}
		}
	}
	return c;
}

// 排查雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;	// 标记排查的个数

	while (win < r*c-EASY_COUNT)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);

		// 判断坐标合法性
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			// 判断该处是否为雷
			if (mine[x][y] == '0')	// 不是雷
			{
				// 判断该处是否被排查过
				if (show[x][y] == '*')  // 未被排查
				{
					// 统计周围雷的个数并显示
					int c = GetMineCount(mine, x, y);
					show[x][y] = c + '0';
					//  '0' - 0 = 48
					// 字符和数字的转换
					DisplayBoard(show, ROW, COL);
					win++;
				}
				else					// 已被排查
				{
					printf("该处已被排查过，请重新输入\n");
				}
			}
			else				   // 是雷
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, r, c);
				break;
			}
		}
		else
		{
			printf("输入的坐标不合法，请重新输入\n");
		}
	}
	if (win == r * c - EASY_COUNT)
	{
		printf("恭喜你获胜了！\n");
		DisplayBoard(mine, r, c);
	}
}