#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void _MergeSort(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(array, begin, mid, tmp);
	_MergeSort(array, mid + 1, end, tmp);
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
}

void Print(int* array, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void MergeSortNonR(int* array, int sz)
{
	int* tmp = (int*)malloc(sizeof(int)*sz);
	int rangeN = 1;
	while (rangeN < sz)
	{
		for (int i = 0; i < sz; i += rangeN * 2)
		{
			int left1 = i, right1 = i + rangeN - 1;
			int left2 = i + rangeN, right2 = i + rangeN * 2 - 1;
			if (right1 >= sz)
			{
				break;
			}
			else if (left2 >= sz)
			{
				break;
			}
			else if (right2 >= sz)
			{
				right2 = sz - 1;
			}
			int j = i;
			while (left1 <= right1&&left2 <= right2)
			{
				if (array[left1] <= array[left2])
				{
					tmp[j++] = array[left1++];
				}
				else
				{
					tmp[j++] = array[left2++];
				}
			}
			while (left1 <= right1)
			{
				tmp[j++] = array[left1++];
			}
			while (left2 <= right2)
			{
				tmp[j++] = array[left2++];
			}
			memcpy(array + i, tmp + i, sizeof(int)*(right2 - i + 1));
		}
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}

int main()
{
	int array[] = { 5, 1, 3, 9, 10, 7, 4, 6, 0, 2, 8 };
	//int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(array) / sizeof(array[0]);

	MergeSort(array,sz);
	Print(array, sz);
	MergeSortNonR(array, sz);
	Print(array, sz);
	return 0;
}