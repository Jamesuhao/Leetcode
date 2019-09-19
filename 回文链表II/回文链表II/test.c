#include<stdio.h>
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
//��� pos �� - 1�����ڸ�������û�л���
//˵�����������޸ĸ���������
//ʾ�� 1��
//���룺head = [3, 2, 0, -4], pos = 1
//�����tail connects to node index 1
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
//�ж��Ƿ���ڻ�
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
	//������ڻ�  Ѱ�����
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