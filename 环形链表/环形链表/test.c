#include<stdio.h>
//����һ�������ж��������Ƿ��л���
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
//��� pos �� - 1�����ڸ�������û�л���
//ʾ�� 1��
//���룺head = [3, 2, 0, -4], pos = 1
//�����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* hasCycle(struct ListNode* head)
{
	struct ListNode* fast, * slow;
	if (head == NULL||head->next==NULL)
	{
		return "false";
	}
	fast = slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return "true";
		}
	}
	return "fasle";
}