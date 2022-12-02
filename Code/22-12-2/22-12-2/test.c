#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


int Partion(int* array, int left, int right)
{
	int key = array[left];
	int begin = left;
	int end = right;
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



void quicksort(int* array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = Partion(array, left, right);
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

int main()
{
	int array[] = { 5, 1, 3, 9, 7, 4, 6, 0, 2, 8 };
	int sz = sizeof(array) / sizeof(array[0]);
	quicksort(array, 0, sz-1);
	Print(array, sz);
	return 0;
}