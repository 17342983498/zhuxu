#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include<vector>

#if 0
void YHTest(size_t n)
{
	vector<vector<int>> vv;
	vv.resize(n);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		vv[i].resize(i + 1, 1);
	}
	for (size_t i = 2; i < n; ++i)
	{
		for (size_t j = 1; j < vv[i].size() - 1; ++j)
		{
			vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
		}
	}
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			//cout << vv[i][j] << " ";
			printf("%3d ",vv[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	int n = 0;
	cin >> n ;
	YHTest(n);
	return 0;
}
#endif

void TestFunc()
{
	/*vector<vector<int>> vv(5);
	vector<int> v(4);
	for (size_t i = 0; i < 5; ++i)
	{
		vv.push_back(v);
	}*/

	vector<vector<int>> vv(4,vector<int> (4,10));
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			//cout << vv[i][j] << " ";
			printf("%3d ", vv[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	TestFunc();
	return 0;
}