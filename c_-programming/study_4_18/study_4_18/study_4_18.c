#define _CRT_SECURE_NO_WARNINGS

// 刷题
// 
//#include<stdio.h>
//
//int main()
//{
//	char a[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int len = sizeof(a) / sizeof(a[0]);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", a[i]);
//	}
//
//	return 0;
//}

// 格式化输入输出
// 通过scanf函数的%m格式控制可以指定输入域宽，
// 输入数据域宽（列数），按此宽度截取所需数据
// 通过printf函数的%0格式控制符，
// 输出数值时指定左面不使用的空位置自动填0
//#include <stdio.h>
//
//int main() {
//    int year, month, date;
//    scanf("%4d%2d%2d", &year, &month, &date);
//
//    if (year >= 1990 && year <= 2015 && month >= 1 && month <= 12 && date >= 1 && date <= 30)
//        printf("year=%d\nmonth=%02d\ndate=%02d\n", year, month, date);
//
//    return 0;
//}

// 移位运算实现2的n次方计算
// 移位运算就是将数据的二进制数向左移动，得到新的数，但该数据不变
//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int r = 1 << n;
//	printf("%d\n", r);
//
//	return 0;
//}

// 按照格式输入并交换值，然后输出
//#include <stdio.h>
//
//int main() {
//    int a, b;
//    int* p1, * p2;//指针变量
//    p1 = &a;
//    p2 = &b;
//    scanf("a=%d,b=%d", &a, &b);
//    printf("a=%d,b=%d", *p2, *p1);
//
//    return 0;
//}

// 计算三角形的周长和面积
//#include <stdio.h>
//#include<math.h>
//
// 判断能否构成三角形
//int Istriangle(int a, int b, int c)
//{
//    if (a + b > c && a + c > b && b + c > a)
//    {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    int a = 0;
//    int b = 0;
//    int c = 0;
//
//    scanf("%d%d%d", &a, &b, &c);
//    if (Istriangle(a, b, c))
//    {
//        double cir = 0.0;
//        double s = 1.0;
//        double p = 0.0;
//        cir = a + b + c;
//        p = cir / 2.0;
//        // 利用海伦公式求面积
//        s = sqrt(p * (p - a) * (p - b) * (p - c));
//        printf("circumference=%.2lf area=%.2lf\n", cir, s);
//    }
//
//    return 0;
//}

// 笔记

//#include<stdio.h>
//
// 数组作为形参时，不会创造另一个数组，即实参和形参是同一个元素
//void set_a(int a[], int len)// 形参的定义不能只定义数组名
//{
//	for (int i = 0; i < len; i++)
//	{
//		a[i] = -1;
//	}
//}
//
//void print_a(int a[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = sizeof(a) / sizeof(a[0]);
//
//	print_a(a, len);
//
//	// 数组传参数（实参）只需要数组名和数组的元素个数
//	set_a(a, len);// 写一个函数把数组中元素的值全部改为-1
//	print_a(a, len);// 写一个函数打印数组
//
//	return 0;
//}


// 二维数组传实参时，需要传数组名、行数和列数
//#include<stdio.h>
//
//void print_a2(int a[3][5], int r, int c)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a[3][5] = { {1,2,3}, { 2,3,4,5}, { 3,4,5,6,7} };
//	// 写一个函数打印二维数组
//	print_a2(a, 3, 5);
//
//	return 0;
//}


// 函数的嵌套调用和链式访问（直接打印函数的返回值）

// 写一个程序，判断输入的月份有多少天
//#include<stdio.h>
//#include<stdbool.h>
//
//bool Is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int the_day_of_month(int y, int m)
//{
//	int dates[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	// 判断平闰年
//	
//	if (Is_leap_year(y) && (m == 2))
//	{
//		d += 1;
//	}
//	return d;
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//
//	scanf("%d%d", &year, &month);
//	int day = the_day_of_month(year, month);
//
//	return 0;
//}


// strlen函数的返回值和sizeof一样都是size_t类型（无符号整型）
// 可以用%zd和%zu来格式化打印

// printf函数返回值是打印的字符个数

// 函数的声明中，形参的变量名字可以省略

// 企业中开发会把代码拆分放到多个文件中/多文件操作
// 以加法运算函数Add()为例：add.h中放函数声明，add.c放函数定义
// 主文件调用#include"add.h"即可使用函数
// extern关键字声明外部文件的函数
// 静态库

// （局部变量和全局变量）作用域和生命周期

// static和extern

// static可以修饰局部变量、全局变量和函数
// 加了static的语句不会被多次执行,只会在编译时执行（延长变量的生命周期）

// 内存的三个区域：
// 栈区（局部变量和函数参数）、堆区（动态内存管理）和静态区（全局变量和静态变量）
// static修饰局部变量的本质就是改变了变量的存储类型（存储位置）：
// 栈区 ——> 静态区

// 可以使用extern声明外部全局变量
// extern 类型 变量名字

// 若在外部文件中用static修饰了全局变量，则无法使用该全局变量
// 其原因是：全局变量的外部链接属性被改成了内部链接属性

// static修饰函数：
// 函数默认是有外部链接属性，与全局变量相似
// 使用static修饰后，会和全局变量一样，变成内部链接属性
















