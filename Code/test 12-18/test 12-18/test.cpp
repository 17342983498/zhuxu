#define _CRT_SECURE_NO_WARNINGS 1

#if 0
����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
����������[3, 9, 20, null, null, 15, 7],

3
/ \
9  20
/ \
15   7
�������Ե����ϵĲ�α���Ϊ��

[
	[15, 7],
	[9, 20],
	[3]
]

#endif

#if 0
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vv;
		queue<TreeNode*> q;
		q.push(root);
		if (nullptr == root)
			return vv;
		while (!q.empty())
		{
			vector<int> v;
			int num = q.size();
			for (int i = 0; i<num; i++)
			{
				v.push_back(q.front()->val);
				if (q.front()->left)
				{
					q.push(q.front()->left);
				}
				if (q.front()->right)
				{
					q.push(q.front()->right);
				}
				q.pop();
			}
			vv.push_back(v);
		}
		reverse(vv.begin(), vv.end());
		return vv;
	}
};

#endif

