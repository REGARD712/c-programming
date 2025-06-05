#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//void menu()
//{
//	printf("\t*********************\n");
//	printf("\t***** 猜数字游戏*****\n");
//	printf("\t****** 1.play  ******\n");
//	printf("\t****** 2.quit  ******\n");
//	printf("\t*********************\n");
//}
//
//void game()
//{
//	int round = 5;// 最多猜5次
//	int ret = rand() % 100 + 1; // 随机生成1~100之间的数字
//	int guess = 0;
//	printf("请猜数字：");
//	scanf("%d", &guess);
//	while (1)
//	{
//		if (guess < ret)
//		{
//			printf("猜小了，请重新猜：");
//			scanf("%d", &guess);
//		}
//		else if (guess > ret)
//		{
//			printf("猜大了，请重新猜：");
//			scanf("%d", &guess);
//		}
//		else
//		{
//			printf("恭喜你，猜对了！\n");
//			system("pause");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));// 利用时间戳生成随机数种子
//	do
//	{
//		system("cls");
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("开始游戏\n");
//			system("pause");
//			game();
//			break;
//		case 2:
//			printf("已成功退出游戏\n");
//			break;
//		default:
//			printf("无效的输入，请重新输入！\n");
//			system("pause");
//			continue;
//		}
//	} while (input != 2);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Istriangle(int a, int b, int c)
//{
//    if ((a + b > c) || (b + c > a) || (a + c > b) || (a - b < c) || (a - c > b) || (b - c > a))
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//int main()
//{
//    int a, b, c;
//    while (scanf("%d%d%d", &a, &b, &c) == 3)// 多组输入
//    {
//        // 判断能否构成三角形
//        if (Istriangle(a,b,c))
//        {
//            if (a == b && b == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if ((a == b) || (a == c) || (b == c))
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//
//    return 0;
//}


// 二分查找
//#include<stdio.h>
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(a) / sizeof(a[0]) - 1;
//
//	int n = 7;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (a[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到。\n");
//	}
//
//	return 0;
//}

// 动态字符串
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//int main()
//{
//	char a[] = "Welcome !!!";
//	char b[] = "***********";
//
//	int left = 0;
//	int right = strlen(a) - 1;
//	
//	printf("%s\n", b);
//	while (left <= right)
//	{
//		Sleep(1000);
//		b[left] = a[left];
//		b[right] = a[right];
//		left++;
//		right--;
//		printf("%s\n", b);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d%d", &a, &b);
//	printf("a + b = %d\n", Add(a, b));
//
//	return 0;
//}









