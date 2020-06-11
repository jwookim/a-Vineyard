#pragma once
#include"List.h"
#include<list>
#include"BSTree.h"
#include"AllChamp.h"
#include"AllObj.h"

enum END_TYPE
{
	END_CONTINUE,
	END_GAME_OVER,
	END_CLEAR,
	END_EXIT
};

class StageManage
{
private:
	int m_istage;
	Position m_Goal;
	Player* m_Player;
	list<Enemy*> m_Enemy;
	list<Projectile*> m_Projectile;
	BSTree m_Block;
	BSTree m_Bush;
	BSTree m_Switch;
	BSTree m_Trap;
	BSTree m_Door;
public:
	StageManage(int stage);
	END_TYPE TimeProgress();
	void MoveCheck();
	void StatusCheck();
	void SwitchCheck();
	void TrapCheck();
	void HitCheck();
	END_TYPE EndCheck();
	void Restoration(Object* target);
	~StageManage();
};

//버섯을 올려놓는 것으로 스위치 작동 가능
//스위치 - 자신의 좌표에 오브젝트가 존재하는가 체크?