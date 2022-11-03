#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* BuySListNode(SLTDateType data)
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

void SListPushBack(SListNode** Head, SLTDateType data)
{
	assert(Head);
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


void SListPushFront(SListNode** Head, SLTDateType data)
{
	assert(Head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *Head;
	*Head = newNode;

}

void SListPopBack(SListNode** Head)
{
	if (*Head == NULL)
	{
		return;
	}
	else if ((*Head)->next == NULL)
	{
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
	if (*Head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = *Head;
		*Head = (*Head)->next;
		free(cur);
	}
}

SListNode* SListFind(SListNode* Head, SLTDateType data)
{
	assert(Head);
	while (Head)
	{
		if (Head->data == data)
		{
			return Head;
		}
		Head = Head->next;
	}
	return NULL;
}

SListNode* SListFind1(SListNode* Head, SLTDateType data)
{
	assert(Head);
	SListNode* prev = NULL;
	while (Head)
	{
		if (Head->data == data)
		{
			return prev;
		}
		prev = Head;
		Head = Head->next;
	}
	return NULL;
}

void SListInsert(SListNode* pos, SLTDateType data)
{
	SListNode* newNode = BuySListNode(data);
	if (NULL == pos)
		return;
	newNode->next = pos->next;
	pos->next = newNode;
}


//void SListInsertFront(SListNode* pos, SLTDateType data)
//{
//	SListNode* newNode = BuySListNode(data);
//	if (NULL == pos)
//		return;
//	newNode->next = pos->next;
//	pos->next = newNode;
//}

void SListDel(SListNode* pos)
{
	SListNode* newNode = NULL;
	if (NULL == pos || NULL == pos->next)
		return;
	newNode = pos->next;
	pos->next = newNode->next;
	free(newNode);
}

void SListPrint(SListNode* Head)
{
	SListNode* cur = Head;
	while (cur)
	{
		printf("%d---->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
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

	SListInsert(SListFind(ListNode, 2), 0);
	SListPrint(ListNode);

	SListInsert(SListFind1(ListNode, 2), 0);
	SListPrint(ListNode);

	SListDel(SListFind(ListNode, 2));
	SListPrint(ListNode);

	SListDel(SListFind(ListNode, 1));
	SListPrint(ListNode);
}