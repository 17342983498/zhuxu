#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <queue>

void TestFunc1()
{
	priority_queue<int> q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.push(8);
}

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return ((_year < d._year) ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day));
	}
	bool operator>(const Date& d)const
	{
		return ((_year > d._year) ||
			(_year == d._year&&_month > d._month) ||
			(_year == d._year&&_month == d._month&&_day > d._day));
	}

	int _year;
	int _month;
	int _day;
};
void TestFunc2()
{
	priority_queue<Date> d;
	d.push(Date(2020, 11, 11));
	d.push(Date(2020, 11, 12));
	d.push(Date(2020, 11, 13));
	d.push(Date(2020, 11, 14));
	d.push(Date(2020, 11, 15));
	d.push(Date(2020, 11, 16));
	d.push(Date(2020, 11, 10));
	d.push(Date(2020, 11, 9));
}

#include <functional>
void TestFunc3()
{
	priority_queue<Date,vector<Date>,greater<Date>> d;
	d.push(Date(2020, 11, 11));
	d.push(Date(2020, 11, 12));
	d.push(Date(2020, 11, 13));
	d.push(Date(2020, 11, 14));
	d.push(Date(2020, 11, 15));
	d.push(Date(2020, 11, 16));
	d.push(Date(2020, 11, 10));
	d.push(Date(2020, 11, 9));
}

class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return (left->_day > right->_day);
	}
};
void TestFunc4()
{
	Date* q1 = new Date(2020, 11, 12);
	Date* q2 = new Date(2020, 11, 13);
	Date* q3 = new Date(2020, 11, 11);
	priority_queue<Date*, vector<Date*>, Greater> q;
	q.push(q1);
	q.push(q2);
	q.push(q3);
}
int main()
{
	// TestFunc1();
	// TestFunc2();
	// TestFunc3();
	TestFunc4();
	return 0;
}