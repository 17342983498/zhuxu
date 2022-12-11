#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	if (NULL == ps->array)
	{
		assert(ps);
		return;
	}
	ps->capacity = 10;
	ps->size = 0;
}

//入栈
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size++] = data;
}

//出栈
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}

//给出栈顶元素
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty (ps));
	return ps->array[ps->size - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

//检测栈是否为空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

//销毁
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//扩容
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SDataType* tmp = (SDataType*)malloc(sizeof(SDataType)*ps->size* 2);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		memcpy(tmp, ps->array, sizeof(SDataType)*ps->size);
		free(ps->array);
		ps->array = tmp;
		ps->capacity *= 2;
	}
}
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackDestroy(&s);
}