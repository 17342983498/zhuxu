#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
typedef int HDataType;

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
}Heap;

void HeapInit(Heap* hp,int InitCap);

void HeapCreat(Heap* hp, int* array, int size);

void HeapPush(Heap* hp);

void HeapPop(Heap* hp);

HDataType HeapTop(Heap* hp);

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);

void HeapDestroy(Heap* hp);

void HeapTest();