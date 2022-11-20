#define _CRT_SECURE_NO_WARNINGS 1

#include "HeapSort.h"


void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void AdjustDown(HeapDataType array[], int num, int parent)
{
	int child = parent * 2 + 1;
	while (child < num)
	{
		if (child + 1 < num && array[child] < array[child + 1])
		{
			child ++ ;
		}
		if (array[child]>array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapCreat(Heap* h,int arr[],int num)
{
	h->array = (HeapDataType*)malloc(sizeof(HeapDataType)*num);
	memcpy(h->array, arr, sizeof(HeapDataType)*num);
	for (int root = (num - 2) / 2; root >= 0; --root)
	{
		AdjustDown(h->array, num, root);
	}
	int end = num - 1;
	while (end)
	{
		swap(&h->array[0], &h->array[end]);
		AdjustDown(h->array, end, 0);
		end--;
	}
}


void HeapTest()
{
	Heap h;
	int arr[10] = { 5, 4, 3, 9, 7, 6, 1, 2, 8, 0 };
	int num = sizeof(arr) / sizeof(arr[0]);
	HeapCreat(&h, arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", h.array[i]);
	}
	printf("\n");
}