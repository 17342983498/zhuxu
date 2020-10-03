#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

int main()
{
	char arr[1024] = { 0 };
	gets(arr);
	int sz = strlen(arr);
	while (sz--)
	{
		if (arr[sz] == ' ')
		{
			cout << arr + sz + 1 << endl;
			break;
		}
	}
	if (sz < 0)
	{
		cout << arr << endl;
	}
	return 0;
}