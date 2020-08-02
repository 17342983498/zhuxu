#define _CRT_SECURE_NO_WARNINGS 1

#include"sort.h"
#include<stdio.h>

#if 0
void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 0, 1 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	InsertSort(array, sizeof(array) / sizeof(array[0]));
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
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;
		while (array[end]>key && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
#endif

#if 0
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
void QuickSort(int array[], int left, int right)
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
#endif 

#if 0
void TestSort()
{
	int array[] = { 2,5,6,8,4,1,0,9,3,7 };
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	HeapSort(array, sizeof(array) / sizeof(array[0]));
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
void HeapAdjust(int array[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] > array[child])
			child += 1;
		if (array[child]>array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int array[], int size)
{
	int end = size - 1;
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	while (end)
	{
		swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}
#endif

#if 0
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
		for (int j = 0; j < size - i - 1; j++)
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
#endif

#if 0
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
	//int gap = 3;
	int gap = size;
	//while (gap>0)
	while (gap>1)
	{
		gap = gap / 3 + 1;
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
		//gap--;
	}
}
#endif

void SelectSort1(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int maxpos = 0;
		for (int j = 1; j < size - i; j++)
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

//#if 0
void TestSort()
{
	int array[] = { 2, 5, 8, 3, 5, 6, 4, 8, 5, 1, 7, 9, 2, 0 };
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
//#endif