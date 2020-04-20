#pragma once
#include"DLinkedList.h"
#include"Point.h"
#include<time.h>
#include<stdlib.h>
#define LISTSIZE 30

void main()
{
	srand((unsigned)time(NULL));

	Point* rnum = new Point;

	List* list = new List;

	ListInit(list);

	SetSortRule(list, &PointComp);

	for (int i = 0; i < LISTSIZE; i++)
	{
		SetPointPos(rnum, rand() % LISTSIZE + 1, rand() % LISTSIZE + 1);

		LInsert(list, rnum);
	}

	delete rnum;

	LFirst(list, rnum);
	ShowPointPos(rnum);

	while (LNext(list, rnum) != FALSE)
		ShowPointPos(rnum);

	LFirst(list, rnum);
	while (list->numOfData > 0)
		LRemove(list);
}