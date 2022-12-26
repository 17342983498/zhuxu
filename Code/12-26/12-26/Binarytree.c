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

void PreOrder(BTreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BTreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(BTreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}


int size = 0;

int TreeNodeNum(BTreeNode* root)
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


int TreeHeight(BTreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = TreeHeight(root->left);
	int right = TreeHeight(root->right);
	return left >= right ? left + 1 : right + 1;
}

int LeafNodeNum(BTreeNode* root)
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

int LayerKNum(BTreeNode* root, int k)
{

	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return LayerKNum(root->left, k - 1) + LayerKNum(root->right, k - 1);
}

//查找结点
BTreeNode* FindNode(BTreeNode* root, BTreeNodeType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data = data)
	{
		return root;
	}
	BTreeNode* lchild = FindNode(root->left, data);
	if (lchild != NULL)
	{
		return lchild;
	}
	BTreeNode* lright = FindNode(root->right, data);
	if (lright != NULL)
	{
		return lright;
	}
	return NULL;
}


void test()
{
	BTreeNode* root = CreatBinaryTree();
	printf("前序遍历结果：");
	PreOrder(root);
	printf("\n");
	printf("中序遍历结果：");
	InOrder(root);
	printf("\n");
	printf("后序遍历结果：");
	PostOrder(root);
	printf("\n");
	int num = TreeNodeNum(root);
	printf("结点个数：%d\n", num);
	int height = TreeHeight(root);
	printf("树的高度为：%d\n", height);
	num = LeafNodeNum(root);
	printf("叶子结点个数：%d\n", num);
	int k = 0;
	scanf("%d", &k);
	num = LayerKNum(root, k);
	printf("第K层结点个数：%d\n", num);
	
	BTreeNode* node = FindNode(root, 5);
	printf("%d\n", node->data);

}