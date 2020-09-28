#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//
//int main()
//{
//	int a = 9;
//	int b = 11;
//	int k = 0;
//	k = a != b ? a + b : a - b;
//	printf("%d\n", k);
//	return 0;
//}

#if 0
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display(const Date* this) 
	{
		cout << "Display () const" << endl;
		cout << "year:" << this->_year << endl;
		cout << "month:" << this->_month << endl;
		cout << "day:" << this->_day << endl;
	}
private:
	int _year; // Äê
	int _month; // ÔÂ
	int _day; // ÈÕ
};
void Test()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
}

#endif

//int main()
//{
//	char arr[40];
//	gets(arr);
//	int sz = strlen(arr);
//	while (sz--)
//	{
//		if (arr[sz] == ' ')
//		{
//			printf("%s\n",arr+sz+1);
//			break;
//		}
//	}
//	if (sz < 0)
//	{
//		printf("%s\n", arr);
//	}
//	return 0;
//}

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

