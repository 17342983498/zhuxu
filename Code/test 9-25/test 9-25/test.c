#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Print(int* a, int k)
{
	int num = *a;
	while (--k)
	{
		a++;
		if (num > *a)
			num = *a;
	}
	return num;
}
int main()
{
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	int k = 0;
	printf("\n");
	scanf("%d", &k);
	int num = Print(a, k);
	printf("%d\n", num);
	return 0;
}