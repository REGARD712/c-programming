#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	int size;		// 记录有效的数据个数
	int capacity;	// 当前的空间大小
}SL;

// 初始化
void SLInit(SL* ps);

// 顺序表的销毁
void SLDestroy(SL* ps);
void SLPrint(SL s);

// 头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);

void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

// 打印
void SLPrint(SL ps);