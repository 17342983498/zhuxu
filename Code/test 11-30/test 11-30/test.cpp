#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);

	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// ��ǲ��ܷŵ����λ��
				if ((i + 2)<w)
					a[i + 2][j] = 0;

				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}
#endif


#if 0
class Solution {
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;

		int symbol = 1;
		if (str[0] == '-') //������
		{
			symbol = -1;
			str[0] = '0'; //�������ַ�'0',����0
		}
		else if (str[0] == '+') //��������
		{
			symbol = 1;
			str[0] = '0';
		}

		int sum = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}

			sum = sum * 10 + str[i] - '0';

		}
		return symbol * sum;
	}
};
#endif
