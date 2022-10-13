#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void reverse(int* left, int* right)
{
	while (left<right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k){
	if (numsSize <= 1)
	{
		return;
	}
	if (k>numsSize)
	{
		k = k%numsSize;
	}
	reverse(nums + numsSize - k, nums + numsSize - 1);
	reverse(nums, nums + numsSize - k - 1);
	reverse(nums, nums + numsSize - 1);
}

int main()
{
	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(arr, 7, 3);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}