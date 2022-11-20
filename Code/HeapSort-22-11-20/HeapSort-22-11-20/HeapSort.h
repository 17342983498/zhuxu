#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* array;
	//int capacity;
	//int size;
}Heap;


void HeapInit(Heap* h);

void HeapCreat(Heap* h, int arr[], int num);

void HeapTest();