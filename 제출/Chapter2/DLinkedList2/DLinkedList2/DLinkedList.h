#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Point.h"
using namespace std;

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

typedef Point* LData;
typedef struct _node
{
	LData data;
	struct _node * next;
} Node;
typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;
typedef LinkedList List;
void ListInit(List* plist); // 초기화

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

template <typename Type>
void LInsert(List* plist, Type data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

template <typename Type>
void FInsert(List* plist, Type data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = plist->head->next;

	plist->head->next = newNode;

	(plist->numOfData)++;
}

template <typename Type>
void SInsert(List* plist, Type data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}



template <typename Type>
int LFirst(List* plist, Type* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

template <typename Type>
int LNext(List* plist, Type* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist); // 참조한 데이터 삭제
int LCount(List* plist); // 저장된 데이터의 수 반환