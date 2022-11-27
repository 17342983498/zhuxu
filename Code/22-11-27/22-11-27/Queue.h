#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <malloc.h>

struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);
void QueueTest();