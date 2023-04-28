#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
int main()
{
	string s;
	getline(cin, s);
	char c=getchar();
	int count = 0;
	auto it = s.begin();
	while (it != s.end())
	{
		if (*it == c)
		{
			count++;
		}
		else if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) && ((*it - c) == 32 || (c - *it) == 32))
		{
			count++;
		}
		it++;
	}
	cout << count << endl;
	return 0;
}