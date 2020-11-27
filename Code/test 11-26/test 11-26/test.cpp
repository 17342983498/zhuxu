#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int i = 0;
	int count = 0;
	while (i < n)
	{
		if (v[i] < v[i + 1])
		{
			while (i < n && v[i] < v[i+1])
			{
				i++;
			}
			i++;
			count++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i < n && v[i] > v[i + 1])
			{
				i++;
			}
			i++;
			count++;
		}
	}
	cout << count << endl;
	return 0;

}
#endif


#if 0
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (*end != ' '&&end != s.end())
		{
			end++;
		}
		reverse(start, end);
		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start=end;
		}
	}
	cout << s << endl;
	return 0;
}
#endif



#if 0
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto start = s.begin();
	while (start != s.end())
	{
		auto first = start;
		while (*first != ' '&&first != s.end())
		{
			first++;
		}
		reverse(start, first);
		if (first != s.end())
		{
			start = first + 1;
		}
		else
			start = first;
	}
	cout << s << endl;
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n ;
	cin >> n;
	int sum = 0;
	vector<int> v(3*n);
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		sum += v[2 * i + n];
	}
	cout << sum << endl;
	return 0;
}
#endif


#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	int arr[256] = { 0 };
	for (size_t i = 0; i < s2.size(); i++)
	{
		arr[s2[i]] = 1;
	}
	string str;
	for (size_t i = 0; i < s1.size(); i++)
	{
		if (arr[s1[i]] == 0)
		{
			str += s1[i];
		}
	}
	cout << str << endl;
	return 0;
}