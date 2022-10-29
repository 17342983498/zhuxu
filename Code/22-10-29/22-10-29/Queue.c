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


// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// 队尾入队列 

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

// 队头出队列 

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

// 获取队列头部元素 

QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return -1;
	}
	return q->front->data;
}

// 获取队列队尾元素 

QDataType QueueBack(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		return -1;
	}
	return q->rear->data;
}

// 获取队列中有效元素个数 

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 

int QueueEmpty(Queue* q)
{
	return q->size == 0;
}

// 销毁队列 

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