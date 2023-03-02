#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>


void VectorTest1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void VectorTest2()
{
	vector<int> v(5, 6);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v1(v.begin(), v.end());

	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	vector<int> v2(v);
	vector<int>::iterator it2 = v2.begin();
	while (it2 != v2.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}


void VectorTest3()
{
	vector<int> v;
	cout << v.max_size() << endl;

	v.reserve(10);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	cout << v.empty() << endl;
	v.resize(5, 'a');
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	cout << v.empty() << endl;
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}


void VectorTest4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << v.at(3) << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v.back() << endl;

	vector<int>::iterator it = v.begin();
	v.insert(it + 2, 0);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.insert(it + 2, 5, 100);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;


	it = v.begin();
	v.erase(it + 2, it + 8);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int> v1(5, 100);
	v.insert(it+2, v1.begin(), v1.end());
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.insert(it + 2, v1.begin()++, v1.end()--);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	VectorTest4();
	return 0;
}