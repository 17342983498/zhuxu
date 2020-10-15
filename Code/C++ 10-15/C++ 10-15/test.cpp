#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template <typename T>

T Add(T a, T b)
{
	cout << typeid(T).name() << endl;
	return a + b;
}

template <typename T,typename U>

T Add(T a, U b)
{
	cout << typeid(T).name() << <<" "<<typeid(U).name()  << endl;
	return a + b;
}

//int Add(int a, int b)
//{
//	cout << typeid(T).name() << endl;
//	return a + b;
//}
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add(1, 2.0);
	Add(1.0, 2);
	Add<int,int>(1.0, 2.0);
	return 0;
}