#pragma once
#include"List.h"
#include"AllChamp.h"
#include"AllObj.h"
class StageManage
{
private:
	Player* m_Player;
	List<Enemy*> m_Enemy;
	List<Block*> m_Block;
	List<Bush*> m_Bush;
	List<Switch*> m_Switch;
	List<Projectile*> m_Projectile;
	List<Trap*> m_Trap;
public:
	void TimeCheck();
	void MoveCheck();
	void SwitchCheck();
	void TrapCheck();
};

//버섯을 올려놓는 것으로 스위치 작동 가능
//스위치 - 자신의 좌표에 오브젝트가 존재하는가 체크?