#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[1024] = { 0 };
//	int tmp = 0;
//	for(int i = 0; i < n; i++)
//	{
//		scanf("%d", &tmp);
//		arr[tmp] = tmp;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			printf("  ");
		}
		for (int x = 1; x <= i; x++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}

//        *
//      * *
//    * * *
//  * * * *
//* * * * *