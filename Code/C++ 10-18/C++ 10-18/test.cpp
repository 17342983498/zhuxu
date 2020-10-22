#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//template<class T,class U>
//T Add(T a, U b)
//{
//	return a + b;
//}

template<class T>
T Add(T a, T b)
{
	cout << typeid(T).name() << " " << typeid(T).name() << endl;
	return a + b;
}

int main()
{
	Add(1, 2);
	Add<int>(1, 2.0);
	Add<int>(2.0, 1.0);
	return 0;
}