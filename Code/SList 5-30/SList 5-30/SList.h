#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType data);

// 单链表打印
void SListPrint(SListNode* head);

// 单链表尾插
void SListPushBack(SListNode** head, SLTDateType data);

// 单链表的头插
void SListPushFront(SListNode** head, SLTDateType data);

// 单链表的尾删
void SListPopBack(SListNode** head);

// 单链表头删
void SListPopFront(SListNode** head);

// 单链表查找
SListNode* SListFind(SListNode* head, SLTDateType data);

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType data);

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);

void TestList2();