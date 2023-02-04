#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//构造函数
//	Date(int year = 2000, int month = 1, int day = 9)
//	{
//		cout << "构造函数" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void DatePrint()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.DatePrint();
//	Date d2(2023, 2, 4);
//	d2.DatePrint();
//	Date d3(2023);
//	d3.DatePrint();
//
//	//函数声明
//	//Date d4();
//	return 0;
//}


//class Date
//{
//public:
//	Date()
//	{
//		cout << "构造函数1" << endl;
//	}
//
//	Date(int year, int month, int day)
//	{
//		cout << "构造函数2" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void DatePrint()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	Date d2(2000, 1, 9);
//	//Date d3(2023);
//	return 0;
//}



//class Date
//{
//public:
//
//	void DatePrint()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	//如果类中无显式定义构造函数，那么编译器会自主生成一个构造函数。
//	Date d1;
//	d1.DatePrint();
//	return 0;
//}



//class time
//{
//public:
//	time()
//	{
//		cout << "time()" << endl;
//		_hour = 8;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//class Date
//{
////此时编译器会自动生成一个构造函数，并会还会对自定义类型的参数 _t 进行调用。
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	time _t;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}




class String
{
public:
	String(const char* str = "zhuxu")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
		cout << _str << endl;
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};


class Person
{
private:
	String _name;
	int _age;
};

int main()
{
	Person p;
	return 0;
}
