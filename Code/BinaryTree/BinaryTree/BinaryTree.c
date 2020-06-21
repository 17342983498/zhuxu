#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

BTNode* BuyBinTreeNode(BTNDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}
	newNode->data = data;
	newNode->Lchild = NULL;
	newNode->Rchild = NULL;
	return newNode;
}

BTNode* CreatBinTree()
{
	BTNode* root = NULL;
	BTNode* n1 = BuyBinTreeNode(1);
	BTNode* n2 = BuyBinTreeNode(2);
	BTNode* n3 = BuyBinTreeNode(3);
	BTNode* n4 = BuyBinTreeNode(4);
	BTNode* n5 = BuyBinTreeNode(5);
	BTNode* n6 = BuyBinTreeNode(6);
	BTNode* n7 = BuyBinTreeNode(7);
	root = n1;
	root->Lchild = n2;
	root->Rchild = n3;
	n2->Lchild = n4;
	n2->Rchild = n5;
	n3->Lchild = n6;
	n3->Rchild = n7;
	return root;
}
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}

}
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->Lchild);
		printf("%d ", root->data);
		InOrder(root->Rchild);
	}

}
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%d ", root->data);
	}

}

void Test()
{
	BTNode* root = CreatBinTree();
	printf("前序遍历结果：");
	PreOrder(root);
	printf("\n");
	printf("中序遍历结果：");
	InOrder(root);
	printf("\n");
	printf("后序遍历结果：");
	PostOrder(root);
	printf("\n");
}