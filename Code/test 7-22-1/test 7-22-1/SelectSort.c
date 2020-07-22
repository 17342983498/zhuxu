#define _CRT_SECURE_NO_WARNINGS 1

#include "SelectSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 1, 7, 9, 2,0 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	SelectSort(array, sizeof(array) / sizeof(array[0]));
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

void SelectSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = size - 1;
		for (int j = min-1; j >= i; j--)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
		}
	}
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}