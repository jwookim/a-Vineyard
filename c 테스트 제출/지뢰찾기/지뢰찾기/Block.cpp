#include "Block.h"

bool Block::operator == (Position p)
{
	return m_Position == p;
}

bool Block::operator > (Position p)
{
	return m_Position > p;
}

bool Block::operator < (Position p)
{
	return m_Position < p;
}

Block::Block(Position pos)
{
	m_Position = pos;
}

void Block::SetPosition(Position pos)
{
	m_Position = pos;
}

void Block::Hide()
{
	MapDraw::GetInstance()->DrawPoint("бр", m_Position.x, m_Position.y);
}

CHECK Block::Click()
{
	MapDraw::GetInstance()->ErasePoint(m_Position.x, m_Position.y);

	return CHECK_BLANK;
}