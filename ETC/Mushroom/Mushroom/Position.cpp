#include"Position.h"

Position operator +(Position p1, Position p2)
{
	return { p1.x + p2.x , p1.y + p2.y };
}

bool operator >=(Position p1, Position p2)
{
	if (p1.x > p2.x)
		return true;
	else if (p1.x == p2.x)
	{
		if (p1.y >= p2.y)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool operator <=(Position p1, Position p2)
{
	if (p1.x < p2.x)
		return true;
	else if (p1.x == p2.x)
	{
		if (p1.y <= p2.y)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool operator >(Position p1, Position p2)
{
	if (p1.x > p2.x)
		return true;
	else if (p1.x == p2.x)
	{
		if (p1.y > p2.y)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool operator <(Position p1, Position p2)
{
	if (p1.x < p2.x)
		return true;
	else if (p1.x == p2.x)
	{
		if (p1.y < p2.y)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool operator ==(Position p1, Position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}