#define _CRT_SECURE_NO_WARNINGS 1

#include "SelectSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 1, 7, 9, 2,0 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	SelectSort1(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	SelectSort2(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	SelectSortOP(array, sizeof(array) / sizeof(array[0]));
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
	for (int i = 0; i < size; i++)
	{
		int maxpos = 0;
		for (int j = 1; j < size - i ; j++)
		{
			if (array[j]>array[maxpos])
				maxpos = j;
		}
		if (maxpos != size - i - 1)
			swap(&array[maxpos], &array[size - i - 1]);
	}
}
 
void SelectSort2(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int minpos = size - 1;
		for (int j = minpos - 1; j >= 0; j--)
		{
			if (array[minpos]>array[j])
				minpos = j;
		}
		if (minpos != 0)
		{
			swap(&array[minpos], &array[0]);
		}
	}
}

void SelectSortOP(int array[], int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int minpos = begin;
		int maxpos = begin;
		int j = begin + 1;
		while (j <= end)
		{
			if (array[j]>array[maxpos])
				maxpos = j;
			if (array[j] < array[minpos])
				minpos = j;
			j++;
		}
		if (maxpos != end)
			swap(&array[maxpos], &array[end]);
		/*if (minpos = end)
			minpos = maxpos;*/
		if (minpos != begin)
			swap(&array[minpos], &array[begin]);
		end--;
		begin++;
	}
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}