#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

//int func(string s3)
//{
//	auto it1 = s3.begin();
//	auto it2 = s3.end();
//	int flag = 1;
//	while (it1 <= it2)
//	{
//		if (*it1 != *it2)
//		{
//			flag = 0;
//			break;
//		}
//		++it1;
//		--it2;
//	}
//	if (flag == 1)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}

//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int sum = 0;
//	string s3;
//	int sz = s1.size();
//	for (int i = 0; i <= sz; ++i)
//	{
//		s3 = s1;
//		s3.insert(i, s2);
//		int flag = 1;
//		int left = 0, right = s3.size()-1;
//		while (left <= right)
//		{
//			if (s3[left] != s3[right])
//			{
//				flag = 0;
//				break;
//			}
//			left++;
//			right--;
//		}
//		if (flag == 1)
//		{
//			sum++;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}


#include <vector>
int main()
{
	int n = 0;
	int sum = 0, num = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> v[i];
	}
	int max = v[0];
	for (int i = 1; i<n; ++i)
	{
		if (v[i] > v[0])
		{
			max = v[i];
		}
	}
	if (max < 0)
	{
		cout << max << endl;
	}
	for (int i = 0; i<n; ++i)
	{
		if (v[i]>0)
		{
			num += v[i];
		}
		else
		{
			if (v[i] + num < 0)
			{
				num = 0;
			}
			else
			{
				num += v[i];
			}
		}
		if (num>sum)
		{
			sum = num;
		}
	}
	cout << sum << endl;
	return 0;
}