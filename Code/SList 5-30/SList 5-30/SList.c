#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"
#include<malloc.h>
#include<assert.h>

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//β��
void SListPushBack(SListNode** head, SLTDateType data)
{
	SListNode* newNode = BuySListNode(data);
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
//��ӡ
void SListPrint(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// �������ͷ��
void SListPushFront(SListNode** head, SLTDateType data)
{
	SListNode* newNode = BuySListNode(data);
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		*head = newNode;
	}
}

// �������βɾ
void SListPopBack(SListNode** head)
{
	assert(head);
	if (*head == NULL)
	{
		return ;
	}
	/*SListNode* Right = *head;
	SListNode* Left= *head;
	Right = Right->next;
	while(Right->next)
	{
		Left = Left->next;
		Right = Right->next;
	}*/
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		SListNode* Right = *head;
		SListNode* Left = NULL;
		while (Right->next)
		{
			Left = Right;
			Right = Right->next;
		}
		Left->next = Right->next;
		free(Right);
		Right = NULL;
	}
}

// ������ͷɾ
void SListPopFront(SListNode** head)
{
	assert(head);
	if (*head == NULL)
	{
		return;
	}
	SListNode* cur = *head;
	*head = cur->next;
	free(cur);
	cur = NULL;
}

// ���������
//SListNode* SListFind(SListNode* head, SLTDateType data)
//{
//	assert(head);
//	/*SListNode* cur = head;*/
//	while (head->data != data && head->next != NULL)
//	{
//		head = head->next;
//	}
//	if (head->data == data)
//		printf("����\n");
//	else
//		printf("������\n");
//}

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType data)
{
	SListNode* newNode = BuySListNode(data);
	if (NULL == pos)
	{
		return;
	}
	else
	{
		newNode->next = pos->next;
		pos->next = newNode;
	}
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL || NULL == pos->next)
	{
		return;
	}
	SListNode* delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

SListNode* SListFind(SListNode* head, SLTDateType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//void TestList()
//{
//	SListNode* head = NULL;
//	SListPushBack(&head, 1);
//	SListPushBack(&head, 2);
//	SListPushBack(&head, 3);
//	SListPushBack(&head, 4);
//
//	SListPushFront(&head, 0);
//	SListPushFront(&head, -1);
//
//	SListPopBack(&head);
//	SListPopFront(&head);
//	SListPrint(head);
//}
void TestList2()
{
	SListNode* Listhead = NULL;
	SListPushBack(&Listhead, 0);
	SListPushBack(&Listhead, 1);
	SListPushBack(&Listhead, 3);
	SListPushBack(&Listhead, 4);
	//���ҵ� 1 ���ڵ�λ�ã��ٸ� 1 �ĺ������ 2
	SListInsertAfter(SListFind(Listhead,1), 2);
	SListPrint(Listhead);

	SListEraseAfter(SListFind(Listhead, 1));
	SListPrint(Listhead);
}