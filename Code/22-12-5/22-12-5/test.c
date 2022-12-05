#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void Sort(int* array, int begin, int end)
{
	int key = begin;
	int cur = begin + 1;
	int right = end;
	if (begin >= end)
	{
		return;
	}
	while (cur <= right)
	{
		if (array[cur] < array[key])
		{
			Swap(&array[cur], &array[key]);
			key++;
			cur++;
		}
		else if (array[cur] == array[key])
		{
			cur++;
		}
		else
		{
			Swap(&array[cur], &array[right]);
			right--;
		}
	}
	Sort(array, 0, key - 1);
	Sort(array, cur, end);
}

void arrayPrint(int* array, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 5, 3, 6, 9, 7, 1, 6, 5, 2, 5, 4, 6, 8, 2, 5, 6 };
	Sort(array, 0, sizeof(array) / sizeof(array[0])-1);
	arrayPrint(array, sizeof(array) / sizeof(array[0]));
	return 0;
}