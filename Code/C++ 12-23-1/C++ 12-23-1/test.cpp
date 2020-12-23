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
	// ������ˮ��������Ա����ϲ���Ե�����ˮ��---CVTE������
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	// 1. ͳ��ÿ��ˮ�����ֵĴ���
	// <ˮ��������>
	map<string, size_t> m;
	for (auto& e : fruits)
		m[e]++;  // <e, 0>��map�в���--->���e�����ڷ���0  ���e���ڷ���ֵe��Ӧ�Ĵ���

	// 2. �ҳ�Ա����ϲ���Ե�K��ˮ��----TOP-K---priority_queue
	// ʹ��map�е�Ԫ�ع���һ�����---->���ռ�ֵ���еĴ������бȽ�
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());


	// ȡ��Ա����ϲ���Ե�����ˮ��
	vector<string> favourite;
	for (size_t i = 0; i < 3; ++i)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}

	// ˮ��--->�����ֵ䷽ʽ����
	sort(favourite.begin(), favourite.end());


	set<string> s;
	for (size_t i = 0; i < 3; ++i)
	{
		s.insert(q.top().first);
		q.pop();
	}
	return 0;
}