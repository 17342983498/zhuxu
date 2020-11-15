#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <queue>
#include <functional>

#if 0
int main()
{
	priority_queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5); 
	q.push(6);
	cout << q.size() << endl;
	cout << q.top() << endl;
	q.pop();
	cout << q.size() << endl;
	cout << q.top() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	priority_queue<int, vector<int>, greater<int>> q(v.begin(), v.end());
	return 0;
}
#endif 


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


void TestFunc1()
{
	priority_queue<Date> d1;
	d1.push(Date(2000, 1, 9));
	d1.push(Date(2015, 5, 23));
	d1.push(Date(2018, 10, 30));
	d1.push(Date(2020, 11, 15));
	d1.push(Date(2020, 11, 11));
}

class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return(left->_day < right->_day);
	}

};
void TestFunc2()
{
	priority_queue<Date, vector<Date>, greater<Date>> q;
	q.push(Date(2000, 1, 9));
	q.push(Date(2015, 5, 23));
	q.push(Date(2018, 10, 30));
	q.push(Date(2020, 11, 15));
	q.push(Date(2020, 11, 11));
}

void TestFunc3()
{
	Date* q1 = new Date(2020, 11,12);
	Date* q2 = new Date(2020, 11,13);
	Date* q3 = new Date(2020, 11,11);
	priority_queue<Date*, vector<Date*>, Greater> q;
	q.push(q1);
	q.push(q2);
	q.push(q3);
}

#include <algorithm>

void TestFunc4()
{
	vector<int> v{ 1, 5, 8, 7, 4, 6, 3, 2, 9 };
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(v.begin(), v.end(),greater<int>());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

class Goods
{
public:
	Goods( const string& name,const int& age)
		:_name(name)
		, _age(age)
		{}
	bool operator<(const Goods& d)const
	{
		return _age < d._age;
	}
	bool operator>(const Goods& d)const
	{
		return _age > d._age;
	}
private:
	string _name;
	int _age;
};
void TestFunc5()
{
	Goods d[4] = { { "zhuxu", 20 }, { "wensulei", 19 }, { "wangjiangtao", 21 }, { "guoixngixng", 22 } };
	sort(d, d + sizeof(d) / sizeof(d[0]));
	sort(d, d + sizeof(d) / sizeof(d[0]), greater<Goods>());
}


int main()
{
	// TestFunc1();
	// TestFunc2();
	// TestFunc3();
	// TestFunc4();
	TestFunc5();
	return 0;
}