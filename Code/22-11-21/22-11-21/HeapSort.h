#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
typedef int HPDataType;
typedef struct Heap

{
	HPDataType* array;
	int size;
	int capacity;
}Heap;



void HeapCreate(Heap* hp, HPDataType* a, int n);

void HeapDestory(Heap* hp);

void HeapPush(Heap* hp, HPDataType x);

void HeapPop(Heap* hp);

void HeapPrint(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void Test();