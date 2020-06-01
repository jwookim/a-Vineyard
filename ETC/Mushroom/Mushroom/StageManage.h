#pragma once
#include"List.h"
#include"BSTree.h"
#include"AllChamp.h"
#include"AllObj.h"
class StageManage
{
private:
	int m_istage;
	Player* m_Player;
	List<Enemy*> m_Enemy;
	List<Projectile*> m_Projectile;
	BSTree m_Block;
	BSTree m_Bush;
	BSTree m_Switch;
	BSTree m_Trap;
public:
	StageManage(int stage);
	void TimeProgress();
	void MoveCheck();
	void StatusCheck();
	void SwitchCheck();
	void TrapCheck();
	~StageManage();
};

//버섯을 올려놓는 것으로 스위치 작동 가능
//스위치 - 자신의 좌표에 오브젝트가 존재하는가 체크?