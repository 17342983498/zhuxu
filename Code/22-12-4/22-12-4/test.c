#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[mid])
	{
		if (array[mid] < array[right])
			return mid;
		if (array[right] < array[left])
			return left;
		else
			return right;
	}
	else
	{
		if (array[left] < array[right])
			return left;
		if (array[right] < array[mid])
			return mid;
		else
			return right;
	}
}



int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right;
	int midex = GetMiddleIndex(array, left, right);
	int key;
	if (midex != left)
	{
		swap(&array[left], &array[midex]);
	}
	key = array[left];
	while (begin < end)
	{
		while (begin < end&&array[end] >= key)
		{
			--end;
		}
		while (begin < end&&array[begin] <= key)
		{
			++begin;
		}
		swap(&array[begin], &array[end]);
	}
	if (end != left)
	{
		swap(&array[begin], &array[left]);
	}
	return begin;
}

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right;
	int midex = GetMiddleIndex(array, left, right);
	int key;
	if (midex != left)
	{
		swap(&array[left], &array[midex]);
	}
	key = array[left];
	while (begin < end)
	{
		while (begin<end&&array[end]>key)
		{
			--end;
		}
		array[begin] = array[end];
		while (begin<end&&array[begin]<key)
		{
			++begin;
		}
		if (begin != end)
		{
			array[end] = array[begin];
		}
	}
	array[begin] = key;
	return begin;
}


int Partion3(int* array, int left, int right)
{
	int begin = left + 1;
	int end = left;
	int midex = GetMiddleIndex(array, left, right);
	int key;
	if (midex != left)
	{
		swap(&array[left], &array[midex]);
	}
	key = array[left];
	while (begin <= right)
	{
		if (array[begin] < key&&++end != begin)
		{
			swap(&array[begin], &array[end]);
		}
		++begin;
	}
	swap(&array[left], &array[end]);
	return end;
}

void quicksort(int* array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = Partion3(array, left, right);
	quicksort(array, left, div - 1);
	quicksort(array, div + 1, right);
}


void Print(int* array,int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void _MergeSort(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(array, begin, mid, tmp);
	_MergeSort(array, mid+1, end, tmp);

	int left1 = begin, right1 = mid;
	int left2 = mid + 1, right2 = end;
	int i = begin;
	while (left1 <= right1&&left2 <= right2)
	{
		if (array[left1] <= array[left2])
		{
			tmp[i++] = array[left1++];
		}
		else
		{
			tmp[i++] = array[left2++];
		}
	}
	while (left1 <= right1)
	{
		tmp[i++] = array[left1++];
	}
	while (left2 <= right2)
	{
		tmp[i++] = array[left2++];
	}
	memcpy(array + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}


void MergeSort(int* array, int sz)
{
	int* tmp = (int*)malloc(sizeof(int)*sz);
	_MergeSort(array, 0, sz - 1, tmp);
	free(tmp);
	tmp = NULL;
}

int main()
{
	int array[] = { 5, 1, 3, 9, 7, 4, 6, 0, 2, 8 };
	//int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(array) / sizeof(array[0]);
	//quicksort(array, 0, sz-1);
	MergeSort(array,sz);
	Print(array, sz);
	return 0;
}