#pragma once
#include"MapDraw.h"

enum CHECK
{
	CHECK_BLANK,
	CHECK_MINE
};

struct Position
{
	int x;
	int y;

	bool operator == (Position p) const
	{
		if (x == p.x && y == p.y)
			return true;

		return false;
	}

	bool operator != (Position p) const
	{
		if (x == p.x && y == p.y)
			return false;

		return true;
	}

	bool operator > (Position p) const
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

	bool operator < (Position p) const
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

	Position operator +(Position p)
	{
		return { x + p.x , y + p.y };
	}

	void operator +=(Position p)
	{
		x += p.x;
		y += p.y;
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
	virtual CHECK Click();
	void Hide();
	bool operator == (Position p);
	bool operator > (Position p);
	bool operator < (Position p);
};

