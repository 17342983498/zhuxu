#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// ��̬��������
// 1���麯������д -- ��ͬ(������������������ֵ)
// 2������ָ���������ȥ����
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//
//void Func(Person* p)
//{
//	// 1���������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
//	// 2�������̬   -- ��ָ��Ķ�������ͣ�����������͵ĳ�Ա����
//	p->BuyTicket();
//
//	delete p;
//}
//
//int main()
//{
//	Func(new Person);
//	Func(new Student);
//
//	return 0;
//}

//void Func(Person& p)
//{
//	// 1���������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
//	// 2�������̬   -- ��ָ��Ķ�������ͣ�����������͵ĳ�Ա����
// 	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////
// ��̬��������
// 1���麯������д -- ��ͬ(������������������ֵ) 
//    -- ����(Э��)������ֵ���Բ�ͬ�������Ǹ��ӹ�ϵָ���������
//    -- ���⣺�����麯�����Բ���virtual
// 2������ָ���������ȥ����
//
//class A{};
//class B : public A {};
//
//class Person {
//public:
//	virtual Person* BuyTicket()
//	//virtual A* BuyTicket()
//	{ 
//		cout << "��Ʊ-ȫ��" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual Student* BuyTicket()
//	//virtual B* BuyTicket() 
//	{ 
//		cout << "��Ʊ-���" << endl;
//		return nullptr;
//	}
//};


//void Func(Person* p)
//{
//	// 1���������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
//	// 2�������̬   -- ��ָ��Ķ�������ͣ�����������͵ĳ�Ա����
//	p->BuyTicket();
//
//	delete p;
//}
//
//int main()
//{
//	Func(new Person);
//	Func(new Student);
//
//	return 0;
//}

//void Func(Person p)
//{
//	// 1���������̬ -- �������ߵ����ͣ�����������͵ĳ�Ա����
//	// 2�������̬   -- ��ָ��Ķ�������ͣ�����������͵ĳ�Ա����
// 	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//
//	virtual void test(){ func(); }
//};

//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car{
//public:
//	virtual void Drive(){}
//};
//
//// ����Ƿ������д�����Ǿͱ���
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

//class A
//{
//public:
//	virtual void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}

///////////////////////////////////////////////////////////////////
//class Car
//{
//public:
//	// ���麯��  -- ������ -- ����ʵ����������
//	virtual void Drive() = 0;
//};
//
//// һ����������ʵ��û�ж�Ӧ��ʵ�壬���ǾͿ���һ���ඨ��Ϊ������
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//
//
//int main()
//{
//	// Car car;
//	BMW bmwCar;
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////
// ԭ���
// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base bb;
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void Func() { cout << "��Ʊ-ȫ��" << endl; }
//
//	int _a = 0;
//
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//	int _b = 1;
//};
//
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//
////int main()
////{
////	Person mike;
////	Func(mike);
////
////	Student johnson;
////	Func(johnson);
////
////	mike = johnson;
////
////	return 0;
////}
//
//int main()
//{
//	Student johnson;
//	Func(johnson);
//
//	Person mike = johnson;
//
//	return 0;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b1;
	Base b2;
	Base b3;

	Derive d;

	b1.Func1();
	b1.Func3();


	return 0;
}