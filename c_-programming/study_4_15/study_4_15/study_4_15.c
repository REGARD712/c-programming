#define _CRT_SECURE_NO_WARNINGS

//// 猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("\t*********************\n");
//	printf("\t******猜数字游戏******\n");
//	printf("\t******1.开始游戏******\n");
//	printf("\t******2.退出游戏******\n");
//	printf("\t*********************\n");
//}
//
//void game()
//{
//
//}
//
//int main()
//{
//	int input = 0;
//
//	srand((unsigned)time(NULL));	// 由时间戳生成随机数种子
//
//	do
//	{
//		menu();
//
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("已退出游戏\n");
//			break;
//		default:
//			printf("无效的输入，请重新输入！\n");
//			break;
//		}
//	} while(input != 2);
//	
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int a[] = { 0, 5, 3, 9, 10, 65, 15, 20 };
//	printf("%zd\n", sizeof(a) / sizeof(a[0]));	// 求出数组的长度
//
//	return 0;
//}

// 二维数组的输入输出

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	//int a[3][5] = { 0 };
//	//for (int i = 0; i < 3; i++)		// i 控制行数
//	//{
//	//	for (int j = 0; j < 5; j++)		// j 控制列数
//	//	{
//	//		scanf("%d", &a[i][j]);
//	//	}
//	//}
//	//for (int i = 0; i < 3; i++)		// i 控制行数
//	//{
//	//	for (int j = 0; j < 5; j++)		// j 控制列数
//	//	{
//	//		printf("%d ", a[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	// 二维数组的初始化可以省略行数，但是不可省略列数
//	/*int arr[][5] = { 1,2,3,4,5,6,7 };*/
//
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    printf("%zd %d\n", sizeof(str), strlen(str));
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%zd\n", sizeof(arr));
//    return 0;
//}









