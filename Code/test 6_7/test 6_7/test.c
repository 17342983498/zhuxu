#define _CRT_SECURE_NO_WARNINGS 1

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
//				//ͷɾ
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