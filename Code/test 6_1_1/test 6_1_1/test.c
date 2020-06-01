#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//反转一个单链表。
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//typedef struct ListNode ListNode;
//struct ListNode* reverseList(struct ListNode* head){
//	ListNode* prev = NULL;
//	ListNode* cur = head;
//	ListNode* next = NULL;
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	return prev;
//}
