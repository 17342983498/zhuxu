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
	//const���������ε��ǳ�Ա�����е����ص�thisָ��
	//��ʾ��thisָ��ָ��Ŀռ�������޷����޸ģ�����thisָ��ָ��Ķ������޸�
	void PrintDate()const//const ���εĳ�Ա����
	{
		cout << _year << " " << _month << " " << _day << endl;
		/*_day++;*///�޷������޸�
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