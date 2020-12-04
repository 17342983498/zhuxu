#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
int  length(string s)
{
	int res;
	int n = s.size();
	if (n <= 4)
		res = 5;
	else if (n <= 7)
		res = 10;
	else
		res = 25;
	return res;
}
int alp(string s)
{
	int res, res1 = 0, res2 = 0;
	int n = s.size();
	for (int i = 0; i<n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			res1++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			res2++;
	}
	if (res1 == 0 && res2 == 0)
		res = 0;
	else if (res1 == 0 || res2 == 0)
		res = 10;
	else
		res = 20;
	return res;
}
int dig(string s)
{
	int res, res1 = 0;
	int n = s.size();
	for (int i = 0; i<n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res1++;
	}
	if (res1>1)
		res = 20;
	else if (res1 == 1)
		res = 10;
	else
		res = 0;
	return res;
}
int sym(string s)
{
	int res, res1 = 0;
	int n = s.size();
	for (int i = 0; i<n; i++)
	{
		if ((s[i] >= 33 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126))
			res1++;
	}
	if (res1>1)
		res = 25;
	else if (res1 == 1)
		res = 10;
	else
		res = 0;
	return res;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		int res = length(s) + alp(s) + dig(s) + sym(s);
		if ((alp(s)>10) && dig(s) && sym(s))
			res += 5;
		else if (alp(s) && dig(s) && sym(s))
			res += 3;
		else if (dig(s) && alp(s))
			res += 2;
		if (res >= 90)
			cout << "VERY_SECURE" << endl;
		else if (res >= 80)
			cout << "SECURE" << endl;
		else if (res >= 70)
			cout << "VERY_STRONG" << endl;
		else if (res >= 60)
			cout << "STRONG" << endl;
		else if (res >= 50)
			cout << "AVERAGE" << endl;
		else if (res >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;

}