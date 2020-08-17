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
	}
#if 0
	//前置++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++
	Date operator++(int)
	{
		Date temp(*this);
		_day +=  1;
		return temp;
	}
#endif
	////前置--
	//Date& operator--()
	//{
	//	_day -= 1;
	//	return *this;
	//}
	//后置--
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a1(2020, 8, 17);
	Date a2;
	//a2 = a1++;
	//a2 = ++a1;
	a2 = a1--;
	//a2 = --a1;
	return 0;
}