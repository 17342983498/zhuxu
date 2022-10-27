#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//void removeDuplicates(int* arr,int k)
//{
//	int count = 0;
//	for (int i = 1; i < k; i++)
//	{
//		if (arr[i] != arr[count])
//		{
//			arr[++count] = arr[i];
//		}
//	}
//	for (int i = 0; i < k - count; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 1, 1, 2, 3, 3, 4, 4, 5, 6, 6 };
//	int k = sizeof(arr) / sizeof(arr[0]);
//	removeDuplicates(arr,k);
//	return 0;
//}


//int main()
//{
//	int n = 2;
//	int m = 3;
//	int count1 = 0, count2 = 0;
//	while (n--)
//	{
//		count1+=2;
//	}
//	while (m--)
//	{
//		count2+=2;
//	}
//	int count = count1 + count2;
//	printf("%d\n", count);
//	return 0;
//}


int main()
{
	char* s = "abcabcbb";
	int length[1024] = { 0 };
	int count = 0;
	int length = strlen(s);
	for (int i = 0; i<length; i++)
	{
		length[s[i]]++;
	}
	for (int i = 0; i<1024; i++)
	{
		if (length[i] != 0)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}