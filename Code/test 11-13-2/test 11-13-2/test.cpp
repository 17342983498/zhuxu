#define _CRT_SECURE_NO_WARNINGS 1


//�沨�����ʽ
#if 0
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto& e : tokens)
		{
			if (!(e == "+" || e == "-" || e == "*" || e == "/"))
			{
				s.push(atoi(e.c_str()));
			}
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (e[0])
				{
				case'+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};
#endif