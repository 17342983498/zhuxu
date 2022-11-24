#define _CRT_SECURE_NO_WARNINGS 1

#include "HeapSort.h"

void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}


void AdjustDown(Heap* hp, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&hp->array[child] < hp->array[child + 1])
		{
			child += 1;
		}
		if (hp->array[child]>hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->array == NULL)
	{
		return;
	}
	memcpy(hp->array, a, sizeof(HPDataType)*n);
	hp->size = hp->capacity = n;
	for (int root = (n - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, n, root);
	}
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->array[i]);
	}
	printf("\n");
}


void HeapSort(Heap* hp)
{
	assert(hp);
	int size = hp->size;
	while (size)
	{
		Swap(&hp->array[0], &hp->array[size-1]);
		AdjustDown(hp, --size, 0);
	}
}

void Test()
{
	int array[] = { 3, 6, 9, 1, 5, 2, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, 10);
	HeapPrint(&hp);
	HeapSort(&hp);
	HeapPrint(&hp);
}