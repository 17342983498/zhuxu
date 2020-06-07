#define _CRT_SECURE_NO_WARNINGS 1

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* BuyDHClistNode(LTDataType x);

// ��ʼ��
ListNode* ListInit();

//���
void ListClear(ListNode* plist);

// ˫����������
void ListDestory(ListNode** plist);

// ˫�������ӡ
void ListPrint(ListNode* plist);

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x);

// ˫������βɾ
void ListPopBack(ListNode* plist);

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* plist);

// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

void TestList();