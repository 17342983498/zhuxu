#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int PrintMin(int arr[], int n)
{
	int m = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i]>m)
		{
			m = arr[i];
		}
	}
	return m;
}

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num = PrintMin(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", num);
	return 0;
}

void Print(char a)
{
	if (a >= 97 && a <= 108)
	{
		printf("%c\n", a);
	}
}
int main()
{
	char a = '0';
	while (a<97 || a>108)
	{
		scanf("%c", &a);
	}
	Print(a);
	return 0;
}