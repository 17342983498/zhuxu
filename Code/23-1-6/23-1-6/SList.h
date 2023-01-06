#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
	
}SListNode;


SListNode* BuySListNode(SLDataType data);

void SListPrint(SListNode* Head);

void SListPushBack(SListNode** Head, SLDataType data);

void SListPushFront(SListNode** Head, SLDataType data);

void SListPopBack(SListNode** Head);

void SListPopFront(SListNode** Head);

SListNode* SListFind(SListNode* Head, SLDataType data);

void SListInsertAfter(SListNode* pos, SLDataType data);

void SListDelAfter(SListNode* pos);

void SListTest();