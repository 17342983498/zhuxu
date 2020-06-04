#define _CRT_SECURE_NO_WARNINGS 1

//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//	{
//		return l2;
//	}
//	else if (l2 == NULL)
//	{
//		return l1;
//	}
//
//	struct ListNode* cur1 = l1;
//	struct ListNode* cur2 = l2;
//	struct ListNode* newNode = NULL;
//	struct ListNode* tailNode = NULL;
//	if (cur1->val <= cur2->val)
//	{
//		newNode = cur1;
//		tailNode = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newNode = cur2;
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
//	return newNode;
//}