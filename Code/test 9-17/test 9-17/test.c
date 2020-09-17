#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//int exchange(char* arr1, char* arr2)
//{
//	while (*arr1 != '\0')
//	{
//		if (*arr1 != ' ')
//		{
//			*arr2 = *arr1;
//			arr2++;
//		}
//		else
//		{
//			strcpy(arr2, "%20");
//			arr2 += 3;
//		}
//		arr1++;
//	}
//	*arr2 = '\0';
//	return 0;
//}
//int main()
//{
//	char arr1[40];
//	char arr2[40];
//	gets(arr1);
//	exchange(arr1, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}


void exchange(char* arr1, char* arr2)
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
			strcpy(arr2, "20%");
			arr2 += 3;
		}
		arr1++;
	}
	*arr2 = '\0';
}
int main()
{
	char arr1[40];
	char arr2[40];
	gets(arr1);
	exchange(arr1, arr2);
	printf("%s\n", arr2);
	return 0;
}


