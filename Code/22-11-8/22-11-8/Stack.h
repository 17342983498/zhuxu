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
//初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, SDataType data);

//出栈
void StackPop(Stack* ps);

//给出栈顶元素
SDataType StackTop(Stack* ps);

//获取栈中有效元素个数
int StackSize(Stack* ps);

//检测栈是否为空
int StackEmpty(Stack* ps);

//销毁
void StackDestroy(Stack* ps);

void CheckCapacity(Stack* ps);

void TestStack();