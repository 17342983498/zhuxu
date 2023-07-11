#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//int main()
//{
//	int a = 10;
//	double b = a;
//	printf("%d %f\n", a, b);
//
//	int *p = &a;
//	int addres = (int)p;
//	printf("%p %d\n", p, addres);
//	return 0;
//}

//C++强制类型转换
//static_cast----相当于C语言中的隐式类型转换（两个相关类型）

//int main()
//{
//	double a = 3.14;
//	int b = static_cast<int>(a);
//	cout << b << endl;
//	return 0;
//}

//reinterpret_cast
//int main()
//{
//	int a = 10;
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//	return 0;
//}


//const_cast
//int main()
//{
//	//volatile const int a = 2;
//	volatile const int a = 2;
//	int *p = (int*)&a;
//	//int *p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << " " << *p << endl;
//	return 0;
//}
//变量a被修改了，但是打印的结果还是修改之前的值，这是因为a被const修饰，系统认为它是不能被修改
//于是编译器就会进行优化，可能将a的值存入到寄存器中而不在内存中去拿a的值
//VS的优化是直接替换的
//volatile不允许被优化


//dynamic_cast
class A
{
public:

	virtual void f(){}
};

class B : public A
{};

void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	/*B* pb1 = static_cast<B*>(pa);*/
	B* pb1 = (B*)pa;
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl << endl;
}


//void fun(B* pb)
//{
//	B* pb1 = (B*)pb;
//	B* pb2 = dynamic_cast<B*>(pb);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl << endl;
//}

//int main()
//{
//	A a;
//	B b;
//	//fun(&a);
//	fun(&b);
//	return 0;
//}


int main()
{
	clog << "dfsdfds" << endl;
}