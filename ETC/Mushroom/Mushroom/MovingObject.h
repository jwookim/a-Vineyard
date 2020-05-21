#pragma once
#include"Object.h"
class MovingObject : public Object
{
private:
	Position m_NextPos;
	Direct m_Direct;
	int m_iSpeed;
public:
	virtual void TimeCheck() = 0;
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

