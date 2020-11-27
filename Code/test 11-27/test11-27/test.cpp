#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
int main()
{
	int n;
	cin >> n;
	vector<int> v(n+1);
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	i = 0;
	int count = 0;
	while (i<n)
	{
		if (v[i]<v[i + 1])//µÝÔö
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
		else//µÝ¼õ
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