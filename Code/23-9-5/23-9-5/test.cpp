#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

template<class T1,class T2>
void DeclFunc(T1 t1, T2 t2)
{
	decltype(t1*t2) ret;
	cout << typeid(ret).name() << endl;
}

//int main()
//{
//	//auto il = { 1, 2, 3 };
//	//cout << typeid(il).name() << endl;
//
//	const int x = 1;
//	double y = 3.14;
//	decltype(x*y) ret;
//	decltype(&y) p;
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//
//	DeclFunc(1, '1'); // int
//	DeclFunc('1', 1); // int 
//	DeclFunc(3.14,3.14f); // double
//	DeclFunc(1, 3.14); //double
//	return 0;
//}

//int func(int x, int y)
//{}
//
//int main()
//{
//	//左值
//	int a = 10;
//	int* p = &a;
//	const int c = 20;
//
//	//左值引用
//	int& ra = a;
//	int*& rp = p;
//	const int& rc = c;
//
//	//右值（字面常量、表达式返回值、函数返回值）
//	int x = 1, y = 2;
//	int&& ret1 = 10;
//	int&& ret2 = (x + y);
//	int&& ret3 = func(x, y);
//}



int main()
{
	// 左值引用只能引用左值，不能引用右值
	int a = 10;
	int& ra = a;//左值引用
	//int& rra = 10;//10为字面常量，是右值
	const int& rra = 10;


	//右值引用只能引用右值，不能引用左值
	int&& raa = 10;
	
	int b = 20;
	//int&& rb = b;//b为左值
	int&& rb = move(b);
	return 0;
}