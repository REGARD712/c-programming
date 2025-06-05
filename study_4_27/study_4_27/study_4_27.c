#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 2 * i;
//	}
//
//	return 0;
//}

#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 2;
	int b = 5;

	int ret = Add(a, b);
	printf("a + b = %d\n", ret);

	return 0;
}