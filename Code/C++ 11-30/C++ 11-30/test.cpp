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
	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b,int d)
		:Base(b)
		, _d(d)
	{
		cout << "Derived()" << endl;
	}
	~Derived()
	{
		cout << "Derived()" << endl;
	}
protected:
	int _d;
};
int main()
{
	Derived d(10,20);
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b = 10)
		:_b(b)
	{
		cout << "Base()" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		:_d(d)
	{
		cout << "Derived()" << endl;
	}
	~Derived()
	{
		cout << "Derived()" << endl;
	}
protected:
	int _d;
};
int main()
{
	Derived d(10, 20);
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& d)
		:_b(d._b)
	{
		cout << "Base(const Base& d)" << endl;
	}

	Base operator=(const Base& d)
	{
		if (&d != this)
		{
			_b = d._b;
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

class Derived : public Base
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

	Derived operator=(const Derived& d)
	{
		if (&d != this)
		{
			_d = d._d;
		}
		return *this;
	}

	~Derived()
	{
		cout << "Derived()" << endl;
	}
protected:
	int _d;
};
int main()
{
	Derived d1(10, 20);
	Derived d2(d1);
	Derived d3(100,200);
	d3 = d1;
	return 0;
}

#endif



#if 0
//继承与友元
class Person
{
public:
	friend void Display(const Person& p, const Student& s);

protected:
	string _name; // 姓名
};

class Student : public Person
{
protected:
	int _stuNum; // 学号
};

void Display(const Person& p, const Student& s) 
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

void main()
{
	Person p;
	Student s;
	Display(p, s);
}
#endif


//#if 0
//继承与静态成员
class Person
{
public:
	Person() { ++_count; }

protected:
	string _name; // 姓名

public:
	static int _count; // 统计人的个数。
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // 学号
};

class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};

void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}

int main()
{
	TestPerson();
	return 0;
}
//#endif


#if 0
class A
{
public:
	int _a;
};

class B1:public A
{
public:
	int _b1;
};

class B2:public A
{
public:
	int _b2;
};

class C:public B1,public B2
{
public:
	int _c;
};
int main()
{
	C c;
	//c._a = 0;
	c.B1::_a = 0;
	c.B2::_a = 1;
	c._b1 = 2;
	c._b2 = 3;
	c._c = 4;
	return 0;
}
#endif


#if 0
class A 
{
public:
	int _a;
};

class B : virtual public A 
{
public:
	int _b;
};

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
#endif
