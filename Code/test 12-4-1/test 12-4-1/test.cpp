#define _CRT_SECURE_NO_WARNINGS 1

#if 0
class Solution {
public:
	/**
	* 进制转换
	* @param M int整型 给定整数
	* @param N int整型 转换到的进制
	* @return string字符串
	*/
	string solve(int M, int N) {
		string s;
		bool flag = 0;
		if (M<0)
		{
			M = -M;
			flag = 1;
		}
		const char* t = { "0123456789ABCDEF" };
		while (M)
		{
			s = t[M%N] + s;
			M /= N;
		}
		if (flag)
		{
			s = '-' + s;
		}
		return s;
	}
};
#endif


#if 0
//买股票
class Solution {
public:
	/**
	*
	* @param prices int整型vector
	* @return int整型
	*/
	int maxProfit(vector<int>& prices) {
		int max = 0;
		for (int i = 0; i<prices.size(); i++)
		{
			for (int j = i + 1; j<prices.size(); j++)
			{
				if (prices[j] - prices[i]>max)
				{
					max = prices[j] - prices[i];
				}
			}
		}
		return max;
	}
};
#endif