#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


int test(int n, int i)
{
	if (i == 1 || i == 2 * n - 1)
		return 1;
	else if (i<1 || i>2 * n - 1)
		return 0;
	else
		return test(n - 1, i - 2) + test(n - 1, i - 1) + test(n - 1, i);
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i<2 * n - 1; i++)
		{
			if (test(n, i) % 2 == 0)
			{
				cout << i << endl;
				break;
			}
			else if (i == 2 * n - 1)
			{
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}