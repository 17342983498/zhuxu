#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class A
{
public:
	void TestFunc()
	{
		cout << "A()" << endl;
	}
	int _a;
};

class B1 :public A
{
public:
	void TestFunc()
	{
		cout << "B1" << endl;
	}
	int _b1;
};

class B2 :public A
{
public:
	void TestFunc()
	{
		cout << "B2" << endl;
	}
	int _b2;
};

class C :public B1, public B2
{
public:
	void TestFunc()
	{
		cout << "C" << endl;
	}
	int _c;
};

int main()
{
	//A a;
	//a.TestFunc();
	//B1 b1;
	//B2 b2;
	C c;
	c.TestFunc();
	c.B1::TestFunc();
	//a._a = 1;
	//b1._b1 = 2;
	//b2._b2 = 3;
	//c._c = 4;
	return 0;
}
#endif


#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

class D : public B2, public B1
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif


#if 0
class A
{
public:
	void TestFunc()
	{
		cout << "A()" << endl;
	}
	int _a;
};

class B1 :public A
{
public:
	void TestFunc()
	{
		cout << "B1" << endl;
	}
	int _b1;
};

class B2 :public A
{
public:
	void TestFunc()
	{
		cout << "B2" << endl;
	}
	int _b2;
};

class C :public B1, public B2
{
public:
	void TestFunc()
	{
		cout << "C" << endl;
	}
	int _c;
};

int main()
{
	C c;
	c._a = 0;//存在二义性，不知道该访问哪一个类中的 _a
	c._b1 = 1;
	c._b2 = 2;
	c._c = 3;
	return 0;
}
#endif


#if 0
class A
{
public:
	void TestFunc()
	{
		cout << "A()" << endl;
	}
	int _a;
};

class B1 :virtual public A
{
public:
	void TestFunc()
	{
		cout << "B1" << endl;
	}
	int _b1;
};

class B2 :virtual public A
{
public:
	void TestFunc()
	{
		cout << "B2" << endl;
	}
	int _b2;
};

class C :public B1, public B2
{
public:
	void TestFunc()
	{
		cout << "C" << endl;
	}
	int _c;
};

int main()
{
	C c;
	c._a = 0;
	c._b1 = 1;
	c._b2 = 2;
	c._c = 3;
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

protected:
	string _name;
	string _gender;
	int _age;
};


class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免费票" << endl;
	}
protected:
	int _solID;
};

// 代码只有一份，但是最后产生的结果却不同
void TestBuyTicket(Person* p)
{
	// p.BuyTicket();
	p->BuyTicket();
}

int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(&p);
	TestBuyTicket(&stu);
	TestBuyTicket(&sol);
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

protected:
	string _name;
	string _gender;
	int _age;
};


class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免费票" << endl;
	}
protected:
	int _stuID;
};


void TestBuyTicket(Person& p)
{
	 p.BuyTicket();
}

int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(p);
	TestBuyTicket(stu);
	TestBuyTicket(sol);
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

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};


class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "半价票" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "免费票" << endl;
	}

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "免费票" << endl;
	}
protected:
	int _stuID;
};

void TestBuyTicket(Person* p)
{
	p->BuyTicket();
	p->BuyTicket(1);
}

int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(&p);
	TestBuyTicket(&stu);
	TestBuyTicket(&sol);
	return 0;
}
#endif


class Person
{
public:
	virtual void BuyTicket1()
	{
		cout << "全价票" << endl;
	}

	virtual Person* BuyTicket2()
	{
		cout << "全价票" << endl;
		return this;
	}
protected:
	string _name;
	string _gender;
	int _age;
};


class Student : public Person
{
public:
	virtual void BuyTicket1()
	{
		cout << "半价票" << endl;
	}

	virtual Student* BuyTicket2()
	{

		cout << "半价票" << endl;
		return this;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket1()
	{
		cout << "免费票" << endl;
	}

	virtual Soldier* BuyTicket2()
	{
		cout << "免费票" << endl;
		return this;
	}
protected:
	int _stuID;
};

void TestBuyTicket(Person* p)
{
	p->BuyTicket1();
	p->BuyTicket2();
}

int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(&p);
	TestBuyTicket(&stu);
	TestBuyTicket(&sol);
	return 0;
}