#define _CRT_SECURE_NO_WARNINGS 1

#include <malloc.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct ListNode
{
	SLTDateType val;
	struct ListNode* next;
}ListNode;

ListNode* BuySListNode(SLTDateType data);

void ListPushBack(ListNode** Head, SLTDateType data);

void ListPrint(ListNode* Head);