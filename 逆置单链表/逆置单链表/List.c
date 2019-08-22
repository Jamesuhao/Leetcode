#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void InitList(pList plsit)
{
	assert(plsit != NULL);
	plsit->data = -1;
	plsit->next = NULL;
}

//�õ�һ���ڵ�
Node *GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

//ͷ��   plist:  ͷ���ĵ�ַ
void InsertHead(pList plist, int val)//55
{
	Node *pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}
//����
//1.��ָ�뷨(ԭ�����ã�
Node *ReverseList(pList head)
{
	Node *prev = NULL;
	Node *pCur = head->next;;
	Node *pCurN = NULL;
	while (pCur)
	{
		pCurN = pCur->next;
		if (pCurN == NULL)
		{
			head = pCur;
		}
		pCur->next = prev;
		prev= pCur;
		pCur= pCurN;
	}
	return head;
}
//2.ͷ������
//void ReverseList(pList head)
//{
//	Node *pCur = head->next;
//	Node *pNext = pCur;
//	assert(head != NULL);
//	head->next = NULL;
//	while (pCur)
//	{
//		pNext = pCur->next;
//		pCur->next = head->next;
//		head->next = pCur;
//		pCur = pNext;
//	}
//}

//��ӡ
void Show1(pList plist)
{
	Node *p = NULL;
	assert(plist != NULL);
	p = plist->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Show2(pList plist)
{
	Node *p = NULL;
	assert(plist != NULL);
	p =plist;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}