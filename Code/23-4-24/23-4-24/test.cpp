#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

// set  -- key
// map  -- key/value

void test_set1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// �������������޸�key�����ܻ��ƻ������Ĺ���
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ��Χfor
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	// ���� + ȥ��
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	int x;
	while (cin >> x)
	{
	/*	auto ret = s1.find(x);
		if (ret != s1.end())
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}*/

		
		if (s1.count(x))
		{
			cout << "��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
	}
}
//
//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};

void test_set3()
{
	// ����
	multiset<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);

	multiset<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// �������������޸�key�����ܻ��ƻ������Ĺ���
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// ���key��find����ĵ�һ��key
	auto ret = s1.find(1);
	while (ret != s1.end() && *ret == 1)
	{
		cout << *ret << " ";
		++ret;
	}
	cout << endl;

	cout << s1.count(1) << endl;
	cout << s1.count(2) << endl;
}

void test_map1()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));

	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << ":" << (*dit).second << endl;
		++dit;
	}
	cout << endl;
}

void test_map2()
{
	// 21:00����
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));
	dict.insert(make_pair("string", "(�ַ���)")); // ����ʧ��

	dict["left"];			// ����
	dict["right"] = "�ұ�"; // ����+�޸�
	dict["string"] = "(�ַ���)"; // �޸�
	cout << dict["string"] << endl; // ����
	cout << dict["string"] << endl; // ����


	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << ":" << dit->second << endl;

		++dit;
	}
	cout << endl;
}

void test_map3()
{
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶", "��" };
	map<string, int> countMap;
	//for (auto& e : arr)
	//{
	//	auto ret = countMap.find(e);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}

	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

//V& operator[](const K& key)
//{
//	pair<iterator, bool> ret = insert(make_pair(key, V()));
//	return ret.first->second;
//}

//int main()
//{
//	//test_set3();
//	test_map2();
//
//	return 0;
//}

int main()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "����"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("count", "����"));
	dict.insert(make_pair("string", "(�ַ���)")); // ����ʧ��

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	multimap<string, string> mdict;
	//dict.insert(pair<string, string>("sort", "����"));
	mdict.insert(make_pair("sort", "����"));
	mdict.insert(make_pair("string", "�ַ���"));
	mdict.insert(make_pair("count", "����"));
	mdict.insert(make_pair("string", "(�ַ���)")); // ����ʧ��
	mdict.insert(make_pair("string", "�ַ���"));

	for (auto& kv : mdict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}