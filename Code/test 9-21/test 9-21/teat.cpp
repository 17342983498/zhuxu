#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Sum
//{
//public:
//	Sum()
//	{
//		count++;
//		sum += count;
//	}
//	static void Reset()
//	{
//		count = 0;
//		sum = 0;
//	}
//	static int Getsum()
//	{
//		return sum;
//	}
//private:
//	static int sum;
//	static int count;
//};
//int Sum::sum = 0;
//int Sum::count = 0;
//int main()
//{
//	Sum s1[5];
//	cout << Sum::Getsum() << endl;
//	Sum::Reset();
//	Sum s2[3];
//	cout << Sum::Getsum() << endl;
//	return 0;
//}



//int main()
//{
//	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		int sumday = 0;
//		for (int i = 0; i < month - 1; i++)
//		{
//			sumday += days[i];
//		}
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			if (month>2)
//				sumday++;
//		}
//		sumday += day;
//		cout << sumday << endl;
//	}
//	return 0;
//}

int main()
{
	char arr[1024] = { 0 };
	gets(arr);
	int i = strlen(arr);
	for (; i >= 0; i--)
	{
		if (arr[i] == ' ')
		{
			cout << arr + i + 1 << endl;
			break;
		}
	}
	if (i < 0)
	{
		i = 0;
		cout << arr + i << endl;
	}
	return 0;
}