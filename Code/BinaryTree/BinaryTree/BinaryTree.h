#define _CRT_SECURE_NO_WARNINGS 1

typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* Lchild;
	struct BTNode* Rchild;
	BTNDataType data;
}BTNode;

BTNode* CreatBinTree();
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void Test();
//BTNode* BuyBinTreeNode(data);