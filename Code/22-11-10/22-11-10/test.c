#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

ListNode* BuySListNode(SLTDateType data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->val = data;
	newNode->next = NULL;
	return newNode;
}

void ListPushBack(ListNode** Head, SLTDateType data)
{
	assert(Head);
	ListNode* newNode = BuySListNode(data);
	if (*Head == NULL)
	{
		*Head = newNode;
	}
	else
	{
		ListNode* cur = *Head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}


ListNode* partition(ListNode* pHead, int x)
{
	ListNode* greatHead = NULL, *greattail = NULL;
	ListNode* lessHead = NULL, *lesstail = NULL;
	ListNode* cur = pHead;
	while (cur)
	{
		if (cur->val<x)
		{
			if (lessHead == NULL)
			{
				lessHead = cur;
			}
			else
			{
				lesstail->next = cur;
			}
			lesstail = cur;
		}
		else
		{
			if (greatHead == NULL)
			{
				greatHead = cur;
			}
			else
			{
				greattail->next = cur;
			}
			greattail = cur;
		}
		cur = cur->next;
	}
	lesstail->next = greatHead;
	greattail->next = NULL;
	return lessHead;
}

void ListPrint(ListNode* Head)
{
	ListNode* cur = Head;
	while (cur)
	{
		printf("%d---->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

int main()
{
	ListNode* head=NULL;
	ListPushBack(&head, 1);
	ListPushBack(&head, 3);
	ListPushBack(&head, 4);
	ListPushBack(&head, 2);
	ListPushBack(&head, 5);
	partition(head, 3);
	ListPrint(head);
	return 0;
}