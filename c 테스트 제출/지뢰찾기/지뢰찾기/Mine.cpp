#include "Mine.h"

Mine::Mine(Position pos) : Block(pos)
{

}

CHECK Mine::Click()
{
	MapDraw::GetInstance()->DrawPoint("ขอ", m_Position.x, m_Position.y);

	return CHECK_MINE;
}