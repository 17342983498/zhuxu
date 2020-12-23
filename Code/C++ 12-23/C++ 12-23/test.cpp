#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
#include <map>
#include <string>


int main()
{
	map<string, string> m;

	m.insert(pair<string, string>("apple", "ƻ��"));
	m.insert(pair<string, string>("grape", "����"));
	m.insert(pair<string, string>("orange", "����"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("watermelon", "����"));

	auto it = m.begin();
	while (it != m.end())//����
	{
		cout << it->first << " ";
		it++;
	}
	cout << endl;

	auto rit = m.rbegin();
	while (rit != m.rend())//����
	{
		cout << rit->first << " ";
		rit++;
	}
	cout << endl;


	cout << m.size() << endl;

	m["pear"];
	m["waterme"] = "ˮ����";
	m["orange"] = "����";


	auto ret = m.insert(make_pair("orange", "����"));
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	m.erase("apple");

	auto pos = m.find("orange");
	if (pos != m.end())
	{
		m.erase(pos);
	}

	m.erase(m.begin(), m.end());   // m.clear()
	return 0;
}
#endif



#include <set>
#include <string>

#if 0
// ȥ�� + ����
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	set<string> s(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	s.insert("grape");

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#include <functional>

int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	multiset<string, greater<string>> s;

	for (auto& e : fruits)
		cout << e << " ";
	cout << endl;

	s.insert(fruits, fruits + sizeof(fruits) / sizeof(fruits[0]));

	cout << s.count("apple") << endl;

	for (auto& e : s)
		cout << e << " ";
	cout << endl;

	return 0;
}
