#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 多态的条件：
// 1、虚函数的重写 -- 三同(函数名、参数、返回值)
// 2、父类指针或者引用去调用
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	void BuyTicket() { cout << "买票-半价" << endl; }
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
//	// 1、不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 2、满足多态   -- 看指向的对象的类型，调用这个类型的成员函数
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
//	// 1、不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 2、满足多态   -- 看指向的对象的类型，调用这个类型的成员函数
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
// 多态的条件：
// 1、虚函数的重写 -- 三同(函数名、参数、返回值) 
//    -- 例外(协变)：返回值可以不同，必须是父子关系指针或者引用
//    -- 例外：子类虚函数可以不加virtual
// 2、父类指针或者引用去调用
//
//class A{};
//class B : public A {};
//
//class Person {
//public:
//	virtual Person* BuyTicket()
//	//virtual A* BuyTicket()
//	{ 
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual Student* BuyTicket()
//	//virtual B* BuyTicket() 
//	{ 
//		cout << "买票-半价" << endl;
//		return nullptr;
//	}
//};


//void Func(Person* p)
//{
//	// 1、不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 2、满足多态   -- 看指向的对象的类型，调用这个类型的成员函数
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
//	// 1、不满足多态 -- 看调用者的类型，调用这个类型的成员函数
//	// 2、满足多态   -- 看指向的对象的类型，调用这个类型的成员函数
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
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car{
//public:
//	virtual void Drive(){}
//};
//
//// 检查是否完成重写，不是就报错
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
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
//	// 纯虚函数  -- 抽象类 -- 不能实例化出对象
//	virtual void Drive() = 0;
//};
//
//// 一个类型在现实中没有对应的实体，我们就可以一个类定义为抽象类
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
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
// 原理层
// 这里常考一道笔试题：sizeof(Base)是多少？
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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void Func() { cout << "买票-全价" << endl; }
//
//	int _a = 0;
//
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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