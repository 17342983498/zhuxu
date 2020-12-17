#define _CRT_SECURE_NO_WARNINGS 1

//给定一个二叉树的根节点 root ，返回它的 中序 遍历。


#if 0
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (!s.empty() || cur)
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			v.push_back(cur->val);
			cur = cur->right;
		}
		return v;
	}
};
#endif

