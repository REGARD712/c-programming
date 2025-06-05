#define _CRT_SECURE_NO_WARNINGS

// 二维数组的传参本质
//#include <stdio.h>
//void test(/*int arr[3][5]*/int(*arr)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", /*arr[i][j]*/*(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5, 2,3,4,5,6, 3,4,5,6,7 };
//	//二维数组的每个元素是一维数组
//	//二维数组的数组名代表首个一维数组的地址
//	//二维数组的所传送的参数就是数组指针，该指针指向首个一维数组：int(*)[5]
//
//	test(arr, 3, 5);
//
//	return 0;
//}

// 结构体类型
//#include <stdio.h>
//
//struct Stu
//{
//	char id[20];
//	char name[20];
//	int age;
//}s3, s4; //全局变量
//
//int main()
//{
//	//局部变量
//	struct Stu s1 = { "0001", "Zhangsan", 20 };
//	struct Stu s2 = { "0002", "Lisi", 19 };
//
//	printf("%s, %s, %d\n", s1.id, s1.name, s1.age);
//	//结构体变量.成员名
//	//结构体指针->成员名
//
//	return 0;
//}
//
// 结构体的特殊声明：匿名结构体类型（只能使用一次）
//#include <stdio.h>
//
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//
//int main()
//{
//
//
//	return 0;
//}
//
// 结构体的自引用：链表
//#include <stdio.h>
//
//typedef struct Node  //节点
//{
//	int data;  //数据域
//	struct Node* next;  //指针域
//}Node;
//
//int main()
//{
//	//struct Node n;
//	Node n;
//
//	return 0;
//}