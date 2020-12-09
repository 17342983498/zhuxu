#define _CRT_SECURE_NO_WARNINGS 1

//计算逆波兰式（后缀表达式）的值
//运算符仅包含"+", "-", "*"和"/"，被操作数可能是整数或其他表达式
//例如：
//["20", "10", "+", "30", "*"] -> ((20 + 10) * 30) -> 900
//["40", "130", "50", "/", "+"] -> (40 + (130 / 50)) -> 42

#if 0
class Solution {
public:
	/**
	*
	* @param tokens string字符串vector
	* @return int整型
	*/
	int evalRPN(vector<string>& tokens) {
		// write code here
		int a = 0;
		int b = 0;
		stack<int> s;
		for (int i = 0; i<tokens.size(); i++)
		{
			if ((tokens[i] != "+") && (tokens[i] != "-") && (tokens[i] != "*") && (tokens[i] != "/"))
			{
				s.push(stoi(tokens[i]));
			}
			else
			{
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				if (tokens[i] == "+")
				{
					b = b + a;
				}
				else if (tokens[i] == "-")
				{
					b = b - a;
				}
				else if (tokens[i] == "*")
				{
					b = b * a;
				}
				else
				{
					b = b / a;
				}
				s.push(b);
			}
		}
		return s.top();
	}
};
#endif


//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。


#if 0
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (head == NULL){
			return res;
		}
		res = printListFromTailToHead(head->next);
		res.push_back(head->val);
		return res;
	}
};
#endif

/*
给定一个string iniString 及其长度 int len, 已知该字符串中有空格，
现要求编写程序将字符串中空格替换为“ % 20”。返回更改后的string。
假设该字符串有足够的空间存放新增的字符，并且知道原字符的长度(小于等于1000)，
同时保证字符串由大小写的英文字母组成。

测试样例：
"Mr John Smith”,13
返回："Mr%20John%20Smith"
”Hello  World”, 12
返回：”Hello % 20 % 20World”
*/


#if 0
class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		string s;
		for (int i = 0; i<iniString.size(); i++)
		{
			if (iniString[i] == ' ')
			{
				s += "%20";
			}
			else
			{
				s += iniString[i];
			}
		}
		return s;
	}
};
#endif


