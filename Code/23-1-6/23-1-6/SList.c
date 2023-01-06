#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void SListPrint(SListNode* Head)
{
	SListNode* cur = Head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** Head, SLDataType data)
{
	SListNode* newNode = BuySListNode(data);
	if (*Head == NULL)
	{
		*Head = newNode;
	}
	else
	{
		SListNode* cur = *Head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void SListPushFront(SListNode** Head, SLDataType data)
{
	SListNode* newNode = BuySListNode(data);
	newNode->next = *Head;
	*Head = newNode;
}

void SListPopBack(SListNode** Head)
{
	assert(*Head);
	if ((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		SListNode* cur = (*Head)->next;
		SListNode* prev = *Head;
		while (cur->next)
		{
			cur = cur->next;
			prev = prev->next;
		}
		prev->next = NULL;
		free(cur);
	}
}

void SListPopFront(SListNode** Head)
{
	assert(*Head);
	SListNode* cur = *Head;
	*Head = (*Head)->next;
	free(cur);	
}

SListNode* SListFind(SListNode* Head, SLDataType data)
{
	SListNode* cur = Head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = BuySListNode(data);
	if (pos == NULL)
	{
		return;
	}
	newNode->next = pos->next;
	pos->next = newNode;
}

void SListDelAfter(SListNode* pos)
{
	SListNode* newNode = NULL;
	if (NULL == pos || NULL == pos->next)
		return;
	newNode = pos->next;
	pos->next = newNode->next;
	free(newNode);
}

void SListTest()
{
	SListNode* ListNode = NULL;
	SListPushFront(&ListNode, 0);
	SListPushBack(&ListNode, 1);
	SListPushBack(&ListNode, 2);
	SListPushBack(&ListNode, 3);
	SListPushBack(&ListNode, 4);
	SListPushBack(&ListNode, 5);
	SListPrint(ListNode);

	SListPushFront(&ListNode, -1);
	SListPrint(ListNode);

	SListPopBack(&ListNode);
	SListPopBack(&ListNode);
	SListPrint(ListNode);

	SListPopFront(&ListNode);
	SListPrint(ListNode);

	SListNode* ret = SListFind(ListNode, 0);
	if (ret == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了\n");
	}

	SListInsertAfter(SListFind(ListNode, 2), 0);
	SListPrint(ListNode);

	SListDelAfter(SListFind(ListNode, 2));
	SListPrint(ListNode);
}