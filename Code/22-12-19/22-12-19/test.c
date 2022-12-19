#define _CRT_SECURE_NO_WARNINGS 1

//bool isUnivalTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//	if (root->left&&root->val != root->left->val)
//		return false;
//	if (root->right&&root->val != root->right->val)
//		return false;
//	return root->left&&root->right;
//}



//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (q == NULL&&p == NULL)
//	{
//		return true;
//	}
//	if (q == NULL||p == NULL)
//	{
//		return false;
//	}
//	if (q->val != p->val)
//	{
//		return false;
//	}
//	return isSameTree(q->left, p->right) && isSameTree(p->left, q->right);
//}


bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2)
{
		if (root1 == NULL&&root2 == NULL)
		{
			return true;
		}
		if (root1 == NULL||root2 == NULL)
		{
			return false;
		}
		if (root1->val != root2->val)
		{
			return false;
		}
		return _isSymmetric(root1->left, root2->right) && _isSymmetric(root2->left, root1->right);
}