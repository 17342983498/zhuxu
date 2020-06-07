#define _CRT_SECURE_NO_WARNINGS 1

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//
//
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	ListNode* start = pHead;
//	ListNode* end = start;
//	ListNode* prev = NULL;
//	while (start)
//	{
//		end = start->next;
//		while (end)
//		{
//			if (start->val != end->val)
//				break;
//			end = end->next;
//		}
//
//		if (start->next == end)
//		{
//			prev = start;
//			start = end;
//		}
//		else
//		{
//			while (start != end)
//			{
//				//头删
//				if (start == pHead)
//				{
//					pHead = start->next;
//					free(start);
//					start = pHead;
//				}
//				else
//				{
//					prev->next = start->next;
//					free(start);
//					start = start->next;
//				}
//			}
//		}
//	}
//	return pHead;
//}