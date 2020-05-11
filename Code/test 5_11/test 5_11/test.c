#define _CRT_SECURE_NO_WARNINGS 1
//#define N 10
#include<stdio.h>
//int number(int arr[], int k)
//{
//	int i = 0;
//	int sum = 0;
//	int count = 0;
//	for (i = 0; i < k; i++)
//	{
//		printf("请输入成绩:>");
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//	}
//	int ave = 0;
//	ave = sum / k;
//	printf("%d\n", ave);
//	for (i = 0; i < k; i++)
//	{
//		if (arr[i]>0)
//		{
//			if (arr[i] > ave)
//			{
//				count++;
//			}
//		}
//		else
//		{
//			printf("输入结束\n");
//			break;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int arr[N] = { 0 };
//	int n = number(arr, N);
//	printf("%d\n", n);
//	return 0;
//}

//#define SQUARE(X) X*X
//int main()
//{
//	int ch = SQUARE((5 + 1));
//	printf("%d ", ch);
//	return 0;
//}
//#define DOUBLE(x) (x) + (x)
//int main()
//{
//	int a = 5;
//	printf("%d\n", 10 * (DOUBLE(a)));
//	return 0;
//}

//int main()
//{
//	int a[10] = { 0 };
//	int i = 0;
//	printf("请输入十个数字\n");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", a[j]);
//	}
//	printf("%d", a[3]);
//	return 0;
//}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int j = 0;
	for (j = 0; j < 10; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("%d", arr[3]);
	return 0;
}