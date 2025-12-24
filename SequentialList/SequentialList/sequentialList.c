#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXN 32

typedef int elemtype;

/* 定义顺序表结构体类型 */
typedef struct SequenList
{
	elemtype data[MAXN];
	int last;
}SequenList;
