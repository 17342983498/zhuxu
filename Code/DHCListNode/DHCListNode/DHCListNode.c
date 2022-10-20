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

// 初始化
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

//清空
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

// 双向链表销毁
void ListDestory(ListNode** pHead)
{
	assert(pHead);
	ListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

// 双向链表打印
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

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->prev);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->next, x);
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListErase(pHead->next);
}

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
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