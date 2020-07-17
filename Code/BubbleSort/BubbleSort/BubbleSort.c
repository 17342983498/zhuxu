#define _CRT_SECURE_NO_WARNINGS 1

#include "BubbleSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 1, 8, 5, 2, 3, 6, 9, 4, 7, 5, 1, 3, 5 };
	print(array, sizeof(array) / sizeof(array[0]));
	BubbleSort(array, sizeof(array) / sizeof(array[0]));
	print(array, sizeof(array) / sizeof(array[0]));
}
void print(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (array[j]>array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}