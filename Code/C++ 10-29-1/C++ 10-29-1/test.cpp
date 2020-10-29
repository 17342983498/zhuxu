#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

void TestFunc1()
{
	vector<int> v1;
	vector<int> v2(4, 100);
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v3(a, a + sizeof(a) / sizeof(a[0]));
	//char* s = "hello";
	//vector<char> v4(s.begin(), s.end());
	vector<int> v5(v3);
}

void TestFunc2()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	for (auto e : v1)
	{
		e *= 2;
		cout << e << " ";
	}
	cout << endl;
    for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::const_iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void TestFunc3()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	//cout << v1.size() << endl;
	//cout << v1.capacity() << endl;
	//v1.clear();
	//if (v1.empty())
	//{
	//	cout << "vectorÎª¿Õ" << endl;
	//}
	//else
	//	cout << "vector²»Îª¿Õ" << endl;
	//v1.resize(5);
	//v1.resize(8,10);
	//v1.resize(12);
	//v1.resize(15, 100);

	v1.reserve(5);
	v1.resize(5);
	v1.reserve(8);
	v1.resize(8, 10);
	v1.reserve(12);
	v1.resize(12);
	v1.reserve(20);
	v1.resize(15, 100);
}
int main()
{
	//TestFunc1();
	//TestFunc2();
	TestFunc3();
	return 0;
}