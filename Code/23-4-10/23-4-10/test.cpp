#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
//int main()
//{
//	string s;
//	getline(cin, s);
//	reverse(s.begin(), s.end());
//	cout << s << endl;
//	return 0;
//}


//
//int main()
//{
//	string s;
//	getline(cin, s);
//	auto rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit;
//		rit++;
//	}
//	cout << endl;
//	return 0;
//}



#include <string>
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int sz1 = s1.size();
//	int sz2 = s2.size();
//	if (sz1>sz2)
//	{
//		swap(s1, s2);
//		swap(sz1, sz2);
//	}
//	int count = 0;
//	int num = sz1;
//	string str;
//	int y = 1;
//	while (sz1 > 1)
//	{
//		int x = y;
//		while (x)
//		{
//			int num = x;
//			int num1 = sz1;
//			auto it1 = s1.begin();
//			while (--num)
//			{
//				it1++;
//			}
//			while (it1 != s1.end() && num1--)
//			{
//				str += *it1;
//				it1++;
//			}
//			auto it3 = str.begin();
//			while (it3 != str.end())
//			{
//				auto it2 = s2.begin();
//				while (*it2 != *it3)
//				{
//					it2++;
//				}
//				while (it3 != str.end()&&*it2 == *it3)
//				{
//					it2++;
//					it3++;
//				}
//				if (it3 == str.end())
//				{
//					cout << str.size() << endl;
//					x = 1;
//					sz1 = 0;
//					break;
//				}
//				if (*it2 != *it3)
//				{
//					break;
//				}
//			}
//			str.clear();
//			x--;
//		}
//		sz1--;
//		y++;
//	}
//	return 0;
//}



int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	auto it1 = s1.begin();
	int count = 0, maxcount = 0;
	while (it1 != s1.end())
	{
		auto it2 = s2.begin();
		while (it2 != s2.end())
		{

			auto i1 = it1;
			auto i2 = it2;
			while (i1 != s1.end() && i2 != s2.end()&&*i1 == *i2)
			{
				i1++;
				i2++;
				count++;
			}
			if (count >= maxcount)
			{
				maxcount = count;
			}
			count = 0;
			it2++;
		}
		it1++;
	}
	cout << maxcount << endl;
	return 0;
}