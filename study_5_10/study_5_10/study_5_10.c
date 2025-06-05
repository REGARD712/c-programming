#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 数组指针
//#include <stdio.h>
//
//int main()
//{
//	/*char c[6] = { 'H','e','l','l','o' };
//	char (*pc)[6] = &c;*/
//
//	return 0;
//}


// 函数指针
//void fun(char* c, int x)
//{
//
//}
//
//int main()
//{
//	void (*pf)(char*, int) = &fun // fun
//
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	//int (*p1)(int, int) = &Add;
//	
//	// 函数指针数组
//	int (*parr[4])(int, int) = { Add, Sub, Mul, Div };	
//	// 存放四个函数地址的数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int r = parr[i](9, 3);
//		printf("%d\n", r);
//	}
//
//	return 0;
//}

// 简易计算器

//void menu()
//{
//	printf("\t*************************\n");
//	printf("\t****    简易计算器   ****\n");
//	printf("\t*************************\n");
//	printf("\t****      1.Add     ****\n");
//	printf("\t****      2.Sub     ****\n");
//	printf("\t****      3.Mul     ****\n");
//	printf("\t****      4.Div     ****\n");
//	printf("\t****      0.Quit    ****\n");
//	printf("\t************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int r = 0;
//
//	do
//	{
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &x, &y);
//			r = Add(x, y);
//			printf("%d\n", r);
//			break;
//		case 2:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &x, &y);
//			r = Sub(x, y);
//			printf("%d\n", r);
//			break;
//		case 3:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &x, &y);
//			r = Mul(x, y);
//			printf("%d\n", r);
//			break;
//		case 4:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &x, &y);
//			r = Div(x, y);
//			printf("%d\n", r);
//			break;
//		case 0:
//			printf("已退出\n");
//			break;
//		default:
//			printf("输入错误!\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

// 改进：（转移表）
//void menu()
//{
//	printf("\t*************************\n");
//	printf("\t****    简易计算器   ****\n");
//	printf("\t*************************\n");
//	printf("\t****      1.Add     ****\n");
//	printf("\t****      2.Sub     ****\n");
//	printf("\t****      3.Mul     ****\n");
//	printf("\t****      4.Div     ****\n");
//	printf("\t****      0.Quit    ****\n");
//	printf("\t************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int r = 0;
//
//	do
//	{
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("已退出\n");
//		}
//		else if (input <= 4 && input >= 1)
//		{
//			// 转移表
//			int (*parr[5])(int, int) = { NULL, Add, Sub, Mul, Div };// 函数指针数组
//			//                           0     1    2    3    4
//			printf("请输入两个操作数：");
//			scanf("%d %d", &x, &y);
//			r = parr[input](x, y);
//			printf("%d\n", r);
//		}
//		else
//		{
//			printf("输入错误!\n");
//		}
//
//	} while (input);
//
//	return 0;
//}

// 回调函数：通过函数指针（在一个函数中作为形式参数）调用的函数
// 例（简易计算器）：
//void calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int r = 0;
//	printf("请输入两个操作数：");
//	scanf("%d %d", &x, &y);
//	r = pf(x, y);
//	printf("%d\n", r);
//}
//
//void menu()
//{
//	printf("\t*************************\n");
//	printf("\t****    简易计算器   ****\n");
//	printf("\t*************************\n");
//	printf("\t****      1.Add     ****\n");
//	printf("\t****      2.Sub     ****\n");
//	printf("\t****      3.Mul     ****\n");
//	printf("\t****      4.Div     ****\n");
//	printf("\t****      0.Quit    ****\n");
//	printf("\t************************\n");
//}
//
//// 回调函数（Add, Sub, Mul, Div）：
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("已退出\n");
//			break;
//		default:
//			printf("输入错误!\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}

// qsort() ：该函数是C语言中提供的一个排序函数，
// 是基于快速排序算法思想的一种排序算法，可以排序任意类型数据

// 冒泡排序
//void Bubblesort(int arr[10], int len)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// 交换
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//
//// 打印数组函数，方便对比排序效果
//void Print_arr(int arr[10], int len)
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
//	int arr[10] = { 6,9,8,2,5,4,0,3,1,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print_arr(arr, len);
//	Bubblesort(arr, len);
//	Print_arr(arr, len);
//
//	return 0;
//}

// qsort函数：
// 打印数组的函数，方便对比排序效果
//void Print_arr(int arr[10], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//// 用于比较整型数据大小的函数，此时两个参数就指向整型数据
//int cmp_int(const void* p1, const void* p2)
//{
//	// void* 类型的指针不能直接解引用，可通过强制类型转换
//	// 升序排序
//	if (*(int*)p1 > *(int*)p2)
//		return 1;
//	else if (*(int*)p1 < *(int*)p2)
//		return -1;
//	else
//		return 0;
//}
//
//// 测试qsort函数排序整型数组的效果
//void test2()
//{
//	int arr[10] = { 6,9,8,2,5,4,0,3,1,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print_arr(arr, len);
//	qsort(arr, len, sizeof(arr[0]), cmp_int);
//	Print_arr(arr, len);
//}
//
//int main()
//{
//	test2();
//
//	return 0;
//}

// 排序结构体类型数据
//void Print_arr(struct Stu arr[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%s：%d ", arr.name, arr.age);
//	}
//	printf("\n");
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//// 用于比较结构体数据中年龄大小的函数，此时两个参数就指向结构体数据
//int cmp_stu_age(const void* p1, const void* p2)
//{
//	// void* 类型的指针不能直接解引用，可通过强制类型转换
//	return (*(struct Stu*)p1).age - (*(struct Stu*)p2).age;
//}
//
//// 测试qsort函数排序结构体数组（以年龄大小为准进行排序）的效果
//void test3()
//{
//	struct Stu arr[] = { {"张三", 20},{"李四", 25},{"王五", 15} };//	结构体数组
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	Print_arr(arr, len);
//	qsort(arr, len, sizeof(arr[0]), cmp_stu_age);
//	Print_arr(arr, len);
//}
//
//int main()
//{
//	test3();
//
//	return 0;
//}

