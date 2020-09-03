#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int i = 0;
//	int a = 0;
//	int j = 0;
//	scanf("%d", &i);
//	j = i;
//	while (j != 0)
//	{
//		a = a * 10 + j % 10;
//		j /= 10;
//	}
//	if (a == i)
//	{
//		printf("%d是回文数\n", i);
//	}
//	else
//	{
//		printf("%d不是回文数\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int flag = 1;
//	char a[100];
//	gets(a);
//	int length = strlen(a);
//	for (i = 0; i <= length / 2; i++)
//	{
//		if (a[i] != a[length - i - 1])
//			flag = 0;
//		    break;
//	}
//	if (flag == 1)
//	{
//		printf("是回文数！\n");
//	}
//	else
//	{
//		printf("不是回文数！\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int flag = 1;
//	scanf("%d", &i);
//	int j = 0;
//	for (j = 0; i > 0; j++)
//	{
//		i /= 10;
//	}
//	int arr[] = {0};
//	int x = 0;
//	while (i)
//	{
//		arr[x++] = (i / pow(10, j - 1));
//		i -= (arr[x++] * pow(10,j - 1));
//	}
//	for (int n = 0; n <= j / 2; n++)
//	{
//		if (arr[n] != arr[j - n - 1])
//			flag = 0;
//		    break;
//	}
//	if (flag == 1)
//	{
//		printf("是回文数！\n");
//	}
//	else
//	{
//		printf("不是回文数！\n");
//	}
//	return 0;
//}