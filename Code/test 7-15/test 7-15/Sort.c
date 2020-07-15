#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>
void CountSort(int array[], int size)
{
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i]>max)
			max = array[i];
	}
	int count = max - min + 1;
	int* temp = (int*)malloc(sizeof(array[0])*count);
	memset(temp, 0, sizeof(array[0])*count);
	for (int i = 0; i < size; ++i)
	{
		temp[array[i] - min]++;
	}
	int dex = 0;
	for (int i = 0; i < count; ++i)
	{
		while (temp[i]--)
		{
			array[dex++] = i + min;
		}
	}
	free(temp);
}


void TestSort()
{
	int array[] = { 0, 2, 5, 8, 7, 4, 6, 3, 9, 5, 1, 8, 4, 9, 6, 5, 4, 3, 2, 4, 0 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	CountSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
}

void PrintSort(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}