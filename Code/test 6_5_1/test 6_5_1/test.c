#define _CRT_SECURE_NO_WARNINGS 1
//给定一个链表，判断链表中是否有环。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//bool hasCycle(struct ListNode *head) {
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast&&fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow)
//		{
//			return true;
//		}
//	}
//	return false;
//}

//对链表进行插入排序
//
//struct ListNode* insertionSortList(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	struct ListNode* newHead = NULL;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		head = cur->next;
//		struct ListNode* insertPos = newHead;
//		struct ListNode* insertPosPrev = NULL;
//		while (insertPos)
//		{
//			if (cur->val>insertPos->val)
//			{
//				insertPosPrev = insertPos;
//				insertPos = insertPos->next;
//			}
//			else
//			{
//				break;
//			}
//
//		}
//		if (insertPosPrev == NULL)
//		{
//			cur->next = newHead;
//			newHead = cur;
//		}
//		else
//		{
//			cur->next = insertPos;
//			insertPosPrev->next = cur;
//		}
//		cur = head;
//	}
//	return newHead;
//}
