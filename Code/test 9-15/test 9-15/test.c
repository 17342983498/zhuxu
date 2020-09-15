#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#if 0
int Search(int n,int arr[4][4])
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == n)
				return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int n = 0;
	scanf("%d", &n);
	int ret = Search(n,arr);
	if (ret == 1)
		printf("找到了!\n");
	else
		printf("没找到!\n");
	return 0;
}
#endif

#if 0
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int exchange(char *arr1, char *arr2) 
{
	while (*arr1 != '\0') 
	{
		if (*arr1 != ' ') 
		{
			*arr2 = *arr1;
			arr2++;
		}
		else 
		{
			strcpy(arr2, "%20");
			arr2 += 3;
		}
		arr1++;
	}
	*arr2 = '\0';
	return 0;
}
int main() 
{
	char arr1[40];
	gets(arr1);
	char arr2[40];
	exchange(arr1, arr2);
	printf("%s\n", arr2);
	return 0;
}
#endif

#if 0
int Fib(int n)
{
	int First = 1;
	int Second = 1;
	int ret = 0;
	for (int i = 2; i < n; i++)
	{
		ret = First + Second;
		First = Second;
		Second = ret;
	}
	return ret;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}
#endif

//int main()
//{
//	int a = 98732;
//	char c = (char)a;
//	printf("%c\n", c);
//	return 0;
//}

int FindNum(int x)
{
	int ret = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((x>>i) & 1)
		{
			ret++;
		}
	}
	return ret;
}
int main()
{
	unsigned int x = 0;
	scanf("%d", &x);
	int ret = FindNum(x);
	printf("%d\n", ret);
	return 0;
}

