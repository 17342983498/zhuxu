#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
// ��ʽ�ṹ����ʾ���� 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* pNext;
	QDataType data;
}QNode;


// ���еĽṹ 

typedef struct Queue{
	QNode* front;
	QNode* rear;
	int size;
}Queue;


// ��ʼ������ 

void QueueInit(Queue* q);

// ��β����� 

void QueuePush(Queue* q, QDataType data);

// ��ͷ������ 

void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ�� 

QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ�� 

QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ��� 

int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 

int QueueEmpty(Queue* q);

// ���ٶ��� 

void QueueDestroy(Queue* q);
