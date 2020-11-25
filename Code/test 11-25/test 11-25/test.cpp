#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//#include <string>
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int arr[256] = { 0 };
//	for (size_t i = 0; i<s2.size(); i++)
//	{
//		arr[s2[i]]++;
//	}
//	string str;
//	for (size_t i = 0; i<s1.size(); i++)
//	{
//		if (arr[s1[i]] == 0)
//		{
//			str += s1[i];
//		}
//	}
//	cout << str << endl;
//	return 0;
//}




#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n;
	while (cin >> n)
	{
		size_t sum = 0;
		vector<int> arr(3 * n);
		for (size_t i = 0; i<3 * n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		for (size_t i = 0; i<n; i++)
		{
			sum += arr[i * 2 + n];
		}
		cout << sum << endl;
	}
	return 0;
}