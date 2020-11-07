#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include<string>

//bool IsPopOrder(vector<int> pushV, vector<int> popV) 
//{
//	if (pushV.size() != popV.size())
//	{
//		return false;
//	}
//	size_t outIdx = 0;
//	size_t inIdx = 0;
//	stack<int> s;
//	while (outIdx<popV.size())
//	{
//		while (s.empty() || s.top() != popV[outIdx])
//		{
//			if (inIdx<pushV.size())
//			{
//				s.push(pushV[inIdx++]);
//			}
//			else
//				return false;
//		}
//		s.pop();
//		outIdx++;
//	}
//		return true;
//}
//
//int main()
//{
//	vector<int> V1{ 1, 2, 3, 4, 5 };
//	//vector<int> V2{ 1, 2, 3, 4, 5 };
//	vector<int> V2{ 1, 2, 7, 4, 5 };
//	if (IsPopOrder(V1, V2))
//	{
//		cout << "true" << endl;
//	}
//	else
//		cout << "false" << endl;
//	return 0;
//}

void Teststring2()
{
	//string s1("hello, bit!!!");
	//// 测试reserve是否会改变string中有效元素个数
	//s.reserve(100);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	//s.reserve(50);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//s.reserve(5);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//s.resize(5);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	//size_t sz1 = s1.capacity();
	//cout << "making s grow:\n";
	//for (int i = 0; i < 100; ++i)
	//{
	//	s1.push_back('c');
	//	if (sz1 != s1.capacity())
	//	{
	//		sz1 = s1.capacity();
	//		cout << "capacity changed: " << sz1 << '\n';
	//	}
	//}
	//string s;
	//s.reserve(100);
	//size_t sz = s.capacity();

	//cout << "making s grow:\n";
	//for (int i = 0; i < 100; ++i)
	//{
	//	s.push_back('c');
	//	if (sz != s.capacity())
	//	{
	//		sz = s.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// 删除url的协议前缀
/*	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl*/;
}
int main()
{
	Teststring2();
	return 0;
}

