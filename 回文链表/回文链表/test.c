#include<stdio.h>
//���ж�һ�������Ƿ�Ϊ��������
//ʾ�� 1:
//����: 1->2
//��� : false
//ʾ�� 2 :
//���� : 1->2->2->1
//��� : true
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* prev, *cur, * next;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	prev = NULL;
	cur = head;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
struct ListNode* isPalindrome(struct ListNode* head)
{
	struct ListNode* fast, * slow, * rList;
	if (head == NULL || head->next == NULL)
	{
		return "true";
	}
	fast = slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	rList = reverseList(slow);
	while (head && rList)
	{
		if (head->val != rList->val)
		{
			return "false";
		}
		head = head->next;
		rList = rList->next;
	}
	return "true";
}