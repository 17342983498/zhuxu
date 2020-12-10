#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
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
		: Base(b)   // 初始化基类部分继承下来的成员
		, _d(d)
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};


void TestFunc()
{
	Derived d(1, 2);
}

int main()
{
	TestFunc();
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base()
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
		//: Base(b)   // 初始化基类部分继承下来的成员
		: _d(d)
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};


void TestFunc()
{
	Derived d(1, 2);
}

int main()
{
	TestFunc();
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base(int b)" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{
		cout << "Base(const Base& b)" << endl;
	}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}
		cout << "Base& operator=(const Base& d)" << endl;
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};
#endif

#if 0
class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{
		cout << "Derived(int b,int d)" << endl;
	}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{
		cout << "Derived(const Derived& d)" << endl;
	}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}
		cout << "Derived& operator=(const Derived& d)" << endl;
		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};

int main()
{
	Derived d1(1, 2);
	Derived d2(3, 4);
	Derived d3(d1);
	d1 = d2;
	return 0;
}
#endif


#if 0
class Base
{
	friend void TestFriend();
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
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
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};


void TestFriend()
{
	Base b(1);
	b._b = 10;

	Derived d(1, 2);
	d._d = 100;
}

int main()
{
	TestFriend();
	return 0;
}
#endif

#if 0
class Student;
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
void Display(const Person& p, const Student& s) {
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


#if 0
class Person
{
public:
	Person() 
	{ 
		++_count; 
	}
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

void main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
} 
#endif


class  Base
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	void TestFunc(int b)
	{
		Base::_b = 100;
		__super::_b = 10;
		cout << "Derived::TestFunc()" << endl;
	}

	char _b;
};

int main()
{
	Derived d;
	d.TestFunc(10);
	d.Base::TestFunc();

	d.Base::_b = 10;
	return 0;
}
