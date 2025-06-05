#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int* pa = &a;	// 一级指针变量
//	int** ppa = &pa;	// 二级指针变量
//	int*** pppa = &ppa;	// 三级指针变量
//	// ...
//
//	printf("%d\n", **ppa);
//
//	return 0;
//}

// 指针数组（每个元素都是指针）
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	/*int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;*/
//
//	// 创建指向整型的指针数组
//	int* arr[3] = { &a, &b, &c };
//
//
//	return 0;
//}

// 使用指针数组模拟一个二维数组
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	// 把三个一维数组整合成一个二维数组
//	int* arr[] = { arr1, arr2, arr3 };
//	// arr是指针数组
//
//	// 打印该指针数组
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	//char ch = 'w';			// 字符
//	//char* pc = &ch;
//
//	//char arr[] = "abcdef";	// 字符串
//	//char* pstr = arr;
//	//
//	// 也可写成：
//	//char* pstr = "abcdef";		// pstr中存放的是字符串首个字符'a'
//	// 注意：*pstr的内容是常量字符串，无法被修改
//	// 以防出错，在char前加上const更稳妥，即：
//	// const char* pstr = "abcdef";
//	// 
//	//printf("%c\n", *pstr);		// 验证 ——> 'a'
//	//printf("%s\n", pstr);		// abcdef
//
//
//
//
//	return 0;
//}

//int main()
//{
//	char str1[] = "Hello world.";
//	char str2[] = "Hello world.";
//
//	char* str3 = "Hello world.";
//	char* str4 = "Hello world.";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same.\n");
//	else
//		printf("str1 and str2 are not same.\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same.\n");
//	else
//		printf("str3 and str4 are not same.\n");
//
//
//	return 0;
//}

// 数组指针变量
//int main()
//{
//	int arr[10] = { 0 };
//
//	// &arr表示数组的地址
//	int(*p)[10] = &arr;	// 表示指针p是指向数组的指针，存放的是数组的地址
//	
//  区分：
//	
//  int* p = arr;	//表示指向整型变量的指针，存放的是数组的首元素
//
//	return 0;
//}

//int main()
//{
//	char arr[5];
//
//	char(*p)[5] = &arr;
//
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int(*p)[10] = &arr;
//	int* p = arr;// 一级指针
//	
//	// 如何利用数组指针打印该数组？
//	// (*p)[i]
//
//	int i = 0;
//	
//	// 利用数组指针打印
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//	}*/
//
//	// 利用一级指针打印
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}*/
//
//
//	return 0;
//}

// 二维数组传参，形参可以写成二维数组形式
//void test(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

// 形参部分写为数组指针接收地址
//void test(int(*arr)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));
//			//     相当于：  arr[i][j]
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	// 二维数组的首元素是第一行
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	test(arr, 3, 5);
//	// 参数是二维数组中第一行（视为一个一维数组）的地址
//
//	return 0;
//}

// 函数指针变量（存放函数的地址，指向的对象是函数）
//
// 怎么得到函数的地址？用&？
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//printf("&Add = %p\n", &Add);// 函数的地址
//	//printf("&Add = %p\n", Add);	// 函数的地址
//
//	int(*pf)(int, int) = &Add;// 函数指针变量
//	//函数返回类型
//	//       函数的形参
//
//
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	// 写法一：
//	/*
//	int(*pf)(int, int) = &Add;
//	int r = (*pf)(10, 20);
//	*/
//
//	// 写法二：
//	/*
//	int(*pf)(int, int) = Add;
//	int r = pf(10, 20);
//	*/
//	
//	//printf("%d\n", r);
//
//	return 0;
//}

//int main()
//{
//
//	void(* signal(int, void(*)(int)) )(int)
//
//	return 0;
//}

// 用typrdef语句重命名指针类型
//typedef int(*ptr_t)[5];
//
//int main()
//{
//	int arr[5] = { 0 };
//	int(*pa)[5] = &arr;
//	ptr_t pa2 = &arr;
//
//	return 0;
//}

// typedef void(*p)(int)
// 
// void(*signal(int, void(*)(int)))(int)可以写作：
// p signal(int, p);






