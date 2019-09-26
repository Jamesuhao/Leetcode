#include<stdio.h>
//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//ʾ�� 1:
//����: 1->1->2
//��� : 1->2
//ʾ�� 2 :
//���� : 1->1->2->3->3
//��� : 1->2->3
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* prev1 = NULL;
	struct ListNode* prev2 = NULL;
	struct ListNode* cur = NULL;
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		return head;
	}
	prev1 = head;
	prev2 = head;
	cur = head->next;
	while (cur)
	{
		if (cur->val == prev2->val)
		{
			while (cur && cur->val == prev2->val)
			{
				cur = cur->next;
			}
			if (cur)
			{
				prev2->next = cur;
				prev2 = prev2->next;
				cur = cur->next;
			}
			else
			{
				prev2->next = NULL;
			}
		}
		else
		{
			prev1 = prev2;
			prev2 = prev2->next;
			cur = cur->next;
		}
	}
	return head;
}