#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//int main()
//{
//	char arr[1024];
//	gets(arr);
//	int sz = strlen(arr);
//	while (sz--)
//	{
//		if (arr[sz] == ' ')
//		{
//			cout << arr + sz + 1 << endl;
//			break;
//		}
//	}
//	if (sz <= 0)
//	{
//		cout << arr << endl;
//	}
//	return 0;
//}


//int main()
//{
//	char arr[1024] = { 0 };
//	gets(arr);
//	int i = strlen(arr);
//	for (; i > 0; i--)
//	{
//		if (arr[i] == ' ')
//		{
//			cout << arr + i + 1 << endl;
//			break;
//		}
//	}
//	if (i <= 0)
//	{
//		cout << arr + i << endl;
//	}
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
	gets(arr1);
	char arr2[40];
	exchange(arr1, arr2);
	cout << arr2 << endl;
	return 0;
}