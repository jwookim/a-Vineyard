#pragma once
#include"Character.h"
#include"Queue.h"
class Enemy : public Character
{
private:
	Character* m_Target;
	Queue<Position> m_DestPos;
	int m_iSight;
public:
	Enemy(Position pos);
	bool MoveCheck();
	void Chase();
	void Navigate();
	Position CheckTargetInSight();
};


//시야에 들어오면 추격
//시야 밖으로 나가면 나간 직후의 위치까지 인식
//5초간 못찾으면 어그로 해제