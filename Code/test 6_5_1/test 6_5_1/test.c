#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������ж��������Ƿ��л���
//
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
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

//��������в�������
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
