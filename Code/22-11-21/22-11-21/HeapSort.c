#define _CRT_SECURE_NO_WARNINGS 1

#include "HeapSort.h"

void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}


void AdjustDown(Heap* hp,int n,int parent)
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

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->capacity = hp->size = 0;
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		int newCapacity = hp->capacity + 3;
		HPDataType* temp = (HPDataType*)realloc(hp->array,sizeof(HPDataType)* newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}

void AdjustUP(Heap* hp, int child)
{
	assert(hp);
	int parent = (child - 1) / 2;
	while (child)
	{
		if (hp->array[child]>hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			return;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->size++] = x;
	AdjustUP(hp, hp->size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->size-1]);
	hp->size--;
	AdjustDown(hp, hp->size, 0);
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

HPDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

int HeapSize(Heap* hp)
{
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

void Test()
{
	int array[] = { 3, 6, 9, 1, 5, 2, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, 10);
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HPDataType top = HeapTop(&hp);
	printf("堆顶元素：%d\n", top);
	int size = HeapSize(&hp);
	printf("堆元素个数：%d\n", size);
}