#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
//public:
//	int _a;
//};
//
//class B :public A
//{
//public:
//	void Print(int i)
//	{
//		A::Print();
//		cout << "B::Print(int i)" << i << endl;
//	}
//public:
//	int _b;
//};
//
//int main()
//{
//	//A a;
//	//a.Print();
//	B b;
//	b.Print(10);
//}

//class Person
//{
//
//public:
//	string _name;
//};
//
//class Student :virtual public Person
////class Student:public Person
//{
//protected:
//	int _stuid;
//};
//
//class Teacher :virtual public Person
////class Teacher :public Person
//{
//protected:
//	int _teaid;
//};
//
//class assitant :public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};
//
//
//int main()
//{
//	assitant a;
//	//存在二义性，不知道这个_name是属于Student的，还是属于Teacher的
//	a._name = "zhuxu";
//
//	//// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	//a.Student::_name = "zx";
//	//a.Teacher::_name = "xc";
//
//	return 0;
//}



//class A
//{
//public:
//	int _a;
//	int _l;
//};
//
//class B :virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;	
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d.B::_l = 0;
//	return 0;
//}