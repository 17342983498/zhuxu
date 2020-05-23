#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void rotate(int* nums, int numsSize, int k)
//{
//	int i = 0;
//	if (k > numsSize)
//	{
//		k %= numsSize;
//	}
//	for (i = numsSize- k; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	for (i = 0; i < numsSize - k; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}
//int main()
//{
//	int nums[10] = { 0, 1, 2, 3, 4, 5, 6,7,8,9};
//	rotate(nums, 10, 5);
//	return 0;
//}
void rotate(int* nums, int numsSize, int k)
{
	if (k > numsSize)
	{
		k %= numsSize;
	}
	int right = numsSize;
	int left = 0;
	int i = 0;
	int j = numsSize - k;
	int m = numsSize - k;
	int n = numsSize;
	while (i < j)
	{   
		int tmp = 0;
		tmp = nums[i];
		nums[i] = nums[j-1];
		nums[j-1] = tmp;
		i++;
		j--;
	}
	while (m < n)
	{
		int tmp = 0;
		tmp = nums[m];
		nums[m] = nums[n-1];
		nums[n-1] = tmp;
		n--;
		m++;
	}
	while (left< right)
	{
		int tmp = 0;
		tmp = nums[left];
		nums[left] = nums[right-1];
		nums[right-1] = tmp;
		left++;
		right--;
	}
}
int main()
{
	int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	rotate(nums, 10, 15);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}