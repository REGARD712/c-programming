#include "SeqList.h"

// 顺序表的初始化
void SLInit(SL* ps) 
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

// 顺序表的销毁
void SLDestroy(SL* ps)
{
	if (ps->arr != NULL)
	{
		free(ps->arr);
	}

	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

// 打印
void SLPrint(SL ps)
{
	for (int i = 0; i < ps.size; i++)
	{
		printf("%d ", ps.arr[i]);
	}
	printf("\n");
}

// 扩容函数
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		// 空间不申请成功
		if (temp == NULL)
		{
			perror("realloc failed to expand!");
			exit(1);
		}
		//  空间申请成功
		ps->arr = temp;
		ps->capacity = newCapacity;
	}
}

// 尾插
void SLPushBack(SL* ps, SLDataType x)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 扩容
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

// 头插
void SLPushFront(SL* ps, SLDataType x)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 扩容
	SLCheckCapacity(ps);
	// 从后往前挪其余元素
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	// 插入新元素
	ps->arr[0] = x;
	ps->size++;
}

// 尾删
void SLPopBack(SL* ps)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 判断顺序表是否为空
	assert(ps->size);
	ps->size--;
}

// 头删
void SLPopFront(SL* ps)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 判断顺序表是否为空
	assert(ps->size);
	// 从前往后开始把元素往前挪
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// 在指定位置插入元素
void SLInsert(SL* ps, int pos, SLDataType x)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 判断顺序表是否为空
	assert(ps->size);
	// 检查pos的合法性
	assert(pos >= 0 && pos <= ps->size);
	// 检查顺序表是否已满
	SLCheckCapacity(ps);
	// 挪动元素
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

// 在指定位置删除元素
void SLErase(SL* ps, int pos)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 判断顺序表是否为空
	assert(ps->size);
	// 检查pos的合法性
	assert(pos >= 0 && pos < ps->size);
	// 从前往后挪动元素
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// 查找指定元素并返回下标
int SLFind(SL* ps, SLDataType x)
{
	// 判断传入的地址是否为空
	assert(ps);
	// 判断顺序表是否为空
	assert(ps->size);
	// 遍历顺序表
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}