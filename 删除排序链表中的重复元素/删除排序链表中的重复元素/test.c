#include<stdio.h>
//����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
//ʾ�� 1:
//����: 1->2->3->3->4->4->5
//��� : 1->2->5
//ʾ�� 2 :
//���� : 1->1->1->2->3
//��� : 2->3
//

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* prev1 = NULL;//prev2��ǰ�����
	struct ListNode* prev2 = NULL;//cur��ǰ�����
	struct ListNode* cur = NULL;
	if (head == NULL)
	{
		return NULL;
	}
	prev1 = head;
	prev2 = head;
	cur = head->next;
	while (cur)
	{
		if (cur->val == prev2->val)
		{
			while (cur != NULL && cur->val == prev2->val)
			{
				cur = cur->next;
			}
			if (cur != NULL)
			{
				prev2->val = cur->val;
				prev2->next = cur->next;
				cur = cur->next;
			}
			else
			{
				if (prev1->val == prev2->val)
				{
					head = NULL;
				}
				else
				{
					prev1->next == NULL;
				}
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
