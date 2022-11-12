#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//int Printnumber(int arr[])
//{
//	int maxval = 0;
//	int flag = arr[0];
//	int num = 1;
//	int max = 0;
//	for (int i = 1; i < 8; i++)
//	{
//		if (arr[i] == flag)
//		{
//			num++;
//		}
//		else
//		{
//			if (num>max)
//			{
//				max = num;
//				maxval = flag;
//			}
//			flag = arr[i];
//			num = 1;
//		}
//	}
//	return maxval;
//}
//
//
//int main()
//{
//	int arr[8] = { 1, 1, 2, 3, 3, 3, 4, 5 };
//	int ret = Printnumber(arr);
//	printf("%d\n", ret);
//	return 0;
//}

bool Increment(char* number)
{
	bool isoverflaw = false;
	int takeover = 0;
	int len = strlen(number);
	for (int i = len - 1; i >= 0; i--)
	{
		int sum = number[i] - '0' + takeover;
		if (i == len - 1)
		{
			sum++;
		}
		if (sum >= 10)
		{
			if (i == 0)
			{
				isoverflaw = true;
			}
			else
			{
				takeover = 1;
				sum -= 10;
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return isoverflaw;
}

void PrintNumber(char* number)
{
	bool isbeginning0 = true;
	int len = strlen(number);
	for (int i = 0; i < len; i++)
	{
		if (isbeginning0&&number[i] != '0')
		{
			isbeginning0 = false;
		}
		if (!isbeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\n");
}

void Print()
{
	char number[10] = { '0' };
	number[9] = '\0';
	while (!Increment(number))
	{
		PrintNumber(number);
	}
}

int main()
{
	//int n = 0;
	//scanf("%d", &n);
	Print();
	return 0;
}