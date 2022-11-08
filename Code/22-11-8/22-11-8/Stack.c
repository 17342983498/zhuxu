#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	ps->capacity = 10;
	ps->size = 0;
}
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SDataType* arr = (SDataType*)realloc(ps->array, sizeof(SDataType)* (ps->capacity) * 2);
		if (arr == NULL)
		{
			return;
		}
		ps->array = arr;
		ps->capacity *= 2;
	}
}

// 入栈：尾插
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size++] = data;

}
// 检测栈是否为空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// 出栈：尾删
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

// 获取栈顶元素
SDataType StackTop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return NULL;
	}
	return ps->array[ps->size - 1];
}

// 获取栈中有效元素的个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
	ps->array = NULL;
}
int isValid(char* s){
	Stack ps;
	StackInit(&ps);
	while (*s)
	{
		if (*s == '(')
		{
			StackPush(&ps, ')');
		}
		else if (*s == '[')
		{
			StackPush(&ps, ']');
		}
		else if (*s == '{')
		{
			StackPush(&ps, '}');
		}
		else if (StackEmpty(&ps) || (StackTop(&ps) != *s))
		{
			StackDestroy(&ps);
			return 0;
		}
		else
		{
			StackPop(&ps);
		}
		s++;
	}
	if (StackEmpty(&ps))
	{
		StackDestroy(&ps);
		return 0;
	}
	StackDestroy(&ps);
	return 1;

}

void TestStack()
{
	char* s = "()";
	int ret = isValid(s);
}
