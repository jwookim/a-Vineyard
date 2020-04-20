#include "Point.h"


void SetPointPos(Point* ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos)
{
	cout << "x 좌표 : " << ppos->xpos << ", y 좌표 : " << ppos->ypos << endl;
}

//-두 Point변수의 멤버 xpos만 같으면 1
//- 두 Point변수의 멤버 ypos만 같으면 2
//- 두 Point변수의 멤버가 모두 같으면 0
//- 두 Point변수의 멤버가 모두 다르면 - 1
int PointComp(Point* pos1, Point* pos2)
{
	/*if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;
	else if (pos1->xpos == pos2->xpos)
		return 1;
	else if (pos1->ypos == pos2->ypos)
		return 2;
	else
		return -1;*/

	if (pos1->xpos != pos2->xpos)
	{
		if (pos1->xpos < pos2->xpos)
			return 0;
		else
			return 1;
	}
	else
	{
		if (pos1->ypos < pos2->ypos)
			return 0;
		else
			return 1;
	}
}