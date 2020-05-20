
typedef int SDataType;

typedef struct SeqList
{
	SDataType* arr;
	int size;
	int capacity;
}SeqList;

//初始化
void SeqListInit(SeqList* s, int initCapacity);

//尾插
void SeqListPushBack(SeqList* s, SDataType data);

//尾删
void SeqListPopBack(SeqList* s);

//头插
void SeqListPushFront(SeqList* s, SDataType data);

//头删
void SeqListInitPopFront(SeqList* s);

//任意位置的删除
void SeqListErase(SeqList* s,int pos);

//任意位置的插入
void SeqListInsert(SeqList* s, int pos, SDataType data);

//容量
int SeqListSize(SeqList* s);

//检测顺序表是否为空
int SeqListEmpty(SeqList* s);

//查找值为data的元素是否在顺序表中,若在，返回其下标，若不在，返回-1
int SeqListFind(SeqList* s, SDataType data);

//销毁
void SeqListDestroy(SeqList* s);
