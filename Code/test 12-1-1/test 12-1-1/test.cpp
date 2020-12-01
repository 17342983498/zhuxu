#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0
int main()
{
	string s;
	getline(cin, s);
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(')
		{
			count++;
		}
		else if (c == ')')
		{
			if (count>0)
			{
				count--;
			}
			else
			{
				cout<< "false"<<endl;
			}
		}
		else
		{
			cout << "false" << endl;
		}
	}
	if (count == 0)
	{
		cout << "true" << endl;
	}
	else
		cout << "false" << endl;
	return 0;
}
#endif

#include <vector>
int main()
{
	int n;
	cin >> n;
	int first = 0;
	int last = 1;
	int num = 0;
	while (num < n)
	{
		num = first + last;
		first = last;
		last = num;
	}

	int count1 = num - n;
	int count2 = n - first;
	if (count1 <= count2)
	{
		cout << count1 << endl;
	}
	else
		cout << count2 << endl;
	return 0;
}


