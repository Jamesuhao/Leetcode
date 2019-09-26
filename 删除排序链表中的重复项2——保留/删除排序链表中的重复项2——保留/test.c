#include<stdio.h>
//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//示例 1:
//输入: 1->1->2
//输出 : 1->2
//示例 2 :
//输入 : 1->1->2->3->3
//输出 : 1->2->3
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