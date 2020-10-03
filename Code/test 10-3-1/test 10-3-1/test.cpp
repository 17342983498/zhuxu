#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void exchange(char* arr1, char* arr2)
{
	while (*arr1)
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