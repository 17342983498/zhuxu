#define _CRT_SECURE_NO_WARNINGS 1

//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
//
//示例 1:
//
//输入 : 二叉树 : [1, 2, 3, 4]
//	1
//	/ \
//	2     3
//	/
//	4
//
//输出: "1(2(4))(3)"
//
//解释 : 原本将是“1(2(4)())(3())”，
//	 在你省略所有不必要的空括号对之后，
//	 它将是“1(2(4))(3)”。

#if 0
	 class Solution {
	 public:
		 void _tree2str(TreeNode* root, string& strRet)
		 {
			 if (root == nullptr)
			 {
				 return;
			 }
			 char sz[32] = { 0 };
			 sprintf(sz, "%d", root->val);
			 strRet += sz;

			 if (root->left == nullptr)
			 {
				 if (root->right == nullptr)
				 {
					 return;
				 }
				 else
				 {
					 strRet += "()";
				 }
			 }
			 else
			 {
				 strRet += "(";
				 _tree2str(root->left, strRet);
				 strRet += ")";
			 }
			 if (root->right == nullptr)
			 {
				 return;
			 }
			 else
			 {
				 strRet += "(";
				 _tree2str(root->right, strRet);
				 strRet += ")";
			 }

		 }
		 string tree2str(TreeNode* t) {
			 string str;
			 _tree2str(t, str);
			 return str;
		 }
	 };
#endif

