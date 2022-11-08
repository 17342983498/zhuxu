#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef char SDataType;

typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;
	int data;
}Stack;
//��ʼ��
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, SDataType data);

//��ջ
void StackPop(Stack* ps);

//����ջ��Ԫ��
SDataType StackTop(Stack* ps);

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);

//����
void StackDestroy(Stack* ps);

void CheckCapacity(Stack* ps);

void TestStack();