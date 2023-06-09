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

	//���������C++11���Զ������ƶ�
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

	//ͷ��0
	l.push_front(0);
	PrintList(l);

	//ͷɾ
	l.pop_front();
	PrintList(l);

	//β��6
	l.push_back(6);
	PrintList(l);

	//βɾ
	l.pop_back();
	PrintList(l);

}

void ListTest4()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto pos = ++l.begin();
	cout << *pos << endl;

	// ��posǰ����ֵΪ0��Ԫ��
	l.insert(pos, 0);
	PrintList(l);

	// ��posǰ����6��ֵΪ6��Ԫ��
	l.insert(pos, 6, 6);
	PrintList(l);

	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 7, 8, 9 };
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	// ɾ��posλ���ϵ�Ԫ��
	l.erase(pos);
	PrintList(l);

	//// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
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

	//�Ƴ������е���ֵ5
	l1.remove(5);
	PrintList(l1);

	//�Ƴ���ֵ10����Ȼ������û��������֣������ᱨ��
	l1.remove(10);
	PrintList(l1);

	//ȥ������ֵ
	l1.unique();
	PrintList(l1);

	//����
	l1.sort();
	PrintList(l1);

	//�ϲ�
	l1.merge(l2);
	PrintList(l1);

	//��ת
	l1.reverse();
	PrintList(l1);
}





int main()
{
	ListTest6();
	return 0;
}