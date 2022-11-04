#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void HeapInit(Heap* hp,int InitCap)
{
	assert(hp);
	InitCap > 10 ? InitCap : 10;
	hp->array = (HDataType*)malloc(sizeof(HDataType)* InitCap);
	if (hp->array == NULL)
	{
		return;
	}
	hp->capacity = 10;
	hp->size = 0;
}


void swap(HDataType* a, HDataType* b)
{
	HDataType temp = *a;
	*a = *b;
	*b = temp;
}
void AdjustDown(HDataType* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] < array[child])
		{
			child += 1;
		}
		if (array[parent]>array[child])
		{
			swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapCreat(Heap* hp,int* array,int size)
{
	int root = 0;
	assert(hp);
	HeapInit(hp,size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	for (root = (size - 2)/ 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);
	}
	//for (int i = 0; i < size; i++)
	//{
	//	printf("%d ", hp->array[i]);
	//}
}

void HeapPush(Heap* hp);

void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
	{
		return;
	}
	swap(&hp->array[hp->size - 1], &hp->array[0]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}

HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

void HeapTest()
{
	int array[] = { 3, 5, 9, 4, 6, 1, 7, 2, 8, 0 };
	Heap hp;
	int num = sizeof(array) / sizeof(array[0]);
	HeapCreat(&hp, array, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", hp.array[i]);
	}
	printf("\n");
	printf("%d\n", HeapTop(&hp));

	HeapPop(&hp);
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.array[i]);
	}
	printf("\n");
}