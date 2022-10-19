#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>



//void Find_num(int arr[][4], int rows, int cols, int n)
//{
//	int row = 0 ;
//	int col = cols-1;
//	while (row < rows && col >= 0)
//	{
//		if (arr[row][col] == n)
//		{
//			printf("找到了，在第%d行第%d列\n", row + 1, col + 1);
//			return ;
//		}
//		else if (arr[row][col] > n)
//		{
//			col--;
//		}
//		else
//		{
//			row++;
//		}
//	}
//	printf("没找到\n");
//}
//
//
//int main()
//{
//	int arr[4][4] = {  1, 2, 3, 4 ,  5, 6, 7, 8 ,  9, 10, 11, 12 ,14, 15, 16, 17  };
//	int n = 0;
//	scanf("%d", &n);
//	Find_num(arr, 4, 4, n);
//	return 0;
//}



//void ReplaceBlack(char* arr)
//{
//	int num = 0;
//	char* ret = arr;
//	char* p1 = arr;
//	while (*p1 != '\0')
//	{
//		if (*p1 == ' ')
//		{
//			num++;
//		}
//		p1++;
//	}
//	char* p2 = p1;
//	int sum = num * 2;
//	while (sum--)
//	{
//		p2++;
//	}
//	while (p1 != p2)
//	{
//		if (*p1 == ' ')
//		{
//			*p2 = '0';
//			*(p2 - 1) = '2';
//			*(p2 - 2) = '%';
//			p2 -= 2;
//		}
//		else
//		{
//			*p2 = *p1;
//		}
//		p1--;
//		p2--;
//	}
//	printf("%s", ret);
//}
//
//int main()
//{
//	char arr[20] = "we are happy!";
//	ReplaceBlack(arr);
//	return 0;
//}