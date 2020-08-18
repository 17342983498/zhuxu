#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Date(const Date& a)
	//{
	//	_year = a._year;
	//	_month = a._month;
	//	_day = a._day;
	//	cout << _year << " " << _month << " " << _day << endl;
	//}
	bool operator<(const Date& s)
	{
		if (_year < s._year ||
			_year == s._year&&_month < s._month ||
			_year == s._year&&_month == s._month&&_day < s._day)
		{
			cout << &s << endl;
			return true;
		}
		return false;
	}
	Date& operator=(const Date& a)
	{
		if (this != &a)
		{
			_year = a._year;
			_month = a._month;
			_day = a._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//Date a1(2020,8,18);
	//Date a2(a1);
	Date s1(2020, 8, 18);
	Date s2(2020, 8, 19);
	if (s1 < s2)
	{
		cout << &s2 << endl;
		cout << "s1<s2" << endl;
	}
	Date a1(2020, 8, 18);
	Date a2;
	a2=a1;
	return 0;
}