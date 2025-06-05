#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h.>

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = 0;
		printf("Hello\n");
	}

	return 0;
}


int main()
{
	printf("Hello\n");
	main();

	return 0;
}

// 函数递归求n的阶乘

int Fact(int n)
{
	if (n == 0)
		return 1;
	else
		return Fact(n - 1) * n;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fact(n);
	printf("%d! = %d\n", n, ret);

	return 0;
}

// 递归顺序打印整数的每一位
void Print(int n)
{
	if (n > 9)// 整数为多位数
		Print(n / 10);
	printf("%d ", n % 10);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	Print(n);

	return 0;
}

// 迭代法求斐波那契数
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;

	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);

	return 0;
}

