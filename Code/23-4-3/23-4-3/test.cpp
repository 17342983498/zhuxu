#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//class A
//{
//public:
//	void Print()
//	{
//		cout << "A()" << endl;
//	}
//public:
//	int _a;
//};
//
//class B:public A
//{
//public:
//	void Print()
//	{
//		cout << "B()" << endl;
//	}
//public:
//	int _b;
//};
//
//class C :public A
//{
//public:
//	void Print()
//	{
//		cout << "C()" << endl;
//	}
//public:
//	int _c;
//};
//
//
//class D :public B,public C
//{
//public:
//	void Print()
//	{
//		cout << "D()" << endl;
//	}
//public:
//	int _d;
//};
//
//
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}



//class A
//{
//public:
//	int _a;
//};
//
//class B :virtual public A
//{
//
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
//
//class D :public B, public C
//{
//public:
//	int _d;
//};
//
//
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票——全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	//void BuyTicket() 与下面的有同样的效果
//	virtual void BuyTicket()
//	{
//		cout << "买票——半价" << endl;
//	}
//};\


////协变
//class Person
//{
//public:
//	virtual Person* BuyTicket()
//	{
//		cout << "买票——全价" << endl;
//		return new Person;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual Student* BuyTicket()
//	{
//		cout << "买票——半价" << endl;
//		return new Student;
//	}
//};
//
//
//
//
//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Func(&p);
//	Func(&s);
//	return 0;
//}



//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "virtual ~Person()" << endl;
//	}
//};
//
//
//class Student:public Person
//{
//public:
//	/*virtual*/ ~Student()
//	{
//		cout << "virtual ~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}


class A
{
public:
	virtual void Print() = 0;
	int _a;
};

class B :public A
{
public:
	virtual void Print()
	{
		cout << "B:" << _b << endl;
	}
	int _b;
};

class C :public A
{
public:
	virtual void Print()
	{
		cout << "C:" << _c << endl;
	}
	int _c;
};


int main()
{
	A* pa=new B;
	pa->Print();
	A* paa = new C;
	paa->Print();
	return 0;
}