#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#include"Shop.h"
#define UPATTACK 4
#define UPHEALTH 10
struct CHARAC
{
	string strName;
	int iAttack;
	int iCurHealth;
	int iMaxHealth;
	int iEXP;
	int iMaxEXP;
	int iGetEXP;
	int iLevel;
	int iType; // Player or Enemy
	int iGold;
	int iWAttack; // weapon attack;
};


class Character
{
private:
	CHARAC m_PLAYER;
	CHARAC *m_ENEMY;
	MapDraw DrawManager;
	Shop ShopManager;
	int m_iStage;
	int h;
	int w;
	int m_iPlayerChoice, m_iEnemyChoice;
	int m_iSelectNum;
	int m_iPAttack;
public:
	Character();
	inline void SetPlayerName() { cin >> m_PLAYER.strName; }
	void ShowPlayerDetail();
	void ShowMonsterDetail();
	void ShowDetail(CHARAC* C);
	void ShowFightPage(int i);
	int EnemySelect();
	void Fight(int index);
	void SetDefault();
	void ShowChoice(int Num);
	void LevelUp(CHARAC* P1);
	void ExpUp(CHARAC* P1,CHARAC* P2);
	void Attack(CHARAC* P1, CHARAC* P2);
	void FileList();
	void Save();
	int Load();
	void BuyWeapon();
	void CharacterClear();
	~Character();
};

