#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (cur == head)
//			{
//				//cur为第一个节点
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//int main()
//{
//	struct ListNode* removeElements(struct ListNode* head, int val)
//}
int countPrimes(int n)
{
	int m = 0;
	for (int i = 2; i < n; i++)
	{
		int count = 0;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
			{
				count++;
			}
		}
		if (count == 0)
		{
			m++;
		}
	}
	return m;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int m = countPrimes(n);
	printf("%d\n", m);
	return 0;
}