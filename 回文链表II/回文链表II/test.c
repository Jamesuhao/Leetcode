#include<stdio.h>
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
//如果 pos 是 - 1，则在该链表中没有环。
//说明：不允许修改给定的链表。
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
//判断是否存在环
struct ListNode* hasCycle(struct ListNode* head)
{
	struct ListNode* fast, *slow;
	if (head == NULL)
	{
		return NULL;
	}
	fast = slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* cur, *rList;
	if (head == NULL)
	{
		return head;
	}
	cur = head;
	rList = hasCycle(head);
	//如果存在环  寻找入口
	if (rList)
	{
		while (rList != cur)
		{
			cur = cur->next;
			rList = rList->next;
		}
		return cur;
	}
	return NULL;
}