#define _CRT_SECURE_NO_WARNINGS

// 在屏幕上打印九九乘法表
//#include<stdio.h>
//
//int main()
//{
//	for (int i = 1; i <= 9; i++)		// i控制行
//	{
//		for (int j = 1; j <= i; j++)	// j控制列
//		{
//			printf("%dx%d=%d ", j, i, i * j);
//		}
//		printf("\n");// 打印换行符
//	}
//
//	return 0;
//}

// 找出10个整数中的最大值
/*
#include<stdio.h>

int main()
{
	int a[10] = { 0 };
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);		// 存储10个整数的值
		if(i == 0)
			max = a[0];
		if (max < a[i])		// 若比max大，两数互换
		{
			int temp = max;
			max = a[i];
			a[i] = temp;
		}
	}
	printf("max = %d\n", max);
	return 0;
}
*/

/*
#include<stdio.h>

int main()
{
	double sum = 0;
	int flag = 1;	// 处理正负
	for (int i = 1; i <= 100; i++)
	{
		sum += flag * (1.0 / i);	// 得数转为浮点数
		flag = -flag;		// 改为负号
	}
	printf("sum = %.2lf\n", sum);

	return 0;
}
*/


/*
#include<stdio.h>

int main()
{
	int count = 0;	// 作为计数器
	for (int i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 % 10 == 9)
			count++;
	}
	printf("9的个数为%d\n", count);

	return 0;
}
*/


/*
#include<stdio.h>
#include<math.h>

int main()
{
	for (int i = 100; i <= 200; i++)
	{
		int flag = 1;	// 用于判断是否为素数
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				flag = 0;	// 不是素数
		}
		if (flag == 1)		// 是素数
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/

/*
#include<stdio.h>

int main()
{
	for (int year = 1000; year <= 2000; year++)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("%d ", year);
	}

	return 0;
}
*/

/*
#include<stdio.h>

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int gcd = 0;
	if (m < n)	// 确保 m > n
	{
		int temp = m;
		m = n;
		n = temp;
	}
	int t = 0;

	// 辗转相除法求最大公约数
	while (m % n != 0)
	{
		t = m % n;
		m = n;
		n = t;
	}
	if (m % n == 0)
	{
		gcd = n;
	}
	printf("%d\n", gcd);

	return 0;
}
*/






