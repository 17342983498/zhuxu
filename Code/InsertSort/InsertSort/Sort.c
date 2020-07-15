#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 0, 1 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	InsertSort(array, sizeof(array) / sizeof(array[0]));
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

void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;
		while (array[end]>key && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end+1] = key;
	}
}