#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Stack.h"
void _MergeSort(int array[], int left, int right, int temp[])
{
	if (right > left)
	{
		int mid = (right + left) / 2;
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		Merge(array, left, mid, right, temp);
		memcmp(array + left, temp + left, sizeof(array[left])*(right - left));
	}
}
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

void  MergeSort(int array[], int size)
{
	int* temp = malloc(sizeof(array[0])*size);
	if (temp == NULL)
		return;
	_MergeSort(array, 0, size, temp);
	free(temp);
}

void TestSort()
{
	int array[] = { 0, 5, 2, 3, 6, 8, 7, 4, 9, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	MergeSort(array, size);
	PrintSort(array, sizeof(array) / sizeof(array[0]));
}
int PrintSort(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
