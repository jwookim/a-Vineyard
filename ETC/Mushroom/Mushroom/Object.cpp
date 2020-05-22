#include "Object.h"


void Object::Draw()
{
	DrawManager.DrawPoint(to_string(m_chShape), m_Position.x, m_Position.y);
}

void Object::Erase()
{
	DrawManager.ErasePoint(m_Position.x, m_Position.y);
}