#include "MovingObject.h"

MovingObject::MovingObject(Position pos) : Object(pos)
{
	m_Direct = DOWN;
}

MovingObject::MovingObject(Direct dir, Position pos) : Object(pos)
{
	m_Direct = dir;
}

bool MovingObject::MoveTimeCheck()
{
	if (clock() >= m_iMoveTime + ((STANDARD_CLOCK * 100) / m_iSpeed))
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

void MovingObject::SetDirect(Direct dir)
{
	m_Direct = dir;
}

void MovingObject::SetMoveTime(int time)
{
	m_iMoveTime = time;
}