#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<string.h>
#include<iostream>
using namespace std;
#if 0
void exchange(char* arr1, char*arr2)
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
#endif

class A
{
public:
	~A()
	{
		cout << 'A' << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class B
{
public:
	~B()
	{
		cout << 'B' << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class C
{
public:
	~C()
	{
		cout << 'C' << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class D
{
public:
	~D()
	{
		cout << 'D' << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
C c;
int main()
{
	A a;
	B b;
	static D d;
	return 0;
}