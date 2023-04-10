#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//#include <string>
//#include <assert.h>

//int main()
//{
//	string s = "aaaaa";
//	return 0;
//}


//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	~String()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	String s1("hello bit!!!");
//	String s2(s1);
//}


//#include <iostream>
//using namespace std;
//#include <string>
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string maxstr, str;
//	if (s1.size()>s2.size())
//	{
//		swap(s1, s2);
//	}
//	auto it1 = s1.begin();
//	auto it2 = s2.begin();
//	while (it1 != s1.end())
//	{
//		while (*it1 != *it2)
//		{
//			it2++;
//			if (it2 == s2.end())
//			{
//				it1++;
//				break;
//			}
//		}
//		if (it2 == s2.end())
//		{
//			it2 = s2.begin();
//			continue;
//		}
//		while ((it1 != s1.end()) && (it2 != s2.end()) && (*it1 == *it2))
//		{
//			str += *it1;
//			if(*it1 == *(it2 + 1))
//			{
//				it2++;
//			}
//			it1++;
//			it2++;
//		}
//		
//		if (maxstr.size()<str.size())
//		{
//			maxstr = str;
//		}
//		it2 = s2.begin();
//		str.clear();
//	}
//	cout << maxstr << endl;
//	return 0;
//}


#include <iostream>
using namespace std;

int func(int n)
{
	if (n == 2)
	{
		return 1;
	}
	if (n<2)
	{
		return 0;
	}
	return n / 3 + func((n % 3) + (n / 3));
}

int main()
{
	int n = 0;
	while ((cin >> n))
	{
		if (n == 0)
		{
			break;
		}
		int ret = func(n);
		cout << ret << endl;
	}

	return 0;
}




