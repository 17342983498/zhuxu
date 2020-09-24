#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Sum
{
public:
	Sum()
	{
		count++;
		sum+=count;
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
	static int count ;
	static int sum ;
};
int Sum::count = 0;
int Sum::sum = 0;
int main()
{
	Sum s1[5];
	cout << Sum::Getsum() << endl;
	Sum::Reset();
	Sum s2[3];
	cout << Sum::Getsum() << endl;
	return 0;
}