#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

//��ʼ��
void SeqListInit(SeqList* s, size_t capacity)
{
	assert(s);
	s->array = (SLDataType*)malloc(sizeof(SLDataType)* capacity);
	if (s->array == NULL)
	{
		return;
	}
	s->size = 0;
	s->capacity = capacity;
}

// ˳�������
void SeqListDestory(SeqList* s)
{

	if (s->array)
	{
		free(s->array);
	}
	s->array = NULL;
	s->size = 0;
	s->capacity = 0;
}



// ˳����ӡ
void SeqListPrint(SeqList* s)
{

	for (size_t i = 0; i < s->size; i++)
	{
		printf("%d ", s->array[i]);
	}
	printf("\n");
}



// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->capacity == s->size)
	{
		SLDataType* ps = (SLDataType*)realloc(s->array, sizeof(SLDataType)*(s->capacity + 3));
		if (ps == NULL)
		{
			return;
		}
		s->array = ps;
		s->capacity += 3;
	}
}



// ˳���β��
void SeqListPushBack(SeqList* s, SLDataType x)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->size] = x;
	s->size++;
}



// ˳���βɾ
void SeqListPopBack(SeqList* s)
{
	s->size--;
}



// ˳���ͷ��
void SeqListPushFront(SeqList* s, SLDataType x)
{

	CheckCapacity(s);
	for (SLDataType i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = x;
	s->size++;
}



// ˳���ͷɾ
void SeqListPopFront(SeqList* s)
{

	for (size_t i = 1; i < s->size; i++)
	{
		s->array[i - 1] = s->array[i];
	}
	s->size--;
}



// ˳������
int SeqListFind(SeqList* s, SLDataType x)
{

	for (size_t i = 0; i < s->size; i++)
	{
		if (s->array[i] == x)
		{
			//�ҵ�
			return i + 1;
		}
	}
	//û�ҵ�
	return -1;
}



// ˳�����posλ�ò���x
void SeqListInsert(SeqList* s, size_t pos, SLDataType x)
{
	assert(s);
	CheckCapacity(s);
	for (size_t i = s->size - 1; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = x;
	s->size++;
}



// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* s, size_t pos)
{
	assert(s);
	for (size_t i = pos; i < s->size; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->size--;
}


void SeqListTest()
{
	SeqList s;
	int cap = 5;
	SeqListInit(&s, cap);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);


	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 1, 9);
	SeqListPrint(&s);

	SeqListErase(&s, 1);
	SeqListPrint(&s);

	SeqListDestory(&s);
}