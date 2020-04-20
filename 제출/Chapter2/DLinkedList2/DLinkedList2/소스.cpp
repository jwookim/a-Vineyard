#pragma once
#include"DLinkedList.h"
#include"Point.h"
#include<time.h>
#include<stdlib.h>
#define LISTSIZE 50

void main()
{
	srand((unsigned)time(NULL));

	Point* rnum;
	int x, y;

	List* list = new List;

	ListInit(list);

	SetSortRule(list, &PointComp);

	for (int i = 0; i < LISTSIZE; i++)
	{
		rnum = new Point;
		x = rand() % LISTSIZE + 1;
		y = rand() % LISTSIZE + 1;
		SetPointPos(rnum, x, y);

		LInsert(list, rnum);
		rnum = NULL;
	}


	Point* tmp;
	LFirst(list, &tmp);
	ShowPointPos(tmp);

	while (LNext(list, &tmp) != FALSE)
		ShowPointPos(tmp);

	
	while (list->numOfData > 0)
	{
		LFirst(list, &tmp);
		LRemove(list);
	}
}