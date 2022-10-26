#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef char SDataType;


typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;
}Stack;

void StackInit(Stack* ps);

// ��ջ��β��
void StackPush(Stack* ps, SDataType data);

// ��ջ��βɾ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);
