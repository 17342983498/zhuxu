#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//int main()
//{
//	char s[] = "祝旭";
//	cout << s << endl;
//	s[3]--;
//	cout << s << endl;
//	//s[4]--;
//	//cout << s << endl;
//	s[3]++;
//	cout << s << endl;
//	s[3]++;
//	cout << s << endl;
//	//s[23]++;
//	//cout << s << endl;
//	return 0;
//}



//int main()
//{
//	string s1;
//	s1 = "hello world!";
//	cout << s1 << endl;
//	string s2("hello world!");
//	cout << s2 << endl;
//
//	string s3(s1, 6, 4);
//	cout << s3 << endl;
//
//	string s4(s1, 6, 14);
//	cout << s4 << endl;
//
//	string s5(s1, 6);
//	cout << s5 << endl;
//
//	string s6(10, '@');
//	cout << s6 << endl;
//
//	string s7("Another character sequence", 12);
//	cout << s7 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world!");
//
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//
//	//s1.resize(16);
//	//cout << s1 << endl;
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.resize(16,'!');
//	//cout << s1 << endl;
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//	//cout << s1.capacity() << endl;
//
//	//s1.resize(10);
//	//cout << s1 << endl;
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//	//cout << s1.capacity() << endl;
//
//	s1.reserve(16);
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//
//
//	s1.reserve(10);
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//}

//int main()
//{
//	string s1("abc");
//	s1 += 'd';
//	cout << s1 << endl;
//
//	s1.append("efg");
//	cout << s1 << endl;
//
//	s1.push_back('h');
//	cout << s1 << endl;
//
//	s1 += "sdfsdds";
//	cout << s1 << endl;
//}


//int main()
//{
//	string s("abcd");
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}


//int  main()
//{
//	string s("abcd");
//	//string::iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//	//for (auto e : s)
//	//{
//	//	e++;
//	//	cout << e << " ";
//	//	++e;
//	//}
//	//cout << endl;
//
//
//	//string::const_iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	//*it+=1;
//	//	*it++;
//	//	cout << *it << " ";
//	//	++it;
//	//}
//	//cout << endl;
//
//	//string::reverse_iterator rit = s.rbegin();
//	//while (rit != s.rend())
//	//{
//	//	*rit += 1;
//	//	cout << *rit << " ";
//	//	rit++;
//	//}
//	//cout << endl;
//
//
//	auto rit = s.rbegin();
//	cout << typeid(rit).name() << endl;
//}


//int main()
//{
//	string s("world");
//	s.insert(0, "hello");
//	cout << s << endl;
//
//	s.insert(5, " ");
//	cout << s << endl;
//
//	cout << s.at(0) << endl;
//
//	s.insert(2, "dsfsdf", 3);//插入该字符串的三个字符在二号位置
//	cout << s << endl;
//
//	s.erase(2, 3);//从2号位置开始删除三个字符
//	cout << s << endl;
//}



//int main()
//{
//	string s("abcd");
//	s.insert(s.find('b'),"sdfsf");
//	cout << s << endl;
//
//	s.replace(s.find('f'),1,"20%" );
//	cout << s << endl;
//}

//int main()
//{
//	string s("i love you!");
//	size_t pos = s.find(' ');
//	while (pos != string::npos)
//	{
//		s.replace(pos, 1, "%20");
//		pos = s.find(' ', pos + 3);
//	}
//	cout << s << endl;
//}

//int main()
//{
//	//string s("hello world");
//
//	//size_t pos = s.find_first_of("eo",0);
//	//while (pos != string::npos)
//	//{
//	//	s[pos] = '*';
//	//	pos = s.find_first_of("eo", pos + 1);
//	//}
//
//
//	//string s("hello world");
//
//	//size_t pos = s.find_first_not_of("eo", 0);
//	//while (pos != string::npos)
//	//{
//	//	s[pos] = '*';
//	//	pos = s.find_first_not_of("eo", pos + 1);
//	//}
//	//cout << s << endl;
//
//
//	string s("hello world");
//
//	size_t pos = s.find_last_of("eo", s.size()-1);
//	while (pos != string::npos)
//	{
//		s[pos] = '*';
//		pos = s.find_last_of("eo", pos - 1);
//	}
//	cout << s << endl;
//}


int main()
{
	string s;
	getline(cin,s);
	size_t pos = s.rfind(' ', s.size() - 1);
	if (pos != string::npos)
	{
		cout << s.size() - pos - 1 << endl;
	}
	else
	{
		cout << s.size() << endl;
	}
}