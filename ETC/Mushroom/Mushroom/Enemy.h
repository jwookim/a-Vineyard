#pragma once
#include"Character.h"
class Enemy : public Character
{
private:
	Character* m_Target;
	Position m_DestPos;
	int m_iSight;
public:
	Enemy();
	void Chase();
	Position Navigate();
	Position CheckTargetInSight();
};


//시야에 들어오면 추격
//시야 밖으로 나가면 나간 직후의 위치까지 인식
//5초간 못찾으면 어그로 해제