#pragma once
#include"Time.h"
#include"Object.h"

#define STANDARD_CLOCK 500
#define STANDARD_SPEED 100

typedef Position Direct;

class MovingObject : public Object
{
private:
	Position m_NextPos;
	Direct m_Direct;
	int m_iSpeed;
	int m_iMoveTime;
public:
	virtual void TimeCheck() = 0;
	bool MoveCheck();
	void Move(Direct direct);
	void MoveCancle();
};

