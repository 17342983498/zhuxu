#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
//int main()
//{
//	string s;
//	getline(cin, s);
//	auto it = s.begin();
//	//   xcopy /s c:\\ d:\\e
//	int count = 1;
//	while (it != s.end())
//	{
//		if(*it == '"')
//		{
//			it++;
//			while (*it != '"')
//			{
//				it++;
//			}			
//		}
//		if (*it == ' ')
//		{
//			count++;
//		}
//		it++;
//	}
//	cout << count << endl;
//	string s1;
//	it = s.begin();
//	while (it != s.end())
//	{
//		if (*it == '"')
//		{
//			it++;
//			while (*it != '"')
//			{
//				s1 += *it;
//				it++;
//			}
//		}
//		if (*it != ' '&& *it != '"')
//		{
//			s1 += *it;
//		}
//		if (*it == ' ')
//		{
//			cout << s1 << endl;
//			s1.clear();
//		}
//		++it;
//	}
//	cout << s1 << endl;
//	return 0;
//}

//int func(int num,int m)
//{
//	int x = num - 1;
//	if (num < m)
//	{
//		while ((num % x != 0) &&(num + x < m))
//		{
//			x--;
//		}
//		num += x;
//		if (x == 1)
//		{
//			return -1;
//		}
//		return func(num, m) + 1;
//	}
//	else
//		return 0;
//}
//
//
//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	int num = n;
//	int count = 0;
//	int ret=func(num,m);
//	cout << ret << endl;
//	return 0;
//}

int main()
{
	//string s("hello world");
	//size_t pos = s.find_first_of("eo", 0);//从位置0处找到字符e或字符o第一次出现的位置
	//while (pos != string::npos)
	//{
	//	s[pos] = '*';
	//	pos = s.find_first_of("eo", pos + 1);//将整个字符串中的字符e或字符o换成*
	//}
	//cout << s << endl;

	string s("hello world");
	size_t pos = s.find_first_not_of("eo", 0);
	while (pos != string::npos)
	{
		s[pos] = '*';
		pos = s.find_first_not_of("eo", pos + 1);
	}
	cout << s << endl;
}