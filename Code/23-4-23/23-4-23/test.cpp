#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <set>
#include <map>
#include <string>

//void set_test1()
//{
//	int arr[] = { 1, 5, 2, 3, 6, 9, 7, 4, 1, 2, 5, 6 };
//	set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	cout << s.size() << endl;
//
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	cout << s.count(1) << endl;
//}


//void set_test2()
//{
//	int arr[] = { 1, 5, 2, 3, 6, 9, 7, 4, 1, 2, 5, 6 };
//	multiset<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	cout << s.size() << endl;
//
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	cout << s.count(1) << endl;
//}



//void map_test1()
//{
//	map<string, string> m;
//	m.insert(make_pair("Æ»¹û", "apple"));
//	m.insert(make_pair("Ïã½¶", "banan"));
//	m.insert(make_pair("ÆÏÌÑ", "grape"));
//	m.insert(make_pair("ÌÒ×Ó", "peach"));
//	m.insert(make_pair("Î÷¹Ï", "watermelon"));
//
//	for (auto& e : m)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//
//	map<string, string> ::iterator it = m.begin();
//	while (it != m.end())
//	{
//		//cout << (*it).first << " " << (*it).second << endl;
//		//cout << it->first << " " << it->second << endl;
//		it++;
//	}
//}

void map_test2()
{
	string arr[] = { "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "ÌÒ×Ó", "²ÝÝ®", "Î÷¹Ï", "¸ÊÕá", "Æ»¹û", "Ïã½¶", "ÌÒ×Ó", "²ÝÝ®", "Î÷¹Ï" };
	map<string, int> Mapcount;
	for (auto& e : arr)
	{
		auto ret = Mapcount.find(e);
		if (ret == Mapcount.end())
		{
			Mapcount.insert(make_pair(e, 1));
		}
		else
		{
			ret->second++;
		}
	}
	auto it = Mapcount.begin();
	while (it != Mapcount.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}

}


int main()
{
	//set_test2();
	map_test2();
	return 0;
}