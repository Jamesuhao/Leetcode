#include<stdio.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//ʾ�� :
//����: 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = NULL;
	if (head == NULL)
	{
		return head;
	}
	cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			cur = cur->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}