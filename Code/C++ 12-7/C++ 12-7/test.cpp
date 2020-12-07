#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <windows.h>

#if 0
class Car
{
public:
	virtual void Drive() = 0;
};

class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz:舒服" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW:气派" << endl;
	}
};

int main()
{
	Car* benz = new Benz;
	benz->Drive();
	return 0;
}
#endif

#if 0
class Person
{
public:
	virtual void Wc() = 0;
};

class Woman :public Person
{
public:
	virtual void Wc()
	{
		cout << "please turn Right." << endl;
	}
};

class Man :public Person
{
public:
	virtual void Wc()
	{
		cout << "please turn Left." << endl;
	}
};


void TestWC()
{
	// 厕所门口收钱的
	Person* p = nullptr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->Wc();
		delete p;

		Sleep(1000);
	}

}

int main()
{
	TestWC();
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void func1()
	{
		cout << "fun1()" << endl;
	}

	virtual void func2()
	{
		cout << "fun2()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void func1()
	{
		cout << "fun1()" << endl;
	}
	virtual void fun3()
	{
		cout << "fun3()" << endl;
	}
};
int main()
{
	Base b;
	Derived d;
	return 0;
}
#endif

class Base
{
public:
	virtual void func1()
	{
		cout << "Base::fun1()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void func1()
	{
		cout << "Derived::fun1()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.func1();
}

int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	return 0;
}