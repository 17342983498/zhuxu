#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


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
		return;
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

int isValid(char * s)
{
	int len = strlen(s);
	if (len % 2 == 1)
	{
		return 0;
	}
	Stack ps;
	StackInit(&ps);
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '(')
		{
			StackPush(&ps, ')');
		}
		else if (s[i] == '[')
		{
			StackPush(&ps, ']');
		}
		else if (s[i] == '{')
		{
			StackPush(&ps, '}');
		}
		else if (StackEmpty(&ps) || StackTop(&ps) != s[i])
		{
			return 0;
		}
		else
		{
			StackPop(&s);
		}
	}
	StackDestroy(&ps);
	return 1;
}


void Test()
{
	char arr[6] = "(()){}";
	int ret = isValid(arr);
	printf("%d\n", ret);
}