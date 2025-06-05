#define _CRT_SECURE_NO_WARNINGS

// 深入理解指针（2）：const修饰常变量
//#include <stdio.h>
//
//int main()
//{
//	const int a = 10;// const修饰的是常变量，不允许修改
//	//a = 20;
//	 //但是可以通过指针修改
//	int* pa = &a;
//	*pa = 20;
//	
//	 //也可以使用const对指针变量进行修饰(const放在星号左边)：
//	 const int* pa = &a;
//	 //限制的是pa指向的对象，即*pa(a)；但是pa可以改变指向
//
//	// 另一种修饰指针变量的写法(const放在星号右边)：
//	int* const pa = &a;
//	// 限制的是pa，即不能够改变pa的指向；但是*pa(a)可以改变
//
//	return 0;
//}

// 野指针：
// 指针指向的位置不可知、不属于当前程序的空间
//
// 野指针的成因(1)：未初始化指针
//#include <stdio.h>
//
//int main()
//{
//	int* p;	// p是指针变量，当变量被创建且未赋初始值时，默认为随机值
//	*p = 20;
//
//	return 0;
//}
//
// 野指针的成因(2)：指针越界访问
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i <= len; i++)
//	{
//		printf("%d ", *(p + i));	//循环到第11次时，p越界访问，成为野指针
//	}
//
//	return 0;
//}
//
// 野指针的成因(3)：指针指向的空间释放
//#include <stdio.h>
//
//int* test()
//{
//	int n = 100;
//	return &n;	// 返回的是局部变量的地址（栈空间地址），故返回类型为整形指针类型
//}
//
//int main()
//{
//	int* p = test();
//	printf("%d\n", *p);	//调用test()函数结束后n变量销毁空间被释放，p就成为野指针
//
//	return 0;
//}
//
// 规避野指针的方法：
// 1.初始化指针，若不知道初始化为何值时，赋NULL（值为0）；
// 2.注意指针不要越界
// 3.不使用指针时，及时赋NULL

// assert()断言：确保程序运行时符合指定条件，若不符合则会报错或终止程序
// 当想要使assert语句失效，在头文件之前加上：#define NDEBUG即可
//#define NDEBUG
//#include <stdio.h>
//#include <assert.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	
//	assert(pa != NULL);	//判断pa是否为空指针
//	
//	printf("%d\n", *pa);
//
//	return 0;
//}

// 指针的使用：
//
// strlen的模拟实现：
//#include <stdio.h>
//#include <assert.h>
//
//size_t my_strlen(const char* p)
//{
//	size_t count = 0;
//	assert(p != NULL);
//	while (*p)
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%zu\n", len);
//
//	return 0;
//}
//
// 传值调用和传址调用：
// 
// 传址调用
// 写一个函数，实现两个整型变量值的交换：
//#include <stdio.h>
//
//void Swap(int* pa, int* pb)
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
//	printf("交换前：a = %d, b = %d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后：a = %d, b = %d\n", a, b);
//
//	return 0;
//}

// 深入研究数组名：
// 1.sizeof(数组名) ——> 数组名表示整个数组，计算的是整个数组的大小（单位：字节）
// 2.&数组名        ——> 数组名表示的是整个数组，取出的是整个数组的地址
//
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("  arr     = %p\n", arr);		// 首元素的地址
//	printf("  arr+1   = %p\n", arr+1);	//跳过了一个数组元素（整型：4字节）
//
//	printf("&arr[0]   = %p\n", &arr[0]);	// 首元素的地址
//	printf("&arr[0]+1 = %p\n", &arr[0]+1); //跳过了一个数组元素（整型：4字节）
//
//	printf("  &arr    = %p\n", &arr);		// 整个数组的地址
//	printf("  &arr+1  = %p\n", &arr+1); //跳过了一个数组（整型：40字节即十六进制的0x28）
//
//	return 0;
//}

// 使用指针访问数组：
// 数组名本质上是一个地址（指针）
// 
// 1.指针形式：
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	// 将1，2，3，4，5，6，7，8，9，10存放到数组中
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//
//	// 使用指针将值赋给数组中的各个元素
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", p + i);
//	}
//
//	// 使用指针打印数组内容
//	printf("arr：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}
//
// 2.数组形式：
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	// 将1，2，3，4，5，6，7，8，9，10存放到数组中
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//
//	// 使用指针将值赋给数组中的各个元素
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	// 使用指针打印数组内容
//	printf("arr：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
// 3.将指针形式中的指针换为数组名：
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	// 将1，2，3，4，5，6，7，8，9，10存放到数组中
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//
//	// 使用指针将值赋给数组中的各个元素
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", arr + i);
//	}
//
//	// 使用指针打印数组内容
//	printf("arr：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//
//	return 0;
//}
//
// arr[i] == *(arr + i) == *(i + arr) == i[arr]
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	// 将1，2，3，4，5，6，7，8，9，10存放到数组中
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//
//	// 使用指针将值赋给数组中的各个元素
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", arr + i);
//	}
//
//	// 使用指针打印数组内容
//	printf("arr：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", i[arr]);
//	}
//
//	return 0;
//}
//
// 一维数组传参的本质：参数是指针
//#include <stdio.h>
//
//void test(int* arr)
//{
//
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	test(arr);
//
//	return 0;
//}
//
//#include <stdio.h>
//
//void test(int* arr, int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);  //arr[i] ——> *(arr+i)
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	// 打印数组元素
//	test(arr, len);
//
//	return 0;
//}

// 冒泡排序
//#include <stdio.h>
//
//void bubble_sort(int* arr, int len)	//冒泡排序函数
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//
//void Print(int* arr, int len)	//打印数组内容函数
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 1,9,5,0,3,6,2,4,8,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print(arr, len);	//排序前的数组
//	bubble_sort(arr, len);//进行排序
//	Print(arr, len);	//排序后的数组
//
//	return 0;
//}
//
// 改进：
//#include <stdio.h>
//
//void bubble_sort(int* arr, int len)	//冒泡排序函数
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len - 1; i++)
//	{
//		int flag = 1;	//假定相邻两个数已经有序
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//
//void Print(int* arr, int len)	//打印数组内容函数
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 1,9,5,0,3,6,2,4,8,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print(arr, len);	//排序前的数组
//	bubble_sort(arr, len);//进行排序
//	Print(arr, len);	//排序后的数组
//
//	return 0;
//}