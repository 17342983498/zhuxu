#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//class Person
//{
//public:
//	void InfoPrint()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "zhuxu";
//public:
//	int _age = 23;
//};
//
////基类中的public可以在任意位置使用，protected只能在基类和派生类中使用，private只能在基类中使用
//class Student :public Person
//{
//public:
//	void InfoPrint()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//		cout << "stuid:" << _stuid << endl;
//	}
//
//private:
//	string _stuid = "03187021";
//};
//
//int main()
//{
//	//Student s;
//	//s.InfoPrint();
//	//s._age = 0;
//	////s._name = "sad";
//
//	Student s;
//	Person p = s;//派生类对象赋值给基类对象
//	Person *pp = &s;//指针
//	Person& rp = s;//引用
//
//	//基类不能赋值给派生类
//	//基类无法满足派生类
//	//s = r;
//
//	pp = &s;
//	Student* ps=(Student*)pp;
//	ps->_age = 0;
//	return 0;
//}


class Person
{
protected:
	string _name = "zxzxz";
	int _age = 13;
};

class Student:public Person
{
public:
	void InfoPrint()
	{
		cout << "name:" << _name << endl;
		//构成隐藏
		cout << "age:" << Person::_age << endl;
		cout << "age:" << _age << endl;
	}
protected:
	int _age = 23;
};


int main()
{
	Student s;
	s.InfoPrint();
	return 0;
}

