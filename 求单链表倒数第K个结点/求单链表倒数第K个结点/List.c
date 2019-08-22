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
Node *LastkNode(pList plist, int k)
{
	if (k < 0)
	{
		return NULL;
	}
	Node *p = plist;
	Node *q = plist;
	assert(plist != NULL);
	//1.��p����K-1��
	while (k - 1>0)
	{
		if (p->next != NULL)
		{
			p = p->next;
			--k;
		}
		else
		{
			return NULL;
		}
	}
	//2.����ָ��ͬʱ��
	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

//��ӡ
void Show(pList plist)
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