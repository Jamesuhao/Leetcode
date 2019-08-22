#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"List.h"


int main()
{
	Node head;
	Node * p;
	InitList(&head);
	//Í·²å
	InsertHead(&head, 12);
	InsertHead(&head, 22);
	InsertHead(&head, 32);
	InsertHead(&head, 42);
	InsertHead(&head, 52);
	//Show1(&head);
	//ReverseList(&head);
	//Show1(&head);
	Show1(&head);
	p = ReverseList(&head);
	Show2(p);
	return 0;
}