#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"


BTNode* BuyBTNode(BTDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}


BTNode* CreatTree()
{
	BTNode* root = NULL;
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);
	root = n1;
	root->left = n2;
	n2->left = n3;
	n2->right = n4;
	root->right = n5;
	n5->left = n6;
	n5->right = n7;
	return root;
}

void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}


void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}
void BTNodeTest()
{
	BTNode* root = CreatTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
}