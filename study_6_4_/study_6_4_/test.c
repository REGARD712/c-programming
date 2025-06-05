#define _CRT_SECURE_NO_WARNINGS

// 二级指针
//#include <stdio.h>
//
//int main()
//{
//	int a = 10;
//	printf("a = %d\n", a);
//	int* pa = &a; //一级指针
//	int** ppa = &pa; //二级指针
//	//int后第一颗星号表示该指针指向的对象的类型是int*，第二颗星号表示ppa是指针变量
//
//	//如何通过ppa找到a？
//	//*ppa找到pa，再一次解引用就可以找到a
//	*(*ppa) = 200; //此操作将200赋值给a（由ppa经过两次解引用找到）
//
//	printf("a = %d\n", **ppa);
//
//	return 0;
//}

// 指针数组：存放指针类型变量的数组
//#include <stdio.h>
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[] = { &a, &b, &c }; //用指针数组存放三个变量的地址
//	
//
//	return 0;
//}
//
// 使用指针数组模拟二维数组
//#include <stdio.h>
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	//把三个一维数组整合成一个二维数组
//	int* arr[] = { arr1, arr2, arr3 }; //用指针数组存放三个一维数组的首元素地址，arr即为二维数组
//	//下标：         0     1     2
//	//根据一维数组的首元素地址，可以找到后续的所有元素
//
//	//打印二维数组的所有内容
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

// 字符指针变量
//#include <stdio.h>
//
//int main()
//{
//	/*char s[] = "abcedf";
//	char* ps = s;*/
//
//	//const char* ps = "abcdef"; //该字符指针的值是常量字符串，不允许被修改
//	////ps存放的是常量字符串首字符'a'的地址
//	////为了防止手误修改了ps，一般在char*前面加上const
//	//printf("%c\n", *ps);
//	//printf("%s\n", ps);  //打印字符串时需要字符串首字符的地址，无需解引用
//
//	return 0;
//}

// 小题目：
//#include <stdio.h>
//
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//
//	if (str1 == str2)  //比较的是两个数组首元素的地址；若比较两个字符数组的内容，需要使用strcmp()
//	{
//		printf("str1 and str2 are same.\n");
//	}
//	else
//	{
//		printf("str1 and str2 are not same.\n");
//	}
//	//由于str1和str2是两个不同的数组（即使内容相同），所用的内存空间也不同，故数组首元素的地址也不同
//
//	if (str3 == str4)  //str3和str4是字符指针，都指向了常量字符串（内存空间一致）
//	{
//		printf("str3 and str4 are same.\n");
//	}
//	else
//	{
//		printf("str3 and str4 are not same.\n");
//	}
//
//	return 0;
//}

// 数组指针变量：指向数组的指针类型变量，存放的是整个数组的地址
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;	//数组指针变量，区分：int* p[10](指针数组)
//  //类型是：int(*)[10]
// 
//	return 0;
//}

// 使用数组指针打印数组内容
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;	//数组指针变量，区分：int* p[10](指针数组)
//	//类型是：int(*)[10]
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);	//对p解引用后找到数组arr，访问数组元素需要下标
//		printf("%d ", p[i]);	//* &arr[i]：*与&抵消
//	}
//
//	return 0;
//}