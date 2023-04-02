#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//bool func(int num)//ÅÐ¶ÏÊÇ·ñÎªËØÊý
//{
//	for (int i = 2; i<num; ++i)
//	{
//		if (num%i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int x = n / 2, y = n / 2;
//	while (x >= 2)
//	{
//		if (func(x) && func(y))
//		{
//			cout << x << endl;
//			cout << y << endl;
//			break;
//		}
//		x--;
//		y++;
//	}
//
//	return 0;
//}


//int main()
//{
//	int n = 0,m = 0,i = 0,j = 0;
//	cin >> n >> m >> i >> j;
//	m = (m << i);
//	n = (n | m);
//	cout << n << endl;
//	return 0;
//}

#include <string>

void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "first capacity: " << sz << endl;
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

int main()
{
	string s("aaaaaaaaa");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;


	s.reserve(3);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.reserve(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	
	s.reserve(3);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	
	s.resize(3);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	//TestPushBack();
	return 0;
}