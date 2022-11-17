#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* array;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* h);

void HeapPush(Heap* h, HeapDataType data);

void HeapDstroy(Heap* h);

void Test();