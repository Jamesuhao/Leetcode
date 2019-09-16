#include<stdio.h>
//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//示例 1:
//输入: 1->2->3->3->4->4->5
//输出 : 1->2->5
//示例 2 :
//输入 : 1->1->1->2->3
//输出 : 2->3
//

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* prev1 = NULL;//prev2的前驱结点
	struct ListNode* prev2 = NULL;//cur的前驱结点
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
