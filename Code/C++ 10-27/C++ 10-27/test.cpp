#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <string>
#include <algorithm>



#if 0
int main()
{
	string s ("hello");
	//s += ",world!";
	//cout << s << endl;

	//string s1("hello");
	//string s2("world");
	//if (s1 < s2)
	//{
	//	cout << "s1 < s2" << endl;
	//}
	//else
	//	cout << "s1 > s2"<<endl;

	//string::iterator it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it << endl;
	//	++it;
	//}
	////string::reverse_iterator rit = s.rbegin();
	//auto rit = s.rbegin();
	//while (rit != s.rend())
	//{
	//	cout << *rit << endl;
	//	++rit;
	//}
	//reverse(s.rbegin(), s.rend());
	//cout << s << endl;
	//sort(s.begin(), s.end());
	//cout << s << endl;
	//sort(s.rbegin(), s.rend());
	//cout << s << endl;


	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	return 0;
}
#endif

int main()
{
	class Solution {
	public:
		string reverseOnlyLetters(string S) {
			string s("a_bc_c_dff_cdsd");
			size_t begin = 0, end = s.size() - 1;
			while (begin < end)
			{
				while (begin < end)
				{
					if (isalpha(s[begin]))
						break;
					begin++;
				}
				while (begin < end)
				{
					if (isalpha(s[end]))
						break;
					end--;
				}
				if (begin != end)
				{
					char temp = s[begin];
					s[begin] = s[end];
					s[end] = temp;
				}
				begin++;
				end--;
			}
			cout << s << endl;
			return 0;
		}
	};
}