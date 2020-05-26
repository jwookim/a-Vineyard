#pragma once
#include"MovingObject.h"
class Projectile : public MovingObject
{
private:
	int m_iPower;
public:
	bool MoveCheck();
};

