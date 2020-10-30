#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void TestFunc1()
{
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v1.resize(5);
	v1.resize(10, 10);
	v1.resize(15);
	v1.reserve(15);
	v1.reserve(20);
	cout << "v1 contain:";
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << " " << v1[i];
	}
	cout << endl;
}

void TestFunc2()
{
	size_t sz;
	vector<int> v1;
	sz = v1.capacity();
	cout << sz << endl;
	cout << "making v1 grow:"<<endl;
	for (size_t i = 0; i < 100; i++)
	{
		v1.push_back(i);
		if (sz != v1.capacity())
		{
			sz = v1.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void TestFunc3()
{
	vector<int> v1;
	size_t sz = v1.capacity();
	v1.reserve(100);
	cout << "making v1 grow:" << endl;
	for (size_t i = 0; i < 100; i++)
	{
		v1.push_back(i);
		if (sz != v1.capacity())
		{
			sz = v1.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void TestFunc4()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> ::iterator it = v.begin();
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void TestFunc5()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

	vector<int> ::iterator pos = find(v.begin(),v.end(),3);
	v.insert(pos, 100);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 100);
	v.erase(pos);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void TestFunc6()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	v[9] = 10;
	cout << v[9] << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);

	cout << "v data:";
	it = v.begin();
	while (it != v.end())
	{
		cout << "v" << endl;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = swapv.begin();
	while (it != swapv.end())
	{
		cout << "swapv" << endl;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	//TestFunc1();
	//TestFunc2();
	//TestFunc3();
	//TestFunc4();
	//TestFunc5();
	TestFunc6();
	return 0;
}