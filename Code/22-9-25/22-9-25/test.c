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
//	// ��child���parent�ϴ�ĺ��ӣ�Ĭ���ȱ��parent������
//	// �ȱ�����ӵ�ԭ���ǣ����parent�к��ӣ�parentһ�����������ӣ�Ȼ������Һ���
//	int child = parent * 2 + 1;
//
//	while (child < size)
//	{
//		// ��parent�нϴ�ĺ��ӣ���parent���Һ��ӱȽ�
//		// �����ȱ�֤parent���Һ��Ӵ���
//		if (child + 1 < size && array[child + 1] > array[child])
//			child += 1;
//
//		// ���parent�Ƿ�����ѵ�����
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
//	// 1. ����
//	// ע��ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
//	for (int root = (size - 2) / 2; root >= 0; root--)
//		HeapAdjust(array, size, root);  // ���µ���---ʱ�临�Ӷȣ�O(logN)
//
//	// 2. ����--->���ö�ɾ����˼���������
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
////���ǰkС������
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
////�����kС������
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