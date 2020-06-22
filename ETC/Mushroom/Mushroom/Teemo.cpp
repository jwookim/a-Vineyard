#include "Teemo.h"


Teemo::Teemo(Position pos) : Player(pos)
{
	m_strShape = "¿À";
	m_iColor = YELLOW;
	m_iAtk = 70;
	m_iHealth = 400;
	m_iAtkSpeed = 70;
	m_iSpeed = 90;
	SetRange(RANGE_LONG);
	Draw();
}