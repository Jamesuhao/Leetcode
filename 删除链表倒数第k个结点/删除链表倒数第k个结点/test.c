#include<stdio.h>
//����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
//ʾ����
//����һ������ : 1->2->3->4->5, �� n = 2.
//��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode* prev = NULL;
	struct ListNode* slow = NULL;
	struct ListNode* fast = NULL;
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	prev = slow = fast = head;
	while (--n)
	{
		fast = fast->next;
		if (fast==NULL)
		{
			return head;
		}
	}
	while (fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	if (slow->next)
	{
		slow->val = slow->next->val;
		slow->next = slow->next->next;
	}
	else
	{
		prev->next = NULL;
	}
	return head;
}