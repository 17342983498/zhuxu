#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"QuickSort.h"
void TestSort()
{
	int array[] = { 4, 2, 6, 8, 7, 1, 0, 5, 9, 3 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, sizeof(array) / sizeof(array[0]));
	QuickSort(array, 0, size);
	Print(array, sizeof(array) / sizeof(array[0]));

}

void Print(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void QuickSort(int array[], int left,int right)
{
	
	if (right - left>1)
	{
		int div = Partion(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//int Partion(int array[], int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[right - 1];
//	while (begin < end)
//	{
//		while (begin < end && array[begin] <= key)
//		{
//			begin++;
//		}
//		while (begin < end && array[end] >= key)
//		{
//			end--;
//		}
//		if (begin<end)
//		   swap(&array[begin], &array[end]);
//	}
//	swap(&array[begin], &array[right - 1]);
//	return begin;
//}

//ÍÚ¿Ó·¨
int Partion(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			begin++;
		}
		if (begin<end)
		{
			array[end] = array[begin];
			end--;
		}
		while (begin < end && array[end] >= key)
		{
			end--;
		}
		if (begin<end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}

void swap(int* left, int*right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}