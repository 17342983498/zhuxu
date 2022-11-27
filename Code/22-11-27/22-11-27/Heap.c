#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include "Queue.h"


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

void LeverOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	int leverSize = 0;
	if (root != NULL)
	{
		QueuePush(&q, root);
		leverSize = 1;
	}
	while (!QueueEmpty(&q))
	{
		while (leverSize--)
		{
			BTNode* front = QueueFront(&q);
			printf("%d ", front);
			QueuePop(&q);
			if (front->left)
			{
				QueuePush(&q,front->left);
			}
			if (front->right)
			{
				QueuePush(&q, front->right);
			}
		}
		printf("\n");
		leverSize = QueueSize(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}

void Test()
{
	BTNode* root = CreatBinaryTree();
	void LeverOrder(root);
}