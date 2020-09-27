#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//#include<iostream>
//using namespace std;

void Print(char* arr)
{
	int str = sizeof(arr);
	if (arr != " ")
	{
		arr--;
	}
	*arr = '\0';

}
int main()
{
	char arr[40];
	gets(arr);
	Print(arr);
	printf("%s\n", arr);
	return 0;
}


//int main()
//{
//	char arr[1024] = { 0 };
//	gets(arr);
//	int i = strlen(arr);
//	for (; i >= 0; i--)
//	{
//		if (arr[i] == ' ')
//		{
//			cout << arr + i + 1 << endl;
//			break;
//		}
//	}
//	if (i < 0)
//	{
//		i = 0;
//		cout << arr + i << endl;
//	}
//	return 0;
//}