#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Sum
{
public:
	Sum()
	{
		count++;
		sum += count;
	}
	static int Getsum()
	{
		return sum;
	}
	static void Reset()
	{
		count = 0;
		sum = 0;
	}
private:
	static int sum;
	static int count;
};

int Sum::sum = 0;
int Sum::count = 0;

int main()
{
	Sum s1[5];
	cout << Sum::Getsum() << endl;
	Sum::Reset();
	Sum s2[3];
	cout << Sum::Getsum() << endl;
	Sum::Reset();
	return 0;
}
#endif

int main()
{
	int Days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;
	cin >> year >> month >> day;
	int daycount = 0;
	for (int i = 0; i < month - 1; i++)
	{
		daycount += Days[i];
	}
	//if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	//{
	//	if (month > 2)
	//		daycount += 1;
	//}
	if (month > 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			daycount+=1;
		}
	}
	daycount += day;
	cout << daycount << endl;
	return 0;
}


//int main()
//{
//	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		int totalDays = 0;
//		for (int i = 0; i < month - 1; ++i)
//		{
//			totalDays += days[i];
//		}
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			if (month > 2)
//				totalDays += 1;
//		}
//		totalDays += day;
//		cout << totalDays << endl;
//	}
//	return 0;
//}