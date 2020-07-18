#define _CRT_SECURE_NO_WARNINGS 1

#include "HeapSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2,5,6,8,4,1,0,9,3,7 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
}

void PrintSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void HeapSort(int array[], int size)
{
	int end = size - 1;
	for (int root = size - 2 / 2; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	while (end)
	{
		swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

void HeapAdjust(int array[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (array[child] < array[child + 1] && child+1 < size)
		{
			child += 1;
		}
		if (array[child]>array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
	
	

}

void swap(int* parent, int* child)
{
	int temp = *parent;
	*parent = *child;
	*child = temp;
}