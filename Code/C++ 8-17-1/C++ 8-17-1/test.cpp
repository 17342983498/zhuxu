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
	bool operator<(const Date& a)
	{
		if (_year < a._year ||
			_year == a._year&&_month < a._month ||
			_year == a._year&&_month == a._month&&_day < a._year)
		{
			return true;
		}
		return false;
	}
	bool operator!=(const Date& a)
	{
		if (_year == a._year&&_month == a._month&&_day == a._day)
		{
			return false;
		}
		return true;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a1(2020, 8, 17);
	Date a2(2020, 8, 18);
	if (a1 < a2)
	{
		cout << "a1 < a2" << endl;
	}
	if (a1 != a2)
	{
		cout << "a1 != a2" << endl;
	}
	return 0;
}