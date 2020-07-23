#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	auto a = 10;
//	auto b = "abcd";                               //auto只是一个占位符，它不是定义类型
//	auto c = 'c';                                  //在编译时，它在编译阶段，编译器会通过推演得到每个变量的定义类型，用此来替换auto
//	auto d = 10.03;                                
//	auto e = a + 10;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	return 0;
//}

#if 0
int main()
{                       //在使用auto定义变量时，必须对变量初始化，因为在编译阶段它要对变量进行推演得到该变量的定义类型
	auto e;
	return 0;
}
#endif

//int main()
//{
//	auto a = 10;//在定义指针变量时，加不加*都无所谓
//	auto ra = &a;        //  auto   ->   int*
//	auto *rra = &a;      //  auto   ->   int
//	cout << typeid(ra).name() << endl;
//	cout << typeid(rra).name() << endl;
//}


int main()
{
	auto a = 10;
	auto& ra = a;//让 ra 引用 a
	auto rra = a;//这个不是让 rra 引用 a，而只是定义了一个rra的变量，该变量使用 a 来进行初始化，与a是同类型的
	//cout << typeid(a).name() << endl;
	//cout << typeid(ra).name() << endl;
	//cout << typeid(rra).name() << endl;
	cout << &a << endl;     //006FFCE8
	
	cout << &ra << endl;    //006FFCE8
	
	cout << &rra << endl;	//006FFCD0
	//根据这个地址可以看出，在使用auto定义引用类型变量时，auto后面必须加上 &
}