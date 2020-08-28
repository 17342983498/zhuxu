#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	int& ra = a;
	int& rb = b;
	swap(a, b);
	cout <<"a="<< a << " " <<"b="<< b << endl;
	return 0;
}