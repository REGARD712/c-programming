#define _CRT_SECURE_NO_WARNINGS

// 指针运算
#include <stdio.h>

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = &arr[0];
//	int i = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (i = len - 1; i >= 0; i--)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr[] = "Hello world";
//	//printf("%s\n", arr);
//	char* pc = &arr[0];
//	int i = 0;
//	while (*pc != '\0')// \0的ASCII码值是0
//	{
//		printf("%c", *pc);
//		pc++;
//	}
//
//	return 0;
//}

// 指针-指针，相减的两个指针变量必须指向同一个地址
// 得到的是两个指针之间的元素个数(绝对值)
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%lld\n", &arr[9] - &arr[0]);
//	printf("%lld\n", &arr[0] - &arr[9]);
//	// &arr[0] + 9 == &arr[9]
//
//	return 0;
//}

// 写一个函数，实现字符串长度的统计：
// 1.
//size_t my_strlen(char* s)// 长度为正数，不可能是负数
//{
//	int count = 0;
//	while (*s)
//	{
//		count++;
//		s++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zu\n", my_strlen(arr));
//
//	return 0;
//}
//
// 2. 指针-指针：
//size_t my_strlen(char* s)// 长度为正数，不可能是负数
//{
//	char* start = s;
//	while (*s)
//	{
//		s++;
//	}
//	return s - start;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zu\n", my_strlen(arr));
//
//	return 0;
//}

// 指针的关系运算：
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	// 打印数组内容
//	while (p < arr + len)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//
//	return 0;
//}