#include<stdio.h>
//����һ����������������е�����n����㡣
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* FindKthToTail(struct ListNode* head, int n)
{
	struct ListNode* slow = NULL;
	struct ListNode* fast = NULL;
	if (head == NULL)
	{
		return head;
	}
	slow = fast = head;
	while (--n)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			return head;
		}
	}
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}