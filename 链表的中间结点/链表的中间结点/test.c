#include<stdio.h>
//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
//ʾ�� 1��
//���룺[1, 2, 3, 4, 5]
//��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])
//���صĽ��ֵΪ 3 ��(����ϵͳ�Ըý�����л�������[3, 4, 5])��
//ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.
//ʾ�� 2��
//���룺[1, 2, 3, 4, 5, 6]
//��������б��еĽ�� 4 (���л���ʽ��[4, 5, 6])
//���ڸ��б��������м��㣬ֵ�ֱ�Ϊ 3 �� 4�����Ƿ��صڶ�����㡣

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
//����һ���洢������n������n/2�����
struct ListNode* middleNode(struct ListNode* head)
{
	size_t n = 0;
	struct ListNode* cur = NULL;
	if (head == NULL)
	{
		return head;
	}
	cur = head;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
	n = n / 2;
	cur = head;
	while (n--)
	{
		cur = cur->next;
	}
	return cur;
}
//������������ָ�뷨
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow = NULL;
	struct ListNode* fast = NULL;
	if (head == NULL)
	{
		return head;
	}
	slow = head;
	fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}