#include "MovingObject.h"


bool MovingObject::MoveTimeCheck()
{
	if (clock() >= m_iMoveTime + (STANDARD_CLOCK + ((STANDARD_SPEED - m_iSpeed) * (STANDARD_CLOCK / STANDARD_SPEED))))
		return true;
	return false;
}

void MovingObject::TimeCheck()
{

}

bool MovingObject::MoveCheck()
{
	return true;
}

void MovingObject::Move(Direct direct)
{
	m_Direct = direct;
	m_NextPos = GetPosition() + direct;
}

void MovingObject::Move()
{
	SetPosition(m_NextPos);
	m_iMoveTime = clock();
	Draw();
}

void MovingObject::MoveCancle()
{
	m_NextPos = GetPosition();
}

void MovingObject::SetSpeed(int speed)
{
	m_iSpeed = speed;
}