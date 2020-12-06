#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

bool Test(int m)
{
	int count = 0;
	for (int i = 1; i<=m / 2; i++)
	{
		if (m%i == 0)
		{
			count++;
		}
	}
	if (count>1)
		return false;
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x = n / 2;
		int y = n - x;
		while (x>0)
		{
			if (Test(x) && Test(y))
			{
				break;
			}
			x--;
			y++;
		}
		cout << x << endl;
		cout << y << endl;
	}
	return 0;
}