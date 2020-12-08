#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int sum = 0;
		vector<int> v{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month <= 0 || month>12 || day <= 0)
		{
			cout << -1 << endl;
			return 0;
		}
		if (month>2)
		{
			for (int i = 1; i<month; i++)
			{
				sum += v[i];
			}
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			{
				sum++;
			}
		}
		if (month == 2)
		{
			sum += 31;
		}
		cout << sum + day << endl;
	}
	return 0;
}