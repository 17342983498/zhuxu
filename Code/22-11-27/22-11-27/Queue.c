#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->next = NULL;
	newNode->data = data;

	if (QueueEmpty(q))
	{
		q->front = newNode;
	}
	else
	{
		q->rear->next = newNode;
	}
	q->rear = newNode;
	q->size++;
}
void QueuePop(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return;
	}
	QNode* delNode = q->front;
	if (q->front == q->rear)
	{
		q->front = q->rear = NULL;
	}
	else
	{
		q->front = delNode->next;
	}
	free(delNode);
	q->size--;
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->data;
}
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->rear == NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		q->front = cur->next;
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
		cur = cur->next;
	}
	printf("NULL\n");
}

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	int ret = QueueFront(&q);
	printf("%d\n", ret);
	ret = QueueBack(&q);
	printf("%d\n", ret);
}