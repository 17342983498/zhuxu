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
//	auto c = 3, d = 4.0;//һ�е�Ԫ������Ҫһ��
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
    //Ҫ���������Ĳ���ֵ���иı䣬�������õķ�ʽ����������Ϊû�������õĻ� e �൱������Ԫ�صĿ�����������ȥ�ı��������Ԫ�ش�С��
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