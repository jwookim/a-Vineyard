#include "Point.h"


void SetPointPos(Point* ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos)
{
	cout << "x ÁÂÇ¥ : " << ppos->xpos << ", y ÁÂÇ¥ : " << ppos->ypos << endl;
}

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