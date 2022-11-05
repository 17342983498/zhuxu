#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "test.h"
#include <malloc.h>

ListNode* BuyListNode(int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
	ListNode* cur = NULL;
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	if (list1->data>list2->data)
	{
		cur = list1;
		list1 = list2;
		list2 = cur;
	}
	ListNode* newnode = list1;
	cur = newnode;
	list1 = list1->next;
	while (list1&&list2)
	{
		if (list1->data>list2->data)
		{
			cur->next = list2;
			cur = cur->next;
			list2 = cur->next;
		}
		else
		{
			cur->next = list1;
			cur = cur->next;
			list1 = cur->next;
		}
	}
	if (list1)
	{
		cur->next = list1;
	}
	if (list2)
	{
		cur->next = list2;
	}
	return newnode;
}

void ListPushBack(ListNode** Head, int data)
{
	ListNode* newNode = BuyListNode(data);
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

int main()
{
	ListNode* list1 = NULL;
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 4);
	ListNode* list2 = NULL;
	ListPushBack(&list2, 1);
	ListPushBack(&list2, 3);
	ListPushBack(&list2, 4);

	ListNode* ret = mergeTwoLists(list1, list2);
	while (ret)
	{
		printf("%d--->", ret->data);
		ret = ret->next;
	}
	printf("NULL\n");
	return 0;
}