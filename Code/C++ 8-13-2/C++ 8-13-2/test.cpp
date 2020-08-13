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

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date s1(2020, 8, 13);
	Date s2;
	s2 = s1;
	return 0;
}