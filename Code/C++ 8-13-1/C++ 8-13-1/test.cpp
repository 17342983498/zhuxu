#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const Date& s)
	{
		if (s._year == _year && s._month == _month && s._day == _day)
		{
			cout << &s << endl;
			cout << this << endl;
			return true;
		}
		return false;
	}
	bool operator<(const Date& a)
	{
		if (a._year>_year ||
			a._year == _year&&a._month > _month ||
			a._year == _year&&a._month == _month&&a._day > _day)
		{
			cout << &a << endl;
			cout << this << endl;
			return true;
		}
		return false;
	}
	bool operator!=(const Date& c)
	{
		cout << &c << endl;
		cout << this << endl;
		return !(*this==c);
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date s1(2020, 8, 13);
	Date s2(2020, 8, 13);
	if (s1 == s2)
	{
		cout << &s1 << endl;
		cout << &s2 << endl;
		cout << "s1==s2" << endl;
	}
	Date a1(2020, 8, 13);
	Date a2(2020, 8, 14);
	if (a1 < a2)
	{
		cout << &a1 << endl;
		cout << &a2 << endl;
		cout << "a1<a2" << endl;
	}
	Date c1(2020, 8, 13);
	Date c2(2020, 8, 12);
	if (c1 != c2)
	{
		cout << &c1 << endl;
		cout << &c2 << endl;
		cout << "c1!=c2" << endl;
	}
}