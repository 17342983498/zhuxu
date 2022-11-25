#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
typedef int BTreeNodeType;

typedef struct BTreeNode
{
	struct BTreeNode* left;
	struct BTreeNode* right;
	BTreeNodeType data;
}BTreeNode;

BTreeNode* BuyTreeNode(BTreeNodeType data);

BTreeNode* CreatBinaryTree();

void PreOrder(BTreeNode* root);

void InOrder(BTreeNode* root);

void PostOrder(BTreeNode* root);

int TreeNodeNum(BTreeNode* root);

int TreeHeight(BTreeNode* root);

int LeafNodeNum(BTreeNode* root);

int LayerKNum(BTreeNode* root, int k);

void test();