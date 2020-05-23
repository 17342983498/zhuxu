#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<string.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int size = ASize > 5 ? ASize + 1 : 6;
	int* ret = calloc(size, sizeof(int));
	int num = size - 1;
	int total=0;
	while (ASize > 0)
	{
		K += A[ASize - 1];
		ret[num--] = K % 10;
		K /= 10;
		total++;
		ASize--;
	}
	while (K > 0)
	{
		ret[num--] = K % 10;
		K /= 10;
		total++;
	}
	if (total < size)
	{
		memmove(ret, ret + (size - total), total*sizeof(int));
	}
	*returnSize = total;
	return ret;
}
int main()
{
	int A[4] = { 1, 2, 3, 0 };
	int total = 0;
	int* returnSize = &total;
	int* ret = (int *)addToArrayForm(A, 4, 2541, returnSize);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");
	printf("%d\n", *returnSize);
	return 0;
}
