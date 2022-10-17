#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

////void swap(int* a, int* b)
////{
////	int temp = *a;
////	*a = *b;
////	*b = temp;
////}
//
//Heap_Adjust(int arr[10], int i, int length)
//{
//	int child = 0;
//	int temp = 0;
//	for (temp = arr[i]; 2 * i + 1 < length;i = child)
//	{
//		child = 2 * i + 1;
//		if (arr[child] > arr[child + 1] && child + 1 < length)
//		{
//			child++;
//		}
//		if (temp > arr[child])
//		{
//			arr[i] = arr[child];
//		}
//		else
//			break;
//		arr[child] = temp;
//
//	}
//}
//
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int length = sizeof(arr)/sizeof(arr[0]);
//	for (int i = length / 2 - 1; i >= 0; i--)
//	{
//		Heap_Adjust(arr, i, length);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}







//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//Heap_Adjust(int arr[10], int i, int length)
//{
//	int child = 0;
//	int temp = 0;
//	for (temp = arr[i]; 2 * i + 1 < length; i = child)
//	{
//		child = 2 * i + 1;
//		if (arr[child] > arr[child + 1] && child + 1 < length)
//		{
//			child++;
//		}
//		if (temp > arr[child])
//		{
//			swap(&arr[child], &arr[i]);
//		}
//		else
//			break;
//
//	}
//}
//
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	for (int i = length / 2 - 1; i >= 0; i--)
//	{
//		Heap_Adjust(arr, i, length);
//	}
//	int end = length - 1;
//	while (end)
//	{
//		swap(&arr[0], &arr[end]);
//		printf("%d ", arr[end]);
//		Heap_Adjust(arr, 0, end);
//		end--;
//	}
//	printf("%d\n", arr[0]);
//	return 0;
//}




//void HeapAdjust(int array[], int size, int parent)
//{
//	// 用child标记parent较大的孩子，默认先标记parent的左孩子
//	// 先标记左孩子的原因是：如果parent有孩子，parent一定是先有左孩子，然后才有右孩子
//	int child = parent * 2 + 1;
//
//	while (child < size)
//	{
//		// 找parent中较大的孩子：用parent左右孩子比较
//		// 必须先保证parent的右孩子存在
//		if (child + 1 < size && array[child + 1] > array[child])
//			child += 1;
//
//		// 检测parent是否满足堆的性质
//		if (array[child] > array[parent])
//		{
//			Swap(&array[child], &array[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			return;
//		}
//	}
//}
//
//
//void HeapSort(int array[], int size)
//{
//	int end = size - 1;
//	// 1. 建堆
//	// 注意从倒数第一个非叶子节点的位置开始使用堆调整，一直调整到根节点的位置
//	for (int root = (size - 2) / 2; root >= 0; root--)
//		HeapAdjust(array, size, root);  // 向下调整---时间复杂度：O(logN)
//
//	// 2. 排序--->利用堆删除的思想进行排序
//	while (end)
//	{
//		Swap(&array[0], &array[end]);
//		HeapAdjust(array, end, 0);
//		end--;
//	}
//}



//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//Heap_Adjust(int arr[10], int i, int length)
//{
//	int child = 0;
//	int temp = 0;
//	for (temp = arr[i]; 2 * i + 1 < length; i = child)
//	{
//		child = 2 * i + 1;
//		if (arr[child] > arr[child + 1] && child + 1 < length)
//		{
//			child++;
//		}
//		if (temp > arr[child])
//		{
//			swap(&arr[child], &arr[i]);
//		}
//		else
//			break;
//
//	}
//}
//
////输出前k小的数字
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	for (int i = length / 2 - 1; i >= 0; i--)
//	{
//		Heap_Adjust(arr, i, length);
//	}
//	int end = length - 1;
//	while (k--)
//	{
//		swap(&arr[0], &arr[end]);
//		printf("%d ", arr[end]);
//		Heap_Adjust(arr, 0, end);
//		end--;
//	}
//	return 0;
//}



//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//Heap_Adjust(int arr[10], int i, int length)
//{
//	int child = 0;
//	int temp = 0;
//	for (temp = arr[i]; 2 * i + 1 < length; i = child)
//	{
//		child = 2 * i + 1;
//		if (arr[child] > arr[child + 1] && child + 1 < length)
//		{
//			child++;
//		}
//		if (temp > arr[child])
//		{
//			swap(&arr[child], &arr[i]);
//		}
//		else
//			break;
//
//	}
//}
//
////输出第k小的数字
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	for (int i = length / 2 - 1; i >= 0; i--)
//	{
//		Heap_Adjust(arr, i, length);
//	}
//	int end = length - 1;
//	while (k--)
//	{
//		swap(&arr[0], &arr[end]);
//		Heap_Adjust(arr, 0, end);
//		end--;
//	}
//	printf("%d\n", arr[end+1]);
//	return 0;
//}