#define _CRT_SECURE_NO_WARNINGS 1

#include "SelectSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 8, 3, 5, 6, 4, 8, 1, 7, 9, 2, 0 };
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
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		int j = begin + 1;
		while (j <= end)
		{ 
			if (array[j] > array[max])
				max = j;
			if (array[j] < array[min])
				min = j;
			++j;
		}
		if (min != begin)
		{
			swap(&array[min], &array[begin]);
		}
		if (min == end)
		{
			min = max;
		}
		
		if (max != end)
		{
			swap(&array[max], &array[end]);
		}
		++begin;
		--end;
	}
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}