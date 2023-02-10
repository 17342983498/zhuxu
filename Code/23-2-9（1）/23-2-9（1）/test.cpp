#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int GetMonthDay(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			days[2] = 29;
		}
		return days[month];
	}
	Date& operator+=(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	bool operator==(const Date& d)
	{
		return d._year == _year&&d._day == _day&&d._month == _month;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	Date operator++()
	{
		*this += 1;
		return *this;
	}
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int count = 0;
		while (min != max)
		{
			++min;
			++count;
		}
		return count*flag;
	}
private:
	int _year;
	int _month;
	int _day;
};


//int main()
//{
//	int year1, month1, day1;
//	int year2, month2, day2;
//	cin >> year1 >> month1 >> day1;
//	cin >> year2 >> month2 >> day2;
//	Date d1(year1, month1, day1);
//	Date d2(year2, month2, day2);
//	cout << d2 - d1 << endl;
//	return 0;
//}

int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	int date1, date2;
	while (scanf("%d%d", &date1, &date2) != EOF)
	{
		if (date1>date2)
		{
			int tmp = date1;
			date1 = date2;
			date2 = tmp;
		}
		year1 = date1 / 10000;
		month1 = date1 % 10000 / 100;
		day1 = date1 % 100;
		year2 = date2 / 10000;
		month2 = date2 % 10000 / 100;
		day2 = date2 % 100;
		Date d1(year1, month1, day1);
		Date d2(year2, month2, day2);
		cout << d2 - d1 + 1 << endl;
	}
	return 0;
}