#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &a, &b);
	for (i = 1; i<10000000; i++)
	{
		j = a*i;
		if (j%b == 0)
		{
			printf("%d\n", j);
			break;
		}
	}
	return 0;
}


