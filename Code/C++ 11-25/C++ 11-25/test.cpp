#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
class Base
{
public:
	void Testfunc()
	{
		cout << "Base()" << endl;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	void Testfunc()
	{
		cout << "Derived()" << endl;
	}
protected:
	int _d;
};

int main()
{
	Derived d;
	d.Testfunc();
	d.Base::Testfunc();
	return 0;
}
#endif


#if 0
class Base
{
public:
	void Testfunc()
	{
		cout << "Base()" << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	void Testfunc()
	{
		_b = 20;
		Base::_b = 20;
		__super::_b = 30;
		cout << "Derived()" << endl;
	}
	int _b;
	int _d;
};

int main()
{
	Derived d;
	Base b;
	b = d; 

	//d = b;

	Base* b = &d;

	//Derived* d = &b;
	//Derived& d = b;

	Derived* d = (Derived*)&b;
	return 0;
}
#endif


#if 0
class Base
{
public:
	void Testfunc()
	{
		cout << "Base()" << endl;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	void Testfunc()
	{
		cout << "Derived()" << endl;
	}
protected:
	int _d;
};

int main()
{
	Derived d;
	d.Testfunc();
	Base b;
	b.Testfunc();
	d.Base::Testfunc();
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

class Derived :public Base
{
public:
	//默认的无参
	Derived()
	{
		cout << "Derived()" << endl;
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
	Derived d;
	return 0;
}
#endif


#if 0
class Base
{
public:
	//默认的全缺省参数
	Base(int b = 10)
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

class Derived :public Base
{
public:
	Derived(int b,int d)
		: _d(d)
	{
		cout << "Derived()" << endl;
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
	Derived d(10, 20);
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b)
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

class Derived :public Base
{
public:
	Derived(int b,int d)
		: _d(d)
		, Base(b)
	{
		cout << "Derived()" << endl;
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
	Derived d(10, 20);
	return 0;
}
#endif


#if 0
class Base
{
public:

	//当用户没有给出构造函数时，系统会自己生成一个默认的构造函数

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
	{
		cout << "Derived()" << endl;
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
	Derived d(10,20);
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b)
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

class Derived :public Base
{
public:
	Derived()
		: _d(20)
		, Base(10)
	{
		cout << "Derived()" << endl;
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
	Derived d;
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int b = 10)
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

class Derived :public Base
{
public:
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
protected:
	int _d;
};

int main()
{
	Derived d;
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

class Derived :public Base
{
public:

	Derived(int b,int d)
		: _d(d)
		, Base(b)
	{
		cout << "Derived()" << endl;
	}

	Derived(const Derived& d)
		:Base(d)
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
	}

protected:
	int _d;
};

int main()
{
	Derived d1(10,20);
	Derived d2(100, 200);
	d2 = d1;
	return 0;
}
#endif


#if 0
class Base
{
	friend void TestFriend();
public:

	Base(int b)
		:_b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& d)
		:_b(d._b)
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

class Derived :public Base
{
public:

	Derived(int b, int d)
		: _d(d)
		, Base(b)
	{
		cout << "Derived()" << endl;
	}

	Derived(const Derived& d)
		:Base(d)
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
	}

protected:
	int _d;
};

void TestFriend()
{
	Base b(10);
	b._b = 20;
	
	//说明：友元函数不能继承
	Derived d(100, 200);
	d._d = 20;
}

int main()
{
	TestFriend();
	return 0;
}
#endif


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
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}
		return *this;
	}
	static void TestFunc()
	{
		cout << "TestFunc()" << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

	int _b;
	static int _c;
};

int Base::_c = 0;
class Derived :public Base
{
public:

	Derived(int b, int d)
		: _d(d)
		, Base(b)
	{
		cout << "Derived()" << endl;
	}

	Derived(const Derived& d)
		:Base(d)
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
	}

protected:
	int _d;
};


int main()
{
	cout << sizeof(Derived) << endl;
	Base::_c = 10;
	Derived::_c = 20;
	cout << &Base::_c << " " << &Derived::_c << endl;
	Derived::TestFunc();
	return 0;
}