#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = 0, B = 0, C = 0;
	A = (a + c) / 2;
	B = (b + d) / 2;
	C = d - B;
	if (A >= 0 && B >= 0 && C >= 0 && (A - B) == a && (B - C) == b && (A + B) == c && (C + B) == d)
	{
		cout << A << " " << B << " " << C << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}