#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>

void TestFunc1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	L.empty();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;
	L.push_back(7);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.push_front(0);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.pop_back();
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.pop_front();
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestFunc2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//L.insert(find(L.begin(), L.end(), 4), 0);
	//list<int>::iterator it = L.begin();
	////auto it = L.begin();
	//while (it != L.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	L.erase(find(L.begin(), L.end(), 4));
	list<int>::iterator it = L.begin();
	//auto it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestFunc3()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int> L1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L2(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
	L1.swap(L2);
	auto it = L1.begin();
	while (it != L1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto it1 = L2.begin();
	while (it1 != L2.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	L1.clear();
	cout << L1.size() << endl;
}

void TestFunc4()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	auto it = L.begin();
	while (it != L.end())
	{
		//L.erase(it);
		//++it;
		it = L.erase(it);
	}
	cout << L.size() << endl;
}

int main()
{
	//TestFunc1();
	//TestFunc2();
	//TestFunc3();
	TestFunc4();
	return 0;
}