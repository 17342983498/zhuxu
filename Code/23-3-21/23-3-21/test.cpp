#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

//int main()
//{
//	int n = 0, m = 0;
//	cin >> n;
//	m = 3 * n;
//	int i = 0;
//	vector<int> v;
//	v.resize(m);
//	while (m--)
//	{
//		cin >> v[i++];
//	}
//	sort(v.rbegin(), v.rend());
//	long long sum = 0;
//	int j = 1;
//	while (n--)
//	{
//		sum += v[j];
//		j += 2;
//	}
//	cout << sum << endl;
//	return 0;
//}



int main()
{
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	auto it1 = s1.begin();
	while (it1 != s1.end())
	{
		auto it2 = s2.begin();
		int flag = 0;
		while (it2 != s2.end())
		{
			if (*it1 == *it2)
			{
				flag = 1;//表示有相同的字母
				break;
			}
			it2++;
		}
		if (flag == 0)
		{
			s3.push_back(*it1);
		}
		it1++;
	}
	cout << s3 << endl;

	return 0;
}