#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//void InsrtSort(int* array, int sz)
//{
//	for (int i = 1; i < sz; ++i)
//	{
//		for (int j = i; j > 0; --j)
//		{
//			if (array[j] < array[j-1])
//			{
//				Swap(&array[j], &array[j-1]);
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}


void InsrtSort(int* array, int sz)
{
	for (int i = 1; i < sz; ++i)
	{
		int j = i - 1;
		int key = array[i];
		while (j >= 0 && key < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

//void ShellSort(int* array, int sz)
//{
//	int gap = sz;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = gap; i < sz; ++i)
//		{
//			int key = array[i];
//			int j = i - gap;
//			while (j >= 0&&key<array[j])
//			{
//				array[j + gap] = array[j];
//				j -= gap;
//			}
//			array[j + gap] = key;
//		}
//	}
//}


void ShellSort(int* array, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < sz; ++i)
		{
			int key = array[i];
			int j = i - gap;
			while (j >= 0)
			{
				if (key < array[j])
				{
					array[j + gap] = array[j];
				}
				else
				{
					break;
				}
				j -= gap;
			}
			array[j + gap] = key;
		}
	}
}

void AdjustDown(int* array, int root, int sz)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < sz)
	{
		if (child + 1 < sz && array[child + 1] > array[child])
		{
			child += 1;
		}
		if (array[parent] < array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapSort(int* array, int sz)
{
	int root = sz - 2 / 2;
	for (int i = root; i >= 0; --i)
	{
		AdjustDown(array, i, sz);
	}
	for (int i = sz - 1; i > 0; --i)
	{
		Swap(&array[0], &array[i]);
		AdjustDown(array, 0, i);
	}
}


void PrintArray(int* array,int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 5, 7, 1, 2, 9, 3, 6, 8, 4, 0 };
	int sz = sizeof(array) / sizeof(array[0]);
	//InsrtSort(array, sz);
	//ShellSort(array, sz);
	HeapSort(array, sz);
	PrintArray(array, sz);
	return 0;
}