#pragma once
#include<iostream>
using namespace std;
#define UP {0, -1}
#define DOWN {0, 1}
#define LEFT {-1, 0}
#define RIGHT {1, 0}


typedef struct POSITION
{
	int x;
	int y;
}Position;

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