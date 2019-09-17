#include<stdio.h>
//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//示例：
//给定一个链表 : 1->2->3->4->5, 和 n = 2.
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
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