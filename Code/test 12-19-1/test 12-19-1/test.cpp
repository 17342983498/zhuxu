#define _CRT_SECURE_NO_WARNINGS 1

//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
//
//���磬�������¶����� : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//
//
//
//
//
//			 ʾ�� 1:
//
//���� : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//��� : 3
// ���� : �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��

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

