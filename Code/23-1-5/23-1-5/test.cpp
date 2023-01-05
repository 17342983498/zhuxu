#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int& add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//
//int main()
//{
//	int& ret = add(1, 2);
//	add(3, 4);
//	cout << "add(1,2)=" << ret << endl;
//	return 0;
//}

//int& count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int ret = count();
//	cout << ret << endl;
//	return 0;
//}

int main()
{
	const int a = 10;
	const int& aa = a;
	return 0;
}