#define _CRT_SECURE_NO_WARNINGS 1

#include "DHClist.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>


ListNode* BuyDHClistNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
} 
//初始化
ListNode* ListInit()
{
	ListNode* head = BuyDHClistNode(0);
	head->next = head;
	head->prev = head;
	return head;
}
// 双向链表清空
void ListClear(ListNode* pHead)
{
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
//销毁
void ListDestroy(ListNode** pHead)
{
	assert(*pHead);
	ListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->prev, x);
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	ListErase(pHead->prev);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead,x);
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	ListErase(pHead->next);
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assset(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (x = cur->data)
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
	if (NULL == pos)
	{
		return NULL;
	}
	ListNode* newNode = BuyDHClistNode(x);
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	newNode->prev->next = newNode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	if (NULL == pos)
	{
		return NULL;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void TestList()
{
	ListNode* head = ListInit();
	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPushFront(head, 5);
	ListPushFront(head, 6);
	ListPushFront(head, 7);
	ListPrint(head);

	ListPopFront(head);
	ListPrint(head);

	ListPushBack(head, 8);
	ListPrint(head);

	ListPopBack(head);
	ListPrint(head);

	ListInsert(ListFind(head, 3), 20);
	ListPrint(head);

	ListErase(3);
	ListPrint(ListFind(head, 3));

	ListDestory(&head);
}
