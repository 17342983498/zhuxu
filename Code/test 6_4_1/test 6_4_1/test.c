#define _CRT_SECURE_NO_WARNINGS 1


//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
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


//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//
//����������
//1->2->2->1
//���أ�true
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