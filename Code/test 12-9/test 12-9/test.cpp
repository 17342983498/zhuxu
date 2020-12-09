#define _CRT_SECURE_NO_WARNINGS 1

//�����沨��ʽ����׺���ʽ����ֵ
//�����������"+", "-", "*"��"/"�����������������������������ʽ
//���磺
//["20", "10", "+", "30", "*"] -> ((20 + 10) * 30) -> 900
//["40", "130", "50", "/", "+"] -> (40 + (130 / 50)) -> 42

#if 0
class Solution {
public:
	/**
	*
	* @param tokens string�ַ���vector
	* @return int����
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


//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��


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
����һ��string iniString ���䳤�� int len, ��֪���ַ������пո�
��Ҫ���д�����ַ����пո��滻Ϊ�� % 20�������ظ��ĺ��string��
������ַ������㹻�Ŀռ����������ַ�������֪��ԭ�ַ��ĳ���(С�ڵ���1000)��
ͬʱ��֤�ַ����ɴ�Сд��Ӣ����ĸ��ɡ�

����������
"Mr John Smith��,13
���أ�"Mr%20John%20Smith"
��Hello  World��, 12
���أ���Hello % 20 % 20World��
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


