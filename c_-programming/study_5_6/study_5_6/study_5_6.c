#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("a = %d\n", a);
//
//	return 0;
//}


//int* test()
//{
//	int n = 100;
//	return &n;
//}
//
//int main()
//{
//	int* p = test();
//	printf("%d\n", *p);	// 野指针
//
//	return 0;
//}

// 如何规避野指针

//int main()
//{
//	int* p = NULL;	// 初始化指针，表示暂时不要使用它
//
//	return 0;
//}


// 防御性编程
//// 断言
//#include <assert.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	assert(pa != NULL);	// #define NDEBUG可抵消该语句
//
//	printf("%d", *pa);
//
//	return 0;
//}


//void swap(int a, int b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("a = %d, b = %d\n", a, b);
//	swap(a, b);		// 传值调用
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

//void swap(int* pa, int* pb)
//{
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("a = %d, b = %d\n", a, b);
//	swap(&a, &b);		// 传址调用
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}


//int main()
//{
//	int a[10] = { 0 };
//	int* p = a;
//	int sz = sizeof(a) / sizeof(a[0]);
//	
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);// 'p+i'也可以改成'a+i'
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}

// 冒泡排序算法
void bubble_stone(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	bubble_stone(arr, sz);

	return 0;
}