#pragma once
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct _node
{
	int data; //데이터를 담을 공간
	struct _node* next; //연결의 도구
}Node;


void LInsert(Node** head, Node** tail, int Data);
void LRead(Node* head);
int LRemove(Node* head, Node* tail);