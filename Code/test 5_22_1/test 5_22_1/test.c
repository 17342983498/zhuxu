#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

// ԭ���Ƴ����������е�Ԫ��val
//int removeElement(int* nums, int numsSize, int val)
//{
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == val)
//			count++;
//		else
//			nums[i - count] = nums[i];
//	}
//	return numsSize-count;
//}
//int main()
//{
//	int arr[] = { 1, 2, 2, 3, 4, 2, 3, 5 };
//	int i = 0;
//	int j = removeElement(arr,8,2);
//	printf("%d\n", j);
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

// ɾ�����������е��ظ��
int removeDuplicates(int* nums, int numsSize)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[j] == nums[i])
			count++;
		else
		{
			nums[i - count] = nums[i];
			j++;
		}
	}
	return numsSize - count;
}
int main()
{
	int arr[] = { 1, 1, 1, 2, 2, 3, 4, 4, 5, 6 };
	int j = removeDuplicates(arr,10);
	int i = 0;
	printf("%d\n", j);
	for (i = 0; i < j; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}