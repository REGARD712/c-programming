#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 定义seqList结构体
struct seqList {
	int arr[10];	// 数组
	int usedSize;	// 统计数组中的元素个数
};

//  使用尾插法添加元素
void add(int data)
{
	if (isFull())
		expand();
}

int isFull()