#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class A1
{
public:
	int a1;
};

class A2
{
public:
	int a2;
};

//class B:public A1 ,public A2
//{
//public:
//	int b;
//};

class B :public A2, public A1
{
public:
	int b;
};

int main()
{
	B b;
	b.a1 = 1;
	b.a2 = 2;
	b.b = 3;
	return 0;
}
#endif 


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

class C :public B1, public B2
{
public:
	int _c;
};

int main()
{
	C c;
	cout << sizeof(c) << endl;
	c.B1::_a = 10;
	c._b1 = 20;
	return 0;
}
#endif


class A
{
public:
	int _a;
};

class B:virtual public A
{
public:
	int _b;
};

int main()
{
	cout << sizeof(B) << endl;
	B b;
	b._a = 1;
	b._b = 2;
	return 0;
}