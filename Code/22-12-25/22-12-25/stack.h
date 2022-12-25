#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* array;
	int capacity;
	int size;
}Stack;


void StackInit(Stack* s);
void StackPush(Stack* s, STDataType data);
void StackPop(Stack* s);
int StackTop(Stack* s);
bool StackEmpty(Stack* s);
void StackDestroy(Stack* s);
void StackTest();