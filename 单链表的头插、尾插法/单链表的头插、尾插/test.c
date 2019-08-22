#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"List.h"


int main()
{
	Node head;
	Node *p;
	InitList(&head);
	//Í·²å
	InsertHead(&head, 12);
	InsertHead(&head, 22);
	InsertHead(&head, 32);
	InsertHead(&head, 42);
	//Î²²å
	//InsertTail(&head, 12);
	//InsertTail(&head, 22);
	//InsertTail(&head, 32);
	//InsertTail(&head, 42);
	p = LastkNode(&head, 3);
	Show(&head);
	printf("%d\n", p->data);
	//Show(&head);
	return 0;
}
