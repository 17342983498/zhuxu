#define _CRT_SECURE_NO_WARNINGS 1

//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 
//（即逐层地，从左到右访问所有节点）。


#if 0
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return vv;
	}
};
#endif