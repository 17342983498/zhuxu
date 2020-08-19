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
	Date(const Date& a)
	{
		_year = a._year;
		_month = a._month;
		_day = a._day;
		cout << _year << " " << _month << " " << _day << endl;
	}
	Date& operator=(const Date& a)
	{
		if (this!=&a)
		{
			_year = a._year;
			_month = a._month;
			_day = a._day;
		}
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a1(2020, 8, 19);
	Date a2(a1);
	Date s1(2000, 1, 9);
	Date s2;
	s2 = s1;
	return 0;
}