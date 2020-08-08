#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << this << endl;
		cout << &d << endl;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date s1(2020, 8, 8);
	s1.Print();
	Date s2(s1);
	s2.Print();
	cout << &s1 << endl;
	cout << &s2 << endl;
	return 0;
}
#endif

class String
{
public:
	String(const char* str = " haha ")
	{
		str = (char*)malloc(sizeof(_str)+1);
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	return 0;
}