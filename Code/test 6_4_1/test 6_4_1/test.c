#define _CRT_SECURE_NO_WARNINGS 1


//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
//
//ListNode* partition(ListNode* pHead, int x) {
//	if (pHead == NULL)
//		return NULL;
//	ListNode cur1Head(0);
//	ListNode cur2Head(0);
//	ListNode* cur1 = &cur1Head;
//	ListNode* cur2 = &cur2Head;
//	ListNode* cur = pHead;
//	while (cur)
//	{
//		pHead = cur->next;
//		if (cur->val<x)
//		{
//			cur1->next = cur;
//			cur1 = cur;
//		}
//		else
//		{
//			cur2->next = cur;
//			cur2 = cur;
//		}
//		cur = pHead;
//	}
//	cur2->next = NULL;
//	cur1->next = cur2Head.next;
//	return cur1Head.next;
//}


//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true
//
//bool chkPalindrome(ListNode* A) {
//	if (A == NULL)
//		return true;
//	int arr[900] = { 0 };
//	ListNode* cur = A;
//	int size = 0;
//	while (cur)
//	{
//		arr[size++] = cur->val;
//		cur = cur->next;
//	}
//	int left = 0;
//	int right = size - 1;
//	while (left <= right)
//	{
//		if (arr[left++] != arr[right--])
//		{
//			return false;
//		}
//	}
//	return true;
//}