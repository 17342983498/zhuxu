#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reserve(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr1, int k)
{
	int len = strlen(arr1);
	reserve((arr1),(arr1+k));
	reserve((arr1+k+1),(arr1+len-1));
	reserve((arr1),(arr1+len-1));
}
int is_left_move(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		int n = strcmp(arr1, arr2);
		if (n == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int len = is_left_move(arr1, arr2);
	if (len == 1)
	{
		printf("YES!\n");
	}
	else
		printf("NO!\n");
	return 0;
}
