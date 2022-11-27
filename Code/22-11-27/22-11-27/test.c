#define _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyTreeNode(BTDataType data);

BTNode* BuyTreeNode(BTDataType data)
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
			printf("%d ", front->data);
			QueuePop(&q);
			if (front->left)
			{
				QueuePush(&q, front->left);
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


int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return 0;
		}
	}
	QueueDestroy(&q);
	return 1;
}

void PrevOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

int main()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");
	LeverOrder(root);
	int ret = BinaryTreeComplete(root);
	printf("%d\n", ret);
}