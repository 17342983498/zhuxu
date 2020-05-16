#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int div(int arr[], int k, int size)
//{
//	int left = 0;
//	int right = size - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] == k)
//		{
//			return mid;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int k = 0;
//	scanf("%d", &k);
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int m = div(arr, k, size);
//	if (m == -1)
//	{
//		printf("没有找到该数字\n");
//	}
//	else
//	{
//		printf("%d\n", m);
//	}
//	return 0;
//}

//递归实现，效率低
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = Fib(n);
//	printf("%d", num);
//	return 0;
//}

//迭代实现
//int Fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//	{
//		int first = 1;
//		int second = 1;
//		int tmp = 0;
//		int i = 0;
//		for (i = 0; i < n - 2; i++)
//		{
//			tmp = first + second;
//			first = second;
//			second = tmp;
//		}
//		return tmp;
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = Fib(n);
//	printf("%d\n", num);
//	return 0;
//}

//循环左移字符串
#include<string.h>
int main()
{
	char arr[1024]="HELLO WORLD!";
	int i = 0;
	int n = 0;
	int num = strlen(arr);
	scanf("%d", &n);
	if (n > num)
	{
		n %= num;
	}
	for (i = n; i < num; i++)
	{
		printf("%c", arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
	return 0;
}



//int main()
//{
//	int num = 0;
//	char arr[1024];
//	int i = 0;
//	int n = 0;
//	char c;
//	while ((c = getchar()) != '\n')
//	{
//		num++;
//		arr[i++] = c;
//	}
//	scanf("%d", &n);
//	if (n > num)
//	{
//		n %= num;
//	}
//	for (i = n; i < num; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
