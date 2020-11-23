#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n = 3;
	//cin >> n;
	int sum = 0;
	vector<int> v{2 ,8 ,4 ,6 ,3 ,1 ,9 ,7 ,5};
	//for (int i = 0; i < 9; i++)
	//{
	//	cin >> v[i];
	//}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		sum += v[2 * i + n];
	}
	cout << sum << endl;

	return 0;
}



#if 0
while (cin >> n)
{
	vector<int> v;
	for (int i = 0; i < n * 3; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		sum += v[2 * i + n];
	}
}
#endif