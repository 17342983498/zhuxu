#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

QNode* BuyQNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}


// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// ��β����� 

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = BuyQNode(data);
	if (QueueEmpty(q))
	{
		q->front = newNode;
	}
	else
	{
		q->rear->pNext = newNode;
	}
	q->rear = newNode;
	q->size++;
}

// ��ͷ������ 

void QueuePop(Queue* q)
{
	assert(q);
	QNode* DelNode = q->front;
	if (q->size == 0)
	{
		return;
	}
	else if (q->size == 1)
	{
		q->front = q->rear = NULL;
	}
	else
	{
		q->front = DelNode->pNext;
		free(DelNode);
		q->size--;
	}
}

// ��ȡ����ͷ��Ԫ�� 

QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return -1;
	}
	return q->front->data;
}

// ��ȡ���ж�βԪ�� 

QDataType QueueBack(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return -1;
	}
	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ��� 

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 

int QueueEmpty(Queue* q)
{
	return q->size == 0;
}

// ���ٶ��� 

void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		q->front = cur->pNext;
		free(cur);
		cur = q->front;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->pNext;
	}
	printf("NULL\n");
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2); 
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	int ret = QueueEmpty(&q);
	printf("%d\n", ret);
	printf("%d\n", QueueSize(&q));
	QueueDestroy(&q);
}