#define _CRT_SECURE_NO_WARNINGS 1

#include "DCHListNode.h"

DHCList* BuyDHCListNode(DHCListNode data)
{
	DHCList* newNode = (DHCList*)malloc(sizeof(DHCList));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

DHCList* ListInit()
{
	DHCList* pHead = BuyDHCListNode(0);
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

DHCList* ListFind(DHCList* pHead, DHCListNode data)
{
	assert(pHead);
	DHCList* cur = pHead->next;
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

void ListPushBack(DHCList* pHead, DHCListNode data)
{
	assert(pHead);
	ListInsert(pHead, data);
}

void ListPushFront(DHCList* pHead, DHCListNode data)
{
	assert(pHead);
	ListInsert(pHead->next, data);
}

void ListPopBack(DHCList* pHead)
{
	assert(pHead);
	ListErase(pHead->prev);
}

void ListPopFront(DHCList* pHead)
{
	assert(pHead);
	ListErase(pHead->next);
}

//在pos之前插入
void ListInsert(DHCList* pos, DHCListNode data)
{
	assert(pos);
	DHCList* newNode = BuyDHCListNode(data);
	newNode->next = pos;
	newNode->prev = pos->prev;
	pos->prev->next = newNode;
	pos->prev = newNode;
}

void ListErase(DHCList* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void ListPrint(DHCList* pHead)
{
	assert(pHead);
	DHCList* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d----", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListClear(DHCList* pHead)
{
	assert(pHead);
	DHCList* cur = pHead->next;
	while (cur != pHead)
	{
		pHead->next = cur->next;
		free(cur);
		cur = pHead->next;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
}

void ListDestory(DHCList** pHead)
{
	assert(pHead);
	ListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

void TestList()
{
	DHCList* pHead = ListInit();
	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPrint(pHead);

	ListPushFront(pHead, 0);
	ListPrint(pHead);

	ListPopFront(pHead);
	ListPrint(pHead);

	ListPopBack(pHead);
	ListPrint(pHead);

	ListClear(pHead);
	ListPrint(pHead);

	ListDestory(&pHead);
	//ListPrint(pHead);
}