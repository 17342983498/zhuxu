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
	//const本质是修饰的是成员函数中的隐藏的this指针
	//表示：this指针指向的空间的内容无法被修改，即，this指针指向的对象不能修改
	void PrintDate()const//const 修饰的成员函数
	{
		cout << _year << " " << _month << " " << _day << endl;
		/*_day++;*///无法进行修改
		cout << typeid(this).name() << endl;
	}
	const Date& GetDate()
	{
		_day++;
		cout << typeid(this).name() << endl;
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
	/*mutable int _day;*/
};
int main()
{
	Date a(2020, 8, 21);
	a.GetDate();
	a.PrintDate();
	return 0;
}