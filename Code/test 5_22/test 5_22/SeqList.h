
typedef int SDataType;

typedef struct SeqList
{
	SDataType* arr;
	int size;
	int capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* s, int initCapacity);

//β��
void SeqListPushBack(SeqList* s, SDataType data);

//βɾ
void SeqListPopBack(SeqList* s);

//ͷ��
void SeqListPushFront(SeqList* s, SDataType data);

//ͷɾ
void SeqListInitPopFront(SeqList* s);

//����λ�õ�ɾ��
void SeqListErase(SeqList* s,int pos);

//����λ�õĲ���
void SeqListInsert(SeqList* s, int pos, SDataType data);

//����
int SeqListSize(SeqList* s);

//���˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* s);

//����ֵΪdata��Ԫ���Ƿ���˳�����,���ڣ��������±꣬�����ڣ�����-1
int SeqListFind(SeqList* s, SDataType data);

//����
void SeqListDestroy(SeqList* s);
