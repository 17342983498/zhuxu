#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include <time.h>

using namespace std;

//void ListTest1()
//{
//	list<int> l1;
//	list<int> l2(5, 10);
//	list<int> l3(l2);
//	int arr[] = { 1, 2, 3, 4, 5 };
//	list<int> l4(arr,arr+sizeof(arr)/sizeof(arr[0]));
//	list<int> l5(l4.begin(), l4.end());
//
//	for (auto& e : l3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}


void PrintList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void ListTest2()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//这里可以用C++11的自动类型推断
	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void ListTest3()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//头插0
	l.push_front(0);
	PrintList(l);

	//头删
	l.pop_front();
	PrintList(l);

	//尾插6
	l.push_back(6);
	PrintList(l);

	//尾删
	l.pop_back();
	PrintList(l);

}

void ListTest4()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto pos = ++l.begin();
	cout << *pos << endl;

	// 在pos前插入值为0的元素
	l.insert(pos, 0);
	PrintList(l);

	// 在pos前插入6个值为6的元素
	l.insert(pos, 6, 6);
	PrintList(l);

	// 在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 7, 8, 9 };
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	// 删除pos位置上的元素
	l.erase(pos);
	PrintList(l);

	//// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
	//l.erase(l.begin(), l.end());
	//PrintList(l);

	l.clear();
	PrintList(l);
}


//void ListTest5()
//{
//	list<int> l1{ 0, 1, 2, 3, 4 };
//	list<int> l2{ 5, 6, 7, 8, 9 };
//
//	PrintList(l1);
//	l1.clear();
//	PrintList(l1);
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	l1.clear();
//	cout << l1.size() << endl;
//}


void ListTest6()
{
	int n = 1000000;
	vector<int> v;
	list<int> l;
	srand(time(nullptr));
	int begin1 = clock();
	for (int i = 0; i < n; ++i)
	{
		auto e = rand();
		v.push_back(e);
	}
	int end1 = clock();
	cout << end1 - begin1 << endl;


	int begin2 = clock();
	for (int i = 0; i < n; ++i)
	{
		auto e = rand();
		l.push_back(e);
	}
	int end2 = clock();
	cout << end2 - begin2 << endl;
}

void ListTest7()
{
	list<int> l1{ 2, 0, 0, 3, 0, 1, 4, 5 };
	list<int> l2{6, 7, 8, 9};

	//移除容器中的数值5
	l1.remove(5);
	PrintList(l1);

	//移除数值10，虽然容器中没有这个数字，但不会报错
	l1.remove(10);
	PrintList(l1);

	//去除冗余值
	l1.unique();
	PrintList(l1);

	//排序
	l1.sort();
	PrintList(l1);

	//合并
	l1.merge(l2);
	PrintList(l1);

	//反转
	l1.reverse();
	PrintList(l1);
}





int main()
{
	ListTest6();
	return 0;
}