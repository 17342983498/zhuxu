#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType data);

// �������ӡ
void SListPrint(SListNode* head);

// ������β��
void SListPushBack(SListNode** head, SLTDateType data);

// �������ͷ��
void SListPushFront(SListNode** head, SLTDateType data);

// �������βɾ
void SListPopBack(SListNode** head);

// ������ͷɾ
void SListPopFront(SListNode** head);

// ���������
SListNode* SListFind(SListNode* head, SLTDateType data);

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType data);

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);

void TestList2();