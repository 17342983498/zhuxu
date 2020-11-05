#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>
#include <vector>

void TestFunc1()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));
	L.push_back(7);
	L.pop_back();
	L.push_front(0);
	L.pop_front();
	L.insert(find(L.begin(), L.end(), 3), 7);
	L.erase(find(L.begin(), L.end(), 7));
	vector<int> v = { 7, 8, 9 };
	L.insert(find(L.begin(), L.end(), 6),v.begin(), v.end());
}

int main()
{
	TestFunc1();
	return 0;
}