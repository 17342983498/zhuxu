#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		:_b(b._b)
	{
		cout << "Base(const Base& b)" << endl;
	}

	Base& operator=(const Base& b)
	{
		cout << "Base& operator=(const Base& b)" << endl;
		if (&b != this)
		{
			_b = b._b;
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};

class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)

	{
		cout << "Derived()" << endl;
	}

	Derived(const Derived& d)
		:Base(d)
		, _d(d._d)
	{
		cout << "Derived(const Derived& d)" << endl;
	}

	Derived& operator=(const Derived& d)
	{
		cout << "Derived& operator=(const Derived& d)" << endl;
		if (&d != this)
		{
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};

int main()
{
	Derived d1(1, 2);
	Derived d2(d1);

	Derived d3(10, 20);
	d1 = d3;
	return 0;
}
#endif


#if 0
class Person
{
public:
	Person()
	{
		++_count;
	}

protected:
	string _name;

public:
	static int _count;
};

int Person::_count = 0;

class Student :public Person
{
protected:
	int _stuNum;
};

class Graduate :public Student
{
protected:
	string _seminarCourse;
};

int main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
	return 0;
}
#endif


class A 
{
public:
	int _a;
};

// class B : public A
class B : virtual public A 
{
public:
	int _b;
};

// class C : public A
class C : virtual public A 
{
public:
	int _c;
};

class D : public B, public C 
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}