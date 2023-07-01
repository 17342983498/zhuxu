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


//class Person
//{
//protected:
//	string _name = "zxzxz";
//	int _age = 13;
//};
//
//class Student:public Person
//{
//public:
//	void InfoPrint()
//	{
//		cout << "name:" << _name << endl;
//		//构成隐藏
//		cout << "age:" << Person::_age << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _age = 23;
//};
//
//
//int main()
//{
//	Student s;
//	s.InfoPrint();
//	return 0;
//}


//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	void func(int i)
//	{
//		cout << "func(int i)" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.func(0);
//	b.A::func();
//	return 0;
//}



//class Person
//{
//public:
//	Person(const char* name="zhuxu")
//		:_name(name)
//	{
//		cout << "Person(const char* name) " << endl;
//	}
//
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name,int stuid)
//		:Person(name)
//		,_stuid(stuid)
//	{
//		cout << "Student(const char* name,int stuid)" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)//切片
//		, _stuid(s._stuid)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator==(const Student& s)
//	{
//		cout << "Student& operator==(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_stuid = s._stuid;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _stuid;
//};
//
//int main()
//{
//	Student stu("zhangsan",13246);
//	Student s(stu);
//	Person p;
//	p = s;
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void display(const Person& p, const Student& s);
//protected:
//	string _name;
//};
//
//class Student:public Person
//{
//protected:
//	int _stuid;
//};
//
//void display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s.stuid << endl;基类友元不能访问子类私有和保护成员
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	display(p, s);
//	return 0;
//}


class Person
{
public:
	Person()
	{
		++count;
	}

	static int count;
};

int Person::count = 0;

class Student :public Person
{
protected:
	int _stuid;
};
class Teacher :public Person
{
protected:
	int _Teaid;
};


int main()
{
	Person p;
	Student s;
	Teacher t;
	Person s1;
	cout << "人数：" << Person::count << endl;
	return 0;
}