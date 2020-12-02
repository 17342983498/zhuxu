#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
};

class Student:public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
};

class Soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免票" << endl;
	}
};

void BuyTickets(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person p;
	Student s;
	Soldier so;
	BuyTickets(p);
	BuyTickets(s);
	BuyTickets(so);
	return 0;
}
#endif


#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
};

class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
};

class Soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免票" << endl;
	}
};

void BuyTickets(Person *p)
{
	p->BuyTicket();
}
int main()
{
	Person p;
	Student s;
	Soldier so;
	BuyTickets(&p);
	BuyTickets(&s);
	BuyTickets(&so);
	return 0;
}
#endif


#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}

	virtual Person* BuyTicket()
	{
		cout << "(Person)全价票" << endl;
	}
};

class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}

	virtual Student* BuyTicket()
	{
		cout << "(Person)半价票" << endl;
	}
};

class Soldier :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免票" << endl;
	}
};

void BuyTickets(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person p;
	Student s;
	Soldier so;
	BuyTickets(p);
	BuyTickets(s);
	BuyTickets(so);
	return 0;
}
#endif


#if 0
class A
{};

class B : public A 
{};

class Person 
{
public:
	virtual A* f() 
	{ 
		cout << "A" << endl;
		return new A;
	}
};

class Student : public Person 
{
public:
	virtual B* f() 
	{ 
		cout << "B" << endl;
		return new B;
	}
};

void Test(Person& p)
{
	p.f();
}
int main()
{
	Person p;
	Test(p);
	Student s;
	Test(s);
	return 0;
}
#endif


#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{

	}
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
	int _a;
};

class B : public A
{
public:
	B(int a,int b)
		:A(a)
		,_b(b)
	{
		_p = new int[10];
	}

	~B()
	{
		delete[] _p;
	}
	int _b;
	int* _p;
};

int main()
{
	A* pa = new B(1, 2);
	delete pa;
	pa = nullptr;
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}
};

class Derived :public Base
{
public:
	// 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错
	virtual void Test()override
	{
		cout << "Derived::Test()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.Test();
}
int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	d.Test();
	return 0;
}
#endif


class Base
{
public:
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}
};

class Derived :public Base
{
public:
	//该final关键字意思是不允许自己的派生类重写该虚函数
	virtual void Test()final
	{
		cout << "Derived::Test()" << endl;
	}
};

//class D :public Derived
//{
//public:
//	virtual void Test()
//	{
//		cout << "D::Test()" << endl;
//	}
//};

void TestFunc(Base& b)
{
	b.Test();
}
int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	return 0;
}