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

// 入栈：尾插
void StackPush(Stack* ps, SDataType data);

// 出栈：尾删
void StackPop(Stack* ps);

// 获取栈顶元素
SDataType StackTop(Stack* ps);

// 获取栈中有效元素的个数
int StackSize(Stack* ps);

// 检测栈是否为空
int StackEmpty(Stack* ps);

// 销毁栈
void StackDestroy(Stack* ps);
