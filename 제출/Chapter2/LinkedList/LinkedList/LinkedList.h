#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef char type;
typedef struct _node
{
	type data; //데이터를 담을 공간
	struct _node* next; //연결의 도구
}Node;

template <typename Type>
void LInsert(Node** head, Node** tail, Type Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = Data;
	newNode->next = NULL;
	if (*tail == NULL)
		*tail = newNode;
	else
		newNode->next = *head;
	*head = newNode;
}
void LRead(Node* head);
int LRemove(Node* head, Node* tail);