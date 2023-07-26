#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <set>
#include <map>
#include <string>

//void test_set()
//{
//	int arr[] = { 2, 4, 5, 8, 1, 3, 6, 9, 7 };
//	set<int> s(arr,arr+sizeof(arr)/sizeof(arr[0]));
//
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	s.insert(2);//˵������set�У�����һ��ԭ�����ڵ�key�ǲ��ɹ���
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	auto pos = s.find(2);
//	s.erase(pos);//ɾ��posλ�ô���Ԫ��
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	s.erase(9);//ɾ��Ԫ��9
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	pos = s.find(5);
//	s.erase(s.begin(), pos);//����ҿ�
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test_multiset()
//{
//	int arr[] = { 2, 4, 5, 8, 1, 3, 6, 9, 7 };
//	multiset<int> s(arr,arr+sizeof(arr)/sizeof(arr[0]));
//	
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	
//	s.insert(2);
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}


//void test_map()
//{
//	map<string, string> m;
//	m.insert(make_pair("bnana", "�㽶"));
//	m.insert(make_pair("grapes", "����"));
//	m.insert(make_pair("apple", "ƻ��"));
//	m.insert(make_pair("peach", "����"));
//	m.insert(make_pair("watermelon", "����"));
//	for (auto& kv : m)
//	{
//		cout << kv.first << " " << kv.second << endl;
//	}
//
//	m.insert(make_pair("peach", "������"));//����ʧ��
//	for (auto& kv : m)
//	{
//		cout << kv.first << " " << kv.second << endl;
//	}
//
//	m["strawberry"] = "��ݮ";
//	for (auto& kv : m)
//	{
//		cout << kv.first << " " << kv.second << endl;
//	}
//}

void test_map()
{
	string arr[] = { "red", "blue", "black", "white", "yellow", "blue", "yellow" };
	map<string, int> m;


	//for(auto& e:arr)
	//{
	//	auto ret = m.find(e);
	//	if (ret == m.end())
	//	{
	//		m.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}

	for (auto& e : arr)
	{
		m[e]++;
	}
	for (auto& e : m)
	{
		cout << e.first << " " << e.second << endl;
	}
}

int main()
{
	//test_set();
	//test_multiset();
	test_map();
	return 0;
}