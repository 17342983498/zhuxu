#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


#define Com(a,b) ((a) > (b)) ? (a) : (b)   // 7
                                           //由此可看出，使用宏函数可能会产生副作用
//int Com(int a, int b)                    // 6
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
int main()
{
	int a = 5;
	int b = 5;
	int max = Com(++a, b);
	cout << max << endl;
	return 0;
}