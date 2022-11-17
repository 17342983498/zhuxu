#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(Heap* h)
{
	h->array = (HeapDataType*)malloc(sizeof(HeapDataType)* 4);
	if (h->array==NULL)
	{
		perror("Init fail\n");
	}
	h->capacity = 4;
	h->size = 0;
}



//void HeapInit(Heap* h)
//{
//	h->array = NULL;
//	h->capacity = 0;
//	h->size = 0;
//}

void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustUp(HeapDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (array[parent] < array[child])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(Heap* h, HeapDataType data)
{
	assert(h);
	if (h->capacity == h->size)
	{
		//int newCapacity = h->capacity == 0 ? 4 : h->capacity * 2;
		int newCapacity = h->capacity * 2;
		HeapDataType* temp = (HeapDataType*)realloc(h->array, sizeof(HeapDataType)*newCapacity);
		if (temp == NULL)
		{
			return;
		}
		h->array = temp;
		h->capacity = newCapacity;
	}
	h->array[h->size] = data;
	h->size++;
	AdjustUp(h->array, h->size - 1);
}



void AdjustDown(HeapDataType* array, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (array[child] < array[child + 1] && child + 1 < n)
		{
			child += 1;
		}
		if (array[child]>array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent=child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapPop(Heap* h)
{
	assert(h);
	assert(h->size > 0);

	Swap(&h->array[0], &h->array[h->size - 1]);
	h->size--;

	AdjustDown(h->array, h->size, 0);
}

void HeapPrint(Heap* h)
{
	assert(h);
	for (int i = 0; i < h->size; ++i)
	{
		printf("%d ", h->array[i]);
	}
	printf("\n");
}

void HeapDestroy(Heap* h)
{
	assert(h);
	free(h->array);
	h->array = NULL;
	h->size = h->capacity = 0;
}
void Test()
{
	Heap h;
	HeapInit(&h);
	HeapPush(&h, 3);
	HeapPush(&h, 5);
	HeapPush(&h, 0);
	HeapPush(&h, 1);
	HeapPush(&h, 6);
	HeapPush(&h, 4);
	HeapPush(&h, 7);
	HeapPush(&h, 2);
	HeapPrint(&h);
	HeapPop(&h);
	HeapPrint(&h);
	HeapDestroy(&h);
}