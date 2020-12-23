#define _CRT_SECURE_NO_WARNINGS 1


#include <map>
#include <string>
#include <queue>
#include <set>
#include <iostream>
using namespace std;


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
	// 在以下水果中挑出员工最喜欢吃的三种水果---CVTE笔试题
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	// 1. 统计每个水果出现的次数
	// <水果，次数>
	map<string, size_t> m;
	for (auto& e : fruits)
		m[e]++;  // <e, 0>向map中插入--->如果e不存在返回0  如果e存在返回值e对应的次数

	// 2. 找出员工最喜欢吃的K种水果----TOP-K---priority_queue
	// 使用map中的元素构造一个大堆---->按照键值对中的次数进行比较
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());


	// 取到员工最喜欢吃的三种水果
	vector<string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	// 水果--->按照字典方式排序
	sort(favourite.begin(), favourite.end());


	set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}
	return 0;
}