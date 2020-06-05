#define _CRT_SECURE_NO_WARNINGS 1

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//
//struct ListNode *detectCycle(struct ListNode *head) {
//	struct ListNode* hasCycle(struct ListNode *head)
//	{
//		struct ListNode* fast = head;
//		struct ListNode* slow = head;
//		while (fast&&fast->next)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//			if (fast == slow)
//			{
//				return fast;
//			}
//		}
//		return NULL;
//	}
//	struct ListNode* PM = hasCycle(head);
//	if (PM == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* PH = head;
//	while (PM != PH)
//	{
//		PM = PM->next;
//		PH = PH->next;
//	}
//	return PM;
//}

//编写一个程序，找到两个单链表相交的起始节点。
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	if (headA == NULL || headB == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* cur1 = headA;
//	struct ListNode* cur2 = headB;
//	int countA = 1;
//	int countB = 1;
//	while (cur1->next)
//	{
//		countA++;
//		cur1 = cur1->next;
//	}
//	while (cur2->next)
//	{
//		countB++;
//		cur2 = cur2->next;
//	}
//	cur1 = headA;
//	cur2 = headB;
//	int gap = countA - countB;
//	if (gap>0)
//	{
//
//		while (gap--)
//		{
//			cur1 = cur1->next;
//		}
//	}
//	else
//	{
//		while (gap++)
//		{
//			cur2 = cur2->next;
//		}
//	}
//	while (cur1 != cur2)
//	{
//		cur1 = cur1->next;
//		cur2 = cur2->next;
//	}
//	return cur1;
//}