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
	c._a = 0;//���ڶ����ԣ���֪���÷�����һ�����е� _a
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
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}
protected:
	int _solID;
};

// ����ֻ��һ�ݣ������������Ľ��ȴ��ͬ
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
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
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
		cout << "ȫ��Ʊ" << endl;
	}

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
	}

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "���Ʊ" << endl;
	}
protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}

	virtual void BuyTicket(int n)
	{
		cout << n << endl;
		cout << "���Ʊ" << endl;
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
		cout << "ȫ��Ʊ" << endl;
	}

	virtual Person* BuyTicket2()
	{
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
	}

	virtual Student* BuyTicket2()
	{

		cout << "���Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
	}

	virtual Soldier* BuyTicket2()
	{
		cout << "���Ʊ" << endl;
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