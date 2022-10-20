#define _CRT_SECURE_NO_WARNINGS 1

#include "DHCListNode.h"


ListNode* BuyDHCListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

// ��ʼ��
ListNode* ListInit()
{
	ListNode* pHead = BuyDHCListNode(0);
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

//���
void ListClear(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		pHead->next = cur->next;
		free(cur);
		cur = pHead->next;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
}

// ˫����������
void ListDestory(ListNode** pHead)
{
	assert(pHead);
	ListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d----", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->prev);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->next);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur!=pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newHead;
	if (pos == NULL)
	{
		return;
	}
	newHead = BuyDHCListNode(x);
	newHead->next = pos;
	newHead->prev = pos->prev;
	pos->prev->next = newHead;
	pos->prev = newHead;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void TestList()
{
	ListNode* pHead = ListInit();
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
	ListPrint(pHead);
}