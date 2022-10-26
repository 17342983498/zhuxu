#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char input[100] = { 0 };
//	gets(input);
//	char* left = input;
//	char* right = input;
//	while (right)
//	{
//		while (*right != ' ' && *right != '\0')
//		{
//			right++;
//		}
//		right--;
//		if (left != right)
//		{
//			reverse(left, right);
//		}
//		if (*(right+1) == '\0')
//		{
//			break;
//		}
//		right+=2;
//		left = right;
//	}
//	reverse(input, input + strlen(input) - 1);
//	printf("%s\n", input);
//	return 0;
//}

void swap(char* x,char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void rotate(char* str, int k)
{
	int n = strlen(str);
	if (n == 0 || k <= 0)
		return;
	if (k % n <= 0)
		return;
	int num = n - k - (n % k);
	int p1 = 0;
	int p2 = k;
	while (num--)
	{
		swap(&str[p1], &str[p2]);
		p1++;
		p2++;
	}
	int x = n - p2;
	while (x--)
	{
		int i = p2;
		while (i > p1)
		{
			swap(&str[i], &str[i-1]);
			i--;
		}
		p2++;
		p1++;
	}
}



int main()
{
	char str[10] = "abcdefgh";
	rotate(str, 3);	printf("%s\n", str);
	return 0;
}