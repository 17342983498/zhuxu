#define _CRT_SECURE_NO_WARNINGS 1

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* BuyDHClistNode(LTDataType x);

// 初始化
ListNode* ListInit();

//清空
void ListClear(ListNode* plist);

// 双向链表销毁
void ListDestory(ListNode** plist);

// 双向链表打印
void ListPrint(ListNode* plist);

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* plist);

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* plist);

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);

void TestList();