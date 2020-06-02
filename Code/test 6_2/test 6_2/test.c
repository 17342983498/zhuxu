#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//输入一个链表，输出该链表中倒数第k个结点。
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
//{
//	if (pListHead == NULL || k == 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//	while (k--)
//	{
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}

//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//	if (pListHead == NULL || k == 0)
//		return NULL;
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//	while (--k)
//	{
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//	if (fast == NULL)
//		return NULL;
//	while (fast->next)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}


//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
//struct ListNode* middleNode(struct ListNode* head){
//
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}


//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//	if (l1 == NULL)
//		return l2;
//	else if (l2 == NULL)
//		return l1;
//	struct ListNode* newhead = NULL;
//	struct ListNode* cur1 = l1;
//	struct ListNode* cur2 = l2;
//	struct ListNode* tailNode = NULL;
//	if (cur1->val <= cur2->val)
//	{
//		newhead = cur1;
//		tailNode = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newhead = cur2;
//		tailNode = cur2;
//		cur2 = cur2->next;
//	}
//	while (cur1&&cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tailNode->next = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			tailNode->next = cur2;
//			cur2 = cur2->next;
//		}
//		tailNode = tailNode->next;
//	}
//	if (cur1 == NULL)
//	{
//		tailNode->next = cur2;
//	}
//	else if (cur2 == NULL)
//	{
//		tailNode->next = cur1;
//	}
//	return newhead;
//}
