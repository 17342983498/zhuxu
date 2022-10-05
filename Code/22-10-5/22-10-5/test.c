#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int print(int n)
//{
//	int count = 0;
//	int sum = 0;
//	for (int i = 1; count < n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			sum += i;
//			count++;
//			if (count == n)
//				break;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = print(n);
//	printf("%d\n", ret);
//	return 0;
//}


int main()
{
	int n = 0;
	int arr[5] = { 0 };
	scanf("%d", &n);
	int num = 1;
	while (num <= n)
	{
		int sum = 0;
		int m = num;
		int i = 0;
		while (m)
		{
			arr[i++] = m % 10;
			m /= 10;
		}
		i--;
		for (int j = 0; j <= i;j++)
		{
			sum = arr[j] + sum * 10;
		}
		if (sum == num)
		{
			printf("%d ", sum);
		}
		num++;
	}
	return 0;
}