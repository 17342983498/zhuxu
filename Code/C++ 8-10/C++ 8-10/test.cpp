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
	//<的运算符重载
	bool operator<(const Date& s)
	{
		if ((_year < s._year) ||
			(_year == s._year) && (_month < s._month) ||
			(_year == s._year) && (_month == s._month) && (_day < s._day))
		{
			return true;
		}
		cout << "s1不小于s2" << endl;
		return false;
	}
	bool operator==(const Date& d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		{
			return true;
		}
		cout << "d1不等于d2" << endl;
		return false;
	}
	bool operator>(const Date& a)
	{
		if ((_year > a._year) ||
			(_year == a._year) && (_month > a._month) ||
			(_year == a._year) && (_month == a._month) && (_day > a._day))
		{
			return true;
		}
		cout << "a1不大于a2" << endl;
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date s1(2020, 8, 10);
	Date s2(2020, 8, 11);
	if (s1 < s2)
	{
		cout << "s1:2020,8,10" << endl;
		cout << "s1:2020,8,11" << endl;
		cout << "s1<s2" << endl;
		cout << endl;
	}
	Date d1(2020, 8, 10);
	Date d2(2020, 8, 10);
	if (d1 == d2)
	{
		cout << "d1:2020,8,10" << endl;
		cout << "d2:2020,8,10" << endl;
		cout << "d1==d2" << endl;
		cout << endl;
	}
	Date a1(2020, 8, 12);
	Date a2(2020, 8, 11);
	if (a1 > a2)
	{
		cout << "a1:2020,8,12" << endl;
		cout << "a1:2020,8,11" << endl;
		cout << "a1>a2" << endl;
		cout << endl;
	}
	return 0;
}