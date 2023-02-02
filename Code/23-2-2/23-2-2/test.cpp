#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int a = 1;
//	auto b = 2.0;
//	auto& c = a;
//	auto d = &a;
//	auto* f = &a;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(f).name() << endl;
//
//	return 0;
//}


//int main()
//{
//	auto a = 1, b = 2;
//
//	auto c = 3, d = 4.0;//一行的元素类型要一致
//
//	return 0;
//}


//int main()
//{
//	int array[] = { 0, 1, 2, 3, 4 };
//
//	for (auto e:array)
//	//for (auto& e : array)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}



//int main()
//{
//	int array[] = { 0, 1, 2, 3, 4 };
//
    //要将数组的里的参数值进行改变，得用引用的方式来操作，因为没有用引用的话 e 相当于数组元素的拷贝，并不会去改变数组里的元素大小。
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//
//	for (auto e : array)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	f(nullptr);
	f((int*)NULL);
	return 0;
}