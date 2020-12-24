#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>

class Compare
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

int main()
{
	string fruits[] = { "apple", "apple", "orange", "orange", "banana", "banana", "apple", "orange", "banana", "banana", "peach", "banana", "banana", "banana", "watermelon", "banana", "banana" };

	map<string, size_t> m;
	for (auto& e : fruits)
		m[e]++;  // <e, 0>向map中插入--->如果e不存在返回0  如果e存在返回值e对应的次数

	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());

	vector<string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	for (auto e : favourite)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(favourite.begin(), favourite.end());
	for (auto e : favourite)
	{
		cout << e << " ";
	}
	cout << endl;

	/*set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}*/
	return 0;
}