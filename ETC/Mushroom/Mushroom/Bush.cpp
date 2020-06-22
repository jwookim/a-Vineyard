#include "Bush.h"


Bush::Bush(Position pos) : Object(pos)
{
	m_strShape = "¢Æ";
	m_iColor = GREEN;

	Draw();
}