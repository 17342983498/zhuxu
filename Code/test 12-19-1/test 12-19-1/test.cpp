#define _CRT_SECURE_NO_WARNINGS 1

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉树 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//
//
//
//
//
//			 示例 1:
//
//输入 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//输出 : 3
// 解释 : 节点 5 和节点 1 的最近公共祖先是节点 3。

#if 0
class Solution {
public:
	bool GetNodePath(TreeNode* root, TreeNode* p, stack<TreeNode*>& s)
	{
		if (root == nullptr)
		{
			return false;
		}
		s.push(root);
		if (root == p)
		{
			return true;
		}
		bool isin = false;
		if (isin = GetNodePath(root->left, p, s))
		{
			return true;
		}
		if (isin = GetNodePath(root->right, p, s))
		{
			return true;
		}
		s.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (q == root || p == root)
		{
			return root;
		}
		stack<TreeNode*> s1, s2;
		GetNodePath(root, p, s1);
		GetNodePath(root, q, s2);
		int size1 = s1.size();
		int size2 = s2.size();
		while (!s1.empty() && !s2.empty())
		{
			if (size1>size2)
			{
				s1.pop();
				size1--;
			}
			else if (size1<size2)
			{
				s2.pop();
				size2--;
			}
			else
			{
				if (s1.top() == s2.top())
				{
					return s1.top();
				}
				else
				{
					s1.pop();
					s2.pop();
					size1--;
					size2--;
				}
			}
		}
		return nullptr;
	}
};

#endif

