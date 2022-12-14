#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <malloc.h>

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


//void QuickSort(int* array, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && array[right] >= array[keyi])
//		{
//			--right;
//		}
//		while (left < right && array[left] <= array[keyi])
//		{
//			++left;
//		}
//		Swap(&array[left], &array[right]);
//	}
//	Swap(&array[left], &array[keyi]);
//	keyi = left;
//	QuickSort(array, begin, keyi - 1 );
//	QuickSort(array, keyi+1, end);
//}


int GetMiddleIndex(int* array, int left,int right)
{
	int mid = (left + right) / 2;
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

//hore
//void QuickSort(int* array, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int left = begin, right = end;
//	int midex = GetMiddleIndex(array, left, right);
//	if (midex != left)
//	{
//		Swap(&array[midex], &array[left]);
//	}
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && array[right] >= array[keyi])
//		{
//			--right;
//		}
//		while (left < right && array[left] <= array[keyi])
//		{
//			++left;
//		}
//		Swap(&array[left], &array[right]);
//	}
//	Swap(&array[left], &array[keyi]);
//	keyi = left;
//	QuickSort(array, begin, keyi - 1 );
//	QuickSort(array, keyi+1, end);
//}


//挖坑法
//void QuickSort(int* array, int begin, int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int left = begin, right = end;
//	int midex = GetMiddleIndex(array, left, right);
//	if (midex != left)
//	{
//		Swap(&array[midex], &array[left]);
//	}
//	int key = array[left];
//	while (left < right)
//	{
//		while (left < right && array[right] >= key)
//		{
//			--right;
//		}
//		if (left != right)
//		{
//			array[left] = array[right];
//		}
//		while (left < right && array[left] <= key)
//		{
//			++left;
//		}
//		if (left != right)
//		{
//			array[right] = array[left];
//		}
//	}
//	array[left] = key;
//	QuickSort(array, begin, left - 1);
//	QuickSort(array, left + 1, end);
//}


//void QuickSort(int* array, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int midex = GetMiddleIndex(array, left, right);
//	if (midex != left) 
//	{
//		Swap(&array[midex], &array[left]);
//	}
//	int key = array[left];
//	int begin = left + 1, end = left;
//	while (begin <= right)
//	{
//		if (array[begin] < key && ++end != begin)
//		{
//			Swap(&array[end], &array[begin]);
//		}
//		++begin;
//	}
//	Swap(&array[end], &array[left]);
//	QuickSort(array, left, end - 1);
//	QuickSort(array, end + 1, right);
//}


int Partion3(int* array, int left, int right)
{
	int midex = GetMiddleIndex(array, left, right);
	if (midex != left) 
	{
		Swap(&array[midex], &array[left]);
	}
	int key = array[left];
	int begin = left + 1, end = left;
	while (begin <= right)
	{
		if (array[begin] < key && ++end != begin)
		{
			Swap(&array[end], &array[begin]);
		}
		++begin;
	}
	Swap(&array[end], &array[left]);
	return end;
}


//int Partion3(int* a, int begin, int end)
//{
//	int mid = GetMiddleIndex(a, begin, end);
//	Swap(&a[begin], &a[mid]);
//
//	int keyi = begin;
//	int prev = begin, cur = begin + 1;
//	while (cur <= end)
//	{
//		// 找到比key小的值时，跟++prev位置交换，小的往前翻，大的往后翻
//		if (a[cur] < a[keyi] && ++prev != cur)
//			Swap(&a[prev], &a[cur]);
//
//		++cur;
//	}
//
//	Swap(&a[prev], &a[keyi]);
//	keyi = prev;
//	return keyi;
//}

//void QuickSort(int* array, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int midex = GetMiddleIndex(array, left, right);
//	if (midex != left)
//	{
//		Swap(&array[midex], &array[left]);
//	}
//	int key = array[left];
//	int begin = left + 1, end = left;
//	while (begin <= right)
//	{
//		if (array[begin] < key)
//		{
//			Swap(&array[++end], &array[begin]);
//		}
//		++begin;
//	}
//	Swap(&array[end], &array[left]);
//	QuickSort(array, left, end - 1);
//	QuickSort(array, end + 1, right);
//}



//void QuickSortNor(int* array, int begin, int end)
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, begin);
//	StackPush(&s, end);
//	while (!StackEmpty(&s))
//	{
//		int right = StackTop(&s);
//		StackPop(&s);
//		int left = StackTop(&s);
//		StackPop(&s);
//		int keyi = Partion3(array, left, right);
//		if (keyi + 1 < right)
//		{
//			StackPush(&s, keyi + 1);
//			StackPush(&s, right);
//		}
//		if (left < keyi - 1)
//		{
//			StackPush(&s, left);
//			StackPush(&s, keyi - 1);
//		}
//	}
//	StackDestroy(&s);
//}


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
		if (array[left1] < array[left2])
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
	int array[] = { 5, 7, 1, 2, 9, 3, 6, 8, 4, 0, 5, 6 };
	int sz = sizeof(array) / sizeof(array[0]);
	//InsrtSort(array, sz);
	//ShellSort(array, sz);
	//HeapSort(array, sz);
	//QuickSort(array, 0, sz - 1);
	//QuickSortNor(array, 0, sz - 1);
	//MergeSort(array,sz);
	MergeSortNor(array, sz);
	PrintArray(array, sz);
	return 0;
}