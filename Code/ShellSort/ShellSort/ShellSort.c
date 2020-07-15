#define _CRT_SECURE_NO_WARNINGS 1


#include "ShellSort.h"
#include<stdio.h>

void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 0, 1 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	ShellSort(array, sizeof(array) / sizeof(array[0]));
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

void ShellSort(int array[], int size)
{
	int gap = 3;
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;
			while (array[end]>key && end >= 0)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}