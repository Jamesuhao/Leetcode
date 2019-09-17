#include<stdio.h>
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//ʾ����
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* newhead;
	struct ListNode* newtail;
	if (l1== NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->val < l2->val)
	{
		newhead = l1;
		l1 = l1->next;
	}
	else
	{
		newhead = l2;
		l2 = l2->next;
	}
	newtail = newhead;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			newtail = l1;
			l1 = l1->next;
		}
		else
		{
			newtail = l2;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		newtail->next = l1;
	}
	if (l2)
	{
		newtail->next = l2;
	}
	return newhead;
}