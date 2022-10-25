#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int func(int num)
{
	if (num == 0)
	{
		return 0;
	}
	int x = num % 10;
	static int sum = 0;
	num /= 10;
	sum = sum * 10 + x;
	func(num);
	return sum;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = func(num);
	printf("%d\n", ret);
	return 0;
}