#pragma once
#include"Employee.h"

typedef Employee* LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* Before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist);

void LInsert(List* plist, LData data, int check = FALSE);

int LFirst(List * plist, LData * pdata);

int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);

int LCount(List * plist);