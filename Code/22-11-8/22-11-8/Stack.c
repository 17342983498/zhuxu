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

// ��ջ��β��
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size++] = data;

}
// ���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// ��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return NULL;
	}
	return ps->array[ps->size - 1];
}

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// ����ջ
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
