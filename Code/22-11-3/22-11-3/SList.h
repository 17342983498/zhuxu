#define _CRT_SECURE_NO_WARNINGS 1

#include <malloc.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SLTDateType data);

void SListPrint(SListNode* Head);

void SListPushBack(SListNode** Head, SLTDateType data);

void SListPushFront(SListNode** Head, SLTDateType data);

void SListPopBack(SListNode** Head);

void SListPopFront(SListNode** Head);

SListNode* SListFind(SListNode* Head, SLTDateType data);

void SListInsert(SListNode* pos, SLTDateType data);

void SListDel(SListNode* pos);

void SListTest();