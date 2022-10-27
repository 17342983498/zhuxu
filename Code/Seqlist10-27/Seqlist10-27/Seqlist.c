#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)* 5);
	if (ps->a == NULL)
	{
		return;
	}
	ps->capacity = 5;
	ps->size = 0;
}
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SLDateType* array = (SLDateType*)realloc(ps->a,sizeof(SLDateType)* (ps->capacity*2));
		if(array==NULL)
		{
			return;
		}
		ps->a = array;
		ps->capacity *= 2;
	}
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < (ps->size); i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	ps->a[ps->size++] = x;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (int i = 1; i < (ps->size); i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < (ps->size); i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	for (int i = pos + 1; i < (ps->size); i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}


void SeqListTest()
{
	SeqList ps;
	SeqListInit(&ps);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPrint(&ps);

	SeqListPushFront(&ps, 0);
	SeqListPrint(&ps);

	SeqListPopFront(&ps);
	SeqListPrint(&ps);

	SeqListPopBack(&ps);
	SeqListPrint(&ps);

	SeqListInsert(&ps, 1, 6);
	SeqListPrint(&ps);

	SeqListErase(&ps, 1);
	SeqListPrint(&ps);
}