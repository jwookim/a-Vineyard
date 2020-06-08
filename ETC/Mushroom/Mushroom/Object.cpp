#include "Object.h"

Object::Object()
{
}

void Object::SetPosition(Position pos)
{
	m_Position = pos;
}

void Object::SetShape(string shape)
{
	m_strShape = shape;
}

void Object::SetColor(int color)
{
	m_iColor = color;
}

void Object::Draw()
{
	DrawManager.ChangeColor(m_iColor);
	DrawManager.DrawPoint(m_strShape, m_Position.x, m_Position.y);
	DrawManager.ChangeColor(ORIGINAL);
}

void Object::Erase()
{
	DrawManager.ErasePoint(m_Position.x, m_Position.y);
}

Object::~Object()
{
}