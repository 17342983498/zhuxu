#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


QNode* BuyQNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
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
		q->rear->next = newNode;
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
		q->size = 0;
	}
	else
	{
		q->front = DelNode->next;
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

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}

// ���ٶ��� 

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



typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(ms->q1));
	QueueInit(&(ms->q2));
	return ms;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		//q1����Ԫ�أ���ǰsize-1�����Ƶ�q2��
		while (QueueSize(&obj->q1)>1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
	}
	else
	{
		while (QueueSize(&obj->q2)>1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		ret = QueueFront(&obj->q2);
		QueuePop(&obj->q2);
	}
	return ret;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	return QueueBack(&obj->q2);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

void test()
{
	MyStack ms;
	myStackCreate();
	myStackPush(&ms, 1);
	myStackPush(&ms, 2);
	myStackPush(&ms, 3);
	myStackPush(&ms, 4);
	myStackPush(&ms, 5);
	myStackPop(&ms);
	int ret = myStackTop(&ms);
	printf("%d", ret);
	myStackFree(&ms);
}

int main()
{
	test();
	return 0;
}