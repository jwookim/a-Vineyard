#pragma once
#include"MapDraw.h"

struct Position
{
	int x;
	int y;

	bool operator == (Position p)
	{
		if (x == p.x && y == p.y)
			return true;

		return false;
	}

	bool operator > (Position p)
	{
		if (x > p.x)
			return true;
		else if (x == p.x)
		{
			if (y > p.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator < (Position p)
	{
		if (x < p.x)
			return true;
		else if (x == p.x)
		{
			if (y < p.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};


class Block
{
protected:
	Position m_Position;
public:
	Block(Position pos);
	inline Position GetPosition() const
	{
		return m_Position;
	}
	void SetPosition(Position pos);
	bool operator == (Position p);
	bool operator > (Position p);
	bool operator < (Position p);
};

