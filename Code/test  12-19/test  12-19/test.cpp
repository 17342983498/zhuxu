#define _CRT_SECURE_NO_WARNINGS 1

//����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
//
//�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
//
//ʾ�� 1:
//
//���� : ������ : [1, 2, 3, 4]
//	1
//	/ \
//	2     3
//	/
//	4
//
//���: "1(2(4))(3)"
//
//���� : ԭ�����ǡ�1(2(4)())(3())����
//	 ����ʡ�����в���Ҫ�Ŀ����Ŷ�֮��
//	 �����ǡ�1(2(4))(3)����

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

