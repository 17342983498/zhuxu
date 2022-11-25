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

void Test();