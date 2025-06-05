#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a[8] = { 0 };
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		printf("&a[%d] = %p\n", i, & a[i]);
	}
	/*int a[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}*/

	return 0;
}