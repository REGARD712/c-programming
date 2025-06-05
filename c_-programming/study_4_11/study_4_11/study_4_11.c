#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	// 在屏幕上打印1~10
	/*
	int i = 1;
	// 使用while循环
	while (i <= 10) // 判断循环条件
	{
		printf("%d ",i);
		i++;  // 循环变量的调整
	}
	*/

	// 输入一个正数，逆序打印
	/*
	int num = 0;
	int n = 0;
	scanf("%d", &num);
	while (num)
	{
		n = num % 10;
		printf("%d ", n);
		num /= 10;
	}
	*/

	// 用for循环在屏幕上打印1~10
	/*
	for (int num = 1; num <= 10; num++)
	{// 循环变量的初始化-循环条件判断-循环变量的调整
		printf("%d ", num);
	}
	*/

	// 计算1~100之间3的倍数之和
	/*
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
			sum += i;
		}
		if (i == 100)
		{
			printf("\n");
		}
	}
	printf("sum = %d\n", sum);
	*/

	// 用do...while循环打印1~10
	/*
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 10);
	*/
	
	// 输入一个数字，判断他是几位数
	/*
	int count = 0;		// 充当计数器
	int num = 0;
	scanf("%d", &num);
	do
	{
		count++;
		num /= 10;
	} while (num);
	printf("%d\n", count);
	*/
	
	// continue语句
	
	// while中的continue和break
	/*
	int i = 1;
	while (i <= 10)
	{
		i++;
		if (i == 5)
		{
			continue;
		}
		printf("%d ", i);
	}
	int i = 1;
	while (i <= 10)
	{
		i++;
		if (i == 5)
		{
			break;
		}
		printf("%d ", i);
	}
	*/
	
	// for中的continue
	/*
	for (int i = 1; i <= 10; i++)
	{
		if (i == 5)
		{
			continue;
		}
		printf("%d ", i);
	}
	*/
	
    // do...while中的continue
 	/*
	int i = 1;
	do
	{
		if (i == 5)
		{
			break;
		}
		printf("%d ", i);
		i++;
	} while (i <= 10);
	*/
		
	// 找出100~200之间的素数，并打印在屏幕上
	/*
	for (int i = 100; i <= 200; i++)
	{
		int flag = 1;		// 用于标记是否素数
		// 判断i是否素数
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;	// 不是素数
				break;
			}
		}
		if (flag == 1)		// 是素数
			printf("%d ", i);
	}
	*/
	
	// 优化版本
	/*
	// 如果a和b是i的因子，那么a或者b肯定有一个<=sqrt(i).
	for (int i = 101; i <= 200; i+=2)
	{
		int flag = 1;		// 用于标记是否素数
		// 判断i是否素数
		for (int j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;	// 不是素数
				break;
			}
		}
		if (flag == 1)		// 是素数
			printf("%d ", i);
	}
	*/
	
	// goto语句：可以跳转语句，当想要一次性跳出多层嵌套的语句时很有用
	/*
	printf("first");
	goto next;
	printf("second");
	next:
	printf("third");
	*/
	/*
	again:
		printf("first");
		printf("second");

	goto again;
	*/

	// switch（不可以是浮点型数据）{}
	/*
	float n = 0;
	scanf("%f", &n);
	switch (n)
	{
	case 1:
		printf("Good!");
		break;
	}
	*/
//int a = 0, b = 0;
//for (a = 1, b = 1; a <= 100; a++)
//{
//	if (b >= 20) break;
//	if (b % 3 == 1)
//	{
//		b = b + 3;
//		continue;
//	}
//	b = b - 5;
//}
//printf("%d\n", a);
	













	
	return 0;
}