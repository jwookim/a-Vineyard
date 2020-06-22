#include "Block.h"


Block::Block(Position pos) : Object(pos)
{
	m_strShape = "бс";
	m_iColor = DARK_BLUE;
	Draw();
}