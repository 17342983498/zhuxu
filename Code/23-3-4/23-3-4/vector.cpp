#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

void TestVector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (auto e : v)
	{
		cout << e << " ";
		++e;
	}
	cout << endl;


	vector<int> v1(v);
	for (auto e : v1)
	{
		cout << e << " ";
		++e;
	}
	cout << endl;
	vector<int> v2(v.begin(), v.end());
	for (auto e : v2)
	{
		cout << e << " ";
		++e;
	}
	cout << endl;
}


void TestVector2()
{
	vector<int> v(5, 100);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



void TestVector3()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	cout << v.capacity() << endl;
}



void TestVector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10, 0);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(13);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void TestVector5()
{
	vector<int> v;
	int sz = v.capacity();
	cout << "making v grow:" << endl;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			cout << "capacity changed: " << sz << endl;
			sz = v.capacity();
		}
	}
}


void TestVector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.pop_back();
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void TestVector7()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	v.insert(pos, 0);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;


	//pos = find(v.begin(), v.end(), 0);
	v.erase(pos);
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}



void TestVector8()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	vector<int> swapv;
	swapv.swap(v);
	vector<int>::iterator it = swapv.begin();
	while (it != swapv.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	swapv[0] += 5;
	cout << swapv[0] << endl;

	for (size_t i = 0; i < swapv.size(); ++i)
	{
		swapv[i] += 1;
	}


	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;
}

int main()
{
	TestVector8();
	return 0;
}