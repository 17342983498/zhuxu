#define _CRT_SECURE_NO_WARNINGS 1

//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

#if 0
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		if (nullptr == root)
			return v;
		TreeNode* cur = root;
		while (!s.empty() || cur)
		{
			if (cur)
			{
				s.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			else
			{
				cur = s.top();
				s.pop();
				cur = cur->right;
			}

		}
		return v;
	}
};
#endif

