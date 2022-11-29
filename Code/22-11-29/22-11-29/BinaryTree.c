#define _CRT_SECURE_NO_WARNINGS 1

#include "Binarytree.h"


BTreeNode* BuyTreeNode(BTreeNodeType data)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTreeNode* CreatBinaryTree()
{
	BTreeNode* root = NULL;
	BTreeNode* t1 = BuyTreeNode(1);
	BTreeNode* t2 = BuyTreeNode(2);
	BTreeNode* t3 = BuyTreeNode(3);
	BTreeNode* t4 = BuyTreeNode(4);
	BTreeNode* t5 = BuyTreeNode(5);
	BTreeNode* t6 = BuyTreeNode(6);
	root = t1;
	root->left = t2;
	root->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->right = t6;
	return root;
}


BTreeNode* BinaryTreeFind(BTreeNode* root, BTreeNodeType x)
{
	BTreeNode* ret1 = NULL;
	BTreeNode* ret2 = NULL;
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
		return ret1;
	ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
		return ret2;
}


void test()
{
	BTreeNode* root = CreatBinaryTree();
	BTreeNode* node = BinaryTreeFind(root, 7);
	if (node == NULL)
	{
		printf("Ã»ÕÒµ½\n");
	}
	else
	{
		printf("%d\n", node->data);
	}
}

int main()
{
	test();
	return 0;
}