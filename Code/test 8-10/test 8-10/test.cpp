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
	bool IsLess(const Date& s)//s是s2的引用，如果是(const Date s),那s是s2的一份临时拷贝，也就是值传递。
	{
		cout << this << endl;
		cout << &s << endl;
		if ((_year < s._year) ||
			(_year == s._year) && (_month < s._month) ||
			(_year == s._year) && (_month == s._month) && (_day < s._day))
		{
			return true;
		}
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
	if (s1.IsLess(s2))
	{
		cout << "s1 < s2" << endl;
	}
	cout << &s1 << endl;
	cout << &s2 << endl;
	return 0;
}