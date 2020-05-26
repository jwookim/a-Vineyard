#include "MovingObject.h"

bool MovingObject::MoveTimeCheck()
{
	if (clock() >= m_iMoveTime + (STANDARD_CLOCK + ((STANDARD_SPEED - m_iSpeed) * (STANDARD_CLOCK / STANDARD_SPEED))))
		return true;
	return false;
}

void MovingObject::Move(Direct direct)
{
	m_Direct = direct;
	m_NextPos = GetPosition() + direct;
}

void MovingObject::MoveCancle()
{
	m_NextPos = GetPosition();
}