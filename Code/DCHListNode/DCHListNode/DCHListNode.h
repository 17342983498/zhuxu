#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DHCListNode;

typedef struct DHCList
{
	DHCListNode data;
	struct DHCList* prev;
	struct DHCList* next;
}DHCList;

DHCList* ListInit();

DHCList* BuyDHCListNode(DHCListNode data);

DHCList* ListFind(DHCList* pHead, DHCListNode data);

void ListPushBack(DHCList* pHead, DHCListNode data);

void ListPushFront(DHCList* pHead, DHCListNode data);

void ListPopBack(DHCList* pHead);

void ListPopFront(DHCList* pHead);

void ListInsert(DHCList* pos, DHCListNode data);

void ListErase(DHCList* pos);

void ListPrint(DHCList* pHead);

void ListClear(DHCList* pHead);

void ListDestory(DHCList** pHead);

void TestList();