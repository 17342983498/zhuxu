#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

//��ʼ��
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 3 ? 3 : initCapacity;
	s->arr = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (s->arr == NULL)
		return ;
	s ->size = 0;
	s->capacity = initCapacity;
}

//����Ƿ���Ҫ����
int SeqListCheck(SeqList* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newcapacity = s->capacity * 2;
		s->arr = realloc(s->arr,sizeof(SDataType)*newcapacity);
		if (s->arr == NULL)
			return 0;
		s->capacity = newcapacity;
		printf("���ݳɹ�\n");
	}
	return 1;
}

//β��
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//�ٲ���֮ǰ��֤���пռ�
	if (!SeqListCheck(s))
		return;
	/*if (s->size > s->capacity)
		SeqListExpcapacity(s);*/
	s->arr[s->size] = data;
	s->size++;
}

//βɾ
void SeqListPopBack(SeqList* s)
{
	assert(s);
	if (SeqListEmpty(s))
		return;
	s->size--;
}

//ͷ��
void SeqListPushFront(SeqList* s, SDataType data)
{
	assert(s);
	if (!SeqListCheck(s))
		return;
	for (int i = s->size-1; i >= 0; i--)
	{
		s->arr[i+1] = s->arr[i];
	}
	s->arr[0] = data;
	s->size++;
}

//ͷɾ
void SeqListInitPopFront(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size-1; i++)
	{
		s->arr[i] = s->arr[i+1];
	}
	s ->size--;
}

//����λ�õ�ɾ��
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	for (int i = pos + 1; i < s->size; i++)
	{
		s->arr[i-1] = s->arr[i];
	}
	s->size--;
}

//����λ�õĲ���
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	if (!SeqListCheck(s))
		return;
	for (int i = s->size - 1; i >= pos; i--)
	{
		s->arr[i + 1] = s->arr[i];
	}
	s->arr[pos] = data;
	s->size++;
}

//����
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

//���˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

//����ֵΪdata��Ԫ���Ƿ���˳�����,���ڣ��������±꣬�����ڣ�����-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
	{
		if (s->arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}

//����
void SeqListDestroy(SeqList* s)
{
	assert(s);
	free(s->arr);
	s->arr = NULL;
	s->size = 0;
	s->capacity = 0;
}


void SeqListPrint(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size; i++)
		printf("%d ", s->arr[i]);
	printf("\n");
}

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	printf("��ǰ˳����д���%d����\n",SeqListSize(&s));//6
	SeqListPrint(&s);//1 2 3 4 5 6
	
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("��ǰ˳����д���%d����\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 2 3 4

	SeqListPushFront(&s, 0);
	printf("��ǰ˳����д���%d����\n", SeqListSize(&s));//5
	SeqListPrint(&s);//0 1 2 3 4 

	SeqListInitPopFront(&s);
	printf("��ǰ˳����д���%d����\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 2 3 4

	SeqListErase(&s, 2);
	printf("��ǰ˳����д���%d����\n", SeqListSize(&s));//3
	SeqListPrint(&s);//1 2 4

	SeqListInsert(&s, 1, 3);
	printf("��ǰ˳����д���%d����\n", SeqListSize(&s));//4
	SeqListPrint(&s);//1 3 2 4

	SeqListDestroy(&s);  
}