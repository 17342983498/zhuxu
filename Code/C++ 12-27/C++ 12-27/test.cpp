#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0
#include <map>
int main()
{
	map<string, string> m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("orange", "橘子"));
	m.insert(make_pair("watermelon", "西瓜"));

	auto ret = m.insert(make_pair("grapes", "葡萄"));//返回值为 0 或 1
	if (ret.second)
	{
		cout << ret.second << endl;
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败，map中已存在该对象" << endl;
	}

	auto ret1 = m.insert(make_pair("apple", "苹果"));
	if (ret1.second)
	{
		cout << ret1.second << endl;
		cout << "插入成功" << endl;
	}
	else
	{
		cout << ret1.second << endl;
		cout << "插入失败，map中已存在该对象" << endl;
	}

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())
	{
		cout << rit->first << " ";
		++rit;
	}
	cout << endl;

	for (auto& e : m)
	{
		cout << e.first << " ";
	}
	cout << endl;

	cout << m.size() << endl;

	m.erase("apple");

	cout << m.size() << endl;

	m.clear();

	cout << m.size() << endl;

	if (m.empty())
	{
		cout << "map is empty!" << endl;
	}
	return 0;
}
#endif

#if 0
#include <map>

int main()
{
	multimap<string, string> m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("orange", "橘子"));
	m.insert(make_pair("watermelon", "西瓜"));
	m.insert(make_pair("banana", "香蕉"));
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;
	return 0;
}
#endif


#include <set>

int main()
{
	int array[] = { 1, 5, 3, 7, 2, 4, 3, 8, 4, 7, 9, 2, 5, 6 };
	set<int>s(array, array + sizeof(array) / sizeof(array[0]));

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.insert(10);

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.erase(1);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.count(3) << endl;
	return 0;
}