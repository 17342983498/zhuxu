#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//void reverse(char* str, int front, int end)
//{
//	while (front < end)
//	{
//		char s = str[front];
//		str[front] = str[end];
//		str[end] = s;
//		front++;
//		end--;
//	}
//}
//
//
//void rev_str(char* str, int num)
//{
//	reverse(str, 0, num);
//	int front = 0, end = 0;
//	while (str[front])
//	{
//		while (str[end] != ' '&& str[end] != '\0')
//		{
//			end++;
//		}
//		reverse(str, front, end - 1);
//		front = end + 1;
//		end = front;
//	}
//}
//
//int main()
//{
//	char str[100] = { 0 };
//	gets(str);
//	int ret = strlen(str) - 1;
//	rev_str(str, ret);
//	printf("%s\n", str);
//	return 0;
//}

//void replaceSpace(char *str, int length)
//{
//	char* cur = str;
//	int count = 0;
//	while (*cur != '\0')
//	{
//		if (*cur == ' ')
//		{
//			count++;
//		}
//		cur++;
//	}
//	for (int i = length - 1; i >= 0; i--)
//	{
//		if (*(str+i) == ' ')
//		{
//			str[i + count * 2] = '0';
//			str[i + count * 2 - 1] = '2';
//			str[i + count * 2 - 2] = '%';
//			count--;
//		}
//		else
//		{
//			str[i + count * 2] = str[i];
//		}
//	}
//}



//void replaceSpace(char *str, int length)
//{
//	char* cur = str;
//	int count = 0;
//	while (*cur != '\0')
//	{
//		if (*cur == ' ')
//		{
//			count++;
//		}
//		cur++;
//	}
//	for (int i = length - 1; i >= 0; i--)
//	{
//		if (*(str + i) == ' ')
//		{
//			*(str + i + 2 * count) = '0';
//			*(str + i + 2 * count - 1) = '2';
//			*(str + i + 2 * count - 2) = '%';
//			count--;
//		}
//		else
//		{
//			*(str + i + 2 * count) = *(str + i);
//		}
//	}
//}

void replaceSpace(char *str, int length)
{
	int count = 0;
	char newstr[100] = { 0 };
	for (int i = 0; i < length; i++)
	{
		if ( str[i] == ' ')
		{
			count++;
			newstr[i + 2 * count - 2] = '%';
			newstr[i + 2 * count - 1] = '2';
			newstr[i + 2 * count] = '0';
		}
		else
		{
			newstr[i + count * 2] = str[i];
		}
	}
	printf("%s\n", newstr);
}
int main()
{
	char str[100] = "i like beijing.";
	int length = strlen(str);
	replaceSpace(str, length);
	//printf("%s\n", str);
	return 0;
}