#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

//void _MergeSort(int array[], int left, int right, int temp[])
//{
//	if (right > left)
//	{
//		int mid = (right + left) / 2;
//		_MergeSort(array, left, mid, temp);
//		_MergeSort(array, mid, right, temp);
//		Merge(array, left, mid, right, temp);
//		memcmp(array + left, temp + left, sizeof(array[0])*(right - left));
//	}
//}
void Merge(int array[], int left, int mid, int right, int temp[])
{
	int p1 = left, p2 = mid, p = left;
	while (p1 < mid && p2 < right)
	{
		if (array[p1] <= array[p2])
			temp[p++] = array[p1++];
		else
			temp[p++] = array[p2++];
	}
	while (p1 < p2)
	{
		temp[p++] = array[p1++];
	}
	while (p2 < right)
	{
		temp[p++] = array[p2++];
	}
}

void MergeSortNor(int array[], int size)
{
	int gap = 1;
	int* temp = (int*)malloc(array[0] * size);
	if (temp == NULL)
		return;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid>size)
				mid = size;
			if (right > size)
				right = size;
			Merge(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(array[0])*size);
		gap *= 2;
	}
	
	free(temp);
}

void TestSort()
{
	int array[] = { 0, 5, 2, 3, 6, 8, 7, 4, 9, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	MergeSortNor(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
}
void PrintSort(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}