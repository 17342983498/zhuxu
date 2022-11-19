#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"



void StackInit(Stack* s)
{
	assert(s);
	s->array = (STDataType*)malloc(sizeof(STDataType)* 5);
	if (s->array == NULL)
	{
		return;
	}
	s->capacity = 5;
	s->size = 0;
}

void StackCheckCap(Stack* s)
{
	assert(s);
	if (s->capacity == s->size)
	{
		int newCap = s->capacity * 2;
		STDataType* array = (STDataType*)realloc(s->array,sizeof(STDataType)* newCap);
		if (array == NULL)
		{
			return;
		}
		s->array = array;
		s->capacity = newCap;
	}
}

void StackPush(Stack* s, STDataType data)
{
	assert(s);
	StackCheckCap(s);
	s->array[s->size] = data;
	s->size++;
}
void StackPop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	s->size--;
}
int StackTop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	int n = s->size - 1;
	return s->array[n];
}
bool StackEmpty(Stack* s)
{
	assert(s);
	return s->size == 0;
}
void StackDestroy(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->capacity = s->size = 0;
}

void StackTest()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	int ret = StackTop(&s);
	printf("%d\n", ret);
	StackPop(&s);
	ret = StackTop(&s);
	printf("%d\n", ret);
	StackDestroy(&s);
}