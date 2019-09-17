#include<stdio.h>
//输入一个链表，输出该链表中倒数第n个结点。
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