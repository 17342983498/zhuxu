#define _CRT_SECURE_NO_WARNINGS 1

#include "SelectSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 1, 7, 9, 2,0 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	SelectSort1(array, sizeof(array) / sizeof(array[0]));
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

void SelectSort1(int array[], int size)
{
	for (int i = 0; i < size ; i++)
	{
		int max = 0;
		for (int j = 1; j < size - i ; j++)
		{
			if (array[j]>=array[max])
			{
				max = j;
			}
		}
		if (max != size - i - 1)
		{
			swap(&array[max], &array[size - i - 1]);
		}
	}
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}