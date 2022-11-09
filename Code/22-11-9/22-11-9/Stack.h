#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SDataType;

typedef struct Stack
{
	SDataType* array;
	int Capacity;
	int size;
	int data;
}Stack;

void StackInit(Stack* s);

void CheckCapacity(Stack* s);

void StackPush(Stack* s,int data);

void StackPop(Stack* s);

SDataType StackTop(Stack* s);

int StackSize(Stack* s);

bool StackEmpty(Stack* s);

void StackDestory(Stack* s);

void Test();