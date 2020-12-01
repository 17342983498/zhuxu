#define _CRT_SECURE_NO_WARNINGS 1

//组队竞赛

//牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.
//现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。

//例如:
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。

//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1 : {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//而如果方案为 :
//   team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//		   没有比总和为10更大的方案, 所以输出10.


#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	size_t n;
	while (cin >> n)
	{
		vector<int> v(3 * n);
		for (size_t i = 0; i<3 * n; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		size_t sum = 0;
		for (size_t i = 0; i<n; i++)
		{
			sum += v[2 * i + n];
		}
		cout << sum << endl;
	}
	return 0;
}
#endif


//删除公共字符

//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”


#if 0
#include <iostream>
using namespace std;

#include <string>

int main()
{
	string  s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int arr[256] = { 0 };
	string str;

	for (int i = 0; i<s2.size(); i++)
	{
		arr[s2[i]] = 1;
	}

	for (int i = 0; i<s1.size(); i++)
	{
		if (arr[s1[i]] != 1)
		{
			str += s1[i];
		}
	}
	cout << str << endl;
	return 0;
}
#endif


//排序子序列
//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2


#if 0
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	int count = 0;
	int i = 0;
	while (i<n)
	{
		if (v[i]<v[i + 1])
		{
			while (i<n&&v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i<n&&v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif



//倒置字符串

//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I


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
	int i = 0;
	while (start != s.end())
	{
		auto end = start;
		while (*end != ' ' && end != s.end())
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
			start = end;
		}
	}
	cout << s << endl;
	return 0;
}