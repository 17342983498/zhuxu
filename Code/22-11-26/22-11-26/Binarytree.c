#define _CRT_SECURE_NO_WARNINGS 1

#include "Binarytree.h"

BTNode* BuyTreeNode(BinTNType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTNode* CreatBinaryTree()
{
	BTNode* root = BuyTreeNode(0);
	BTNode* n1 = BuyTreeNode(1);
	BTNode* n2 = BuyTreeNode(2);
	BTNode* n3 = BuyTreeNode(3);
	BTNode* n4 = BuyTreeNode(4);
	BTNode* n5 = BuyTreeNode(5);
	BTNode* n6 = BuyTreeNode(6);
	BTNode* n7 = BuyTreeNode(7);
	BTNode* n8 = BuyTreeNode(8);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = n8;
	return root;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int Lheight = TreeHeight(root->left);
	int Rheight = TreeHeight(root->right);
	return Lheight >= Rheight ? Lheight + 1 : Rheight + 1;
}

int size = 0;
int TreeNodeNum(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	size++;
	TreeNodeNum(root->left);
	TreeNodeNum(root->right);
	return size;
}

int LeafNodeNum(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return LeafNodeNum(root->left) + LeafNodeNum(root->right);
}

int LayerKNum(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	k--;
	return LayerKNum(root->left, k) + LayerKNum(root->right, k);
}

void Test()
{
	BTNode* root = CreatBinaryTree();
	printf("前序遍历：");
	PreOrder(root);
	printf("\n");
	printf("中序遍历：");
	InOrder(root);
	printf("\n");
	printf("后序遍历：");
	PostOrder(root);
	printf("\n");
	int ret = TreeHeight(root);
	printf("树的高度为：%d\n", ret);
	int NodeNum = TreeNodeNum(root);
	printf("树的结点个数：%d\n", NodeNum);
	ret = LeafNodeNum(root);
	printf("叶子结点个数：%d\n", ret);
	int k = 0;
	scanf("%d", &k);
	printf("第K层有%d个结点\n", LayerKNum(root, k));
}