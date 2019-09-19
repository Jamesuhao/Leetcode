#include<stdio.h>
//编写一个程序，找到两个单链表相交的起始节点。
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	int lenA, lenB,gap;
	struct ListNode* Long, * Short,*curA,*curB;
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	curA = headA;
	while (curA)
	{
		++lenA;
		curA = curA->next;
	}
	curB = headB;
	while (curB)
	{
		++lenB;
		curB = curB->next;
	}
	Long = lenA;
	Short = lenB;
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		Long = lenB;
		Short = lenA;
	}
	while (gap--)
	{
		Long = Long->next;
	}
	while (Short && Long)
	{
		if (Short == Long)
		{
			return Short;
		}
		Short = Short->next;
		Long = Long->next;
	}
	return NULL;
}