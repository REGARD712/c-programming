#define _CRT_SECURE_NO_WARNINGS

// 写一个二分查找函数
//#include<stdio.h>
//
//// 二分查找函数
//int bin_search(int arr[], int left, int right, int key) 
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 7;
//
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]);
//
//	int ret = bin_search(arr, left, right, key);
//
//	if (ret != -1)
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	else
//		printf("找不到\n");
//
//	return 0;
//}

// 写一个打印乘法口诀表的函数
//#include<stdio.h>
//
//// 乘法口诀表打印函数
//void mul_print(int num)
//{
//	for (int i = 1; i <= num; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//
//	mul_print(num);
//
//	return 0;
//}

// 写一个能够判断是否闰年的函数
//#include<stdio.h>
//
//void Is_leap_year(int y) 
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		printf("%d是闰年\n", y);
//	}
//	else
//	{
//		printf("%d是平年\n", y);
//	}
//}
//
//int main()
//{
//	int year = 0;
//	printf("请输入年份：");
//	scanf("%d", &year);
//
//	Is_leap_year(year);
//
//	return 0;
//}

// 打印100~200之间的素数（函数法判断素数）
//#include<stdio.h>
//
//// 能够判断素数的函数
//int Is_prime(int n)
//{
//	int flag = 1;		// 作为是否素数的标记
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//			flag = 0;
//	}
//	if (flag == 1)
//	{
//		return 1;		// 是素数
//	}
//	else
//	{
//		return 0;		// 不是素数
//	}
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (Is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//
//// 能够判断素数的函数
//int Is_prime(int n)
//{
//	int flag = 1;		// 作为是否素数的标记
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			flag = 0;
//	}
//	if (flag == 1)
//	{
//		return 1;		// 是素数
//	}
//	else
//	{
//		return 0;		// 不是素数
//	}
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (Is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//#include<stdio.h>
//
////// 能够实现将数组元素全部初始化的函数
////void init(int arr[], int len)
////{
////	for (int i = 0; i < len; i++)
////	{
////		arr[i] = 0;
////	}
////}
//
//// 能够打印数组每个元素的函数
//void arr_print(int arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//// 能够实现数组元素逆置的函数
//void reverse(int arr[], int arr2[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		arr2[9-i] = arr[i];
//	}
//}
//void reverse(int arr[], int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	int arr2[10] = { 0 };		// 用来接收逆置arr数组的元素
//
//	// 调用逆置函数前的数组元素
//	arr_print(arr, len);
//
//	//init(arr, len);
//	reverse(arr, arr2, len);
//	reverse(arr, len);
//
//	// 调用逆置函数后的数组元素
//	arr_print(arr2, len);
//	arr_print(arr, len);
//
//	return 0;
//}


#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    switch (n % 3)
    {
    case 0:
        printf("整除，余数为0\n");
    case 1:
        printf("余数是1\n");
    case 2:
        printf("余数是2\n");
    }
    return 0;
}



