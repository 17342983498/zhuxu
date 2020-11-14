#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "stack"
#include "queue"

#if 0
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	int ret = s.top();
	cout << ret << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;
}
#endif

int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.pop();
	int ret = q.front();
	cout << ret << endl;
	int ret1 = q.back();
	cout << ret1 << endl;
	cout << q.size() << endl;
	cout << q.empty() << endl;
}