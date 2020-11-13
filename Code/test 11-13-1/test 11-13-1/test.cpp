#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//Õ¾µÄÑ¹Èëµ¯³ö
#if 0
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
		{
			return false;
		}
		int InIdx = 0;
		int OutIdx = 0;
		stack<int> s;
		while (OutIdx<popV.size())
		{
			while (s.empty() || s.top() != popV[OutIdx])
			{
				if (InIdx<pushV.size())
				{
					s.push(pushV[InIdx++]);
				}
				else
				{
					return false;
				}
			}
			s.pop();
			OutIdx++;
		}
		return true;
	}
};
#endif