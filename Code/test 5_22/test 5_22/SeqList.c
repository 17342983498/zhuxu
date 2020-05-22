#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

//初始化
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 3 ? 3 : initCapacity;
	s->arr = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (s->arr == NULL)
		return ;
	s ->size = 0;
	s->capacity = initCapacity;
}

//检查是否需要扩容
int SeqListCheck(SeqList* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newcapacity = s->capacity * 2;
		s->arr = realloc(s->arr,sizeof(SDataType)*newcapacity);
		if (s->arr == NULL)
			return 0;
		s->capacity = newcapacity;
		printf("扩容成功\n");
	}
	return 1;
}

//尾插
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//再插入之前保证还有空间
	if (!SeqListCheck(s))
		return;
	/*if (s->size > s->capacity)
		SeqListExpcapacity(s);*/
	s->arr[s->size] = data;
	s->size++;
}

//尾删
void SeqListPopBack(SeqList* s)
{
	assert(s);
	if (SeqListEmpty(s))
		return;
	s->size--;
}

//头插
void SeqListPushFront(SeqList* s, SDataType data)
{
	assert(s);
	if (!SeqListCheck(s))
		return;
	for (int i = s->size-1; i >= 0; i--)
	{
		s->arr[i+1] = s->arr[i];
	}
	s->arr[0] = data;
	s->size++;
}

//头删
void SeqListInitPopFront(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size-1; i++)
	{
		s->arr[i] = s->arr[i+1];
	}
	s ->size--;
}

//任意位置的删除
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	for (int i = pos + 1; i < s->size; i++)
	{
		s->arr[i-1] = s->arr[i];
	}
	s->size--;
}

//任意位置的插入
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	if (!SeqListCheck(s))
		return;
	for (int i = s->size - 1; i >= pos; i--)
	{
		s->arr[i + 1] = s->arr[i];
	}
	s->arr[pos] = data;
	s->size++;
}

//容量
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//检测顺序表是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//查找值为data的元素是否在顺序表中,若在，返回其下标，若不在，返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		if (s->arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}

//销毁
void SeqListDestroy(SeqList* s)
{
	assert(s);
	free(s->arr);
	s->arr = NULL;
	s->size = 0;
	s->capacity = 0;
}


void SeqListPrint(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
		printf("%d ", s->arr[i]);
	printf("\n");
}

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	printf("当前顺序表中存在%d个数\n",SeqListSize(&s));//6
	SeqListPrint(&s);//1 2 3 4 5 6
	
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("当前顺序表中存在%d个数\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 2 3 4

	SeqListPushFront(&s, 0);
	printf("当前顺序表中存在%d个数\n", SeqListSize(&s));//5
	SeqListPrint(&s);//0 1 2 3 4 

	SeqListInitPopFront(&s);
	printf("当前顺序表中存在%d个数\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 2 3 4

	SeqListErase(&s, 2);
	printf("当前顺序表中存在%d个数\n", SeqListSize(&s));//3
	SeqListPrint(&s);//1 2 4

	SeqListInsert(&s, 1, 3);
	printf("当前顺序表中存在%d个数\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 3 2 4

	SeqListDestroy(&s);  
}