#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int num = v[0];
	int max = v[0];
	for (int i = 1; i < n; i++)
	{
		if (num >= 0)
		{
			num += v[i];
		}
		else
		{
			num = v[i];
		}
		if (num>max)
		{
			max = num;
		}
	}
	cout << max << endl;
	return 0;
}
#endif



#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int count = 0;
	for (int i = 0; i <= s1.size(); i++)
	{
		string s3 = s1;
		s3.insert(i, s2);
		int left = 0;
		int right = s3.size() - 1;
		while (left<right)
		{
			if (s3[left] != s3[right])
			{
				break;
			}
			else
			{
				left++;
				right--;
			}
		}
		if (left >= right)
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.reserve(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int num = v[0];
		int max = v[0];
		for (int i = 1; i < n; i++)
		{
			if (num >= 0)
			{
				num += v[i];
			}
			else
			{
				num = v[i];
			}
			if (max<num)
			{
				max = num;
			}
		}
		cout << max << endl;
	}
	return 0;
}