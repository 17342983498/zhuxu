#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#include <time.h>

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
	}


	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(5);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(6);
	lt.push_back(4);
	lt.push_back(0);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.sort();
	// 迭代器功能分类
	// 1、单向  ++
	// 2、双向  ++  --  
	// 3、随机  ++  --  +  -
	//sort(lt.begin(), lt.end());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);

	list<int> lt1;
	list<int> lt2;
	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		//v.push_back(e);
		lt1.push_back(e);
		lt2.push_back(e);
	}

	// 拷贝到vector排序，排完以后再拷贝回来
	int begin1 = clock();
	for (auto e : lt1)
	{
		v.push_back(e);
	}
	sort(v.begin(), v.end());
	size_t i = 0;
	for (auto& e : lt1)
	{
		e = v[i++];
	}
	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

#include "List.h"

int main()
{
	//test_list2();
	//test_op();

	bit::test_list3();

	return 0;
}