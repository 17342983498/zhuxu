#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>


typedef int BinTNType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BinTNType data;
}BTNode;


BTNode* BuyTreeNode(BinTNType data);

BTNode* CreatBinaryTree();

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

void Test();