#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack* s)
{
	assert(s);
	s->array = (SDataType*)malloc(sizeof(SDataType)*3);
	if (s->array == NULL)
	{
		return;
	}
	s->Capacity = 3;
	s->size = 0;
}

void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->size == s->Capacity)
	{
		SDataType* arr = (SDataType*)realloc(s->array, sizeof(SDataType)* 2 * (s->Capacity));
		if (arr == NULL)
		{
			assert(0);
			return;
		}
		s->array = arr;
		s->Capacity *= 2;
	}
}

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->size++] = data;
}

void StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		return;
	}
	s->size--;
}

SDataType StackTop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->array[s->size-1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->size;
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->size == 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->Capacity = s->size = 0;
}

void Test()
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
	StackDestory(&s);
}