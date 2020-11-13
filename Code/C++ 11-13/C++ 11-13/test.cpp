#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>
//ππ‘Ï
void TestFunc1()
{
	list<int> L1;

	list<int> L2(4, 10);
	for (auto e : L2)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << L2.size() << endl;

	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L3(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << L3.size() << endl;

	list<int> L4(L3);
	for (auto e : L4)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << L4.size() << endl;

}

void TestFunc2()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = L.rbegin();
	while (rit != L.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void TestFunc3()
{
	list<int> L{ 0, 1, 2, 3 };
	L.resize(10, 4);
	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestFunc4()
{
	list<int> L{ 0, 1, 2, 3 };
	cout << L.front() << endl;
	cout << L.back() << endl;
}

void TestFunc5()
{
	list<int> L{ 1, 2, 3 };

	L.push_back(4);
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

void TestFunc6()
{
	list<int> L{ 1, 2, 3 };
	L.insert(find(L.begin(), L.end(), 2), 0);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.erase(find(L.begin(), L.end(), 0));
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int> L1{ 4, 5, 6 };
	L.swap(L1);

	L1.clear();
}

bool even(int data)
{
	return 0 == data % 2;
}
bool greater(int left,int right)
{
	return left > right;
}
bool lesser(int left, int right)
{
	return left < right;
}
void TestFunc7()
{
	list<int> L{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	L.remove(5);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
	L.remove_if(even);
	list<int> L1{ 1, 5, 3, 9, 7, 2, 6, 0, 4, 8 };
	L1.sort();
	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;

	L1.sort(greater);
	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;

	L1.sort(lesser);
	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestFunc8()
{
	list<int> L{ 1, 1, 2, 2, 2, 3, 4, 4, 5, 6, 6 };
	L.unique();
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> L1{ 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 2 };
	L1.sort();
	L1.unique();
	for (auto e : L1)
	{
		cout << e << " ";
	}
	cout << endl;


	list<int> L2{ 1, 2, 3 };
	list<int> L3{ 4, 5, 6, 7 };
	L2.merge(L3);
	for (auto e : L2)
	{
		cout << e << " ";
	}
	cout << endl;

	L2.reverse();
	for (auto e : L2)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	// TestFunc1();
	// TestFunc2();
	// TestFunc3();
	// TestFunc4();
	// TestFunc5();
	// TestFunc6();
	// TestFunc7();
	TestFunc8();
	return 0;
}