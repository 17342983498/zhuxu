#define _CRT_SECURE_NO_WARNINGS 1

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

ListNode* BuyListNode(int data);


void ListPushBack(ListNode** Head, int data);