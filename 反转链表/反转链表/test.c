#include<stdio.h>
//��תһ��������
//ʾ�� :
//����: 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
struct ListNode
{
	int val;
	struct ListNode* next;
};
//ͷ�巨��
struct ListNode* reversrList(struct ListNode* head)
{
	struct ListNode* prev = NULL;
	struct ListNode* newhead = head;
	struct ListDode* next = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	while (newhead)
	{
		next = newhead->next;
		newhead->next = prev;
		prev = newhead;
		newhead = next;
	}
	return prev;
}
//�����ת����
struct ListNode* reversrList(struct ListNode* head)
{
	struct ListNode* n1 = head;
	struct ListNode* n2 = NULL;
	struct ListNode* n3 = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	n2 = n1->next;
	n3 = n1->next->next;
	n1->next=NULL;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
}