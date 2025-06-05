#define _CRT_SECURE_NO_WARNINGS 1

//猜数字游戏
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu() {
	printf("\t********************************\n");
	printf("\t********  GUESS THE NUM ********\n");
	printf("\t********************************\n");
	printf("\t********  1.game start  ********\n");
	printf("\t********  0.quit        ********\n");
	printf("\t********************************\n");
}

void game() {
	/*生成一系列数字(1~100)*/
	int ret = rand() % 100 + 1;//生成随机数
	
	/*猜数字*/
	int guess = 0;
	printf("请猜数字：");
	scanf("%d", &guess);

	while (1) {
		if (guess > ret) {
			printf("猜大了，请重新猜：");
			scanf("%d", &guess);
		}
		else if (guess < ret) {
			printf("猜小了，请重新猜：");
			scanf("%d", &guess);
		}
		else {
			printf("恭喜你，猜对了！该数字是%d\n",guess);
			break;
		}
	}
}

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));//利用时间戳函数生成随机数种子

	do {
		menu();
		printf("请选择：");
		scanf("%d", &input);

		switch (input) {
		case 1:
			/*开始游戏*/
			game();
			break;
		case 0:
			printf("已退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);

	return 0;
}