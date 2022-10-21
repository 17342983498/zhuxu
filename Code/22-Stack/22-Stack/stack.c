#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"



void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType)* 5);
	ps->capacity = 5;
	ps->size = 0;
}


void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SDataType* arr = (SDataType*)realloc(ps->array, sizeof(SDataType)* (ps->capacity)*2);
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

// ��ջ��βɾ
void StackPop(Stack* ps)
{
	assert(!StackEmpty(ps));
	ps->size--;
}

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size-1];
}

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// ���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
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

void Print(Stack* ps)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		printf("%d ", ps->array[i]);
		i++;
	}
	printf("\n");
}
void test()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 0);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	Print(&ps);
	StackPop(&ps);
	Print(&ps);
	int ret = StackTop(&ps);
	printf("%d\n", ret);
	ret = StackSize(&ps);
	printf("%d\n", ret);
}