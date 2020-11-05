#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>

void TestFunc1()
{
	list<int> L1;
	list<int> L2(10, 5);
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L3(array, array + (sizeof(array) / sizeof(array[0])));
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int> L4(L3);
}

void TestFunc2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L(array, array + (sizeof(array) / sizeof(array[0])));
	//list<int>::iterator it = L.begin();
	//while (it != L.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl; 
	list<int>::reverse_iterator it = L.rbegin();
	while (it != L.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	// TestFunc1();
	TestFunc2();
	return 0;
}