#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode

{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


BTNode* BuyBTNode(BTDataType data);
BTNode* CreatTree();